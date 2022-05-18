#pragma once

#include <algorithm>
#include <chrono>

#include "data_storage.h"
#include "s21_matrix_oop.h"
#include "export.h"

namespace s21 {

constexpr double MIN = -1.0;
constexpr double MAX = 1.0;
constexpr int DATASET_SIZE = 14400;
constexpr int LAYER_INPUT = 784;
constexpr int LAYER_HIDEN = 140;
constexpr int LAYER_OUTPUT = 26;
constexpr char TEST[] = USER_APP "datasets/emnist-letters/emnist-letters-test.csv";
constexpr char TRAIN[] = USER_APP "datasets/emnist-letters/emnist-letters-train.csv";

struct Metrics {
    int _fp = 0, _fn = 0, _tp = 0, _tn = 0;
    double _accuracy = 0, _precision = 0, _recall = 0, _fScore = 0, _time = 0;
};

class NetworkInterface {
 public:
    NetworkInterface() {}
    virtual ~NetworkInterface() {}

    virtual const std::vector<double> &train(int epochs) = 0;
    virtual const std::vector<double> &crossValidation(int k) = 0;
    virtual char predict(const std::vector<double> &inputValues) = 0;
    virtual Metrics predictTest(double partTestData) = 0;
    virtual void saveWeights(std::string filename) = 0;
    virtual void getWeights(std::string filename) = 0;
    void getMetrics(Metrics &Metrics);
    void checkAnswer(Metrics &Metrics, std::vector<double> outputValues, int answer);
    bool guessedOrNot(std::vector<double> outputValues, int answer);
};

class Neuron {
    std::vector<double> _weights;
    double _output;
    double _bios;
    double _delta;

    double generateRandomNumber() {
        double random = (double)rand() / RAND_MAX;
        return MIN + random * (MAX - MIN);
    }
    void setWeights(int weightsSize);

 public:
    explicit Neuron(int weightsSize);
    ~Neuron() {}

    void setOutput(double output) { _output = output; }
    void setDelta(double delta) { _delta = delta; }
    void setBios(double bios) { _bios = bios; }
    double getBios() { return _bios; }
    double getOutput() { return _output; }
    double getDelta() { return _delta; }
    auto &getWeights() { return _weights; }
};

class Layer {
 private:
    std::vector<Neuron *> _neurons;
    std::vector<double> _bioses;

 public:
    Layer(int layerSize, int weightsSize);
    ~Layer();

    auto getNeurons() { return _neurons; }
    auto getBioses() { return _bioses; }
};

class GraphNetwork : public NetworkInterface {
 private:
    DataStorage _dataStorage;
    std::vector<Layer *> _layers;
    std::vector<int> _layersSize;
    std::vector<double> _outputValues;
    int _hiddenLayers;
    double ALPHA = 0.25;

    void initializeLayersSize();
    double functionActivation(double value);
    double functionActivationDerivate(double value);
    double calculateTransferNeurons(std::vector<double> weights, std::vector<double> inputValues,
                                    double bios);
    void forwardPropagation(const std::vector<double> &inputValues);
    void backPropagation();
    void updateWeight();

 public:
    explicit GraphNetwork(int hiddenLayers);
    ~GraphNetwork();

    void initilizeNetwork();
    const std::vector<double> &train(int epochs) override;
    const std::vector<double> &crossValidation(int k) override;
    char predict(const std::vector<double> &inputValues) override;
    Metrics predictTest(double partTestData) override;
    void saveWeights(std::string filename) override;
    void getWeights(std::string filename) override;
};

class MatrixNetwork : public NetworkInterface {
 private:
    DataStorage _dataStorage;
    std::vector<S21Matrix> _matrixWeight;
    std::vector<S21Matrix> _matrixBios;
    std::vector<S21Matrix> _matrixOutput;
    std::vector<S21Matrix> _gradientErrors;
    int _hiddenLayers;
    double ALPHA = 0.25;

    double functionActivation(double value) { return 1.0 / (1.0 + exp(-value)); }
    double functionActivationDerivate(double value) { return value * (1.0 - value); }
    void fillMatrixRandomValue(S21Matrix &matrix);
    void fillVectorMatrixRandomValue(std::vector<S21Matrix> &matrix);
    std::vector<double> transformMatrixToVector(S21Matrix &matrix);
    void transferMatrixByActivationFunction(S21Matrix &matrix);
    void transferMatrixByDerivateFunction(S21Matrix &matrix);
    S21Matrix oneHotEncoder();
    void forwardPropagation(const std::vector<double> &inputValues);
    void backPropagation();
    void updateWeight();

 public:
    explicit MatrixNetwork(int hiddenLayers);
    ~MatrixNetwork() {}

    void initilizeNetwork();
    const std::vector<double> &train(int epochs) override;
    char predict(const std::vector<double> &inputValues) override;
    Metrics predictTest(double partTestData) override;
    const std::vector<double> &crossValidation(int k) override;
    void saveWeights(std::string filename) override;
    void getWeights(std::string filename) override;
};

class Network {
 private:
    NetworkInterface *_networkInterface;

 public:
    explicit Network(NetworkInterface *networkInterface) : _networkInterface(networkInterface) {}
    ~Network() { delete _networkInterface; }

    const std::vector<double> &train(int epochs) { return _networkInterface->train(epochs); }
    const std::vector<double> &crossValidation(int k) { return _networkInterface->crossValidation(k); }
    char predict(const std::vector<double> &inputValues) { return _networkInterface->predict(inputValues); }
    Metrics predictTest(double partTestData) { return _networkInterface->predictTest(partTestData); }
    void saveWeights(std::string filename) { _networkInterface->saveWeights(filename); }
    void getWeights(std::string filename) { _networkInterface->getWeights(filename); }
    void getMetrics(Metrics &Metrics) { _networkInterface->getMetrics(Metrics); }
};

}  // namespace s21

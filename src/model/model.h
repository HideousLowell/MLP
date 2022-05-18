#pragma once

#include "network.h"

namespace s21 {

enum TypeNetwork { GRAPH, MATRIX };

class Model {
 private:
    Network *_network;

 public:
    Model() { _network = nullptr; }
    ~Model() { delete _network; }

    void initilizeNetwork(TypeNetwork type, int hidenLayers) {
        delete _network;
        if (type == GRAPH) {
            _network = new Network(new GraphNetwork(hidenLayers));
        } else if (type == MATRIX) {
            _network = new Network(new MatrixNetwork(hidenLayers));
        }
    }
    const std::vector<double> &train(int epochs) { return _network->train(epochs); }
    const std::vector<double> &crossValidation(int k) { return _network->crossValidation(k); }
    char predict(const std::vector<double> &inputValues) { return _network->predict(inputValues); }
    Metrics predictTest(double partTestData) { return _network->predictTest(partTestData); }
    void saveWeights(std::string filename) { _network->saveWeights(filename); }
    void getWeights(std::string filename) { _network->getWeights(filename); }
    void getMetrics(Metrics &metrics) { _network->getMetrics(metrics); }
};

}  // namespace s21

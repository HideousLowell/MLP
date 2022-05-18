#include "network.h"

namespace s21 {

/* NEURON */

Neuron::Neuron(int weightsSize) : _output(0), _delta(0) {
    setWeights(weightsSize);
    _bios = generateRandomNumber();
}

void Neuron::setWeights(int weightsSize) {
    for (int i = 0; i < weightsSize; i++) {
        _weights.push_back(generateRandomNumber());
    }
}

/* LAYER */

Layer::Layer(int layerSize, int weightsSize) {
    for (int i = 0; i < layerSize; i++) {
        Neuron *neuron = new Neuron(weightsSize);
        _neurons.push_back(neuron);
        _bioses.push_back(neuron->getBios());
    }
}

Layer::~Layer() {
    for (size_t i = 0; i < _neurons.size(); i++) {
        delete _neurons[i];
    }
}

/* GRAPH NETWORK */

GraphNetwork::GraphNetwork(int hiddenLayers) : NetworkInterface(), _hiddenLayers(hiddenLayers) {
    initilizeNetwork();
}

GraphNetwork::~GraphNetwork() {
    for (size_t i = 0; i < _layers.size(); i++) {
        delete _layers[i];
    }
}

void GraphNetwork::initilizeNetwork() {
    initializeLayersSize();
    for (int i = 0; i < _hiddenLayers + 1; i++) {
        _layers.push_back(new Layer(_layersSize[i + 1], _layersSize[i]));
    }
}

void GraphNetwork::initializeLayersSize() {
    _layersSize.push_back(LAYER_INPUT);
    for (int i = 0; i < _hiddenLayers; i++) {
        _layersSize.push_back(LAYER_HIDEN);
    }
    _layersSize.push_back(LAYER_OUTPUT);
}

double GraphNetwork::functionActivation(double value) { return 1.0 / (1.0 + exp(-value)); }

double GraphNetwork::functionActivationDerivate(double value) { return value * (1.0 - value); }

double GraphNetwork::calculateTransferNeurons(std::vector<double> weights, std::vector<double> inputValues,
                                              double bios) {
    double resultValue = bios;
    for (size_t i = 0; i < weights.size(); i++) {
        resultValue += weights[i] * inputValues[i];
    }
    return resultValue;
}

void GraphNetwork::forwardPropagation(const std::vector<double> &inputValues) {
    std::vector<double> inputValuesTemp = inputValues;
    for (int i = 0; i < _hiddenLayers + 1; i++) {
        std::vector<double> newInputValues;
        for (Neuron *neurons : _layers[i]->getNeurons()) {
            double activation =
                calculateTransferNeurons(neurons->getWeights(), inputValuesTemp, neurons->getBios());
            neurons->setOutput(functionActivation(activation));
            newInputValues.push_back(neurons->getOutput());
        }
        inputValuesTemp = newInputValues;
    }
    _outputValues = inputValuesTemp;
}

void GraphNetwork::backPropagation() {
    double expected = _dataStorage.getAnswer() - 1;
    std::vector<double> answer(LAYER_OUTPUT, 0);
    answer[expected] = 1.0;
    for (int i = _hiddenLayers; i >= 0; i--) {
        std::vector<double> errors;
        if (i != _hiddenLayers) {
            for (size_t j = 0; j < _layers[i]->getNeurons().size(); j++) {
                double error = 0.0;
                for (Neuron *neuron : _layers[i + 1]->getNeurons()) {
                    double tempError = neuron->getWeights()[j] * neuron->getDelta();
                    error += tempError;
                }
                errors.push_back(error);
            }
        } else {
            for (size_t j = 0; j < _layers[i]->getNeurons().size(); j++) {
                errors.push_back(_layers[i]->getNeurons()[j]->getOutput() - answer[j]);
            }
        }
        for (size_t j = 0; j < _layers[i]->getNeurons().size(); j++) {
            Neuron *neuron = _layers[i]->getNeurons()[j];
            double delta = errors[j] * functionActivationDerivate(neuron->getOutput());
            neuron->setDelta(delta);
        }
    }
    answer.clear();
}

void GraphNetwork::updateWeight() {
    std::vector<double> inputValues = _dataStorage.getData(false);
    for (int i = 0; i < _hiddenLayers + 1; i++) {
        if (i != 0) {
            for (Neuron *neuron : _layers[i - 1]->getNeurons()) {
                double neuronTemp = neuron->getOutput();
                inputValues.push_back(neuronTemp);
            }
        }
        for (Neuron *neuron : _layers[i]->getNeurons()) {
            for (size_t j = 0; j < inputValues.size(); j++) {
                neuron->getWeights()[j] -= ALPHA * neuron->getDelta() * inputValues[j];
            }
            double bios = neuron->getBios() - ALPHA * neuron->getDelta();
            neuron->setBios(bios);
        }
        inputValues.clear();
    }
}

const std::vector<double> &GraphNetwork::train(int epochs) {
    static std::vector<double> valueError;
    _dataStorage.readFile(TRAIN);
    for (int i = 0; i < epochs; i++) {
        double accuracy = 0;
        for (int j = 0; j < _dataStorage.getSize(); j++) {
            std::vector<double> inputValues = _dataStorage.getData(true);
            forwardPropagation(inputValues);
            if (guessedOrNot(_outputValues, _dataStorage.getAnswer())) {
                accuracy++;
            }
            backPropagation();
            updateWeight();
        }
        accuracy = (accuracy / _dataStorage.getSize()) * 100.0;
        valueError.push_back(100.0 - accuracy);
    }
    return valueError;
}

const std::vector<double> &GraphNetwork::crossValidation(int k) {
    _dataStorage.readFile(TRAIN);
    static std::vector<double> valueAccuracy;
    int endTest = _dataStorage.getSize();
    int sizeSet = endTest / k;
    int startTest = endTest - sizeSet;
    for (int i = 0; i < k; i++) {
        GraphNetwork networkTemp(_hiddenLayers);
        networkTemp._dataStorage.readFile(TRAIN);
        double accuracy = 0;
        for (int j = 0; j < networkTemp._dataStorage.getSize(); j++) {
            std::vector<double> inputValues = networkTemp._dataStorage.getData(true);
            if (j < startTest || j > endTest) {
                networkTemp.forwardPropagation(inputValues);
                networkTemp.backPropagation();
                networkTemp.updateWeight();
            }
        }
        for (int l = 0; l < _dataStorage.getSize(); l++) {
            std::vector<double> inputValues = networkTemp._dataStorage.getData(true);
            if (l >= startTest && l <= endTest) {
                networkTemp.forwardPropagation(inputValues);
                if (guessedOrNot(networkTemp._outputValues, networkTemp._dataStorage.getAnswer())) {
                    accuracy++;
                }
            }
        }
        startTest -= sizeSet;
        endTest -= sizeSet;
        valueAccuracy.push_back(100.0 - (accuracy / (double)sizeSet) * 100);
    }
    return valueAccuracy;
}

char GraphNetwork::predict(const std::vector<double> &inputValues) {
    forwardPropagation(inputValues);
    int answer =
        std::distance(_outputValues.begin(), std::max_element(_outputValues.begin(), _outputValues.end()));
    return answer + 'A';
}

Metrics GraphNetwork::predictTest(double partTestData) {
    auto start = std::chrono::high_resolution_clock::now();
    _dataStorage.readFile(TEST);
    Metrics metrics;
    int sizeData = _dataStorage.getSize() * partTestData;
    for (int i = 0; i < sizeData; i++) {
        std::vector<double> inputValues = _dataStorage.getData(true);
        forwardPropagation(inputValues);
        checkAnswer(metrics, _outputValues, _dataStorage.getAnswer());
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    metrics._time = duration.count();
    metrics._accuracy = metrics._accuracy / sizeData;
    return metrics;
}

void GraphNetwork::saveWeights(std::string filename) {
    std::ofstream output(filename);
    for (auto *layer : _layers) {
        for (auto *neuron : layer->getNeurons()) {
            output << neuron->getBios() << ' ';
            for (auto &weight : neuron->getWeights()) {
                output << weight << ' ';
            }
            output << std::endl;
        }
    }
}

void GraphNetwork::getWeights(std::string filename) {
    std::ifstream myfile(filename);
    if (!myfile) {
        throw std::invalid_argument("NO SUCH FILE!");
    }
    for (auto *layer : _layers) {
        for (auto *neuron : layer->getNeurons()) {
            std::string line;
            getline(myfile, line);
            size_t sub_pos = 0;
            neuron->setBios(std::stod(line, &sub_pos));
            size_t pos = sub_pos + 1;
            for (auto &weight : neuron->getWeights()) {
                weight = std::stod(line.substr(pos), &sub_pos);
                pos += sub_pos + 1;
            }
        }
    }
}

/* MATRIX NETWORK */

MatrixNetwork::MatrixNetwork(int hiddenLayers) : NetworkInterface(), _hiddenLayers(hiddenLayers) {
    initilizeNetwork();
}

void MatrixNetwork::initilizeNetwork() {
    S21Matrix weightOne(LAYER_INPUT, LAYER_HIDEN);
    _matrixWeight.push_back(weightOne);
    for (int i = 1; i < _hiddenLayers; i++) {
        S21Matrix weightHiden(LAYER_HIDEN, LAYER_HIDEN);
        _matrixWeight.push_back(weightHiden);
    }
    for (int j = 0; j < _hiddenLayers; j++) {
        S21Matrix biosTemp(1, LAYER_HIDEN);
        _matrixBios.push_back(biosTemp);
    }
    S21Matrix weightOutput(LAYER_HIDEN, LAYER_OUTPUT);
    _matrixWeight.push_back(weightOutput);
    S21Matrix biosOutput(1, LAYER_OUTPUT);
    _matrixBios.push_back(biosOutput);
    fillVectorMatrixRandomValue(_matrixWeight);
    fillVectorMatrixRandomValue(_matrixBios);
}

void MatrixNetwork::fillVectorMatrixRandomValue(std::vector<S21Matrix> &matrix) {
    for (auto &index : matrix) {
        fillMatrixRandomValue(index);
    }
}

void MatrixNetwork::fillMatrixRandomValue(S21Matrix &matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            matrix(i, j) = MIN + ((double)rand() / RAND_MAX) * (MAX - MIN);
        }
    }
}

void MatrixNetwork::transferMatrixByActivationFunction(S21Matrix &matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            matrix(i, j) = functionActivation(matrix(i, j));
        }
    }
}

void MatrixNetwork::transferMatrixByDerivateFunction(S21Matrix &matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            matrix(i, j) = functionActivationDerivate(matrix(i, j));
        }
    }
}

std::vector<double> MatrixNetwork::transformMatrixToVector(S21Matrix &matrix) {
    std::vector<double> result;
    for (int i = 0; i < matrix.getCols(); i++) {
        result.push_back(matrix(0, i));
    }
    return result;
}

void MatrixNetwork::forwardPropagation(const std::vector<double> &inputValues) {
    S21Matrix inputValuesMatrix(1, LAYER_INPUT);
    inputValuesMatrix.transform_vector_to_matrix(inputValues);
    for (int i = 0; i < _hiddenLayers + 1; i++) {
        inputValuesMatrix *= _matrixWeight[i];
        inputValuesMatrix += _matrixBios[i];
        transferMatrixByActivationFunction(inputValuesMatrix);
        _matrixOutput.push_back(inputValuesMatrix);
    }
}

S21Matrix MatrixNetwork::oneHotEncoder() {
    double expected = _dataStorage.getAnswer() - 1;
    S21Matrix answer(1, LAYER_OUTPUT);
    answer.input_value_in_zero_vector(expected);
    return answer;
}

void MatrixNetwork::backPropagation() {
    S21Matrix answer = oneHotEncoder();
    S21Matrix tempGradient = _matrixOutput[_hiddenLayers] - answer;
    S21Matrix outputMatrix = _matrixOutput[_hiddenLayers];
    transferMatrixByDerivateFunction(outputMatrix);
    tempGradient = tempGradient.mul_vector(outputMatrix);
    _gradientErrors.push_back(tempGradient);
    for (int i = _hiddenLayers, j = 0; i > 0; i--, j++) {
        tempGradient = _gradientErrors[j] * _matrixWeight[i].transpose();
        outputMatrix = _matrixOutput[i - 1];
        transferMatrixByDerivateFunction(outputMatrix);
        tempGradient = tempGradient.mul_vector(outputMatrix);
        _gradientErrors.push_back(tempGradient);
    }
}

void MatrixNetwork::updateWeight() {
    std::vector<double> inputValues = _dataStorage.getData(false);
    S21Matrix inputValuesMatrix(1, LAYER_INPUT);
    inputValuesMatrix.transform_vector_to_matrix(inputValues);
    for (int i = 0, j = _hiddenLayers; i < _hiddenLayers + 1; i++, j--) {
        if (i != 0) {
            inputValuesMatrix = _matrixOutput[i - 1];
        }
        S21Matrix tempWeight = inputValuesMatrix.transpose() * _gradientErrors[j];
        tempWeight *= ALPHA;
        _matrixWeight[i] -= tempWeight;
        S21Matrix tempBios = _gradientErrors[j] * ALPHA;
        _matrixBios[i] -= tempBios;
    }
    _matrixOutput.clear();
    _gradientErrors.clear();
}

const std::vector<double> &MatrixNetwork::crossValidation(int k) {
    _dataStorage.readFile(TRAIN);
    static std::vector<double> valueAccuracy;
    int endTest = _dataStorage.getSize();
    int sizeSet = endTest / k;
    int startTest = endTest - sizeSet;
    for (int i = 0; i < k; i++) {
        MatrixNetwork networkTemp(_hiddenLayers);
        networkTemp._dataStorage.readFile(TRAIN);
        double accuracy = 0;
        for (int j = 0; j < _dataStorage.getSize(); j++) {
            std::vector<double> inputValues = networkTemp._dataStorage.getData(true);
            if (j < startTest || j >= endTest) {
                networkTemp.forwardPropagation(inputValues);
                networkTemp.backPropagation();
                networkTemp.updateWeight();
            }
        }
        for (int l = 0; l < _dataStorage.getSize(); l++) {
            if (l >= startTest && l <= endTest) {
                std::vector<double> inputValues = networkTemp._dataStorage.getData(true);
                networkTemp.forwardPropagation(inputValues);
                auto outputValues = transformMatrixToVector(networkTemp._matrixOutput[_hiddenLayers]);
                if (guessedOrNot(outputValues, networkTemp._dataStorage.getAnswer())) {
                    accuracy++;
                }
                networkTemp._matrixOutput.clear();
            }
        }
        startTest -= sizeSet;
        endTest -= sizeSet;
        valueAccuracy.push_back(100 - (accuracy / (double)sizeSet) * 100);
    }
    return valueAccuracy;
}

const std::vector<double> &MatrixNetwork::train(int epochs) {
    static std::vector<double> valueError;
    _dataStorage.readFile(TRAIN);
    for (int i = 0; i < epochs; i++) {
        double accuracy = 0;
        for (int j = 0; j < _dataStorage.getSize(); j++) {
            std::vector<double> inputValues = _dataStorage.getData(true);
            forwardPropagation(inputValues);
            auto outputValues = transformMatrixToVector(_matrixOutput[_hiddenLayers]);
            if (guessedOrNot(outputValues, _dataStorage.getAnswer())) {
                accuracy++;
            }
            backPropagation();
            updateWeight();
        }
        accuracy = (accuracy / _dataStorage.getSize()) * 100.0;
        valueError.push_back(100.0 - accuracy);
    }
    return valueError;
}

char MatrixNetwork::predict(const std::vector<double> &inputValues) {
    forwardPropagation(inputValues);
    auto outputValues = transformMatrixToVector(_matrixOutput[_hiddenLayers]);
    _matrixOutput.clear();
    int answer =
        std::distance(outputValues.begin(), std::max_element(outputValues.begin(), outputValues.end()));
    return answer + 'A';
}

Metrics MatrixNetwork::predictTest(double partTestData) {
    auto start = std::chrono::high_resolution_clock::now();
    _dataStorage.readFile(TEST);
    Metrics metrics;
    int sizeData = _dataStorage.getSize() * partTestData;
    for (int i = 0; i < sizeData; i++) {
        std::vector<double> inputValues = _dataStorage.getData(true);
        forwardPropagation(inputValues);
        auto outputValues = transformMatrixToVector(_matrixOutput[_hiddenLayers]);
        _matrixOutput.clear();
        checkAnswer(metrics, outputValues, _dataStorage.getAnswer());
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    metrics._time = duration.count();
    metrics._accuracy = metrics._accuracy / sizeData;
    return metrics;
}

void MatrixNetwork::saveWeights(std::string filename) {
    std::ofstream output(filename);
    for (size_t i = 0; i < _matrixWeight.size(); i++) {
        for (int j = 0; j < _matrixWeight[i].getCols(); j++) {
            output << _matrixBios[i](0, j) << ' ';
            for (int k = 0; k < _matrixWeight[i].getRows(); k++) {
                output << _matrixWeight[i](k, j) << ' ';
            }
            output << std::endl;
        }
    }
}

void MatrixNetwork::getWeights(std::string filename) {
    std::ifstream myfile(filename);
    if (!myfile) {
        throw std::invalid_argument("NO SUCH FILE!");
    }
    for (size_t i = 0; i < _matrixWeight.size(); i++) {
        for (int j = 0; j < _matrixWeight[i].getCols(); j++) {
            std::string line;
            getline(myfile, line);
            size_t sub_pos = 0;
            _matrixBios[i](0, j) = std::stod(line, &sub_pos);
            size_t pos = sub_pos + 1;
            for (int k = 0; k < _matrixWeight[i].getRows(); k++) {
                _matrixWeight[i](k, j) = std::stod(line.substr(pos), &sub_pos);
                pos += sub_pos + 1;
            }
        }
    }
}

/* NetworkInterface */

void NetworkInterface::getMetrics(Metrics &metrics) {
    metrics._precision = (double)metrics._tp / (double)(metrics._tp + metrics._fp);
    metrics._recall = (double)metrics._tp / (double)(metrics._tp + metrics._fn);
    metrics._fScore = 2 * (metrics._precision * metrics._recall) / (metrics._precision + metrics._recall);
}

void NetworkInterface::checkAnswer(Metrics &metrics, std::vector<double> outputValues, int answer) {
    int expected =
        std::distance(outputValues.begin(), std::max_element(outputValues.begin(), outputValues.end()));
    if (expected == answer - 1) metrics._accuracy++;
    for (int i = 0; i < 26; i++) {
        if (i == answer - 1) {
            if (outputValues[i] > 0.5)
                metrics._tp++;
            else
                metrics._fp++;
        } else {
            if (outputValues[i] > 0.5)
                metrics._fn++;
            else
                metrics._tn++;
        }
    }
}

bool NetworkInterface::guessedOrNot(std::vector<double> outputValues, int answer) {
    int expected =
        std::distance(outputValues.begin(), std::max_element(outputValues.begin(), outputValues.end()));
    if (expected == answer - 1) {
        return true;
    }
    return false;
}

}  // namespace s21

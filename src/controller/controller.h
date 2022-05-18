#pragma once
#include "../model/model.h"

namespace s21 {

class Controller {
 private:
    Model *_model;

 public:
    explicit Controller(Model *model) : _model(model) {}

    void initilizeNetwork(TypeNetwork type, int hidenLayers) { _model->initilizeNetwork(type, hidenLayers); }
    const std::vector<double> &train(int epochs) { return _model->train(epochs); }
    const std::vector<double> &crossValidation(int k) { return _model->crossValidation(k); }
    char predict(const std::vector<double> &inputValues) { return _model->predict(inputValues); }
    Metrics predictTest(double partTestData) { return _model->predictTest(partTestData); }
    void saveWeights(std::string filename) { _model->saveWeights(filename); }
    void getWeights(std::string filename) { _model->getWeights(filename); }
    void getMetrics(Metrics &metrics) { _model->getMetrics(metrics); }
};

}  // namespace s21

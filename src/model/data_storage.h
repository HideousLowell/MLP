#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace s21 {

class DataStorage {
 private:
    std::vector<std::vector<double>> _data;
    std::vector<double> _answers;
    int _position = -1;

 public:
    void readFile(std::string);
    int getSize() { return _data.size() - 1; }
    double getAnswer() { return _answers.at(_position); }
    std::vector<double> getData(bool is_new);
    void clearData();
    void print();
};

}  // namespace s21

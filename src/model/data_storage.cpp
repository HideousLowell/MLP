#include "data_storage.h"

namespace s21 {

std::vector<double> &sendData(bool is_new, int &pos, std::vector<std::vector<double>> &data) {
    pos += (int)is_new;
    if (pos >= (int)data.size() - 1) {
        pos = 0;
    }
    return data.at(pos);
}

std::vector<double> DataStorage::getData(bool is_new) { return sendData(is_new, _position, _data); }

void DataStorage::clearData() {
    _data.clear();
    _answers.clear();
    _position = -1;
}

void parse(std::string &filename, std::vector<std::vector<double>> &data, std::vector<double> &answers) {
    std::ifstream myfile(filename);
    for (int i = 0; myfile; i++) {
        data.push_back(std::vector<double>());
        std::string line;
        getline(myfile, line);
        if (line.length() == 0) {
            continue;
        }
        size_t sub_pos = 0;
        answers.push_back(std::stod(line, &sub_pos));
        size_t pos = sub_pos + 1;
        while (pos <= line.size()) {
            data[i].push_back(std::stod(line.substr(pos), &sub_pos) / 255.0);
            pos += sub_pos + 1;
        }
    }
}

void DataStorage::readFile(std::string filename) {
    clearData();
    parse(filename, _data, _answers);
}

}  // namespace s21

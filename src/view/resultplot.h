#pragma once

#include <QtWidgets/QDialog>

#include "../ui/ui_resultplot.h"

namespace s21 {

namespace Ui {
class ResultPlot;
}

class ResultPlot : public QDialog {
    Q_OBJECT

 public:
    explicit ResultPlot(QWidget *parent = nullptr);
    void draw(const std::vector<double> &std_y);
    void setLabels(const QVector<double> &errors, int i = 0);
    ~ResultPlot();

 private:
    Ui::ResultPlot *ui;
};

}  // namespace s21

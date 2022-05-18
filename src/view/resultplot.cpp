#include "resultplot.h"

#include "../ui/ui_resultplot.h"

namespace s21 {

ResultPlot::ResultPlot(QWidget *parent) : QDialog(parent), ui(new Ui::ResultPlot) {
    ui->setupUi(this);
    setFixedSize(501, 357);
}

void ResultPlot::setLabels(const QVector<double> &errors, int i) {
    ui->label_2->setText(i < errors.size() ? QString::number(errors[i++], 'f', 1) : "");
    ui->label_3->setText(i < errors.size() ? QString::number(errors[i++], 'f', 1) : "");
    ui->label_4->setText(i < errors.size() ? QString::number(errors[i++], 'f', 1) : "");
    ui->label_5->setText(i < errors.size() ? QString::number(errors[i++], 'f', 1) : "");
    ui->label_6->setText(i < errors.size() ? QString::number(errors[i++], 'f', 1) : "");
}

void ResultPlot::draw(const std::vector<double> &std_y) {
    double nums[]{1, 2, 3, 4, 5};
    ui->widget->xAxis->setRange(0.5, 5.5);
    ui->widget->yAxis->setRange(0, 100);
    ui->widget->xAxis->setLabel("Epochs");
    ui->widget->yAxis->setLabel("Errors %");
    QCPBars *barBottom = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
    QVector<double> qt_y = QVector<double>(std_y.begin(), std_y.end());
    QVector<double> qt_x = QVector<double>(nums, nums + qt_y.size());
    barBottom->addData(qt_x, qt_y);
    ui->widget->addGraph();
    ui->widget->replot();
    setLabels(qt_y);
}

ResultPlot::~ResultPlot() { delete ui; }

}  // namespace s21

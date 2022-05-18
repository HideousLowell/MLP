#include "mainwindow.h"

#include "../ui/ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(Controller *controller, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      _controller(controller),
      _settings(_controller, this),
      _metrics(this) {
    ui->setupUi(this);
    ui->render_area->setMainWindow(this);
}

void MainWindow::on_btn_settings_clicked() { _settings.show(); }

void MainWindow::on_btn_start_tests_clicked() {
    double partTestData = ui->spinBox_selection->value();
    Metrics metric = _controller->predictTest(partTestData);
    _controller->getMetrics(metric);
    _metrics.setMetrics(metric);
    _metrics.show();
}

void MainWindow::on_btn_bmp_clicked() {
    QString filename = QFileDialog::getOpenFileName(this, ("Open the file"), USER_APP "bmp/", "*.bmp");
    QImage tmp_img(filename, "BMP");
    ui->render_area->getImage() = tmp_img.scaled(QSize(387, 409)).convertToFormat(QImage::Format_RGB16);
    ui->render_area->update();
    predict();
}

void MainWindow::on_btn_start_learning_clicked() {
    if (ui->checkBox_crossv->isChecked())
        _resultplot.draw(_controller->crossValidation(ui->spinBox_groupsk->text().toInt()));
    else
        _resultplot.draw(_controller->train(ui->spinBox_epochs->text().toInt()));
    _resultplot.setModal(true);
    _resultplot.exec();
}

void MainWindow::on_btn_save_clicked() {
    QString filename = QFileDialog::getSaveFileName(this, ("Save to file"), USER_APP "weights/", "*.conf");
    _controller->saveWeights(filename.toStdString());
}

void MainWindow::on_btn_load_clicked() {
    QString filename = QFileDialog::getOpenFileName(this, ("Open the file"), USER_APP "weights/", "*.conf");
    try {
        _controller->getWeights(filename.toStdString());
    } catch (std::invalid_argument &ex) {
    }
}

void MainWindow::predict() {
    std::vector<double> vec;
    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 28; j++) {
            QRgb color = ui->render_area->getImage().pixel(i * 387 / 28 + 7, j * 409 / 28 + 7);
            vec.push_back(255 - (color & 0x000000ff));
        }
    }
    std::string str;
    str += _controller->predict(vec);
    ui->label_result->setText(QString::fromStdString(str));
}

void MainWindow::on_checkBox_crossv_stateChanged(int checked) {
    ui->spinBox_groupsk->setEnabled(checked);
    ui->label_groupsk->setEnabled(checked);
}

MainWindow::~MainWindow() { delete ui; }

}  // namespace s21

#pragma once

#include <QtGui/QImage>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QFileDialog>
#include <array>
#include <fstream>
#include <string>
#include <vector>

#include "../controller/controller.h"
#include "settings.h"
#include "metricsdialog.h"
#include "resultplot.h"

namespace s21 {

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

 public:
    explicit MainWindow(Controller *controller, QWidget *parent = nullptr);
    void predict();
    ~MainWindow();

 private slots:
    void on_btn_start_learning_clicked();
    void on_btn_settings_clicked();
    void on_btn_start_tests_clicked();
    void on_btn_bmp_clicked();
    void on_btn_save_clicked();
    void on_btn_load_clicked();
    void on_checkBox_crossv_stateChanged(int);

 private:
    Ui::MainWindow *ui;
    Controller *_controller;
    Settings _settings;
    MetricsDialog _metrics;
    ResultPlot _resultplot;
};

}  // namespace s21

#pragma once

#include <QtWidgets/QDialog>
#include "../controller/controller.h"

namespace s21 {

namespace Ui {
class MetricsDialog;
}

class MetricsDialog : public QDialog {
    Q_OBJECT

 public:
    explicit MetricsDialog(QWidget *parent = nullptr);
    ~MetricsDialog();

    void setMetrics(Metrics _metrics);

 private:
    Ui::MetricsDialog *ui;

 private slots:
    void on_btn_ok_clicked();
};

}  // namespace s21

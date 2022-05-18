#include "../ui/ui_metricsdialog.h"
#include "metricsdialog.h"

namespace s21 {

MetricsDialog::MetricsDialog(QWidget *parent) : QDialog(parent), ui(new Ui::MetricsDialog) {
    ui->setupUi(this);
}

void MetricsDialog::setMetrics(Metrics _metrics) {
    ui->aver_accur_num->setText(QString::number(_metrics._accuracy));
    ui->precision_num->setText(QString::number(_metrics._precision));
    ui->recall_num->setText(QString::number(_metrics._recall));
    ui->f_measure_num->setText(QString::number(_metrics._fScore));
    ui->time_num->setText(QString::number(_metrics._time));
}

void MetricsDialog::on_btn_ok_clicked() {
    close();
}

MetricsDialog::~MetricsDialog() { delete ui; }

}  // namespace s21

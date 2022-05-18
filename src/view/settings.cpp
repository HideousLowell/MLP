#include "settings.h"

#include "../ui/ui_settings.h"

namespace s21 {

Settings::Settings(Controller *controller, QWidget *parent)
    : QDialog(parent),
      ui(new Ui::Settings),
      _controller(controller),
      _type(TypeNetwork::MATRIX),
      _layers(4) {
    ui->setupUi(this);
}

Settings::~Settings() { delete ui; }

void Settings::resetUIState() {
    QRadioButton *rb = (_type == TypeNetwork::MATRIX) ? ui->rb_matrix : ui->rb_graph;
    rb->setChecked(true);
    ui->spinBox_layers->setValue(_layers);
}

void Settings::closeEvent(QCloseEvent *) {
    resetUIState();
    hide();
}

void Settings::on_btn_cancel_clicked() {
    resetUIState();
    hide();
}

void Settings::on_btn_ok_clicked() {
    TypeNetwork type_mem = _type;
    int layers_mem = _layers;
    if (ui->rb_graph->isChecked()) {
        _type = TypeNetwork::GRAPH;
    }
    _layers = ui->spinBox_layers->value();
    if (_type != type_mem || _layers != layers_mem) {
        _controller->initilizeNetwork(_type, _layers);
    }
    hide();
}

}  // namespace s21

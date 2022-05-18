#pragma once

#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>

#include "../controller/controller.h"

namespace s21 {

QT_BEGIN_NAMESPACE
namespace Ui {
class Settings;
}
QT_END_NAMESPACE

class Settings : public QDialog {
    Q_OBJECT

 public:
    explicit Settings(Controller *controller, QWidget *parent = nullptr);
    ~Settings();

 private:
    void resetUIState();

 protected:
    void closeEvent(QCloseEvent *) override;

 private slots:
    void on_btn_cancel_clicked();
    void on_btn_ok_clicked();

 private:
    Ui::Settings *ui;
    Controller *_controller;

    TypeNetwork _type;
    int _layers;
};

}  // namespace s21

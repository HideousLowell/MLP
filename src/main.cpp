#include <QtWidgets/QApplication>

#include "view/mainwindow.h"
#include "controller/controller.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    srand(time(nullptr));
    s21::Model model;
    model.initilizeNetwork(s21::MATRIX, 4);

    s21::Controller controller(&model);
    s21::MainWindow w(&controller);
    w.show();
    return a.exec();
}

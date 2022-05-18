#pragma once

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "../view/renderarea.h"

QT_BEGIN_NAMESPACE
namespace s21 {

class Ui_MainWindow {
 public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *vl_main_left;
    RenderArea *render_area;
    QPushButton *btn_bmp;
    QLabel *label_result;
    QPushButton *btn_settings;
    QVBoxLayout *vl_main_right;
    QVBoxLayout *vl_learning;
    QLabel *label_learning_h;
    QGridLayout *grid_learning;
    QSpinBox *spinBox_epochs;
    QCheckBox *checkBox_crossv;
    QLabel *label_epochs;
    QLabel *label_crossv;
    QLabel *label_groupsk;
    QSpinBox *spinBox_groupsk;
    QPushButton *btn_start_learning;
    QFrame *line_1;
    QVBoxLayout *vl_tests;
    QLabel *label_tests_h;
    QGridLayout *grid_tests;
    QDoubleSpinBox *spinBox_selection;
    QLabel *label_selection;
    QPushButton *btn_start_tests;
    QFrame *line_2;
    QVBoxLayout *vl_saving;
    QLabel *label_saving_h;
    QPushButton *btn_save;
    QPushButton *btn_load;

    void setupUi(QMainWindow *MainWindow) {
        if (MainWindow->objectName().isEmpty()) MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 420);
        MainWindow->setMinimumSize(QSize(800, 420));
        MainWindow->setMaximumSize(QSize(800, 448));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: #202124;"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        vl_main_left = new QVBoxLayout();
        vl_main_left->setSpacing(5);
        vl_main_left->setObjectName(QString::fromUtf8("vl_main_left"));
        render_area = new RenderArea(centralwidget);
        render_area->setObjectName(QString::fromUtf8("render_area"));
        render_area->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(render_area->sizePolicy().hasHeightForWidth());
        render_area->setSizePolicy(sizePolicy);
        render_area->setMinimumSize(QSize(387, 409));
        render_area->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        btn_bmp = new QPushButton(render_area);
        btn_bmp->setObjectName(QString::fromUtf8("btn_bmp"));
        btn_bmp->setGeometry(QRect(10, 60, 40, 40));
        sizePolicy.setHeightForWidth(btn_bmp->sizePolicy().hasHeightForWidth());
        btn_bmp->setSizePolicy(sizePolicy);
        btn_bmp->setStyleSheet(
            QString::fromUtf8("QPushButton {\n"
                              "   width: 40px;\n"
                              "   height: 40px;\n"
                              "   border-radius: 20px;\n"
                              "   background-color: #94B4F2;\n"
                              "   border: none;\n"
                              "}\n"
                              "\n"
                              "QPushButton:hover {\n"
                              "   background-color: #88A5DF;\n"
                              "}\n"
                              "\n"
                              "QPushButton:pressed {\n"
                              "   background-color: #728ABB;\n"
                              "}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/bmp.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_bmp->setIcon(icon);
        btn_bmp->setIconSize(QSize(25, 25));
        label_result = new QLabel(render_area);
        label_result->setObjectName(QString::fromUtf8("label_result"));
        label_result->setGeometry(QRect(320, 340, 58, 61));
        QFont font;
        font.setPointSize(60);
        label_result->setFont(font);
        label_result->setStyleSheet(
            QString::fromUtf8("color: #3D4043;\n"
                              "background-color: none;"));
        label_result->setAlignment(Qt::AlignCenter);
        btn_settings = new QPushButton(render_area);
        btn_settings->setObjectName(QString::fromUtf8("btn_settings"));
        btn_settings->setGeometry(QRect(10, 10, 40, 40));
        sizePolicy.setHeightForWidth(btn_settings->sizePolicy().hasHeightForWidth());
        btn_settings->setSizePolicy(sizePolicy);
        btn_settings->setStyleSheet(
            QString::fromUtf8("QPushButton {\n"
                              "   width: 40px;\n"
                              "   height: 40px;\n"
                              "   border-radius: 20px;\n"
                              "   background-color: #94B4F2;\n"
                              "   border: none;\n"
                              "}\n"
                              "\n"
                              "QPushButton:hover {\n"
                              "   background-color: #88A5DF;\n"
                              "}\n"
                              "\n"
                              "QPushButton:pressed {\n"
                              "   background-color: #728ABB;\n"
                              "}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/shaft.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_settings->setIcon(icon1);
        btn_settings->setIconSize(QSize(25, 25));
        label_result->raise();
        btn_bmp->raise();
        btn_settings->raise();

        vl_main_left->addWidget(render_area);

        horizontalLayout->addLayout(vl_main_left);

        vl_main_right = new QVBoxLayout();
        vl_main_right->setSpacing(5);
        vl_main_right->setObjectName(QString::fromUtf8("vl_main_right"));
        vl_learning = new QVBoxLayout();
        vl_learning->setObjectName(QString::fromUtf8("vl_learning"));
        label_learning_h = new QLabel(centralwidget);
        label_learning_h->setObjectName(QString::fromUtf8("label_learning_h"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_learning_h->sizePolicy().hasHeightForWidth());
        label_learning_h->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        label_learning_h->setFont(font1);
        label_learning_h->setStyleSheet(
            QString::fromUtf8("margin-bottom: 5px;\n"
                              "color: #E8EAED;"));
        label_learning_h->setAlignment(Qt::AlignCenter);

        vl_learning->addWidget(label_learning_h);

        grid_learning = new QGridLayout();
        grid_learning->setObjectName(QString::fromUtf8("grid_learning"));
        spinBox_epochs = new QSpinBox(centralwidget);
        spinBox_epochs->setObjectName(QString::fromUtf8("spinBox_epochs"));
        spinBox_epochs->setStyleSheet(
            QString::fromUtf8("QSpinBox {\n"
                              "   height: 30px;\n"
                              "   background-color: #3D4043;\n"
                              "   color: #E8EAED;\n"
                              "}"));
        spinBox_epochs->setMinimum(1);
        spinBox_epochs->setMaximum(5);
        spinBox_epochs->setValue(2);

        grid_learning->addWidget(spinBox_epochs, 0, 1, 1, 1);

        checkBox_crossv = new QCheckBox(centralwidget);
        checkBox_crossv->setObjectName(QString::fromUtf8("checkBox_crossv"));
        checkBox_crossv->setChecked(false);

        grid_learning->addWidget(checkBox_crossv, 1, 1, 1, 1);

        label_epochs = new QLabel(centralwidget);
        label_epochs->setObjectName(QString::fromUtf8("label_epochs"));
        label_epochs->setStyleSheet(QString::fromUtf8("color: #E8EAED;"));

        grid_learning->addWidget(label_epochs, 0, 0, 1, 1);

        label_crossv = new QLabel(centralwidget);
        label_crossv->setObjectName(QString::fromUtf8("label_crossv"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_crossv->sizePolicy().hasHeightForWidth());
        label_crossv->setSizePolicy(sizePolicy2);
        label_crossv->setMinimumSize(QSize(0, 30));
        label_crossv->setStyleSheet(QString::fromUtf8("color: #E8EAED;"));

        grid_learning->addWidget(label_crossv, 1, 0, 1, 1);

        label_groupsk = new QLabel(centralwidget);
        label_groupsk->setObjectName(QString::fromUtf8("label_groupsk"));
        label_groupsk->setEnabled(false);
        label_groupsk->setStyleSheet(
            QString::fromUtf8("QLabel {\n"
                              "   color: #E8EAED;\n"
                              "}\n"
                              "\n"
                              "QLabel:disabled {\n"
                              "   color: grey;\n"
                              "}"));

        grid_learning->addWidget(label_groupsk, 2, 0, 1, 1);

        spinBox_groupsk = new QSpinBox(centralwidget);
        spinBox_groupsk->setObjectName(QString::fromUtf8("spinBox_groupsk"));
        spinBox_groupsk->setEnabled(false);
        spinBox_groupsk->setStyleSheet(
            QString::fromUtf8("QSpinBox {\n"
                              "   height: 30px;\n"
                              "   background-color: #3D4043;\n"
                              "   color: #E8EAED;\n"
                              "}\n"
                              "\n"
                              "QSpinBox:disabled {\n"
                              "   color: grey;\n"
                              "}"));
        spinBox_groupsk->setMinimum(2);
        spinBox_groupsk->setMaximum(5);
        spinBox_groupsk->setValue(2);

        grid_learning->addWidget(spinBox_groupsk, 2, 1, 1, 1);

        vl_learning->addLayout(grid_learning);

        btn_start_learning = new QPushButton(centralwidget);
        btn_start_learning->setObjectName(QString::fromUtf8("btn_start_learning"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btn_start_learning->sizePolicy().hasHeightForWidth());
        btn_start_learning->setSizePolicy(sizePolicy3);
        btn_start_learning->setStyleSheet(
            QString::fromUtf8("QPushButton {\n"
                              "   background-color: #94B4F2;\n"
                              "   color: #202124;\n"
                              "   border: none;\n"
                              "   border-radius: 5px;\n"
                              "   height: 30px;\n"
                              "   margin: 5px 125px;\n"
                              "}\n"
                              "\n"
                              "QPushButton:hover {\n"
                              "   background-color: #88A5DF;\n"
                              "}\n"
                              "\n"
                              "QPushButton:pressed {\n"
                              "   background-color: #728ABB;\n"
                              "}"));

        vl_learning->addWidget(btn_start_learning);

        vl_main_right->addLayout(vl_learning);

        line_1 = new QFrame(centralwidget);
        line_1->setObjectName(QString::fromUtf8("line_1"));
        line_1->setFrameShape(QFrame::HLine);
        line_1->setFrameShadow(QFrame::Sunken);

        vl_main_right->addWidget(line_1);

        vl_tests = new QVBoxLayout();
        vl_tests->setObjectName(QString::fromUtf8("vl_tests"));
        label_tests_h = new QLabel(centralwidget);
        label_tests_h->setObjectName(QString::fromUtf8("label_tests_h"));
        sizePolicy1.setHeightForWidth(label_tests_h->sizePolicy().hasHeightForWidth());
        label_tests_h->setSizePolicy(sizePolicy1);
        label_tests_h->setFont(font1);
        label_tests_h->setStyleSheet(
            QString::fromUtf8("margin-bottom: 5px;\n"
                              "color: #E8EAED;"));
        label_tests_h->setAlignment(Qt::AlignCenter);

        vl_tests->addWidget(label_tests_h);

        grid_tests = new QGridLayout();
        grid_tests->setObjectName(QString::fromUtf8("grid_tests"));
        grid_tests->setContentsMargins(-1, -1, 8, -1);
        spinBox_selection = new QDoubleSpinBox(centralwidget);
        spinBox_selection->setObjectName(QString::fromUtf8("spinBox_selection"));
        spinBox_selection->setStyleSheet(
            QString::fromUtf8("QDoubleSpinBox {\n"
                              "   height: 30px;\n"
                              "   background-color: #3D4043;\n"
                              "   color: #E8EAED;\n"
                              "}"));
        spinBox_selection->setMaximum(1.000000000000000);
        spinBox_selection->setSingleStep(0.050000000000000);
        spinBox_selection->setValue(1.000000000000000);

        grid_tests->addWidget(spinBox_selection, 0, 1, 1, 1);

        label_selection = new QLabel(centralwidget);
        label_selection->setObjectName(QString::fromUtf8("label_selection"));
        label_selection->setStyleSheet(QString::fromUtf8("color: #E8EAED;"));

        grid_tests->addWidget(label_selection, 0, 0, 1, 1);

        vl_tests->addLayout(grid_tests);

        btn_start_tests = new QPushButton(centralwidget);
        btn_start_tests->setObjectName(QString::fromUtf8("btn_start_tests"));
        sizePolicy3.setHeightForWidth(btn_start_tests->sizePolicy().hasHeightForWidth());
        btn_start_tests->setSizePolicy(sizePolicy3);
        btn_start_tests->setStyleSheet(
            QString::fromUtf8("QPushButton {\n"
                              "   background-color: #94B4F2;\n"
                              "   color: #202124;\n"
                              "   border: none;\n"
                              "   border-radius: 5px;\n"
                              "   height: 30px;\n"
                              "   margin: 5px 125px;\n"
                              "}\n"
                              "\n"
                              "QPushButton:hover {\n"
                              "   background-color: #88A5DF;\n"
                              "}\n"
                              "\n"
                              "QPushButton:pressed {\n"
                              "   background-color: #728ABB;\n"
                              "}"));

        vl_tests->addWidget(btn_start_tests);

        vl_main_right->addLayout(vl_tests);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        vl_main_right->addWidget(line_2);

        vl_saving = new QVBoxLayout();
        vl_saving->setObjectName(QString::fromUtf8("vl_saving"));
        label_saving_h = new QLabel(centralwidget);
        label_saving_h->setObjectName(QString::fromUtf8("label_saving_h"));
        sizePolicy1.setHeightForWidth(label_saving_h->sizePolicy().hasHeightForWidth());
        label_saving_h->setSizePolicy(sizePolicy1);
        label_saving_h->setFont(font1);
        label_saving_h->setStyleSheet(
            QString::fromUtf8("margin-bottom: 5px;\n"
                              "color: #E8EAED;"));
        label_saving_h->setAlignment(Qt::AlignCenter);

        vl_saving->addWidget(label_saving_h);

        btn_save = new QPushButton(centralwidget);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));
        sizePolicy3.setHeightForWidth(btn_save->sizePolicy().hasHeightForWidth());
        btn_save->setSizePolicy(sizePolicy3);
        btn_save->setStyleSheet(
            QString::fromUtf8("QPushButton {\n"
                              "   background-color: #686c6e;\n"
                              "   color: #E8EAED;\n"
                              "   border: none;\n"
                              "   border-radius: 5px;\n"
                              "   height: 30px;\n"
                              "   margin: 5px 125px;\n"
                              "}\n"
                              "\n"
                              "QPushButton:hover {\n"
                              "   background-color: #606367;\n"
                              "}\n"
                              "\n"
                              "QPushButton:pressed {\n"
                              "   background-color: #4f5255;\n"
                              "}"));

        vl_saving->addWidget(btn_save);

        btn_load = new QPushButton(centralwidget);
        btn_load->setObjectName(QString::fromUtf8("btn_load"));
        sizePolicy3.setHeightForWidth(btn_load->sizePolicy().hasHeightForWidth());
        btn_load->setSizePolicy(sizePolicy3);
        btn_load->setStyleSheet(
            QString::fromUtf8("QPushButton {\n"
                              "   background-color: #686c6e;\n"
                              "   color: #E8EAED;\n"
                              "   border: none;\n"
                              "   border-radius: 5px;\n"
                              "   height: 30px;\n"
                              "   margin: 5px 125px;\n"
                              "   margin-top: 10px;\n"
                              "}\n"
                              "\n"
                              "QPushButton:hover {\n"
                              "   background-color: #606367;\n"
                              "}\n"
                              "\n"
                              "QPushButton:pressed {\n"
                              "   background-color: #4f5255;\n"
                              "}"));

        vl_saving->addWidget(btn_load);

        vl_main_right->addLayout(vl_saving);

        horizontalLayout->addLayout(vl_main_right);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    }  // setupUi

    void retranslateUi(QMainWindow *MainWindow) {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MLP", nullptr));
        label_result->setText(QString());
        label_learning_h->setText(QCoreApplication::translate("MainWindow", "Learning", nullptr));
        checkBox_crossv->setText(QString());
        label_epochs->setText(QCoreApplication::translate("MainWindow", "Number of epochs:", nullptr));
        label_crossv->setText(QCoreApplication::translate("MainWindow", "Cross-validation:", nullptr));
        label_groupsk->setText(QCoreApplication::translate("MainWindow", "Number of groups k:", nullptr));
        btn_start_learning->setText(QCoreApplication::translate("MainWindow", "Start learning", nullptr));
        label_tests_h->setText(QCoreApplication::translate("MainWindow", "Tests", nullptr));
        label_selection->setText(QCoreApplication::translate("MainWindow", "Selection part:", nullptr));
        btn_start_tests->setText(QCoreApplication::translate("MainWindow", "Start tests", nullptr));
        label_saving_h->setText(QCoreApplication::translate("MainWindow", "Saving & uploading", nullptr));
        btn_save->setText(QCoreApplication::translate("MainWindow", "Save weights", nullptr));
        btn_load->setText(QCoreApplication::translate("MainWindow", "Load weights", nullptr));
    }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

}  // namespace s21
QT_END_NAMESPACE

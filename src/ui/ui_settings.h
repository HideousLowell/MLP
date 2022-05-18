#pragma once

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace s21 {

class Ui_Settings {
 public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *grid;
    QLabel *label_realization;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *rb_matrix;
    QRadioButton *rb_graph;
    QLabel *label_layers;
    QSpinBox *spinBox_layers;
    QHBoxLayout *hl_buttons;
    QPushButton *btn_cancel;
    QPushButton *btn_ok;

    void setupUi(QDialog *Settings) {
        if (Settings->objectName().isEmpty()) Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(300, 160);
        Settings->setMinimumSize(QSize(300, 160));
        Settings->setMaximumSize(QSize(300, 160));
        Settings->setStyleSheet(QString::fromUtf8("background-color: #202124;"));
        Settings->setModal(true);
        verticalLayout_2 = new QVBoxLayout(Settings);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        grid = new QGridLayout();
        grid->setObjectName(QString::fromUtf8("grid"));
        label_realization = new QLabel(Settings);
        label_realization->setObjectName(QString::fromUtf8("label_realization"));
        label_realization->setStyleSheet(
            QString::fromUtf8("margin-top: 14px;\n"
                              ""));
        label_realization->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignTop);

        grid->addWidget(label_realization, 0, 0, 1, 1);

        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(
            QString::fromUtf8("background-color: none;\n"
                              "border: none;"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rb_matrix = new QRadioButton(groupBox);
        rb_matrix->setObjectName(QString::fromUtf8("rb_matrix"));
        rb_matrix->setChecked(true);

        verticalLayout->addWidget(rb_matrix);

        rb_graph = new QRadioButton(groupBox);
        rb_graph->setObjectName(QString::fromUtf8("rb_graph"));

        verticalLayout->addWidget(rb_graph);

        grid->addWidget(groupBox, 0, 1, 1, 1);

        label_layers = new QLabel(Settings);
        label_layers->setObjectName(QString::fromUtf8("label_layers"));

        grid->addWidget(label_layers, 1, 0, 1, 1);

        spinBox_layers = new QSpinBox(Settings);
        spinBox_layers->setObjectName(QString::fromUtf8("spinBox_layers"));
        spinBox_layers->setStyleSheet(
            QString::fromUtf8("QSpinBox {\n"
                              "   height: 30px;\n"
                              "   background-color: #3D4043;\n"
                              "   color: #E8EAED;\n"
                              "}"));
        spinBox_layers->setMinimum(2);
        spinBox_layers->setMaximum(5);
        spinBox_layers->setValue(4);

        grid->addWidget(spinBox_layers, 1, 1, 1, 1);

        verticalLayout_2->addLayout(grid);

        hl_buttons = new QHBoxLayout();
        hl_buttons->setObjectName(QString::fromUtf8("hl_buttons"));
        hl_buttons->setContentsMargins(-1, 10, -1, -1);
        btn_cancel = new QPushButton(Settings);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setStyleSheet(
            QString::fromUtf8("QPushButton {\n"
                              "   background-color: #686c6e;\n"
                              "   color: #E8EAED;\n"
                              "   border: none;\n"
                              "   border-radius: 5px;\n"
                              "   height: 30px;\n"
                              "}\n"
                              "\n"
                              "QPushButton:hover {\n"
                              "   background-color: #606367;\n"
                              "}\n"
                              "\n"
                              "QPushButton:pressed {\n"
                              "   background-color: #4f5255;\n"
                              "}"));

        hl_buttons->addWidget(btn_cancel);

        btn_ok = new QPushButton(Settings);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setStyleSheet(
            QString::fromUtf8("QPushButton {\n"
                              "   background-color: #94B4F2;\n"
                              "   color: #202124;\n"
                              "   border: none;\n"
                              "   border-radius: 5px;\n"
                              "   height: 30px;\n"
                              "}\n"
                              "\n"
                              "QPushButton:hover {\n"
                              "   background-color: #88A5DF;\n"
                              "}\n"
                              "\n"
                              "QPushButton:pressed {\n"
                              "   background-color: #728ABB;\n"
                              "}"));

        hl_buttons->addWidget(btn_ok);

        verticalLayout_2->addLayout(hl_buttons);

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    }  // setupUi

    void retranslateUi(QDialog *Settings) {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Settings", nullptr));
        label_realization->setText(QCoreApplication::translate("Settings", "Realization:", nullptr));
        groupBox->setTitle(QString());
        rb_matrix->setText(QCoreApplication::translate("Settings", "Matrix", nullptr));
        rb_graph->setText(QCoreApplication::translate("Settings", "Graph", nullptr));
        label_layers->setText(QCoreApplication::translate("Settings", "Hidden layers:", nullptr));
        btn_cancel->setText(QCoreApplication::translate("Settings", "Cancel", nullptr));
        btn_ok->setText(QCoreApplication::translate("Settings", "Ok", nullptr));
    }  // retranslateUi
};

namespace Ui {
class Settings : public Ui_Settings {};
}  // namespace Ui

}  // namespace s21
QT_END_NAMESPACE

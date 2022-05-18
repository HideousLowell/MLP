#pragma once

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace s21 {

class Ui_MetricsDialog {
 public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *grid;
    QLabel *aver_accur;
    QLabel *precision;
    QLabel *f_measure;
    QLabel *recall;
    QLabel *time;
    QLabel *aver_accur_num;
    QLabel *precision_num;
    QLabel *recall_num;
    QLabel *f_measure_num;
    QLabel *time_num;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_ok;

    void setupUi(QDialog *MetricsDialog) {
        if (MetricsDialog->objectName().isEmpty())
            MetricsDialog->setObjectName(QString::fromUtf8("MetricsDialog"));
        MetricsDialog->resize(306, 252);
        MetricsDialog->setStyleSheet(QString::fromUtf8("background-color: #202124;"));
        verticalLayout_2 = new QVBoxLayout(MetricsDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        grid = new QGridLayout();
        grid->setObjectName(QString::fromUtf8("grid"));
        grid->setContentsMargins(10, 10, -1, 5);
        aver_accur = new QLabel(MetricsDialog);
        aver_accur->setObjectName(QString::fromUtf8("aver_accur"));
        aver_accur->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        aver_accur->setFont(font);
        aver_accur->setStyleSheet(QString::fromUtf8("color: #E8EAED;"));
        aver_accur->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignTop);
        aver_accur->setMargin(5);

        grid->addWidget(aver_accur, 0, 0, 1, 1);

        precision = new QLabel(MetricsDialog);
        precision->setObjectName(QString::fromUtf8("precision"));
        precision->setFont(font);
        precision->setStyleSheet(QString::fromUtf8("color: #E8EAED;"));
        precision->setMargin(5);

        grid->addWidget(precision, 1, 0, 1, 1);

        f_measure = new QLabel(MetricsDialog);
        f_measure->setObjectName(QString::fromUtf8("f_measure"));
        f_measure->setFont(font);
        f_measure->setStyleSheet(QString::fromUtf8("color: #E8EAED;"));
        f_measure->setMargin(5);

        grid->addWidget(f_measure, 3, 0, 1, 1);

        recall = new QLabel(MetricsDialog);
        recall->setObjectName(QString::fromUtf8("recall"));
        recall->setFont(font);
        recall->setStyleSheet(QString::fromUtf8("color: #E8EAED;"));
        recall->setMargin(5);

        grid->addWidget(recall, 2, 0, 1, 1);

        time = new QLabel(MetricsDialog);
        time->setObjectName(QString::fromUtf8("time"));
        time->setFont(font);
        time->setStyleSheet(QString::fromUtf8("color: #E8EAED;"));
        time->setMargin(5);

        grid->addWidget(time, 4, 0, 1, 1);

        aver_accur_num = new QLabel(MetricsDialog);
        aver_accur_num->setObjectName(QString::fromUtf8("aver_accur_num"));
        aver_accur_num->setStyleSheet(QString::fromUtf8("color: #E8EAED;"));

        grid->addWidget(aver_accur_num, 0, 1, 1, 1);

        precision_num = new QLabel(MetricsDialog);
        precision_num->setObjectName(QString::fromUtf8("precision_num"));
        precision_num->setStyleSheet(QString::fromUtf8("color: #E8EAED;"));

        grid->addWidget(precision_num, 1, 1, 1, 1);

        recall_num = new QLabel(MetricsDialog);
        recall_num->setObjectName(QString::fromUtf8("recall_num"));
        recall_num->setStyleSheet(QString::fromUtf8("color: #E8EAED;"));

        grid->addWidget(recall_num, 2, 1, 1, 1);

        f_measure_num = new QLabel(MetricsDialog);
        f_measure_num->setObjectName(QString::fromUtf8("f_measure_num"));
        f_measure_num->setStyleSheet(QString::fromUtf8("color: #E8EAED;"));

        grid->addWidget(f_measure_num, 3, 1, 1, 1);

        time_num = new QLabel(MetricsDialog);
        time_num->setObjectName(QString::fromUtf8("time_num"));
        time_num->setStyleSheet(QString::fromUtf8("color: #E8EAED;"));

        grid->addWidget(time_num, 4, 1, 1, 1);

        verticalLayout_2->addLayout(grid);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 10, -1, -1);
        btn_ok = new QPushButton(MetricsDialog);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(150, 16777215));
        btn_ok->setStyleSheet(
            QString::fromUtf8("QPushButton {\n"
                              "        background-color: #94B4F2;\n"
                              "        color: #202124;\n"
                              "        border: none;\n"
                              "        border-radius: 5px;\n"
                              "        height: 30px;\n"
                              "}\n"
                              "\n"
                              "QPushButton:hover {\n"
                              "        background-color: #88A5DF;\n"
                              "}\n"
                              "\n"
                              "QPushButton:pressed {\n"
                              "        background-color: #728ABB;\n"
                              "}"));

        horizontalLayout->addWidget(btn_ok);

        verticalLayout_2->addLayout(horizontalLayout);

        retranslateUi(MetricsDialog);

        QMetaObject::connectSlotsByName(MetricsDialog);
    }  // setupUi

    void retranslateUi(QDialog *MetricsDialog) {
        MetricsDialog->setWindowTitle(QCoreApplication::translate("MetricsDialog", "Dialog", nullptr));
        aver_accur->setText(QCoreApplication::translate("MetricsDialog", "Average accuracy:", nullptr));
        precision->setText(QCoreApplication::translate("MetricsDialog", "Precision:", nullptr));
        f_measure->setText(QCoreApplication::translate("MetricsDialog", "F-measure:", nullptr));
        recall->setText(QCoreApplication::translate("MetricsDialog", "Recall:", nullptr));
        time->setText(QCoreApplication::translate("MetricsDialog", "Time:", nullptr));
        aver_accur_num->setText(QCoreApplication::translate("MetricsDialog", "TextLabel", nullptr));
        precision_num->setText(QCoreApplication::translate("MetricsDialog", "TextLabel", nullptr));
        recall_num->setText(QCoreApplication::translate("MetricsDialog", "TextLabel", nullptr));
        f_measure_num->setText(QCoreApplication::translate("MetricsDialog", "TextLabel", nullptr));
        time_num->setText(QCoreApplication::translate("MetricsDialog", "TextLabel", nullptr));
        btn_ok->setText(QCoreApplication::translate("MetricsDialog", "Ok", nullptr));
    }  // retranslateUi
};

namespace Ui {
class MetricsDialog : public Ui_MetricsDialog {};
}  // namespace Ui

}  // namespace s21
QT_END_NAMESPACE

#pragma once

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

#include "../view/qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace s21 {

class Ui_ResultPlot {
 public:
    QCustomPlot *widget;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *ResultPlot) {
        if (ResultPlot->objectName().isEmpty()) ResultPlot->setObjectName(QString::fromUtf8("ResultPlot"));
        ResultPlot->resize(501, 357);
        widget = new QCustomPlot(ResultPlot);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 501, 351));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 270, 58, 16));
        QFont font;
        font.setPointSize(15);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: black;"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 270, 58, 16));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: black;"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(240, 270, 58, 16));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: black;"));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(330, 270, 58, 20));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: black;"));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(410, 270, 58, 16));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: black;"));
        label_6->setAlignment(Qt::AlignCenter);

        retranslateUi(ResultPlot);

        QMetaObject::connectSlotsByName(ResultPlot);
    }  // setupUi

    void retranslateUi(QDialog *ResultPlot) {
        ResultPlot->setWindowTitle(QCoreApplication::translate("ResultPlot", "Results", nullptr));
    }  // retranslateUi
};

namespace Ui {
class ResultPlot : public Ui_ResultPlot {};
}  // namespace Ui

}  // namespace s21
QT_END_NAMESPACE

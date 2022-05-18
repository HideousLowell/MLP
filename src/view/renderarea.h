#pragma once

#include <QtGui/QImage>
#include <QtGui/QMouseEvent>
#include <QtGui/QPainter>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <array>
#include <functional>

#include "mainwindow.h"

namespace s21 {

class RenderArea : public QWidget {
    Q_OBJECT

 private:
    MainWindow *_mainwindow;
    QPoint mPos;
    Qt::MouseButton mBtn;
    QImage image;

    void mousePressEvent(QMouseEvent *mo) override;
    void mouseMoveEvent(QMouseEvent *mo) override;
    void mouseReleaseEvent(QMouseEvent *mo) override;
    void paintEvent(QPaintEvent *event) override;
    void drawLineTo(const QPoint &endPos);

 public:
    explicit RenderArea(QWidget *parent = nullptr);
    void clearImage();
    QImage &getImage() { return image; }
    void setMainWindow(MainWindow *mw) { _mainwindow = mw; }
};

}  // namespace s21

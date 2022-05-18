#include "renderarea.h"

namespace s21 {

RenderArea::RenderArea(QWidget *parent) : QWidget(parent) {
    image = QImage(QSize(387, 409), QImage::Format_RGB16);
    clearImage();
}

void RenderArea::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);

    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void RenderArea::clearImage() { image.fill(qRgb(255, 255, 255)); }

void RenderArea::mousePressEvent(QMouseEvent *mo) {
    mBtn = mo->button();
    if (mBtn == Qt::LeftButton) {
        mPos = mo->pos();
    } else {
        clearImage();
        update();
    }
}

void RenderArea::mouseMoveEvent(QMouseEvent *mo) {
    if (mBtn == Qt::LeftButton) {
        drawLineTo(mo->pos());
    }
}

void RenderArea::mouseReleaseEvent(QMouseEvent *mo) {
    if (mo->button() == Qt::LeftButton) {
        _mainwindow->predict();
    }
}

void RenderArea::drawLineTo(const QPoint &endPos) {
    QPainter painter(&image);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::black, 40, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(mPos, endPos);

    int rad = (40 / 2) + 2;
    update(QRect(mPos, endPos).normalized().adjusted(-rad, -rad, +rad, +rad));

    mPos = endPos;
}

}  // namespace s21

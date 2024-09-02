#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include "qpushbutton.h"
#include "qpainter.h"
#include "qpixmap.h"

class ImageButton : public QPushButton {
    Q_OBJECT

public:
    explicit ImageButton(const QString &imagePath, QWidget *parent = nullptr)
        : QPushButton(parent), m_imagePath(imagePath) {
        setFixedSize(50, 80); 
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);

        QPainter painter(this);
        QPixmap pixmap(m_imagePath);
        painter.drawPixmap(rect(), pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    void mousePressEvent(QMouseEvent *event) override {
        QPushButton::mousePressEvent(event);
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        QPushButton::mouseReleaseEvent(event);
    }

private:
    QString m_imagePath;  
};

#endif // IMAGEBUTTON_H

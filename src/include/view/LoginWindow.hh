#ifndef LoginWindow_H
#define LoginWindow_H

#include "qmainwindow.h"
#include "qapplication.h"
#include "qwidget.h"
#include "qpainter.h"
#include "qpixmap.h"
#include "qmessagebox.h"
#include "qtimer.h"
#include "qdebug.h"


class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    void quitWindows();
    ~LoginWindow();

protected:
    void paintEvent(QPaintEvent *event) override;
private slots:
    void updatePositions();
private:
    LoginWindow *root;
    QPixmap background;
    QPixmap centerImage;
    QPixmap bg_leftSelectImage;
    QPixmap bg_rightSelectImage;
    QPixmap p1_SelectImage;
    QPixmap p2_SelectImage;

    int bg_leftImagePos=width()/2 - bg_leftSelectImage.width();
    int l_nextImagePos ;
    int bg_rightImagePos=width()/2 + bg_rightSelectImage.width();
    int r_nextImagePos;
    const int speed = 5;


};
#endif // LoginWindow_H


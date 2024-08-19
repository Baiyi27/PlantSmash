#ifndef LoginWindow_H
#define LoginWindow_H

#include "qmainwindow.h"
#include "qapplication.h"
#include "qwidget.h"
#include "qpainter.h"
#include "qpixmap.h"
#include "qmessagebox.h"
#include "qtimer.h"
#include "qpushbutton.h"
#include "qdebug.h"

enum class Role
{
    Peashooter=1,
    Sunflower,
    Nut,
    Gloomshroom
};

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    void quitWindows();
    void checkRole(int player);
    void chageRole(Role &playerRole);
    ~LoginWindow();

protected:
    void paintEvent(QPaintEvent *event) override;
private slots:
    void updatePositions();
private:
    LoginWindow *root;
    QPixmap background;
    QPixmap centerImage;
    QPixmap centerHelpImage;
    QPixmap bg_leftSelectImage;
    QPixmap bg_rightSelectImage;
    QPixmap p1_SelectImage;
    QPixmap p2_SelectImage;
    QPixmap p1_selectbackimg;
    QPixmap p2_selectbackimg;
    QPixmap p1_helpImg;
    QPixmap p2_helpImg;
    QPixmap p1_titleImg;
    QPixmap p2_titleImg;
    Role p1_checkRoles;
    Role p2_checkRoles;

    QString ck_peashooterImgPath;
    QString ck_sunflowerImgPath;

    QStringList characterImages;
    int currentIndex;

    int bg_leftImagePos=width()/2 - bg_leftSelectImage.width();
    int l_nextImagePos ;
    int bg_rightImagePos=width()/2 + bg_rightSelectImage.width();
    int r_nextImagePos;
    int roleNum=2;
    const int speed = 5;


};
#endif // LoginWindow_H


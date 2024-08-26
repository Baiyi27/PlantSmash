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
#include "qlabel.h"
#include "qmovie.h"
#include "qboxlayout.h"

#include "ImageButton.hh"

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
    void p1_updateCharacterImage();  
    void p1_showPreviousCharacter();  
    void p1_showNextCharacter();  
    void p2_updateCharacterImage();  
    void p2_showPreviousCharacter();  
    void p2_showNextCharacter();  


    LoginWindow *root;
    QPixmap background;
    QPixmap centerImage;
    QPixmap centerHelpImage;
    QPixmap p1_SelectBackImage;
    QPixmap p2_SelectBackImage;
    QLabel * p1_SelectImage;
    QLabel * p2_SelectImage;
    std::unique_ptr<QMovie> p1_SelectMovie;
    std::unique_ptr<QMovie> p2_SelectMovie;
    QPixmap p1_selectbackimg;
    QPixmap p2_selectbackimg;
    QPixmap p1_helpImg;
    QPixmap p2_helpImg;
    QPixmap p1_titleImg;
    QPixmap p2_titleImg;
    ImageButton *p1_leftButton;  
    ImageButton *p1_rightButton;  
    ImageButton *p2_leftButton;  
    ImageButton *p2_rightButton;  

    QStringList characterBackImages; 
    QStringList characterImages;
    int currentIndex;
    int p1_currentIndex = 0;
    int p2_currentIndex = 0;

    int bg_leftImagePos=width()/2 - p1_SelectBackImage.width();
    int l_nextImagePos ;
    int bg_rightImagePos=width()/2 + p2_SelectBackImage.width();
    int r_nextImagePos;
    int roleNum=2;
    const int speed = 5;


};
#endif // LoginWindow_H


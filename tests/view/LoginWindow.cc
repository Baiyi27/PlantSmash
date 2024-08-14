#include "LoginWindow.hh"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QString backImagePath       = "../../resources/components/selector_background.png";
    QString centerImagePath     = "../../resources/components/VS.png";
    QString bg_peashooterImgPath= "../../resources/roles/peashooter/peashooter_selector_background.png";
    QString bg_sunflowerImgPath = "../../resources/roles/sunflower/sunflower_selector_background.png";
    QString ck_backImgPath      = "../../resources/components/gravestone.png";
    QString ck_peashooterImgPath= "../../resources/roles/peashooter/avatar_peashooter.png";
    QString ck_sunflowerImgPath = "../../resources/roles/sunflower/avatar_sunflower.png";
    QString bg_leftImgPath      = bg_peashooterImgPath;
    QString bg_rightImgPath     = bg_sunflowerImgPath;
    QString p1_checkRoles, p2_checkRoles;

    root= this;
    // this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    background.load(backImagePath);
    centerImage.load(centerImagePath);
    bg_leftSelectImage.load(bg_leftImgPath);
    bg_rightSelectImage.load(bg_rightImgPath);

    setMinimumSize(1380, 600); // 设置最小窗口大小，方便测试
    // setMaximumSize(3040,1020);
    setWindowTitle("Resizable Window with Background Image");

    QTimer *timer= new QTimer(this);
    connect(timer, &QTimer::timeout, this, &LoginWindow::updatePositions);
    timer->start(20);
}

void LoginWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // 将背景图片按窗口大小缩放绘制
    painter.drawPixmap(0, 0, width(), height(), background);
    // 计算中心图片的位置
    int centerX   = (width() - centerImage.width()) / 2;
    int centerY   = (height() - centerImage.height()) / 2;
    l_nextImagePos= bg_leftImagePos - bg_leftSelectImage.width();
    r_nextImagePos= bg_rightImagePos - bg_rightSelectImage.width();

    // 绘制左侧的循环播放图片
    painter.drawPixmap(bg_leftImagePos - 180, 0, bg_leftSelectImage);
    painter.drawPixmap(l_nextImagePos - 180, 0, bg_leftSelectImage);
    painter.drawPixmap(bg_leftImagePos - 180, 720, bg_leftSelectImage);
    painter.drawPixmap(l_nextImagePos - 180, 720, bg_leftSelectImage);

    // 绘制右侧的循环播放图片
    painter.drawPixmap(bg_rightImagePos + 180, 0, bg_rightSelectImage);
    painter.drawPixmap(r_nextImagePos + 180, 0, bg_rightSelectImage);
    painter.drawPixmap(bg_rightImagePos + 180, 720, bg_rightSelectImage);
    painter.drawPixmap(r_nextImagePos + 180, 720, bg_rightSelectImage);

    // 绘制中心图片
    painter.drawPixmap(centerX, centerY, centerImage);
}

void LoginWindow::updatePositions()
{
    // 更新左边图片位置
    bg_leftImagePos+= speed;
    if(bg_leftImagePos >= (width() - bg_leftSelectImage.width() - 280) / 2) {
        bg_leftImagePos= width() / 2 - bg_leftSelectImage.width();
    }

    // 更新右边图片位置
    bg_rightImagePos-= speed;
    if(bg_rightImagePos <= (width() + bg_rightSelectImage.width() + 280) / 2) {
        bg_rightImagePos= width() / 2 + bg_rightSelectImage.width();
        qDebug() << bg_rightImagePos << width() / 2 << bg_rightSelectImage.width() << height();
    }

    // 更新界面
    update();
}

void LoginWindow::quitWindows()
{
    // root->destroyed();
}

LoginWindow::~LoginWindow()
{
}

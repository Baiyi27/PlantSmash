#include "LoginWindow.hh"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QString bg_peashooterImgPath = "../../resources/roles/peashooter/peashooter_selector_background.png";
    QString bg_sunflowerImgPath = "../../resources/roles/sunflower/sunflower_selector_background.png";

    QString bg_leftImgPath = bg_peashooterImgPath;
    QString bg_rightImgPath = bg_sunflowerImgPath;

    ck_peashooterImgPath = "../../resources/roles/peashooter/avatar_peashooter.png";
    ck_sunflowerImgPath = "../../resources/roles/sunflower/avatar_sunflower.png";

    // this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    background.load("../../resources/components/selector_background.png");
    centerImage.load("../../resources/components/VS.png");
    centerHelpImage.load("../../resources/components/selector_tip.png");
    bg_leftSelectImage.load(bg_leftImgPath);
    bg_rightSelectImage.load(bg_rightImgPath);
    p1_selectbackimg.load("../../resources/components/gravestone.png");
    p2_selectbackimg.load("../../resources/components/gravestone.png");
    p1_titleImg.load("../../resources/components/1P.png");
    p2_titleImg.load("../../resources/components/2P.png");
    p1_helpImg.load("../../resources/components/1P_desc.png");
    p2_helpImg.load("../../resources/components/2P_desc.png");
    

    p1_SelectImage.load(ck_peashooterImgPath);
    p2_SelectImage.load(ck_sunflowerImgPath);
    setMinimumSize(1380, 600); // 设置最小窗口大小，方便测试

    QPushButton *leftFroutBtn = new QPushButton(this);
    leftFroutBtn->setIcon(QIcon(":/resources/components/1P_selector_left_btn_idle.png"));
    leftFroutBtn->setIconSize(QSize(53, 83)); // 设置图标大小

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &LoginWindow::updatePositions);
    timer->start(20);
}

void LoginWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // 将背景图片按窗口大小缩放绘制
    painter.drawPixmap(0, 0, width(), height(), background);
    // 计算中心图片的位置
    int centerX = (width() - centerImage.width()) / 2;
    int centerY = (height() - centerImage.height()) / 2;
    int centerMidX = (centerX)/2 - p1_selectbackimg.width()/2;
    l_nextImagePos = bg_leftImagePos - bg_leftSelectImage.width();
    r_nextImagePos = bg_rightImagePos - bg_rightSelectImage.width();

    // 绘制左侧的循环播放图片
    painter.drawPixmap(bg_leftImagePos - 180, 0, bg_leftSelectImage);
    painter.drawPixmap(l_nextImagePos - 180, 0, bg_leftSelectImage);
    painter.drawPixmap(bg_leftImagePos - 180, 720, bg_leftSelectImage);
    painter.drawPixmap(l_nextImagePos - 180, 720, bg_leftSelectImage);

    // 绘制右侧的循环播放图片
    painter.save();
    painter.scale(-1, 1);
    painter.drawPixmap(-bg_rightImagePos - bg_rightSelectImage.width()-240, 0, bg_rightSelectImage);
    painter.drawPixmap(-r_nextImagePos - bg_rightSelectImage.width()-240, 0, bg_rightSelectImage);
    painter.drawPixmap(-bg_rightImagePos - bg_rightSelectImage.width()-240, 720, bg_rightSelectImage);
    painter.drawPixmap(-r_nextImagePos - bg_rightSelectImage.width()-240, 720, bg_rightSelectImage);
    // 绘制镜像翻转的图像
    painter.drawPixmap(0, 0, bg_rightSelectImage);
    painter.restore();

    // 绘制中心图片
    painter.drawPixmap(centerX, centerY, centerImage);
    painter.drawPixmap((width() - centerHelpImage.width()) / 2, centerY+centerImage.height(), centerHelpImage);

    // 绘制左右两侧的按钮背景图片
    painter.drawPixmap(centerMidX,centerY,p1_selectbackimg);
    painter.drawPixmap(centerMidX + p1_SelectImage.width()+21, centerY+95, p1_SelectImage);
    painter.save();
    painter.scale(-1, 1);
    painter.drawPixmap(- width() + centerMidX,centerY,p2_selectbackimg);
    painter.drawPixmap(- width() + centerMidX + p2_SelectImage.width()+21, centerY+95, p2_SelectImage);
    painter.restore();
    // 绘制左右两侧的操作提示图片
    painter.drawPixmap((centerX - p1_titleImg.width())/2,centerY-p1_titleImg.height(),p1_titleImg);
    painter.drawPixmap(width() - centerX/2 - p2_titleImg.width()/2,centerY-p2_titleImg.height(),p2_titleImg);

    painter.drawPixmap(centerMidX,centerY+p1_selectbackimg.height(),p1_helpImg);
    painter.drawPixmap(width() - centerMidX-p1_selectbackimg.width(),centerY+p1_selectbackimg.height(),p2_helpImg);
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

void LoginWindow::checkRole(int player)
{
    switch (player)
    {
    case 1:
        if(p1_checkRoles == Role::Peashooter){
            p1_SelectImage.load(ck_peashooterImgPath);
        }
        if(p1_checkRoles == Role::Sunflower){
            p1_SelectImage.load(ck_sunflowerImgPath);
        }
        break;
    case 2:
        if(p2_checkRoles == Role::Peashooter){
            p2_SelectImage.load(ck_peashooterImgPath);
        }
        if(p2_checkRoles == Role::Sunflower){
            p2_SelectImage.load(ck_sunflowerImgPath);
        }
        break;
    default:
        break;
    }
}

void LoginWindow::chageRole(Role &playerRole)
{
    if(playerRole==Role::Sunflower) {
        playerRole=Role::Peashooter;
    }else if (playerRole == Role::Peashooter) {
        playerRole = Role::Sunflower;
    }

}

void LoginWindow::quitWindows()
{
    // root->destroyed();
}

LoginWindow::~LoginWindow()
{
}

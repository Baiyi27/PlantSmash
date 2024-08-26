#include "LoginWindow.hh"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(1380, 600); // 设置最小窗口大小，方便测试

    characterBackImages << "../../resources/roles/gloomshroom/gloomshroom_selector_background.png" 
                << "../../resources/roles/nut/nut_selector_background.png" 
                << "../../resources/roles/peashooter/peashooter_selector_background.png"
                << "../../resources/roles/sunflower/sunflower_selector_background.png";

    characterImages << "../../resources/roles/gloomshroom/idle/gloomshroom.gif" 
                << "../../resources/roles/nut/idle/nut.gif" 
                << "../../resources/roles/peashooter/idle/peashooter.gif"
                << "../../resources/roles/sunflower/idle/sunflower.gif";


    // this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    background.load("../../resources/components/selector_background.png");
    centerImage.load("../../resources/components/VS.png");
    centerHelpImage.load("../../resources/components/selector_tip.png");
    p1_selectbackimg.load("../../resources/components/gravestone.png");
    p2_selectbackimg.load("../../resources/components/gravestone.png");
    p1_titleImg.load("../../resources/components/1P.png");
    p2_titleImg.load("../../resources/components/2P.png");
    p1_helpImg.load("../../resources/components/1P_desc.png");
    p2_helpImg.load("../../resources/components/2P_desc.png");
    
    p1_SelectBackImage.load(characterBackImages[p1_currentIndex]);
    p2_SelectBackImage.load(characterBackImages[p2_currentIndex]);
    p1_SelectImage = new QLabel(this);
    p2_SelectImage = new QLabel(this);

    p1_leftButton = new ImageButton("../../resources/components/1P_selector_left_btn_down.png", this);
    p1_rightButton = new ImageButton("../../resources/components/1P_selector_right_btn_down.png", this);
    p2_leftButton = new ImageButton("../../resources/components/2P_selector_left_btn_down.png", this);
    p2_rightButton = new ImageButton("../../resources/components/2P_selector_right_btn_down.png", this);
    
    connect(p1_leftButton, &ImageButton::clicked, this, &LoginWindow::p1_showPreviousCharacter);  
    connect(p1_rightButton, &ImageButton::clicked, this, &LoginWindow::p1_showNextCharacter);  
    connect(p2_leftButton, &ImageButton::clicked, this, &LoginWindow::p2_showPreviousCharacter);  
    connect(p2_rightButton, &ImageButton::clicked, this, &LoginWindow::p2_showNextCharacter);  

    QHBoxLayout *mainLayout = new QHBoxLayout;  

    QHBoxLayout *p1Layout = new QHBoxLayout;  
    p1Layout->addWidget(p1_leftButton);  
    p1Layout->addWidget(p1_SelectImage);  
    p1Layout->addWidget(p1_rightButton);  

    QHBoxLayout *p2Layout = new QHBoxLayout;  
    p2Layout->addWidget(p2_leftButton);  
    p2Layout->addWidget(p2_SelectImage);  
    p2Layout->addWidget(p2_rightButton);  

    mainLayout->addLayout(p1Layout);  
    mainLayout->addLayout(p2Layout);  

    QWidget *centralWidget = new QWidget(this);  
    centralWidget->setLayout(mainLayout);  
    setCentralWidget(centralWidget);  

    p1_updateCharacterImage();
    p2_updateCharacterImage();
 
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
    l_nextImagePos = bg_leftImagePos - p1_SelectBackImage.width();
    r_nextImagePos = bg_rightImagePos - p2_SelectBackImage.width();

    // 绘制左侧的循环播放图片
    painter.drawPixmap(bg_leftImagePos - 180, 0, p1_SelectBackImage);
    painter.drawPixmap(l_nextImagePos - 180, 0, p1_SelectBackImage);
    painter.drawPixmap(bg_leftImagePos - 180, 720, p1_SelectBackImage);
    painter.drawPixmap(l_nextImagePos - 180, 720, p1_SelectBackImage);

    // 绘制右侧的循环播放图片
    painter.save();
    painter.scale(-1, 1);
    painter.drawPixmap(-bg_rightImagePos - p2_SelectBackImage.width()-240, 0, p2_SelectBackImage);
    painter.drawPixmap(-r_nextImagePos - p2_SelectBackImage.width()-240, 0, p2_SelectBackImage);
    painter.drawPixmap(-bg_rightImagePos - p2_SelectBackImage.width()-240, 720, p2_SelectBackImage);
    painter.drawPixmap(-r_nextImagePos - p2_SelectBackImage.width()-240, 720, p2_SelectBackImage);
    // 绘制镜像翻转的图像
    painter.drawPixmap(0, 0, p2_SelectBackImage);
    painter.restore();

    // 绘制中心图片
    painter.drawPixmap(centerX, centerY, centerImage);
    painter.drawPixmap((width() - centerHelpImage.width()) / 2, centerY+centerImage.height(), centerHelpImage);

    // 绘制左右两侧的按钮背景图片
    painter.drawPixmap(centerMidX,centerY,p1_selectbackimg);
    // painter.drawPixmap(centerMidX + p1_SelectImage.width()+21, centerY+95, p1_SelectImage);
    painter.save();
    painter.scale(-1, 1);
    painter.drawPixmap(- width() + centerMidX,centerY,p2_selectbackimg);
    // painter.drawPixmap(- width() + centerMidX + p2_SelectImage.width()+21, centerY+95, p2_SelectImage);
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
    if(bg_leftImagePos >= (width() - p1_SelectBackImage.width() - 280) / 2) {
        bg_leftImagePos= width() / 2 - p1_SelectBackImage.width();
    }

    // 更新右边图片位置
    bg_rightImagePos-= speed;
    if(bg_rightImagePos <= (width() + p2_SelectBackImage.width() + 280) / 2) {
        bg_rightImagePos= width() / 2 + p2_SelectBackImage.width();
        qDebug() << bg_rightImagePos << width() / 2 << p2_SelectBackImage.width() << height();
    }

    update();
}

void LoginWindow::p1_updateCharacterImage() {
    p1_SelectMovie = std::make_unique<QMovie>(characterImages[p1_currentIndex]);
    if (!p1_SelectMovie->isValid()) {
        qDebug() << "Failed to load movie for Player 1 at index:" << p1_currentIndex;
        return;
    }
    p1_SelectImage->setMovie(p1_SelectMovie.get());
    p1_SelectMovie->start();
    p1_SelectBackImage.load(characterBackImages[p1_currentIndex]);
}

void LoginWindow::p1_showPreviousCharacter() {
    p1_currentIndex = (p1_currentIndex - 1 + characterImages.size()) % characterImages.size();
    p1_updateCharacterImage();
}

void LoginWindow::p1_showNextCharacter() {
    p1_currentIndex = (p1_currentIndex + 1) % characterImages.size();
    p1_updateCharacterImage();
}

void LoginWindow::p2_updateCharacterImage() {
    p2_SelectMovie = std::make_unique<QMovie>(characterImages[p2_currentIndex]);
    if (!p2_SelectMovie->isValid()) {
        qDebug() << "Failed to load movie for Player 2 at index:" << p2_currentIndex;
        return;
    }
    p2_SelectImage->setMovie(p2_SelectMovie.get());
    p2_SelectMovie->start();
    p2_SelectBackImage.load(characterBackImages[p2_currentIndex]);
}

void LoginWindow::p2_showPreviousCharacter() {
    p2_currentIndex = (p2_currentIndex - 1 + characterImages.size()) % characterImages.size();
    p2_updateCharacterImage();
}

void LoginWindow::p2_showNextCharacter() {
    p2_currentIndex = (p2_currentIndex + 1) % characterImages.size();
    p2_updateCharacterImage();
}

void LoginWindow::quitWindows()
{
    // root->destroyed();
}

LoginWindow::~LoginWindow()
{
}

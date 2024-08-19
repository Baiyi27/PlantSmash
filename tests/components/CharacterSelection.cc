#include "CharacterSelection.hh"

CharacterSelection::CharacterSelection(QWidget *parent) : QWidget(parent), currentIndex(0) {  
    // 初始化角色图像列表  
    characterImages << "../../resources/roles/peashooter/idle/peashooter_idle_1.png" 
                << "../../resources/roles/sunflower/idle/sunflower_idle_1.png" 
                << "../../resources/roles/nut/idle/nut_idle_1.png"
                << "../../resources/roles/gloomshroom/idle/gloomshroom_idle_1.png";

    // 设置窗口的标题和大小  
    setWindowTitle("角色选择");  
    setFixedSize(300, 400);  

    // 创建 UI 组件  
    characterLabel = new QLabel(this);  
    updateCharacterImage();  

    leftButton = new QPushButton("←", this);  
    rightButton = new QPushButton("→", this);  

    // 连接按钮点击信号  
    connect(leftButton, &QPushButton::clicked, this, &CharacterSelection::showPreviousCharacter);  
    connect(rightButton, &QPushButton::clicked, this, &CharacterSelection::showNextCharacter);  

    // 创建布局  
    QVBoxLayout *layout = new QVBoxLayout(this);  
    layout->addWidget(characterLabel);  
    layout->addWidget(leftButton);  
    layout->addWidget(rightButton);  

    setLayout(layout);  
}  

void CharacterSelection::updateCharacterImage() {  
    QPixmap pixmap(characterImages[currentIndex]);  
    characterLabel->setPixmap(pixmap.scaled(200, 200, Qt::KeepAspectRatio)); // 根据需要缩放  
}  

void CharacterSelection::showPreviousCharacter() {  
    currentIndex = (currentIndex - 1 + characterImages.size()) % characterImages.size();  
    updateCharacterImage();  
}  

void CharacterSelection::showNextCharacter() {  
    currentIndex = (currentIndex + 1) % characterImages.size();  
    updateCharacterImage();  
}
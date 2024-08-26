#include "CharacterSelection.hh"

CharacterSelection::CharacterSelection(QWidget *parent) : QWidget(parent), currentIndex(0) {  
    // 初始化角色图像列表  
    characterImages << "../../resources/roles/gloomshroom/idle/gloomshroom.gif" 
                << "../../resources/roles/nut/idle/nut.gif" 
                << "../../resources/roles/peashooter/idle/peashooter.gif"
                << "../../resources/roles/sunflower/idle/sunflower.gif";

    setFixedSize(600, 400);  
    characterLabel = new QLabel(this);
    updateCharacterImage();

    leftButton = new ImageButton("../../resources/components/1P_selector_left_btn_down.png", this);
    rightButton = new ImageButton("../../resources/components/1P_selector_right_btn_down.png", this);

    connect(leftButton, &QPushButton::clicked, this, &CharacterSelection::showPreviousCharacter);
    connect(rightButton, &QPushButton::clicked, this, &CharacterSelection::showNextCharacter);

    QHBoxLayout  *layout = new QHBoxLayout (this);

    layout->addWidget(leftButton);
    layout->addWidget(characterLabel);
    layout->addWidget(rightButton);
    layout->setSpacing(20); 
    layout->setContentsMargins(20, 20, 20, 20); 
    setLayout(layout);
}  

void CharacterSelection::updateCharacterImage() {  
    if (movie) {  
        movie->stop();  
    }  
    
    movie = new QMovie(characterImages[currentIndex]);  
    characterLabel->setMovie(movie);  
    movie->start(); 
}  

void CharacterSelection::showPreviousCharacter() {  
    currentIndex = (currentIndex - 1 + characterImages.size()) % characterImages.size();  
    updateCharacterImage();  
}  

void CharacterSelection::showNextCharacter() {  
    currentIndex = (currentIndex + 1) % characterImages.size();  
    updateCharacterImage();  
}
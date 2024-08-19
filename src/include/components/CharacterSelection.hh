#ifndef CharacterSelection_H
#define CharacterSelection_H

#include "qapplication.h"
#include "qwidget.h"
#include "qpainter.h"
#include "qpixmap.h"
#include "qlabel.h"
#include "qtimer.h"
#include "qpushbutton.h"
#include "qboxlayout.h"

class CharacterSelection : public QWidget {  
    Q_OBJECT  

public:  
    CharacterSelection(QWidget *parent = nullptr);  

private slots:  
    void showPreviousCharacter();  
    void showNextCharacter();  

private:  
    void updateCharacterImage();  

    QLabel *characterLabel;  
    QPushButton *leftButton;  
    QPushButton *rightButton;  
    QStringList characterImages; 
    int currentIndex;  
};  
#endif // CharacterSelection_H


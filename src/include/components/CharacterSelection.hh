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
#include "qmovie.h"

#include "ImageButton.hh"

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
    QMovie *movie; 
    ImageButton *leftButton;
    ImageButton *rightButton;  
    QStringList characterImages; 
    int currentIndex;  
};  
#endif // CharacterSelection_H


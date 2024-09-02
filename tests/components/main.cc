#include "CharacterSelection.hh"
#include "LoginWindow.hh"
#include "qapplication.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QHBoxLayout layout;
    LoginWindow window;  
    CharacterSelection leftFroutBtn(&window);

    layout.addWidget(&leftFroutBtn);
    window.setLayout(&layout);
    window.show();  
    
    return app.exec(); 
}
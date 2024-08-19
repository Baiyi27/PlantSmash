#include "CharacterSelection.hh"

#include "qapplication.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CharacterSelection window;  
    window.show();  
    
    return app.exec(); 
}
 #include <qapplication.h>

#include "luces.h"



int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    
    luces ventL;
    
        
    ventL.show();

    return a.exec();
}

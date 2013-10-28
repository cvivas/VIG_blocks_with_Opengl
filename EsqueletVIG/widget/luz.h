#ifndef _LUZ_H_
#define _LUZ_H_

#include <QtOpenGL/qgl.h>
#include <QString>
#include "point.h"



using namespace std;
class luz {
 
public:   
    
    luz (int idL=-1);

    GLfloat posicio[4];
    Point posL;    
    
    GLfloat ambient[4];
    GLfloat difus[4];
    GLfloat specular[4];

    int id;
    bool act;   
    bool selected;

void initLuz();

void setPos(Point p=Point());

void setActivada(bool a);
void setADS(QColor c,int tipo);  

luz copy(luz t);


};

#endif

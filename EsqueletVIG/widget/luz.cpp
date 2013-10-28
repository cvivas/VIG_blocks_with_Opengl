#include "luz.h"
#include <cmath>
#include "point.h"

luz::luz(int idL) 
{
id=idL;
initLuz();
}

void luz::initLuz(){

posL=Point(id,id,id);
 
 posicio[0] = id;
 posicio[1] = id;
 posicio[2] = id;
 posicio[3] = 1;
 
 ambient[0]= 1*0.05;
 ambient[1]= 1*0.05;
 ambient[2]= 1*0.05;
 ambient[3]= 1*0.05;
 
 difus[0] = 1;
 difus[1] = 1;
 difus[2] = 1;
 difus[3] = 1;

 specular[0] = 1;
 specular[1] = 1;
 specular[2] = 1;
 specular[3] = 1;
 
 act = false; 
selected=false;
    
}

void luz::setPos(Point p){

posL = p;
posicio[0]=p.x;
 posicio[1] = p.y;
 posicio[2] = p.z;

}

void luz::setActivada(bool a){

act=a;

}

void luz::setADS(QColor c,int tipo){
qreal rgb[4];
c.getRgbF(&rgb[0],&rgb[1],&rgb[2],&rgb[3]);
if(tipo==1){
 ambient[0]= (float) rgb[0]*0.05;
 ambient[1]= (float)rgb[1]*0.05;
 ambient[2]= (float)rgb[2]*0.05;
// cout<<"el color guardado es: "<<ambient[0]*20.<< " " <<ambient[1]*20.<< " "<<ambient[2]*20.<< " "<<endl;
//  ambient[3]= (float)rgb[0];
}
if(tipo==2){
 difus[0]= (float) rgb[0];
 difus[1]= (float)rgb[1];
 difus[2]= (float)rgb[2];
//  ambient[3]= (float)rgb[0];
}
if(tipo==3){
 specular[0]= (float) rgb[0];
 specular[1]= (float)rgb[1];
 specular[2]= (float)rgb[2];
//  ambient[3]= (float)rgb[0];
}

}

luz luz::copy(luz t){


luz temp=luz(t.id);
Point p=Point(t.posL.x,t.posL.y,t.posL.z);
 temp.posL=p;
temp.posicio[0] =t.posicio[0] ;
 temp.posicio[1]=t.posicio[1];
 temp.posicio[2]=t.posicio[2];
 temp.posicio[3]=t.posicio[3] ;
 
 temp.ambient[0]=t.ambient[0];
 temp.ambient[1]=t.ambient[1];
 temp.ambient[2]=t.ambient[2];
 temp.ambient[3]=t.ambient[3];
 
temp.difus[0]= t.difus[0] ;
temp.difus[1]= t.difus[1] ;
temp.difus[2]= t.difus[2] ;
temp.difus[3]= t.difus[3];

temp.specular[0]= t.specular[0] ;
temp.specular[1]= t.specular[1] ;
temp.specular[2]= t.specular[2] ;
temp.specular[3]= t.specular[3] ;
 
temp.act= t.act ; 
temp.selected= t.selected; 

return temp;
}



#include "luces.h"
#include "ui_luces.h"
#include <iostream> 
#include "../widget/luz.h"
#include "../widget/point.h"

 using namespace std;  

luces::luces(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::luces)
{
    ui->setupUi(this);

QObject::connect(ui->BotonA, SIGNAL(clicked()), this, SLOT(ambient()));
QObject::connect(ui->BotonD, SIGNAL(clicked()), this, SLOT(difus()));
QObject::connect(ui->BotonE, SIGNAL(clicked()), this, SLOT(specular()));
QObject::connect(ui->BotonC, SIGNAL(clicked()), this, SLOT(borrarColores()));
QObject::connect(ui->BotonC, SIGNAL(clicked()), this, SLOT(borrarL()));
QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(cambiarLuz(int )));
QObject::connect(ui->boxAct, SIGNAL(clicked(bool)), this, SLOT(actPressed(bool )));
QObject::connect(ui->boxSel, SIGNAL(clicked(bool)), this, SLOT(selectedL(bool )));
}

luces::~luces()
{
    delete ui;
}


void luces::ambient()
{
    QColor colorA = QColorDialog::getColor();
    if (colorA.isValid()){
   // int rgb[3];
    //colorA.getRgb(&rgb[0],&rgb[1],&rgb[2]);

//ui->BotonA->setPalette(colorA);

    emit enviarAmbientL(colorA);

    }

}

void luces::difus()
{
    QColor colorA = QColorDialog::getColor();
    if (colorA.isValid()){
   // int rgb[3];
    //colorA.getRgb(&rgb[0],&rgb[1],&rgb[2]);
//ui->BotonD->setPalette(colorA);

    emit enviarDifusL(colorA);

    }

}

void luces::specular()
{
    QColor colorA = QColorDialog::getColor();
    if (colorA.isValid()){
   // int rgb[3];
    //colorA.getRgb(&rgb[0],&rgb[1],&rgb[2]);

//ui->BotonE->setPalette(colorA);
    emit enviarSpecularL(colorA);

    }

}

void luces::borrarColores()
{


ui->BotonE->setPalette(QColor(238,238,238));
ui->BotonA->setPalette(QColor(238,238,238));
ui->BotonD->setPalette(QColor(238,238,238));

}


void luces::borrarL()
{

//L[0].act=false;
emit eliminaL();

}

void luces::recibirLuces(luz l[],int i){
//cout<<"recibo luces y l 0 vale: "<<l[0].act<<endl;

for (int j=0;j<8;j++) L[j]=l[j].copy(l[j]);
 //L=l;
luzAct=&L[i];
//cout<<"la luz 0 tiene color amb r: "<<luzAct->ambient[0]<<" g: "<<luzAct->ambient[1] <<" b "<< luzAct->ambient[2]<<endl;
cargarLuces();
ui->comboBox->setCurrentIndex(i);
}

void luces::cargarLuces(){
//cout<<"cargo luces "<<luzAct->id<<" y esta activa? "<<luzAct->act<<endl;
activarLuz(luzAct->act );
//     ui->boxAct->setChecked(luzAct->act);
//     ui->groupBox->setEnabled(luzAct->act);
if(luzAct->act){
QColor temp;
//if(luzAct->ambient[0]>.5)temp.setRgbF(luzAct->ambient[0],luzAct->ambient[1],luzAct->ambient[2]);

float tr,tg,tb;
tr=luzAct->ambient[0]*20.-0.0001;
tg=luzAct->ambient[1]*20.-0.0001;
tb=luzAct->ambient[2]*20.-0.0001;
if(tr<0)tr=0.;
if(tg<0)tg=0.;
if(tb<0)tb=0.;

temp.setRgbF(tr,tg,tb);
// cout<<"el color cargado es: "<<luzAct->ambient[0]*20.<< " " <<luzAct->ambient[1]*20.<< " "<<luzAct->ambient[2]*20.<< " "<<endl;

//cout<<"el color cargado es: "<<luzAct->ambient[0]*20.<< " " <<luzAct->ambient[1]*20.<< " "<<luzAct->ambient[2]*20.<< " "<<endl;
ui->BotonA->setPalette(temp);
//cout<<"la luz 0 tiene color en el boton amb r: "<<temp.redF()<<" g: "<<temp.greenF() <<" b "<< temp.blueF()<<endl;

temp.setRgbF(luzAct->difus[0],luzAct->difus[1],luzAct->difus[2]);
ui->BotonD->setPalette(temp);

temp.setRgbF(luzAct->specular[0],luzAct->specular[1],luzAct->specular[2]);
ui->BotonE->setPalette(temp);


    }

}


void luces::activarLuz( bool b )
{

    //luzAct->act=b;
   if(b) ui->boxAct->setChecked(true);
   if(!b)  ui->boxAct->setChecked(false);
    ui->groupBox->setEnabled(b);
ui->boxSel->setChecked(luzAct->selected);
    emit activaL(luzAct->id, b);


//     emit llumModificada(L);
}

void luces::actPressed(bool b){
luzAct->act=b;
//L[luzAct->id].act=b;
//cout<<"checked vale "<<b<<" y el id es : "<<luzAct->id<<"y el estado de activo es : "<<luzAct->act<<endl;

cargarLuces();

}


void luces::cambiarLuz(int index){

luzAct=&L[index];
//cout<<"cambio el indice a : "<<index<<" y esta activoooooooooooooooo????????  "<<luzAct->act<<endl;
//cout<<"cambio el indice a : "<<index<<" y el 2 esta???????  "<<L[2].act<<endl;
emit cambiaLuz(index);
borrarColores();
cargarLuces();

}

void luces::selectedL( bool b){
luzAct->selected=b;
emit selectL(luzAct->id,b);

}



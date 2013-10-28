#include "materials.h"
#include "ui_materials.h"
#include <iostream> 
 using namespace std;  
materials::materials(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::materials)
{

    ui->setupUi(this);
QObject::connect(ui->BotonA, SIGNAL(clicked()), this, SLOT(ambient()));
QObject::connect(ui->BotonD, SIGNAL(clicked()), this, SLOT(difus()));
QObject::connect(ui->BotonE, SIGNAL(clicked()), this, SLOT(specular()));
QObject::connect(ui->BotonV, SIGNAL(clicked()), this, SLOT(valida()));
QObject::connect(ui->sliderSH, SIGNAL(valueChanged(int)), this, SLOT(shine(int)));
QObject::connect(ui->BotonC, SIGNAL(clicked()), this, SLOT(borrarColores()));

}

materials::~materials()
{
    delete ui;
}


void materials::ambient()
{
    QColor colorA = QColorDialog::getColor();
    if (colorA.isValid()){
   // int rgb[3];
    //colorA.getRgb(&rgb[0],&rgb[1],&rgb[2]);
ui->BotonA->setPalette(colorA);
//cout<<"el color es valido"<<endl;
    emit enviarAmbient(colorA);

    }

}

void materials::difus()
{
    QColor colorA = QColorDialog::getColor();
    if (colorA.isValid()){
   // int rgb[3];
    //colorA.getRgb(&rgb[0],&rgb[1],&rgb[2]);
ui->BotonD->setPalette(colorA);
//cout<<"el color es valido"<<endl;
    emit enviarDifus(colorA);

    }

}

void materials::specular()
{
    QColor colorA = QColorDialog::getColor();
    if (colorA.isValid()){
   // int rgb[3];
    //colorA.getRgb(&rgb[0],&rgb[1],&rgb[2]);
//cout<<"el color es valido"<<endl;
ui->BotonE->setPalette(colorA);
    emit enviarSpecular(colorA);

    }

}

void materials::shine(int sh)
{
cout<<"materials: schine : "<<sh<<endl;

    emit enviarSH(sh);



}
void materials::valida()
{

    emit validarM();
}

void materials::borrarColores()
{


ui->BotonE->setPalette(QColor(238,238,238));
ui->BotonA->setPalette(QColor(238,238,238));
ui->BotonD->setPalette(QColor(238,238,238));
    emit borrarC();
}



#ifndef MATERIALS_H
#define MATERIALS_H

#include <QWidget>
#include <QColorDialog>
#include <stdio.h>
 #include <iostream> 

namespace Ui {
    class materials;
}

class materials : public QWidget
{
    Q_OBJECT

public:
    explicit materials(QWidget *parent = 0);
    ~materials();




private:
    Ui::materials *ui;

public slots:

void ambient();
void difus();
void specular();
void shine(int sh);
void valida();
void borrarColores();


signals:
  void enviarAmbient(QColor c);
  void enviarDifus(QColor c);
  void enviarSpecular(QColor c);
  void enviarSH(int sh);
  void validarM();
  void borrarC();
  

};

#endif // MATERIALS_H


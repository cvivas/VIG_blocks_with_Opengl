#ifndef LUCES_H
#define LUCES_H

#include <QWidget>
#include <QColorDialog>
#include "../widget/luz.h"
#include "../widget/point.h"

namespace Ui {
    class luces;
}

class luces : public QWidget
{
    Q_OBJECT

public:
    explicit luces(QWidget *parent = 0);
    ~luces();

void recibirLuces(luz l[], int i);
private:
    Ui::luces *ui;
    luz* luzAct;
    luz L[8] ;

void cargarLuces();


public slots:

void ambient();
void difus();
void specular();
void borrarColores();
void borrarL();

void activarLuz( bool b );
void cambiarLuz(int index);
void actPressed(bool b);
void selectedL(bool b);


signals:
  void enviarAmbientL(QColor c);
  void enviarDifusL(QColor c);
  void enviarSpecularL(QColor c);
  void eliminaL();
  void cambiaLuz(int i);
  void activaL(int i, bool b);
  void selectL(int i,bool b);

};

#endif // LUCES_H

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QFileDialog>
#include <qtimer.h>
#include "point.h"
#include "scene.h"
#include "tupla.h"
#include "luz.h"


#include "../materials/materials.h"
#include "../luces/luces.h"


class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);

protected:

   Box ce;
    materials ventanaM;
    luces ventanaL;
    luz L[8];
    int Lsel;
    bool actL,verL;
    void initializeGL ();

    void paintGL ();
    void resizeGL (int width, int height);

    virtual void mousePressEvent (QMouseEvent *e);
    virtual void mouseReleaseEvent (QMouseEvent *e);
    virtual void mouseMoveEvent (QMouseEvent *e);
    virtual void keyPressEvent (QKeyEvent *event);
void tratarPA( void );

    double dist, anterior, posterior, radi,anglecam, ra;
    Point VRP,posicionAnterior;
    Scene scene;
    Point centro;
    QTimer timer;
	double temp2,temp3;
double znear,zfar;
float fov,aspect,h,w,angle,  angleX, angleY, angleZ,temp,orientacionAnterior;

    typedef  enum {NONE, ROTATE, ZOOM, PAN, MOVING} InteractiveAction;
    InteractiveAction DoingInteractive;

    int StopMoving,visioPA,objActiu,moviendoObjeto, collide,idff;
    int   xClick, yClick;

GLint VP[4];

std::vector<int> seleccionados;
std::vector<int> LM;
int numSeleccionados;


 void computeDefaultCamera(); 
int Seleccionar();
int Seleccionar(int x, int y);
int comprobarColision();
void undoMov(void);
void tratarBotonLoad(int i);

void enciende(int i,bool b);
void dibuixarLlum();
void enciendeSel();

 public slots:
     void LoadObject ();
     void reset(void);
 void solid();
void wired();
void help(void);
void activaPA(bool checked);
void CargaObjetocub();
void CargaDoor();
void CargaWindow();
void CargaPrisma();
void CargaPiramide();
void escalaX(int x);
void escalaY(int y);
void escalaZ(int z);
void mats();
void editaL();

void recibirAmbient(QColor c);
void recibirDifus(QColor c);
void recibirSpecular(QColor c);
void recibirShine(int sh);
void ValidarMat();
void CancelarMaterial();
void cerrarTodo();

void recibirAmbientL(QColor c);
void recibirDifusL(QColor c);
void recibirSpecularL(QColor c);
void cambiarLuz(int i);

void cerrarL();
void encen(int i, bool b);
void selectLuz(int i, bool b);
void activaLuces(bool b);

void verLuces(bool b);

 signals:

void disableLoad(bool b);
void enableLoad(void);
void setValue(int val);


  
};

#endif

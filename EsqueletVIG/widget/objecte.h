#ifndef _OBJECTE_H_
#define _OBJECTE_H_
#include <vector>
#include <stdio.h>
#include "point.h"
#include "model.h"
#include "box.h"


using namespace std;

class Objecte
{
 protected:
  std::string nom;
  int model;   // identificador del model
  Point pos;    // posicio sobre el terra
  float scale;	   // mida en unitats
  Material mats; 
  Material matsold; 
  float orientation;  //orientaci� respecte Y

 public:
  Objecte(std::string nom, int idmod, Point p, float scl, float ori);
  ~Objecte(void);
  Vector escalado;
  Vector escaladoOriginal;

 Point posAnt;

  void Render(std::vector<Model> &);
  std::string getNom();
  int getModelId();
  Point getPosition();
Point getPosAnt();


  float getScale();
  float getOrientation();
void movex(float moving);
void movey(float moving);
void movez(float moving);
void rotar(float moving);
void LimitedMovex(float moving);
void LimitedMovez(float moving);
Box& computeTransformedBox(Model &mod);
 void setPosition (Point p);
 void setPosAnt (Point p);
void setOrientation(float ori);
void RenderGL_Select(std::vector<Model> &lmodels,int i);
void RenderFilferros(std::vector<Model> &lmodels);
void RenderSeleccion(std::vector<Model> &lmodels,int i);

Vector getEscalado();
void setEscalado(Vector e);
Vector getEscaladoOriginal();
void setEscaladoOriginal(Vector e);

void ValidarMaterial(bool v);
void InitMaterial(std::vector<Model> &lmodels);
void tratarMaterial(double rgb[],int tipo);
void tratarShininess(float fsh);


};

#endif

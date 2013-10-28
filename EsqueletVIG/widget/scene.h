#ifndef _Scene_H_
#define _Scene_H_
#include "objecte.h"
#include "model.h"
#include "box.h"
#include "tupla.h"
#include <QtOpenGL/qgl.h>




class Scene
{
 private:
	
  // Tindrem un vector amb els models geomètrics dels objectes geomètrics
  // i un altre amb instàncies seves (instàncies o referències a objectes).
  std::vector<Model> lmodels;
  std::vector<Objecte> lobjectes;
  std::vector<Tupla> caida;
Box col_box;
  
  
 public:
  static MaterialLib matlib;	  // col·lecció de materials
static void transformPoint(Point &p);
void renderSeleccion();
  Scene( );

  void Init();
  void construirBase();
  void Render();
  void AddModel(Model &);
  void AddObjecte(Objecte &);

  Box CalculaEsfera (double &radi, Point &centreEscena);
int LoadObjects(string fp, string sp);
void movex(float moving);
void movez(float moving);
void movey(float moving,int idmov);
void lmovex(float moving,int objac);
void lmovez(float moving,int objac);
void rotar(float moving,int objac);
void canviarPosLim(int id,float x, float y, float z);

int comprobarColision(int idmov);
int colision(Box& bm, Box& bo);
Point posicionAnt(int objActiu);
void canviarAPos(int id,float x, float y, float z);
float orientacionAnt(int objActiu);
void setOrientation(int objActiu,float ori);
void RenderGL_Select();
void RenderFilferros(int id);
void Renderproyecto(std::vector<int> v);

void LoadModelsInit();
void LoadModelsInitFP(string sp, string fp);
int cargarObjeto(int idmod);
void eliminarSeleccionados(std::vector<int> v);
void cambiarEscalado(int idob,Vector esc,int xyz);

void Elevar(int idObj);
void Hundir(int idObj);

Point ObtenirPos(int idObj);
void SetPos(int idObj, float x, float y, float z);
void hundirTodos();
void hundirTodosMenos(std::vector<int> s);
void updateCaida(float inicio=-1.);
void hundirTodosCaidos(float inicio=-1.);

void tratarMaterial(double rgb[],int tipo,std::vector<int> s);

void tratarShine(std::vector<int> s, float fs);
void ValidarMaterial(std::vector<int> s, bool b);


void updatePosAnt (std::vector<int> s);
void undoMov(std::vector<int> s);

};

#endif


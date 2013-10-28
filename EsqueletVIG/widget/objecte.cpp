#include "objecte.h"
#include "box.h"
#include <QtOpenGL/qgl.h>
#include "scene.h"

Objecte::Objecte(std::string n, int mod, Point p, float scl, float ori):
  nom(n), model(mod), pos(p), scale(scl), orientation(ori)
{}

Objecte::~Objecte(void)
{}

void Objecte::Render(std::vector<Model> &lmodels)
{
  // Cal pintar la geometria de l'objecte transformada de la forma adequada
  float sx, sy, sz;

  Model m=lmodels[this->model];


  Box box=m.boundingBox();
  // A partir d'aqu�, cal aplicar les transformacions de model necess�ries 
  // i pintar l'objecte

  sx=box.maxb.x-box.minb.x;	
  sy=box.maxb.y-box.minb.y;	
  sz = box.maxb.z - box.minb.z;

glMatrixMode(GL_MODELVIEW); // ????????aqui hace falta=?=	
//glLoadIdentity();
  glPushMatrix();


  glTranslatef(pos.x, pos.y, pos.z); // transladamos el objeto a la posicion que toca 
/* PARA MOVER OBJETO */
  glRotatef(orientation, 0, 1, 0);


if (nom !="Base" || sx!=0 ||sy!=0 || sz!=0)  {
glScalef(escalado.x/sx, escalado.y/sy, escalado.z/sz);


}


  glTranslatef(-(box.maxb.x+box.minb.x)/2, -box.minb.y, -(box.maxb.z+box.minb.z)/2);
 

  m.Render(mats);

  glPopMatrix();
}


void Objecte::RenderGL_Select(std::vector<Model> &lmodels,int i){

  float sx, sy, sz;
  Model m=lmodels[this->model];
  Box box=m.boundingBox();
  
  sx=box.maxb.x-box.minb.x;	
  sy=box.maxb.y-box.minb.y;	
  sz = box.maxb.z - box.minb.z;

glMatrixMode(GL_MODELVIEW); 
  glPushMatrix();


  glTranslatef(pos.x, pos.y, pos.z); 
  glRotatef(orientation, 0, 1, 0);

if (nom !="Base" || sx!=0 ||sy!=0 || sz!=0)  {
glScalef(escalado.x/sx, escalado.y/sy, escalado.z/sz);
}
/*
if (nom !="Base" || sx!=0 ||sy!=0 || sz!=0)  {
   glScalef(sx,sy,sz);
  glScalef(scale/sx, scale/sy, scale/sz);
}*/
else if (nom != "Base"){
 cout <<"objecte:  no tratare a : "<< nom << "\n";

}
  glTranslatef(-(box.maxb.x+box.minb.x)/2, -box.minb.y, -(box.maxb.z+box.minb.z)/2);
 



  glPushName(i);
  m.RenderGL_Select();
  glPopName();
  glPopMatrix();
  

}

void Objecte::RenderFilferros(std::vector<Model> &lmodels){

  float sx, sy, sz;
  Model m=lmodels[this->model];
  Box box=m.boundingBox();
  
  sx=box.maxb.x-box.minb.x;	
  sy=box.maxb.y-box.minb.y;	
  sz = box.maxb.z - box.minb.z;

glMatrixMode(GL_MODELVIEW); 
  glPushMatrix();


  glTranslatef(pos.x, pos.y, pos.z); 
  glRotatef(orientation, 0, 1, 0);


if (nom !="Base" || sx!=0 ||sy!=0 || sz!=0)  {
glScalef(escalado.x/sx, escalado.y/sy, escalado.z/sz);
}

/*if (nom !="Base" || sx!=0 ||sy!=0 || sz!=0)  {
   glScalef(sx,sy,sz);
  glScalef(scale/sx, scale/sy, scale/sz);
}*/
else if (nom != "Base"){
 cout <<"objecte:  no tratare a : "<< nom << "\n";

}
  glTranslatef(-(box.maxb.x+box.minb.x)/2, -box.minb.y, -(box.maxb.z+box.minb.z)/2);
 


  m.RenderFilferros();
 
  glPopMatrix();
  

}

// Calculem la caixa transformada a partir de la caixa original
// de l'objecte.

Box& Objecte::computeTransformedBox(Model &mod)
{
/*Clave para renderizar la base*/

  Box b = mod.boundingBox();


  Box result;
  float sa, sb, sc;
  sa=b.maxb.x-b.minb.x;	
  sb=b.maxb.y-b.minb.y;	
  sc = b.maxb.z - b.minb.z;	
//cout <<"objecte: compute trans box : modelo: " << mod.namer() << " mod.bounding box max=: " << b.maxb << " y min : "  << b.minb << "\n";

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();


  glTranslatef(pos.x, pos.y, pos.z);
  glRotatef(orientation, 0, 1, 0);
  if(this->model>0) glScalef(escalado.x/sa, escalado.y/sb, escalado.z/sc);
  glTranslatef(-(b.maxb.x+b.minb.x)/2, -b.minb.y, -(b.maxb.z+b.minb.z)/2);


/*
  glTranslatef(pos.x, pos.y, pos.z);
  glRotatef(orientation, 0, 1, 0);
if ( this->model >0){
glScalef(sa,sb,sc);
  glScalef(scale/sa, scale/sb, scale/sc);} 

 glTranslatef(-(b.maxb.x+b.minb.x)/2, -b.minb.y, -(b.maxb.z+b.minb.z)/2); //revisar
*/
  vector<Vertex> &verts = mod.vertices;
  Point punt(verts[0].coord.x, verts[0].coord.y, verts[0].coord.z);
  Scene::transformPoint(punt);
  result.init(punt);

  for (unsigned int i=1; i<verts.size(); ++i)
  {
    Point punt(verts[i].coord.x, verts[i].coord.y, verts[i].coord.z);
    Scene::transformPoint(punt);
    result.update(punt);
  }
  glPopMatrix();
  return result;
}

std::string Objecte::getNom()
{
  return nom;
}

int Objecte::getModelId()
{
  return model;
}

Point Objecte::getPosition()
{
   return pos;
}

Point Objecte::getPosAnt()
{
   return posAnt;
}

float Objecte::getScale()
{
   return scale;
}

float Objecte::getOrientation()
{
   return orientation;
}

void Objecte::movex(float moving)
{
pos.x+=moving;

}

void Objecte::movey(float moving)
{

pos.y+=moving;

}

void Objecte::movez(float moving)
{

pos.z+=moving;

}
void Objecte::rotar(float moving){

orientation+=moving;
}

void Objecte::LimitedMovez(float moving)
{
float mt=pos.z+moving;
if(mt>-5 && mt<5){
pos.z+=moving;
}
if (mt<-5)pos.z=-5;
if(mt>5)pos.z=5;
//cout<< "la posicion en z es : "<<pos.z<<endl;
}

void Objecte::LimitedMovex(float moving)
{
float mt=pos.x+moving;
if(mt>-5 && mt<5){
pos.x+=moving;
}
if (mt<-5)pos.x=-5;
if(mt>5)pos.x=5;
//cout<< "la posicion en x es : "<<pos.x<<endl;
}

void Objecte::setPosition (Point p){
	pos.x=p.x;
	pos.y=p.y;
	pos.z=p.z;



}
void Objecte::setOrientation(float ori){

orientation=ori;

}

void Objecte::setPosAnt (Point p){
	posAnt.x=p.x;
	posAnt.y=p.y;
	posAnt.z=p.z;



}

void Objecte::RenderSeleccion(std::vector<Model> &lmodels,int i){

  float sx, sy, sz;
  Model m=lmodels[this->model];
  Box box=m.boundingBox();
  
  sx=box.maxb.x-box.minb.x;	
  sy=box.maxb.y-box.minb.y;	
  sz = box.maxb.z - box.minb.z;

glMatrixMode(GL_MODELVIEW); 
  glPushMatrix();


  glTranslatef(pos.x, pos.y, pos.z); 
  glRotatef(orientation, 0, 1, 0);


if (nom !="Base" || sx!=0 ||sy!=0 || sz!=0)  {
glScalef(escalado.x/sx, escalado.y/sy, escalado.z/sz);
}

// if (nom !="Base" || sx!=0 ||sy!=0 || sz!=0)  {
//    glScalef(sx,sy,sz);
//   glScalef(scale/sx, scale/sy, scale/sz);
// }
// else if (nom != "Base"){
//  cout <<"objecte:  no tratare a : "<< nom << "\n";
// 
// }
  glTranslatef(-(box.maxb.x+box.minb.x)/2, -box.minb.y, -(box.maxb.z+box.minb.z)/2);
 



  m.RenderSeleccion(i);

  glPopMatrix();
  

}


Vector Objecte::getEscalado(){

return escalado;
}
void Objecte::setEscalado(Vector e){

escalado=e;
}

Vector Objecte::getEscaladoOriginal(){

return escaladoOriginal;
}
void Objecte::setEscaladoOriginal(Vector e){

escaladoOriginal=e;
}




void Objecte::ValidarMaterial(bool v){
  if (v){
    matsold = mats;
  } else {
    mats=matsold;
  }
}


void Objecte::InitMaterial(std::vector<Model> &lmodels)
{
  Model m = lmodels[this->model];
  int mat = m.faces[0].material;
  mats = Scene::matlib.material(mat);
  matsold=mats;
// cout<<"inicializo difuse : "<<mats.kd.r<<" "<< mats.kd.g <<" "<< mats.kd.b <<" "<< mats.kd.a<<endl;

}


void Objecte::tratarMaterial(double rgb[],int tipo){

if(tipo==1){
mats.ka.r=(float)rgb[0];
mats.ka.g=(float)rgb[1];
mats.ka.b=(float)rgb[2];
}
if(tipo==2){
mats.kd.r=(float)rgb[0];
mats.kd.g=(float)rgb[1];
mats.kd.b=(float)rgb[2];
}
if(tipo==3){
mats.ks.r=(float)rgb[0];
mats.ks.g=(float)rgb[1];
mats.ks.b=(float)rgb[2];
}
// cout<<"actualizo tipo : "<<tipo<<" con color rgb: "<<rgb[0]<<" "<<rgb[1]<<" "<<rgb[2]<<" "<<endl;
}

void Objecte::tratarShininess(float fsh){
  mats.shininess = fsh;
  cout << "S = " << mats.shininess << endl;
}

#include "scene.h"
#include <math.h>
#include <algorithm>
#include "box.h"
#include "point.h"
#include "tupla.h"


MaterialLib Scene::matlib;

Scene::Scene( )
{
//tb= Box();
}

void Scene::Init()
{
  
  construirBase ();
LoadModelsInit();

}

void Scene::construirBase ()
{
  Model b("Base");

  // Construim el poligon base
  Vertex v1(Point(-5,0,-5));
  Vertex v2(Point(-5,0,5));
  Vertex v3(Point(5,0,5));
  Vertex v4(Point(5,0,-5));
  b.vertices.push_back(v1);
  b.vertices.push_back(v2);
  b.vertices.push_back(v3);
  b.vertices.push_back(v4);

  Face face(0,1,2,3);
  face.normal = Vector(0,1,0);
  face.material = 0;
  b.faces.push_back(face);
//tempoboxo=b.boundingBox();
  AddModel(b);
  Objecte oref("Base", 0, Point(0,0,0), 1, 0);// sin escala???
  AddObjecte(oref);
 //tb= b.boundingBox();
}

void Scene::Render()
{
  // Cal pintar tots els objectes de l'escena que es troben al vector
std::vector<Objecte>::iterator obj;
Box bobj;
int i =-1;
  for (obj=lobjectes.begin(); obj!=lobjectes.end(); obj++)
  {
    (*obj).Render(lmodels);
    ////////////////////////////
i++;
if(i==2) bobj=(*obj).computeTransformedBox(lmodels[(*obj).getModelId()]); //optimizable
   // bobj.Render(255,0,255);
  } 


}

void Scene::AddModel(Model &o)
{
  lmodels.push_back(o);
}

void Scene::AddObjecte(Objecte &oref)
{
  lobjectes.push_back(oref);
}

Box Scene::CalculaEsfera (double &radi, Point &centreEscena)
{
  // creem la capsa inicialment amb els v�rtexs m�nim i m�xim del terra

  Box capsaEscena(Point (0.0, 0.0, 0.0), Point (0.0, 0.0, 0.0));
  Box bobj;
  // actualitzem la capsa amb tots els objectes de l'escena

  std::vector<Objecte>::iterator obj;
  for (obj=lobjectes.begin(); obj!=lobjectes.end(); obj++)
  {
//cout << "scene: calcula Esferaaa, obj.getmodelId: " << (*obj).getModelId() << "\n";
    bobj=(*obj).computeTransformedBox(lmodels[(*obj).getModelId()]);
    capsaEscena.update(bobj.minb);
    capsaEscena.update(bobj.maxb);
  }


  centreEscena =  (capsaEscena.minb + capsaEscena.maxb)/2.;
  radi = (capsaEscena.maxb-capsaEscena.minb).length()/2.f;
/*

centreEscena.x=-(capsaEscena.maxb.x+capsaEscena.minb.x)/2.;
centreEscena.y= -capsaEscena.minb.y;
centreEscena.z=-(capsaEscena.maxb.z+capsaEscena.minb.z)/2.;
*/

//cout << "scene: Calcula esfera 89: radi "<< radi << " y el centre Escena: " << centreEscena <<"\n";

return capsaEscena;
}



void Scene::transformPoint(Point &p)
{
  GLfloat m[16];
  GLfloat p1[16];

  int i; 
  for (i=4; i<16; ++i) p1[i]=0.0f;

  p1[0] = p.x; 
  p1[1] = p.y; 
  p1[2] = p.z; 
  p1[3] = 1;

  glPushMatrix();
  glMultMatrixf(p1);
  glGetFloatv(GL_MODELVIEW_MATRIX, m);
  p.x = m[0];
  p.y = m[1];
  p.z = m[2];
  glPopMatrix();
}

void Scene::LoadModelsInit(){

/*
QString t = "../models/cub.obj";
string fp=t.toStdString();
const char *p=fp.c_str();
char *path=realpath(p,NULL);
cout <<path<<endl;*/

LoadModelsInitFP("cub","../models/cub.obj");
LoadModelsInitFP("door","../models/door.obj");
LoadModelsInitFP("prisma","../models/prisma.obj");
LoadModelsInitFP("pyramid","../models/pyramid.obj");
LoadModelsInitFP("window","../models/window.obj");


}


void Scene::LoadModelsInitFP(string sp, string fp){

Model m(sp);
const char *p=fp.c_str();
char *path=realpath(p,NULL);
m.readObj(path,matlib);
AddModel(m);


}



int Scene::cargarObjeto(int idmod){


Model m = lmodels[idmod+1];


Box bb = m.boundingBox();
float maxx,minx,maxz,minz,miny,maxy;
maxx=bb.maxb.x;
minx=bb.minb.x;
maxz=bb.maxb.z;
minz=bb.minb.z;
maxy=bb.maxb.y;
miny=bb.minb.y;

float sa = 0;
float sc = 0;
float sb=0;

if (minx <0 && maxx < 0){
sa = -minx+maxx;
}
else if (minx<0 && maxx>0){ 
sa=-minx+maxx;
}
else {sa=maxx-minx;}


if (miny <0 && maxy < 0){
sb = -miny+maxy;
}
else if (miny<0 && maxy>0){ 
sb=-miny+maxy;
}
else {sb=maxy-miny;}


if (minz <0 && maxz < 0){
sc = -minz+maxz;
}
else if (minz<0 && maxz>0){ 
sc=-minz+maxz;
}
else {sc=maxz-minz;}


  float objscalenow = 0.0;  

if (sa>sc){
objscalenow=1/sa;
}
else{
objscalenow=1/sc;
}
string sp="";
switch(idmod){

case 0:sp="cub";break;
case 1:sp="door";break;
case 2:sp="prisma";break;
case 3:sp="pyramid";break;
case 4:sp="window";break;
default:break;


}

Objecte oref(sp, idmod+1, Point(0,0,0), objscalenow, 1);// 
 oref.InitMaterial(lmodels); 
oref.setPosAnt(oref.getPosAnt());
  AddObjecte(oref);

lobjectes[lobjectes.size()-1].setEscalado(Vector(sa,sb,sc));
lobjectes[lobjectes.size()-1].setEscaladoOriginal(Vector(sa,sb,sc));

return lobjectes.size()-1;


}




void Scene::updatePosAnt (std::vector<int> s){

for(unsigned int i=0;i<s.size();i++){
//cout<<"updating:::::"<<i<<endl;
lobjectes[s[i]].setPosAnt(lobjectes[s[i]].getPosition());

}

}


void Scene::undoMov(std::vector<int> s){

for(unsigned int i=0;i<s.size();i++){

lobjectes[s[i]].setPosition(lobjectes[s[i]].getPosAnt());
Hundir(s[i]);
}


}


int Scene::LoadObjects(string fp, string sp){


Model m(sp);
const char *p=fp.c_str();
m.readObj(p,matlib);
Box bb = m.boundingBox();

std::vector<Model>::iterator it;
it=lmodels.begin();
int trobat =0;
int postrobat=0;
while (it!=lmodels.end() && trobat == 0){

if ( (*it).namer() == sp ){
 trobat =1;
 postrobat--;
}
postrobat++;
it++;
}

//cout << "scene : trobat vale : " << trobat << "\n";
//cout << "scene : postrobat vale : " << postrobat << "\n";
//cout << "scene : lobjsize vale : " << lobjectes.size() << "\n";
if (trobat == 0 ) {AddModel(m);}

float maxx,minx,maxz,minz;
maxx=bb.maxb.x;
minx=bb.minb.x;
maxz=bb.maxb.z;
minz=bb.minb.z;

float sa = 0;
float sc = 0;

if (minx <0 && maxx < 0){
sa = -minx+maxx;
}
else if (minx<0 && maxx>0){ 
sa=-minx+maxx;
}
else {sa=maxx-minx;}


if (minz <0 && maxz < 0){
sc = -minz+maxz;
}
else if (minz<0 && maxz>0){ 
sc=-minz+maxz;
}
else {sc=maxz-minz;}


  float objscalenow = 0.0;  

if (sa>sc){
objscalenow=1/sa;
}
else{
objscalenow=1/sc;
}



Objecte oref(sp, postrobat, Point(0,0,0), objscalenow, 1);// 
  
  AddObjecte(oref);

return lobjectes.size()-1;

}

void Scene::movex(float moving){

if (lobjectes.size()>0){
lobjectes[lobjectes.size()-1].movex(moving);
}

}
void Scene::movey(float moving,int idmov){

if (lobjectes.size()>0){
lobjectes[idmov].movey(moving);
}

}
void Scene::movez(float moving){

if (lobjectes.size()>0){
lobjectes[lobjectes.size()-1].movez(moving);
}

}

void Scene::rotar(float moving,int objac){


if (objac>0 && lobjectes.size()>0){
lobjectes[objac].rotar(moving);
}
}

void Scene::lmovex(float moving,int objac){

if (lobjectes.size()>0){
lobjectes[objac].LimitedMovex(moving);
}

}

void Scene::lmovez(float moving,int objac){

if (lobjectes.size()>0){
lobjectes[objac].LimitedMovez(moving);
}

}

void Scene::canviarPosLim(int id,float x, float y, float z){
	
	Point p= lobjectes[id].getPosition();
	p.x+=x;
	p.y+=y;
	p.z+=z;
if(p.x < -5 || p.x >5) p.x-=x;
if(p.z<-5 || p.z>5 ) p.z-=z;
	lobjectes[id].setPosition(p);

}

void Scene::eliminarSeleccionados(std::vector<int> v){

std::sort(v.begin(),v.end());
int temp = v.size();
 if(lobjectes.size()>1){
	for (unsigned int i=0;i<v.size();i++){
	lobjectes.erase(lobjectes.begin()+v[temp-i-1]);
	}
 }

}


int Scene::comprobarColision(int idmov){

//para saber si esta dentro,  mirar si esta incluido entre las coordenadas X y Z del objeto. 


  std::vector<Objecte>::iterator obj;
  Box bmov;
  Box bobj;
int colisiona=0;
int i=0;
if(lobjectes.size()<2) return 0;

bmov=lobjectes[idmov].computeTransformedBox(lmodels[lobjectes[idmov].getModelId()]);


  for (obj=lobjectes.begin()+1; obj!=lobjectes.end(); obj++)
  {
	i++;
  if(i!=idmov){
         //obtenemos la caja contenedora transformada y miramos si no choca con nada
	bobj=(*obj).computeTransformedBox(lmodels[(*obj).getModelId()]);
         //CalculaEsfera (radio, centro);
	colisiona=colision(bmov,bobj);
	if(colisiona>0) {
//cout <<"COLISION!!!!!!\n";
	col_box=bobj;
	return colisiona;
	
	}


	colisiona=colision(bobj,bmov);
	//if(colisiona>0) {cout <<"COLISION!!!!!!\n";return colisiona;}
    }
  }

return 0;
}

int Scene::colision(Box& bm, Box& bo){

if(bo.minb.x >= bm.minb.x && bo.maxb.x<= bm.maxb.x &&
	bo.minb.y>=bm.minb.y && bo.maxb.y<=bm.maxb.y &&
	bo.minb.z>=bm.minb.z && bo.maxb.z<=bm.maxb.y)
{
return 1;
}
if(bm.maxb.x < bo.minb.x || bm.minb.x>bo.maxb.x) { return 0;} 
if(bm.maxb.y < bo.minb.y || bm.minb.y>bo.maxb.y) { return 0;} 
if(bm.maxb.z < bo.minb.z || bm.minb.z>bo.maxb.z) { return 0;} 

return 2;
}

Point Scene::posicionAnt(int objActiu){
if(objActiu<0) return Point(0.,0.,0.);
return lobjectes[objActiu].getPosition();

}
float Scene::orientacionAnt(int objActiu){
if(objActiu<0) return 0.;
return lobjectes[objActiu].getOrientation();

}

void Scene::canviarAPos(int id,float x, float y, float z){
	
	Point p= Point (x,y,z);
	lobjectes[id].setPosition(p);

}

void Scene::setOrientation(int objActiu,float ori){
if(objActiu>0) 
return lobjectes[objActiu].setOrientation(ori);

}

void Scene::RenderFilferros(int id){

Render();
if(id>=1){
Box bobj;
	lobjectes[id].RenderFilferros(lmodels);
//cout <<" vamos a pintar la caja del " << id << " a ver si se pinta \n";
   bobj=lobjectes[id].computeTransformedBox(lmodels[lobjectes[id].getModelId()]);
  	  bobj.Render(255,0,255);
}
	
}


void Scene::Renderproyecto(std::vector<int> v){

Render();
int temp=v.size();
if(temp>=1){
int i =0;

	while(i<temp){
		int id = v[i];
		Box bobj;
		lobjectes[id].RenderFilferros(lmodels);
		//cout <<" vamos a pintar la caja del " << id << " a ver si se pinta \n";
   		bobj=lobjectes[id].computeTransformedBox(lmodels[lobjectes[id].getModelId()]);
  	  	bobj.Render(255,0,255);
		i++;
	}
}
	
}




void Scene::RenderGL_Select()
{
  // Cal pintar tots els objectes de l'escena que es troben al vector
std::vector<Objecte>::iterator obj;

int i =0;
  for (obj=lobjectes.begin(); obj!=lobjectes.end(); obj++)
  {
    (*obj).RenderGL_Select(lmodels,i);

i++;

  } 


}

void Scene::renderSeleccion(){

std::vector<Objecte>::iterator obj;

int i =0;

  for (obj=lobjectes.begin(); obj!=lobjectes.end(); obj++)
  {
    (*obj).RenderSeleccion(lmodels,i);

i++;

  } 

}

void Scene::Elevar(int idObj) {

  while(comprobarColision(idObj)!=0){

Point p=col_box.maxb;
Point p2=ObtenirPos(idObj);
SetPos(idObj,p2.x,p.y+0.0001,p2.z);
    //movey(0.06,idObj);

  }


}

Point Scene::ObtenirPos(int idObj){
  return lobjectes[idObj].getPosition();
}

void Scene::SetPos(int idObj, float x, float y, float z) {
  Point p;
  p.x = x;
  p.y = y;
  p.z = z;
  lobjectes[idObj].setPosition(p);
}

void Scene::Hundir(int idObj) {
  if (ObtenirPos(idObj).y > 0) {
//cout<<"hundimos"<<endl;
    SetPos(idObj, ObtenirPos(idObj).x, 0.000001, ObtenirPos(idObj).z);
  }
Elevar(idObj);
}


void Scene::hundirTodos(){
std::vector<Objecte>::iterator obj;
int t=1;
  for (obj=lobjectes.begin()+1; obj!=lobjectes.end(); obj++)
  {
//cout << "scene: calcula Esferaaa, obj.getmodelId: " << (*obj).getModelId() << "\n";
   
    Hundir(t);
t++;
  }


}

void Scene::hundirTodosMenos(std::vector<int> s){
std::vector<Objecte>::iterator obj;
int t=1;
  for (obj=lobjectes.begin()+1; obj!=lobjectes.end(); obj++)
  {
//cout << "scene: calcula Esferaaa, obj.getmodelId: " << (*obj).getModelId() << "\n";
   std::vector<int>::iterator found;
found=std::find(s.begin(),s.end(),t);
if(found==s.end())  Hundir(t);
t++;
  }

}

void Scene::updateCaida(float inicio){

  for (unsigned int t=1; t<lobjectes.size(); t++)
  {
float temp = ObtenirPos(t).y;
if(temp>inicio) caida.push_back(Tupla(t,temp));
  }
std::sort(caida.begin(),caida.end());

//if(inicio>-1.)std::reverse(caida.begin(),caida.end());
}

void Scene::cambiarEscalado(int idob,Vector esc,int xyz){

//cout<<"el vector esc tiene:" <<esc<<endl;

Vector t = lobjectes[idob].getEscaladoOriginal();

lobjectes[idob].setEscalado(lobjectes[idob].getEscalado().escalaVec(t,esc,xyz));
//hundirTodosCaidos(ObtenirPos(idob).y);
if(xyz==2)hundirTodosCaidos(ObtenirPos(idob).y);
else{
Hundir(idob);
hundirTodosCaidos();
}

}



void Scene::hundirTodosCaidos(float inicio){
std::vector<Tupla>::iterator obj;
int t=0;
caida.clear();
updateCaida(inicio);
//if(inicio>-1.)cout<<"scene: orden de caidos: "<<endl;
   if(inicio>-1.) { for (obj=caida.begin(); obj!=caida.end(); obj++) movey(20.,(*obj).idO);}
  for (obj=caida.begin(); obj!=caida.end(); obj++)
  {
   t=(*obj).idO;
//if(inicio>-1.) movey(20.,t);
 	Hundir(t);
// cout << (*obj).idO<<" ";
  }
//cout<<endl;


}



void Scene::tratarMaterial(double rgb[],int tipo,std::vector<int> s){

for(unsigned int i=0;i<s.size();i++) lobjectes[s[i]].tratarMaterial(rgb,tipo);


}



void Scene::tratarShine(std::vector<int> s, float fs){

for(unsigned int i=0;i<s.size();i++) lobjectes[s[i]].tratarShininess(fs);

}

void Scene::ValidarMaterial(std::vector<int> s, bool b){
for(unsigned int i=0;i<s.size();i++) lobjectes[s[i]].ValidarMaterial(b);
}

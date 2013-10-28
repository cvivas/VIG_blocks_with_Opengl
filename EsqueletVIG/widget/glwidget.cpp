#include "glwidget.h"
#include <math.h>
#include <algorithm>
#include "../materials/materials.h"
#include "../luces/luces.h"
#include "luz.h"
#include "GL/glu.h"
#define pi 3.141592654
//Carlos Vivas Abilahoud 
GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
setFocusPolicy(Qt::StrongFocus);
 connect( &timer, SIGNAL(timeout()), this, SLOT(updateGL()) );
connect(&ventanaM,SIGNAL(enviarAmbient(QColor)),this,SLOT(recibirAmbient(QColor)));
connect(&ventanaM,SIGNAL(enviarDifus(QColor)),this,SLOT(recibirDifus(QColor)));
connect(&ventanaM,SIGNAL(enviarSpecular(QColor)),this,SLOT(recibirSpecular(QColor)));
connect(&ventanaM,SIGNAL(validarM()),this,SLOT(ValidarMat()));
connect(&ventanaM,SIGNAL(borrarC()),this,SLOT(CancelarMaterial()));
connect(&ventanaM,SIGNAL(enviarSH(int )), this,SLOT(recibirShine(int )));


connect(&ventanaL,SIGNAL(enviarAmbientL(QColor)),this,SLOT(recibirAmbientL(QColor)));
connect(&ventanaL,SIGNAL(enviarDifusL(QColor)),this,SLOT(recibirDifusL(QColor)));
connect(&ventanaL,SIGNAL(enviarSpecularL(QColor)),this,SLOT(recibirSpecularL(QColor)));
connect(&ventanaL,SIGNAL(eliminaL()),this,SLOT(cerrarL()));
connect(&ventanaL,SIGNAL(cambiaLuz(int )),this,SLOT(cambiarLuz(int )));
connect(&ventanaL,SIGNAL(activaL(int,bool )),this,SLOT(encen(int,bool )));
connect(&ventanaL,SIGNAL(selectL(int,bool )),this,SLOT(selectLuz(int,bool )));

  timer.start(0);
temp=1.0;
temp2=10;
temp3=0;
StopMoving=0;
help();
visioPA=0;
objActiu=-1;
moviendoObjeto=0;
collide=0;
idff=-1;
for (int o=0;o<8;o++) {
L[o]=luz(o);
L[o].initLuz();
}
numSeleccionados=0;
LM.clear();

Lsel=0;

actL=true;
verL=true;
 glGetIntegerv(GL_VIEWPORT, VP);
//cout<<"los valores del VP al principio son: " << VP[0]<<VP[1]<<VP[2]<<VP[3] <<endl;
//resizeGL(129,100);
}


// initializeGL() - Aqui incluimos inicialitzaciones del contexto grafico.

void GLWidget::initializeGL()
{
L[0].setPos(Point(0.,1.,0.));
//L[1].setPos(Point(3.,3.,3.));
  glClearColor(0.4f, 0.4f, 0.8f, 1.0f);
//L[2].setPos(Point(4.,4.,4.));
    glEnable(GL_DEPTH_TEST); //activem zbuffer
    glEnable(GL_CULL_FACE); //activem el back face culling
  glEnable(GL_NORMALIZE); 

  glEnable(GL_LIGHTING); //activem la iluminacio
//   glEnable(GL_LIGHT0);
//   glEnable(GL_LIGHT1);
//   GLfloat pos0[4] = {0., 1., 0., 1.}; //sempre per sobre del poligon base
//   glLightfv(GL_LIGHT0, GL_POSITION, pos0);

enciende(0,true);
 enciende(1,true);

//   glPushMatrix();
//   GLfloat pos1[4] = {0., 0., 0., 1.};
//   glLightfv(GL_LIGHT1, GL_POSITION, pos1);
//   glPopMatrix();
// 
//   GLfloat va1[4] = {1, 1, 1, 1};
//   GLfloat vd1[4] = {1, 1, 1, 1};
//   GLfloat vs1[4] = {1, 1, 1, 1};
// 
//   glLightfv(GL_LIGHT0, GL_AMBIENT, va1);
//   glLightfv(GL_LIGHT0, GL_DIFFUSE, vd1);
//   glLightfv(GL_LIGHT0, GL_SPECULAR, vs1);



  scene.Init();
 computeDefaultCamera();
}

void GLWidget::computeDefaultCamera()
{
  // definir camara incial

  angleX = -15;
  angleY = 30;
  angleZ = 0;


  ce = scene.CalculaEsfera(radi,centro); 

  //double pi= 3.141592654;
//2.4...
dist=(2.0)*radi;
  angle = (float)atan(radi/dist)*(180/pi);//poner valores
  //fov=2*angle;
//cout << " el angulo es : " << angle << "\n";
//dist = 1.65*radi;

fov=2*angle;
  znear=radi;
  zfar=radi*6;
 // zfar= radi*temp;

  h=1.;
  w=1.;
  aspect=(float)w/h;

//aspect = 1.29;

  VRP = centro;

  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity();
  gluPerspective(fov,aspect,znear,zfar);
 
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-dist);
  glRotatef(angleX,1,0,0);
  glRotatef(angleY,0,1,0);
  glRotatef(angleZ,0,0,1);
  glTranslatef(-VRP.x,-VRP.y,-VRP.z);


//cout << " glwidget aspect vale : " << aspect << "\n";

}

void GLWidget::resizeGL (int width, int height)
{
  
  //glViewport (0, 0, width, height);
float minim;
   
    if (width > height) minim = height;
    else minim = width;
   
    //if(visioPA==0)glViewport ((width-minim)/2, (height-minim)/2, minim, minim);
  if(!visioPA)glViewport ((width-minim)/2, (height-minim)/2, minim, minim);
if(visioPA)glViewport ((width-minim)/4,(height)/4, minim/2, minim/2);

}

void GLWidget::paintGL( void )
{
if(visioPA==0){
  // Esborrem els buffers
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


	
        glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	//glOrtho(wminx, wmaxx, wminy, wmaxy, anterior, posterior);   
	gluPerspective(fov,aspect,znear,zfar);

  	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(0,0,-(2.2)*radi);
dist=(2.2)*radi;
        glTranslatef(0,0,-dist);

	glRotatef(-angleX,1,0,0);
	glRotatef(-angleY,0,1,0);
	glRotatef(-angleZ,0,0,1);
	
	glTranslatef(-VRP.x,-VRP.y,-VRP.z);




  // dibuixar eixos aplicacio
  glDisable(GL_LIGHTING);
  glBegin(GL_LINES);
  glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(20,0,0); // X
  glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,20,0); // Y
  glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,20); // Z
  glEnd();
glColor3fv(L[0].ambient);

 if(actL)glEnable(GL_LIGHTING);

/*if(L[Lsel].act)*/
if(StopMoving==1 && moviendoObjeto==0){idff=-1;}
else{idff=objActiu;}
//scene.RenderFilferros(idff);

}
else{
tratarPA();
//resizeGL (size().width(), size().height());
}
if(verL)dibuixarLlum();
scene.Renderproyecto(seleccionados);
//if(StopMoving==1 && moviendoObjeto==0){idff=-1;}
//else{idff=objActiu;}

  //scene.Render();
//scene.RenderFilferros(idff);
}


void GLWidget::tratarPA( void ){


double rad=radi;
//Box ce = scene.CalculaEsfera(rad,center);
int h,w;
h=size().height();
w=size().width();
float minim;
   
    if (w> h) minim = h;
    else minim = w;


 	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
//cout << "valores de la esfera: radio: "<<rad<<" y centro x:"<<ce.minb.x<<" "<<ce.maxb.x<< " y ahora Z : " << ce.minb.z<< " " <<ce.maxb.z<<endl;

//Vista izquierda

//viewport: (x int, y int, GLsizei width, GLsizei height).
//--->lower left corner --> (x,y)
	//glViewport (0, 0,  size().width()/2,size().height());
	glViewport (0,0, w/2, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(ce.minb.x,ce.maxb.x,ce.minb.z,ce.maxb.z,znear,-zfar);
	//temp=7,1,temp2==11.8
	
//ortho--> left, Right,Botton,Top,near,far -->todo GLdouble
	//glOrtho(ce.minb.x*temp,ce.maxb.x*temp,ce.maxb.z*2.15,ce.minb.z*2.15,-rad,rad);

	//glOrtho(rad,-rad,ce.maxb.z*2.15,ce.minb.z*2.15,-rad*2.,rad);//BACKUP
	glOrtho(ce.maxb.z*1.2,ce.minb.z*1.2,ce.maxb.z*2.15,ce.minb.z*2.15,-rad*2.,rad);
	glRotatef(90,1,0,0);
	glRotatef(180,0,1,0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_DEPTH_BUFFER_BIT);
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
  	glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(20,0,0); // X
  	//glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,20,0); // Y
  	glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,20); // Z

  	glEnd();
glColor3fv(L[0].ambient);
if(actL)glEnable(GL_LIGHTING);
	if(StopMoving==1 && moviendoObjeto==0){idff=-1;}
	else{idff=objActiu;}
if(verL)dibuixarLlum();
scene.Renderproyecto(seleccionados);
	//scene.RenderFilferros(idff);
	
	


//Vista derecha
	
	glViewport (w/2,0, w/2, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(rad,-rad,ce.maxb.z*2,ce.minb.z*2,-rad,rad);//backup
	//glOrtho(rad,-rad,ce.maxb.z*2.,ce.minb.z*2.,-rad,rad);//HACER CON LA CAJA CONTENEDORA !!!
	glOrtho(ce.maxb.z*2.,ce.minb.z*2.,rad*2.1,-rad*2.1,-rad,rad);
	
	glRotatef(180,1,0,0);
	glRotatef(180,0,1,0);
	
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_DEPTH_BUFFER_BIT);
glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
  	glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(20,0,0); // X
  	glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,20,0); // Y
  	glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,20); // Z
  	glEnd();
glColor3fv(L[0].ambient);
if(actL)glEnable(GL_LIGHTING);
	if(StopMoving==1 && moviendoObjeto==0){idff=-1;}
	else{idff=objActiu;}
	//scene.RenderFilferros(idff);
	



  
}
	


void GLWidget::mousePressEvent( QMouseEvent *e)
{
  xClick = e->x();
  yClick = e->y();

  if (e->button()&Qt::LeftButton &&
      ! (e->modifiers()&(Qt::ShiftModifier|Qt::AltModifier|Qt::ControlModifier)))
  {
    if(visioPA==0){DoingInteractive = ROTATE;}
  }
else if ( e->button()&Qt::MidButton )
  {
	if(visioPA==0){
	  int seleccionat=Seleccionar(xClick,yClick);
	   if (seleccionat>0) 
	   { 
//cout <<" Hemos seleccionado al : "<<seleccionat << "\n";
		objActiu=seleccionat;
		tratarBotonLoad(0);
		StopMoving=0;
		moviendoObjeto=1;
		posicionAnterior=scene.posicionAnt(objActiu);
		orientacionAnterior=scene.orientacionAnt(objActiu);
		scene.RenderFilferros(objActiu);
		glFlush();
		
	   }
	}
	   
  }  

  else if (e->button()&Qt::LeftButton &&  e->modifiers() & Qt::AltModifier && e->modifiers() & Qt::ShiftModifier )
  {
    {DoingInteractive = MOVING;}
  }
  else if (e->button()&Qt::LeftButton &&  e->modifiers() &Qt::ShiftModifier && ! (e->modifiers()&(Qt::AltModifier|Qt::ControlModifier)))
  {
    if(visioPA==0){DoingInteractive = ZOOM;}

  }
  else if ((e->button()&Qt::LeftButton &&  e->modifiers() &Qt::ControlModifier)&&  ! (e->modifiers()&(Qt::ShiftModifier|Qt::AltModifier) ))
  {
     if(visioPA==0){ DoingInteractive = PAN;}
  }
  else if (e->button()&&Qt::RightButton){
	
	if(objActiu>0 && StopMoving==0){
       		collide= comprobarColision();
		if(collide==0){
		//cout <<"ninguna colisison\n";
		StopMoving=1;
		objActiu=-1;
		scene.updatePosAnt(seleccionados);
		seleccionados.clear();
		emit setValue(100);
		}
		else{
		//cout<< "hay colision con otro objeto"<<endl;
		}
	}
  }
 
}

void GLWidget::keyPressEvent(QKeyEvent *e)
{
  switch (e->key())
  {
    case Qt::Key_F:

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        updateGL();
        break;
    case Qt::Key_S:

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        updateGL();
        break;


    case Qt::Key_Z:
        if(StopMoving==0){
	if (e->modifiers() &Qt::ShiftModifier){ for(unsigned int t=0;t<seleccionados.size();t++){scene.lmovez(0.2,seleccionados[t]);scene.Hundir(seleccionados[t]);}}
	else{for(unsigned int t=0;t<seleccionados.size();t++){scene.lmovez(-0.2,seleccionados[t]);scene.Hundir(seleccionados[t]);}}
        scene.hundirTodosCaidos();
	/*for(unsigned int t=0;t<seleccionados.size();t++){	
	  if(scene.comprobarColision(seleccionados[t])!=0){
		scene.Elevar(seleccionados[t]);
		}
else {scene.Hundir(seleccionados[t]);}
	}*/
	

	updateGL();
	}
        break;
    case Qt::Key_X:
        if(StopMoving==0){
        if (e->modifiers() &Qt::ShiftModifier){for(unsigned int t=0;t<seleccionados.size();t++){ scene.lmovex(0.2,seleccionados[t]);scene.Hundir(seleccionados[t]);}}
	else{for(unsigned int t=0;t<seleccionados.size();t++){scene.lmovex(-0.2,seleccionados[t]);scene.Hundir(seleccionados[t]);}}

	scene.hundirTodosCaidos();
	/*for(unsigned int t=0;t<seleccionados.size();t++){	
	  if(scene.comprobarColision(seleccionados[t])!=0){
		scene.Hundir(seleccionados[t]);
		}
	  else {scene.Hundir(seleccionados[t]);}
	}*/
        updateGL();
	}
        break;
    case  '?'  :  help();
        break;

    case  Qt::Key_H  :  help();
        break;

 case Qt::Key_Escape:
        
	undoMov();

        updateGL();
	break;

case Qt::Key_E:

       for(unsigned int t=0;t<seleccionados.size();t++){ scene.rotar(7.,seleccionados[t]);}
//cout << "esquerra\n";
        updateGL();
        break;

case Qt::Key_D:

       for(unsigned int t=0;t<seleccionados.size();t++){ scene.rotar(-7.,seleccionados[t]);}
//cout << "Dreta\n";
        updateGL();
        break;

case Qt::Key_Delete:

        scene.eliminarSeleccionados(seleccionados);
	scene.hundirTodos();
	seleccionados.clear();
	objActiu=-1;
        updateGL();
        break;

case Qt::Key_T:


	for(unsigned int t=0;t<LM.size();t++){
	  L[LM[t]].setPos(Point(L[LM[t]].posL.x, L[LM[t]].posL.y+0.2, L[LM[t]].posL.z));

	}
enciendeSel();
        updateGL();
        break;
case Qt::Key_Y:
	for(unsigned int t=0;t<LM.size();t++){
	  L[LM[t]].setPos(Point(L[LM[t]].posL.x, L[LM[t]].posL.y-0.2, L[LM[t]].posL.z));

	}
enciendeSel();
        updateGL();
        break;

    default: e->ignore();




  }
}

void GLWidget::mouseReleaseEvent( QMouseEvent *)
{
  if(DoingInteractive==MOVING) scene.hundirTodosCaidos(); 

  DoingInteractive = NONE;
}

void GLWidget::mouseMoveEvent(QMouseEvent *e)
{
  // Aqui cal que es calculi i s'apliqui la rotaci, el zoom o el pan
  // com s'escaigui...
  if (DoingInteractive == ROTATE)
  {
    // Fem la rotacio
   angleY += 3*(float((e->x()-xClick)))/4;
   angleX += 3*(float((e->y()-yClick)))/4;
//cout << "angulo X : " << angleX << "  Angulo Y: " << angleY << "  Angulo Z: " << angleZ<< " \n";

  }
  else if (DoingInteractive == ZOOM)
  {
    // Fem el zoom

 float incremento = e->y()-yClick;
      fov += incremento*0.1;
      if (fov < 1) {fov=1; }
      if (fov >179) {fov=179;}

  }
  else if (DoingInteractive==PAN)
  {
    // Fem el pan
 	float m[4][4];
	glGetFloatv(GL_MODELVIEW_MATRIX,&m[0][0]);
	Point Xobs (m[0][0],m[1][0],m[2][0]);
	Point Yobs (m[0][1],m[1][1],m[2][1]);
	
	float valX = xClick - e->x();
	float valY = yClick - e->y();

	VRP += ((valX * Xobs) - (valY * Yobs)) * 0.025;

  }
else if (DoingInteractive==MOVING && (objActiu>0 || LM.size()>0))
  {


	float m[4][4];
	glGetFloatv(GL_MODELVIEW_MATRIX,&m[0][0]);
	Point Xobs (m[0][0],m[1][0],m[2][0]);
	Point Zobs (m[0][2],m[1][2],m[2][2]);
	
	float valXsel = e->x() - xClick;
	float valZsel = e->y() - yClick;
	
		
	Point pos = Point (0.,0.,0.);
	Point cross = Point (0,1,0);
	cross= Xobs*cross;
	pos += ((valXsel * Xobs) + (valZsel * ( cross )))* 0.04;

	//pos += ((valXsel * Xobs) + (valZsel * ( Zobs )))* 0.04;
        float tmpz=angleX;;
	
	float adeZ = fmod(tmpz,360.);
	//if(visioPA==0)pos.z=-pos.z;
	
	if(( (adeZ>0 && adeZ<180)  || 
	     (adeZ>-360 && adeZ<-180) ))
	{ pos.z=-pos.z;}

    if(objActiu>0){



	for(unsigned int t=0;t<seleccionados.size();t++){
	  scene.canviarPosLim(seleccionados[t], pos.x, 0., pos.z);
	scene.Hundir(seleccionados[t]);

	}



	}

else{

	for(unsigned int t=0;t<LM.size();t++){
	  L[LM[t]].setPos(Point(L[LM[t]].posL.x+pos.x, L[LM[t]].posL.y, L[LM[t]].posL.z+pos.z));

	}
enciendeSel();

	}
	glFlush();



  

}
  xClick = e->x();
  yClick = e->y();

}

void GLWidget::CargaObjetocub(){


 objActiu=scene.cargarObjeto(0);
seleccionados.push_back(objActiu);
//seleccionados[numSeleccionados]=objActiu;
//numSeleccionados++;
StopMoving=0;
moviendoObjeto=1;
if(scene.comprobarColision(objActiu)!=0){
	scene.Elevar(objActiu);
}
}
void GLWidget::CargaDoor(){


 objActiu=scene.cargarObjeto(1);
seleccionados.push_back(objActiu);
StopMoving=0;
moviendoObjeto=1;
if(scene.comprobarColision(objActiu)!=0){
	scene.Elevar(objActiu);
}

}
void GLWidget::CargaPrisma(){


 objActiu=scene.cargarObjeto(2);
seleccionados.push_back(objActiu);
StopMoving=0;
moviendoObjeto=1;
if(scene.comprobarColision(objActiu)!=0){
	scene.Elevar(objActiu);
}
}
void GLWidget::CargaPiramide(){


 objActiu=scene.cargarObjeto(3);
seleccionados.push_back(objActiu);
StopMoving=0;
moviendoObjeto=1;
if(scene.comprobarColision(objActiu)!=0){
	scene.Elevar(objActiu);
}

}
void GLWidget::CargaWindow(){


 objActiu=scene.cargarObjeto(4);
seleccionados.push_back(objActiu);
StopMoving=0;
moviendoObjeto=1;
if(scene.comprobarColision(objActiu)!=0){
	scene.Elevar(objActiu);
}
/*cout <<"el obj activo es : "<<objActiu<<endl;
for (int i=0;i<seleccionados.size();i++){
cout<<seleccionados[i]<<endl;
}
*/
}






void GLWidget::LoadObject()
{
  QString model = QFileDialog::getOpenFileName(this, tr("Open File"), "../data", tr("Objectes (*.obj)")); 
  if (model != "")
  {
    // Aquí cal fer el codi per a carregar el model escollit

	string filePath = model.toStdString();
QString separator = "/";
QChar ch = '/';
int postemp = model.lastIndexOf(ch);
//cout << " LA posicion del ultimo slash es : " <<postemp <<"\n";
QString r = model.remove(0,postemp+1);
string sinPath = r.toStdString();

	objActiu=scene.LoadObjects(filePath,sinPath);

StopMoving=0;
moviendoObjeto=1;
posicionAnterior=scene.posicionAnt(objActiu);
orientacionAnterior=scene.orientacionAnt(objActiu);

tratarBotonLoad(0);
//cout << "EL NOMBRE DEL MODELO Q CARGAMOS ES : " << filePath << "\n";
//cout << "EL NOMBRE DEL MODELO R E L A T I V O Q CARGAMOS ES : " << file2 << "\n";
//cout << "ELparametro es :  std es: : " << model[7] << "\n";
  }
}

void GLWidget::reset(){

computeDefaultCamera();
}
void GLWidget::solid(){

glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        updateGL();
}
void GLWidget::wired(){

glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        updateGL();
}

void GLWidget::help( void ){
  cout<<"Teclas Definidas: \n";
  cout<<"Middle Button      Select object\n";
  cout<<"Right  Button      Deselect \n";
  cout<<"f                  Draw in Wireframe\n";
  cout<<"s                  Draw as Solid\n";
  cout<<"x/X                Move +/- X\n";
  cout<<"z/Z                Move +/- Z\n";
  cout<<"D/E                Rotate object\n";
  cout<<"?/h                Print Help\n";
  cout<<"Shift+click        Zoom\n";
  cout<<"Ctrl+click         PAN\n";
  cout<<"t/y                Move selected lights height\n";
  cout<<"ESCAPE		    Disable selection and return objects\n";
  cout<<"Shift+Alt+Raton    Move elements (if lights are not selected)\n";
  cout<<" To select the lights, go to \"Luces\" menu and click \"Seleccionar\" \n";

  

}

void GLWidget::activaPA(bool checked){

if(checked){
//cout<< " activo PA \n";
visioPA=1;
//cout<<" PA los valores del VP son: " << VP[0]<<VP[1]<<VP[2]<<VP[3] <<endl;
}
else{
//cout<< " desactivo PA \n";
visioPA=0;
//cout<<"NO PA los valores del VP son: " << VP[0]<<VP[1]<<VP[2]<<VP[3] <<endl;
//glViewport(VP[0], VP[1], VP[2],VP[3]);
resizeGL (size().width(), size().height());

}

}

int GLWidget::comprobarColision(){

 return scene.comprobarColision(objActiu);


}

void GLWidget::undoMov(){

//cout<< "deshaciendo mov: posAnt vale: " <<  posicionAnterior.x << "  " <<posicionAnterior.y << "  "<< posicionAnterior.z << "\n" ;

//scene.canviarAPos(objActiu, posicionAnterior.x, posicionAnterior.y, posicionAnterior.z); 
//scene.setOrientation(objActiu,orientacionAnterior);
scene.undoMov(seleccionados);
seleccionados.clear();

glFlush();
StopMoving=1;
objActiu=-1;
}




int GLWidget::Seleccionar(int x, int y)
{
/*
if(objActiu>0){ 

cout << "se ha de terminar de posicionar el objeto activo antes de seleccionar otro"<<endl;
return -1;}*/
glDisable(GL_LIGHTING);
//pintar todo colores diff
//detectar color pixel
//color pixel --> id
//pintar normalmente.

//GLint vp[4];
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
GLubyte id[3];
scene.renderSeleccion();
//glGetIntegerv(GL_VIEWPORT,vp);
glReadPixels(x, size().height()-y,1,1,GL_RED,GL_UNSIGNED_BYTE,(void *)id);
//glReadPixels(x, vp[3]-y,1,1,GL_RED,GL_UNSIGNED_BYTE,(void *)id);
 //comprobar
int tt=id[0];
//cout <<"EL ID DEL OBJETO ES :  R: " <<id[0] <<" G: "<< id[1] << " Blue: "<<id[2] <<" TODO: "  << tt<< " \n";

glFlush();
glEnable(GL_LIGHTING);
if(tt==102) return-1;
if(tt<1) return -1;

std::vector<int>::iterator found;
found=std::find(seleccionados.begin(),seleccionados.end(),id[0]);
if(found==seleccionados.end()) seleccionados.push_back(id[0]);
//seleccionados[numSeleccionados]=id[0];
numSeleccionados++;
return id[0];
}



void GLWidget::escalaX(int x){

	for(unsigned int t=0;t<seleccionados.size();t++){
	  scene.cambiarEscalado(seleccionados[t],Vector(x/100.,1,1),1); 
	}

}
void GLWidget::escalaY(int y){

	for(unsigned int t=0;t<seleccionados.size();t++){
	  scene.cambiarEscalado(seleccionados[t],Vector(1,y/100.,1),2); 
	}

}
void GLWidget::escalaZ(int z){

	for(unsigned int t=0;t<seleccionados.size();t++){
	  scene.cambiarEscalado(seleccionados[t],Vector(1,1,z/100.),3); 
	}

}

void GLWidget::tratarBotonLoad(int i){

if(i==0){
emit disableLoad(false);
}
else emit disableLoad(true);

}

void GLWidget::mats(){

ventanaM.show();

}






void GLWidget::recibirAmbient(QColor c){

    qreal rgb[4];
    c.getRgbF(&rgb[0],&rgb[1],&rgb[2],&rgb[3]);
/*cout<<"el color en qreals es : r: "<<rgb[0]<<" "<<rgb[1]<<" "<<rgb[2]<<" "<<endl;
cout<<"el color en floats es : r: "<<(float)rgb[0]<<" "<<(float)rgb[1]<<" "<<(float)rgb[2]<<" "<<endl;
int rgb2[4];
    c.getRgb(&rgb2[0],&rgb2[1],&rgb2[2],&rgb2[3]);
cout<<"el color en int es : r: "<<rgb2[0]<<" "<<rgb2[1]<<" "<<rgb2[2]<<" "<<endl;*/

scene.tratarMaterial(rgb,1,seleccionados);
  updateGL();

}




void GLWidget::recibirDifus(QColor c){

    qreal rgb[4];
    c.getRgbF(&rgb[0],&rgb[1],&rgb[2],&rgb[3]);
scene.tratarMaterial(rgb,2,seleccionados);
  updateGL();

}

void GLWidget::recibirSpecular(QColor c){

    qreal rgb[4];
    c.getRgbF(&rgb[0],&rgb[1],&rgb[2],&rgb[3]);
scene.tratarMaterial(rgb,3,seleccionados);
  updateGL();

}


void GLWidget::recibirShine(int sh){

  //cout << "Component Shininess = " << sh << endl;
  float fs = (float)sh;
  scene.tratarShine(seleccionados, fs);
  updateGL();

}

void GLWidget::ValidarMat(){
  scene.ValidarMaterial(seleccionados, true);
  updateGL();
}

void GLWidget::CancelarMaterial(){

  scene.ValidarMaterial(seleccionados, false);
  updateGL();
}

void GLWidget::cerrarTodo(){

cout<<"See You Next Time !!"<<endl;
ventanaM.close();
ventanaL.close();
}




void GLWidget::editaL(){


//cout<<"envio luces y l 0 vale: "<<L[0].act<<endl;
ventanaL.show();

ventanaL.recibirLuces(L,Lsel);
}


void GLWidget::cerrarL(){
//cout<<"cierro L"<<endl;
// ventanaL.borrarColores();
//ventanaL.close();
}

void GLWidget::recibirAmbientL(QColor c){

L[Lsel].setADS(c,1);
enciende(Lsel,L[Lsel].act);
ventanaL.recibirLuces(L,Lsel);
//cout<<"recibo la luz amb "<<L[Lsel].ambient[0]<<endl;
  updateGL();

}

void GLWidget::recibirDifusL(QColor c){

L[Lsel].setADS(c,2);
enciende(Lsel,L[Lsel].act);
ventanaL.recibirLuces(L,Lsel);
  updateGL();

}

void GLWidget::recibirSpecularL(QColor c){

L[Lsel].setADS(c,3);
enciende(Lsel,L[Lsel].act);
ventanaL.recibirLuces(L,Lsel);
  updateGL();

}

void GLWidget::enciende(int i,bool b){

L[i].act=b;
// cout<<" la luz en "<<i<<" vale "<<b<<endl;
// cout<<" la luz en 0:   "<<L[0].act<<endl;
// cout<<" la luz en 1:   "<<L[1].act<<endl;
// cout<<" la luz en 2:   "<<L[2].act<<endl;

//  int gl=GL_LIGHT0;
if(!b) {glDisable(GL_LIGHT0+i);}
else{glEnable(GL_LIGHT0+i);
glLightfv(GL_LIGHT0+i, GL_AMBIENT,L[i].ambient);
glLightfv(GL_LIGHT0+i, GL_DIFFUSE, L[i].difus);
glLightfv(GL_LIGHT0+i, GL_SPECULAR, L[i].specular);
glPushMatrix();
glLoadIdentity();
glLightfv(GL_LIGHT0+i, GL_POSITION, L[i].posicio);	
glPopMatrix();
}
}

void GLWidget::enciendeSel(){

for(unsigned int j=0;j<LM.size();j++){
bool b = L[LM[j]].act;
int i = LM[j];
	if(!b) {glDisable(GL_LIGHT0+i);}
	else{glEnable(GL_LIGHT0+i);
		glLightfv(GL_LIGHT0+i, GL_AMBIENT,L[i].ambient);
		glLightfv(GL_LIGHT0+i, GL_DIFFUSE, L[i].difus);
		glLightfv(GL_LIGHT0+i, GL_SPECULAR, L[i].specular);
		glPushMatrix();
		glLoadIdentity();
		glLightfv(GL_LIGHT0+i, GL_POSITION, L[i].posicio);	
		glPopMatrix();
	}
}
}


void GLWidget::cambiarLuz(int i){

Lsel=i;
//cout<<"ahora Lsel vale: "<<Lsel<<" y la luz es: "<<L[Lsel].id<<" y su posicion x es : "<< L[Lsel].posicio[0]<<" y su estado de activacion es: "<<L[Lsel].act<<endl;
//ventanaL.recibirLuces(L,Lsel);
}


void GLWidget::encen(int i, bool b){
//cout<<"encendemos con un : "<<b<<endl;
enciende(i,b);
}

void GLWidget::selectLuz(int i , bool b){

L[i].selected=b;

std::vector<int>::iterator found;
found=std::find(LM.begin(),LM.end(),i);
if(found==LM.end() && b)
{

 LM.push_back(i);
//cout<<"insertamos la luz "<<i<<endl;


}
if(found!=LM.end() && !b) {

LM.erase(found);

}
//cout<<"seleccionamos la luz "<< i <<" con el valor booleano : "<<b<<endl;


}


void GLWidget::dibuixarLlum()
{


for (int i = 0;i<8;i++){

if(L[i].act){

        glPushMatrix();
            glTranslatef(L[i].posL.x, L[i].posL.y, L[i].posL.z);
            glMaterialfv(GL_FRONT, GL_AMBIENT, L[i].ambient);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, L[i].difus);
            gluSphere(gluNewQuadric(), radi/18, 50, 50);
            glTranslatef(-L[i].posL.x, -L[i].posL.y, -L[i].posL.z);
        glPopMatrix();


        GLfloat ambient_def[] = { 0.2, 0.2, 0.2, 1.0 };
        GLfloat difos_def[] = { 0.7, 0.7, 0.7, 1.0 };
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_def);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, difos_def);
}

}
}


void GLWidget::activaLuces(bool b){

actL=b;
}


void GLWidget::verLuces(bool b){

verL=b;
}
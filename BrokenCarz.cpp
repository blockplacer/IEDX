// BrokenCarz.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include "pch.h"
#include <iostream>
#include "glut.h"

#include "conio.h"
using namespace std;

#include<stdio.h>
#include "bmp_loader.h"
#include "LoadObj.h"
#include "map_loader.h"
#include "models.h"
#include "IEDX_POLYTEX.h"
#include "FONTGER/include/fontmann.h"
#define KEY_ESC 27 /* GLUT doesn't supply this */
#pragma comment(lib, "GLAUX_iedx_fonts.lib")
#define NDEBUG
#include <cassert>


int fullscreen = 0;
int mouseDown = 0;

float xrot = 100.0f;
float yrot = -100.0f;

float xdiff = 100.0f;
float ydiff = 100.0f;

float tra_x = 0.0f;
float tra_y = 0.0f;
float tra_z = 0.0f;


float grow_shrink = 70.0f;
float resize_f = 1.0f;

GLfloat light_do[] = { 1.0, 1.0, 1.0, 1.0 };  //Green Diffuse light
GLfloat light_pose[] = { 1.0, 1.0, 1.0, 0.0 }; //Light position
GLfloat red_plastic_ambient[] =
{ 0.0, 0.0, 0.0 }, red_plastic_diffuse[] =
{ 0.5, 0.0, 0.0 }, red_plastic_specular[] =
{ 0.7, 0.6, 0.6 }, red_plastic_shininess = 32.0;
GLfloat light_do_spot[] = { 0.0, 1.0, 0.0, 1.0 };  //Green Spot Light
GLfloat light_pose_spot[] = { 1.0, 0.5, -1.0, 0.0 };


GLuint dinoC;
GLuint ground;


const GLdouble FRUSTDIM = 100.f;
const GLdouble FRUSTNEAR = 320.f;
const GLdouble FRUSTFAR = 660.f;

int init(void)
{
	glClearColor(0.93f, 0.93f, 0.93f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0f);

	return 1;
}

int mla = 0;
int mlay = 0;
int mlaz = 0;

bool neu = false;



void display()
{

	


	dinoC = LoadTexture("bitmap1.bmp");
	

	



	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_do);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pose);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);


	dinoC = LoadTexture("bitmap1.bmp");
	glEnable(GL_TEXTURE_2D);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(
		0.0f, 0.0f, 3.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);
	
	glPushMatrix();
	//SLOVE
	glRasterPos2i(20, 20);
	glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, iedx_glaf_o);
	glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, iedx_glaf_b);
	glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, iedx_glaf_a);
	glPopMatrix();




	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glTranslatef(tra_x, tra_y, tra_z);
	if (neu == true) {
		tra_y += 0.050f;
		glutPostRedisplay();
	}

	if (tra_y > 3.0) {



		if (tra_y > 10) {

			tra_y = 0;
			neu = false;
		}

	}


	/*glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glPolygonMode(GL_FRONT, GL_FILL);*/

	GLuint my_texture[13] = { 0xffaec900, 0x0000ffae, 0xc9ffaec9,
		0xffaec9ff, 0xaec90000, 0x00ffaec9,
		0x000000ff, 0xaec9ffae, 0xc9000000,
		0xffaec900, 0x00000000, 0x00ffaec9 }
	;

	//glShadeModel(GL_SMOOTH);//IJEE neon wards ıjee





	



	
	

	cObj obj("data/dragon.obj");
	obj.render();








	/*glLightfv(GL_LIGHT0, GL_DIFFUSE, light_do);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_do_spot);
	glTranslatef(mla, mlay, mlaz);
	LoadMap(3);*/



	


	


	glDisable(GL_TEXTURE_2D);
	/*glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glDisable(GL_TEXTURE_GEN_T);*/

	glFlush();
	glutSwapBuffers();
	
}





void resize(int w, int h)
{


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(grow_shrink, resize_f * w / h, resize_f, 100 * resize_f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}




void idle(void)
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}

	glutPostRedisplay();
}


void mySpecialFunction(int key, int x, int y)
{
	//if (key == GLUT_KEY_F1)
	//{
	printf("U -----------> rotate clockwise\n");
	printf("Y -----------> rotate counter clockwise\n");
	printf("W or w ------> Up\n");
	printf("S or s -----> Down\n");
	printf("D or d ------> Right\n");
	printf("A or a ------> Left\n");
	printf("Z or z ------> Shrink\n");
	printf("X or x ------> Grow\n");
	printf("Escape Key ---> exit the program\n\n");
	//}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(1);
		break;



	case 'w':
	case 'W':
		tra_x += 0.1f;
		break;
	case 's':
	case 'S':
		tra_x -= 0.1f;
		break;
	case 'a':
	case 'A':
		tra_z -= 0.1f;
		break;
	case 'd':
	case 'D':
		tra_z += 0.1f;
		break;
	case 'u':
	case 'U':
		xrot += 1.0f;
		yrot += 1.0f;
		xdiff += 1.0f;
		ydiff += 1.0f;
		break;
		
	case 'y':
	case 'Y':
		xrot -= 1.0f;
		yrot -= 1.0f;
		xdiff += 1.0f;
		ydiff += 1.0f;
		break;

	case 'h':
	case 'H':
		mySpecialFunction(key, x, y);
		break;
	case 'Z':
	case 'z':
		grow_shrink--;
		resize(500, 500);

		break;
	case 'X':
	case 'x':
		grow_shrink++;
		resize(500, 500);

		break;
	case ' ':
		neu = true;

		break;


	}


	glutPostRedisplay();
}

void specialKeyboard(int key, int x, int y)
{
	if (key == GLUT_KEY_F1)
	{
		fullscreen = !fullscreen;

		if (fullscreen)
			glutFullScreen();
		else
		{
			glutReshapeWindow(500, 500);
			glutPositionWindow(50, 50);
		}
	}
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = 1;

		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
		mouseDown = 0;
}

void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();
	}
}

int main(int argc, char *argv[])
{
	GLfloat plane[4];
	GLfloat v0[3], v1[3], v2[3];
	glutInit(&argc, argv);

	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ACCUM | GLUT_DEPTH);

	glutCreateWindow("13 - Solid Shapes");

	glutDisplayFunc(display);
	

	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutReshapeFunc(resize);
//	LoadTexture("bitmap1.bmp");
	
	//glutIdleFunc(idle);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	if (!init())
		return 1;

	
	glutMainLoop();
	extern GLubyte iedx_glaf_f[24];
	return 0;
}

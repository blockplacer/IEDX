#pragma once
#include "pch.h"
#include <iostream>
#include "glut.h"

#include "conio.h"
using namespace std;

#include<stdio.h>

void drawBox()
{



	glBegin(GL_QUADS);



	
	// FRONT
	glNormal3d(0.0000, 1.0000, 0.0000);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	// BACK
	glNormal3d(0.0000, 0.0000, 1.0000);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	// LEFT
	glNormal3d(-1.0000, 0.0000, 0.0000);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	// RIGHT
	glNormal3d(0.0000, -1.0000, 0.0000);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);

	
	// TOP
	glNormal3d(1.0000, 0.0000, 0.0000);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	// BOTTOM
	glNormal3d(0.0000, 0.0000, -1.0000);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glEnd();
}

void dino(GLint tex) {
glPushMatrix();
//head
glBindTexture(GL_TEXTURE_2D, tex);
glRotatef(90, 0, 60, 20);
glColor3f(0, 2, 0);
glutSolidCube(1);
glPopMatrix();
glPushMatrix();
//body
glBindTexture(GL_TEXTURE_2D, tex);
glColor3f(4, 0, 0);
glTranslatef(-1.5, 0, 0);
glScalef(2, 1, 1);
glutSolidCube(1);
glPopMatrix();
glPushMatrix();
//Random things
glBindTexture(GL_TEXTURE_2D, tex);
glColor3f(0, 0, 5);
glTranslatef(-0.9, -1, 0.1);
glRectd(0.1, 0.3, 0.3, 1);
glPopMatrix();
glPushMatrix();
glBindTexture(GL_TEXTURE_2D, tex);
glColor3f(0, 0, 5);
glTranslatef(-1.2, -1.2, 0.1);
glRectd(0.1, 0.3, 0.3, 1);
glPopMatrix();
glPushMatrix();
glBindTexture(GL_TEXTURE_2D, tex);
glColor3f(0, 0, 5);
glTranslatef(-1.5, -1, 0.1);
glRectd(0.1, 0.3, 0.3, 1);
glPopMatrix();
glPushMatrix();
//Leg
glBindTexture(GL_TEXTURE_2D, tex);
glTranslatef(-1.8, 1, 0.3);
glScalef(0.2, 1, 0.1);
glutSolidCube(1);
glPopMatrix();
glPushMatrix();
//Leg
glBindTexture(GL_TEXTURE_2D, tex);
glTranslatef(-1.8, 1, -0.3);
glScalef(0.2, 1, 0.1);
glutSolidCube(1);
glPopMatrix();
}

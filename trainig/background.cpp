#include <stdio.h>
#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
//#include <gl\glaux.h>		// Header File For The Glaux Library
//#include <GL/glut.h>
#include "texture.h"
#include "backgorund.h"






void drawFloor(int image)
{
	
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glColor3f(0,1,0);
	glNormal3f(0,1,0);
	glTexCoord2d(0,0);
	glVertex3f(-300,0,100);
	glTexCoord2d(1,0);
	glVertex3f(300,0,100);
	glTexCoord2d(1,1);
	glVertex3f(300,0,-100);
	glTexCoord2d(0,1);
	glVertex3f(-300,0,-100);
	glEnd();
}

void drawWall(int image)
{
	glBindTexture(GL_TEXTURE_2D,image);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,1);
	glTexCoord2d(0,0);
	glVertex3f(-300,0,-100.1);
	glTexCoord2d(1,0);
	glVertex3f(300,0,-100.1);
	glTexCoord2d(1,1);
	glVertex3f(300,50,-100.1);
	glTexCoord2d(0,1);
	glVertex3f(-300,50,-100.1);
	glEnd();

	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(1,0,0);
	glTexCoord2d(0,0);
	glVertex3f(-300,0,100);
	glTexCoord2d(1,0);
	glVertex3f(-300,0,-100);
	glTexCoord2d(1,1);
	glVertex3f(-300,50,-100);
	glTexCoord2d(0,1);
	glVertex3f(-300,50,100);
	glEnd();

	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(-1,0,0);
	glTexCoord2d(0,0);
	glVertex3f(300,0,100);
	glTexCoord2d(1,0);
	glVertex3f(300,0,-100);
	glTexCoord2d(1,1);
	glVertex3f(300,50,-100);
	glTexCoord2d(0,1);
	glVertex3f(300,50,100);
	glEnd();

	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,1);
	glTexCoord2d(0,0);
	glVertex3f(300,0,100.1);
	glTexCoord2d(1,0);
	glVertex3f(-300,0,100.1);
	glTexCoord2d(1,1);
	glVertex3f(-300,50,100.1);
	glTexCoord2d(0,1);
	glVertex3f(300,50,100.1);
	glEnd();
}

void DrawPlace(int grassTexture,int wallTexture)
{
	drawFloor(grassTexture);
	drawWall(wallTexture);
}
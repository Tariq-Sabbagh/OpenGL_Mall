#include <stdio.h>
#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
//#include <gl\glaux.h>		// Header File For The Glaux Library
//#include <GL/glut.h>
#include "texture.h"
#include "backgorund.h"
#include "Resturant.h"
#include "mall.h"





void drawFloor(int image)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glColor3f(0,1,0);
	glNormal3f(0,1,0);
	glTexCoord2d(0,0);
	glVertex3f(-60,0,60);
	glTexCoord2d(1,0);
	glVertex3f(60,0,60);
	glTexCoord2d(1,1);
	glVertex3f(60,0,-60);
	glTexCoord2d(0,1);
	glVertex3f(-60,0,-60);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void drawall(int image1,int image2,int image3,int image4,int image5)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,image1);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,1);
	glTexCoord2d(0,0);
	glVertex3f(-60,0,-60.1);
	glTexCoord2d(1,0);
	glVertex3f(60,0,-60.1);
	glTexCoord2d(1,1);
	glVertex3f(60,50,-60.1);
	glTexCoord2d(0,1);
	glVertex3f(-60,50,-60.1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,image2);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(1,0,0);
	glTexCoord2d(0,0);
	glVertex3f(-60,0,60);
	glTexCoord2d(1,0);
	glVertex3f(-60,0,-60);
	glTexCoord2d(1,1);
	glVertex3f(-60,50,-60);
	glTexCoord2d(0,1);
	glVertex3f(-60,50,60);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,image3);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(-1,0,0);
	glTexCoord2d(0,0);
	glVertex3f(60,0,60);
	glTexCoord2d(1,0);
	glVertex3f(60,0,-60);
	glTexCoord2d(1,1);
	glVertex3f(60,50,-60);
	glTexCoord2d(0,1);
	glVertex3f(60,50,60);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,image4);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,1);
	glTexCoord2d(0,0);
	glVertex3f(60,0,60.1);
	glTexCoord2d(1,0);
	glVertex3f(-60,0,60.1);
	glTexCoord2d(1,1);
	glVertex3f(-60,50,60.1);
	glTexCoord2d(0,1);
	glVertex3f(60,50,60.1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,image5);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,1,0); 
	glTexCoord2d(0,0);
	glVertex3f(-60,50,-60.1); 
	glTexCoord2d(1,0);
	glVertex3f(60,50,-60.1); 
	glTexCoord2d(1,1);
	glVertex3f(60,50,60.1); 
	glTexCoord2d(0,1);
	glVertex3f(-60,50,60.1); 
	glEnd();

    glDisable(GL_TEXTURE_2D);

}

void drawSidewalk(int image)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,image);//floor
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,1,0); 
	glTexCoord2d(0,0);
	glVertex3f(-60,0,-60.1); 
	glTexCoord2d(1,0);
	glVertex3f(0,0,-60.1); 
	glTexCoord2d(1,1);
	glVertex3f(0,0,60.1); 
	glTexCoord2d(0,1);
	glVertex3f(-60,0,60.1); 
	glEnd();

	glColor3f(1,1,1);//يسار
	glBegin(GL_QUADS);
	glNormal3f(0,1,0); 
	glTexCoord2d(0,0);
	glVertex3f(-60,0,-60.1); 
	glTexCoord2d(1,0);
	glVertex3f(-60,1,-60.1); 
	glTexCoord2d(1,1);
	glVertex3f(-60,1,60.1); 
	glTexCoord2d(0,1);
	glVertex3f(-60,0,60.1); 
	glEnd();

	glColor3f(1,1,1);// ورا
	glBegin(GL_QUADS);
	glNormal3f(0,1,0); 
	glTexCoord2d(0,0);
	glVertex3f(-60,0,60.1); 
	glTexCoord2d(1,0);
	glVertex3f(0,0,60.1); 
	glTexCoord2d(1,1);
	glVertex3f(0,1,60.1); 
	glTexCoord2d(0,1);
	glVertex3f(-60,1,60.1); 
	glEnd();

	glColor3f(1,1,1);//يمين
	glBegin(GL_QUADS);
	glNormal3f(0,1,0); 
	glTexCoord2d(0,0);
	glVertex3f(0,0,60.1); 
	glTexCoord2d(1,0);
	glVertex3f(0,0,-60.1); 
	glTexCoord2d(1,1);
	glVertex3f(0,1,-60.1); 
	glTexCoord2d(0,1);
	glVertex3f(0,1,60.1); 
	glEnd();

	glColor3f(1,1,1);//قدام
	glBegin(GL_QUADS);
	glNormal3f(0,1,0); 
	glTexCoord2d(0,0);
	glVertex3f(-60,0,-60.1); 
	glTexCoord2d(1,0);
	glVertex3f(0,0,-60.1); 
	glTexCoord2d(1,1);
	glVertex3f(0,1,-60.1); 
	glTexCoord2d(0,1);
	glVertex3f(-60,1,-60.1); 
	glEnd();

	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,1,0); 
	glTexCoord2d(0,0);
	glVertex3f(-60,1,-60.1); 
	glTexCoord2d(1,0);
	glVertex3f(0,1,-60.1); 
	glTexCoord2d(1,1);
	glVertex3f(0,1,60.1); 
	glTexCoord2d(0,1);
	glVertex3f(-60,1,60.1); 
	glEnd();



	glDisable(GL_TEXTURE_2D);
}

void drawStreet(float x,float y,float z,float x1,float y2,float z1,int image)
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,image);//floor
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,1,0); 
	glTexCoord2d(0,0);
	glVertex3f(x,y,z); 
	glTexCoord2d(1,0);
	glVertex3f(x1,y,z); 
	glTexCoord2d(1,1);
	glVertex3f(x1,y2,z1); 
	glTexCoord2d(0,1);
	glVertex3f(x,y2,z1); 
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

extern void DrawPlace(int floorTexture,int sky1,int sky2,int sky3,int sky4,int sky5,int sidewalk,int road,int buildingTexture,int buildingTexture2,int upfront,int wall,int glass,int up,int floorMall)
{
	
	drawFloor(floorTexture);
	drawall(sky1,sky2,sky3,sky4,sky5);
	drawSidewalk(sidewalk);
	drawStreet(0,0,60,15,0,-60,road);
	drawStreet(15,0,60,30,0,-60,road);
	//to draw bulding
	for (int z = 60; z > -60; z -= 40) {
		rectangles(30, 0, z, 30, 40, 30, buildingTexture2);
		DrawXZ(30, 0, z - 30, 10, 7, -10, buildingTexture, 0, 0, 1, 0, 1, 1, 0, 1);
		glDisable(GL_TEXTURE_2D);
	}

	

}
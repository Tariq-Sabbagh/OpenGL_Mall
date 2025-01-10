#include <stdio.h>
#include <windows.h>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
//#include <gl\glaux.h>		// Header File For The Glaux Library
//#include <GL/glut.h>
#include <cmath>
#include "texture.h"
#include "backgorund.h"

#include "Resturant.h"
#define pai 3.14159265359





void drawDoor(float d, int image)
{
	glBindTexture(GL_TEXTURE_2D,image);
	glTranslated(-d,0,0);
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glNormal3f(0,0,1);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,0);
	glTexCoord2d(1,0);
	glVertex3f(0,0,0);
	glTexCoord2d(1,1);
	glVertex3f(0,4,0);
	glTexCoord2d(0,1);
	glVertex3f(-2,4,0);
	glEnd();

	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,image);
	glTranslated(d,0,0);
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glNormal3f(0,0,1);
	glTexCoord2d(0,0);
	glVertex3f(0,0,0);
	glTexCoord2d(1,0);
	glVertex3f(2,0,0);
	glTexCoord2d(1,1);
	glVertex3f(2,4,0);
	glTexCoord2d(0,1);
	glVertex3f(0,4,0);
	glEnd();
}

void drawStructure(int image, int image2)
{
	glBindTexture(GL_TEXTURE_2D, image);
	//back
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,1);
	glTexCoord2d(0,0);
	glVertex3f(-30,0,-10);
	glTexCoord2d(1,0);
	glVertex3f(30,0,-10);
	glTexCoord2d(1,1);
	glVertex3f(30,15,-10);
	glTexCoord2d(0,1);
	glVertex3f(-30,15,-10);
	glEnd();

	//right
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(-1,0,0);
	glTexCoord2d(0,0);
	glVertex3f(30,0,-10);
	glTexCoord2d(1,0);
	glVertex3f(30,15,-10);
	glTexCoord2d(1,1);
	glVertex3f(30,15,20);
	glTexCoord2d(0,1);
	glVertex3f(30,0,20);
	glEnd();

	//left
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(1,0,0);
	glTexCoord2d(0,0);
	glVertex3f(-30,0,-10);
	glTexCoord2d(1,0);
	glVertex3f(-30,15,-10);
	glTexCoord2d(1,1);
	glVertex3f(-30,15,20);
	glTexCoord2d(0,1);
	glVertex3f(-30,0,20);
	glEnd();

	//roof
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,-1,0);
	glTexCoord2d(0,0);
	glVertex3f(-30,15,-10);
	glTexCoord2d(1,0);
	glVertex3f(30,15,-10);
	glTexCoord2d(1,1);
	glVertex3f(30,15,20);
	glTexCoord2d(0,1);
	glVertex3f(-30,15,20);
	glEnd();

	//front left
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2d(0,0);
	glVertex3f(-30,0,20);
	glTexCoord2d(1,0);
	glVertex3f(-30,15,20);
	glTexCoord2d(1,1);
	glVertex3f(-25,15,20);
	glTexCoord2d(0,1);
	glVertex3f(-25,0,20);
	glEnd();
	//front right
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2d(0,0);
	glVertex3f(25,0,20);
	glTexCoord2d(1,0);
	glVertex3f(25,15,20);
	glTexCoord2d(1,1);
	glVertex3f(30,15,20);
	glTexCoord2d(0,1);
	glVertex3f(30,0,20);
	glEnd();
	//front up
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2d(0,0);
	glVertex3f(-25,12,20);
	glTexCoord2d(1,0);
	glVertex3f(-25,15,20);
	glTexCoord2d(1,1);
	glVertex3f(25,15,20);
	glTexCoord2d(0,1);
	glVertex3f(25,12,20);
	glEnd();


	//glass place left
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2d(0,0);
	glVertex3f(-25,0,20);
	glTexCoord2d(1,0);
	glVertex3f(-25,0.6,20);
	glTexCoord2d(1,1);
	glVertex3f(-10,0.6,20);
	glTexCoord2d(0,1);
	glVertex3f(-10,0,20);
	glEnd();

	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2d(0,0);
	glVertex3f(-12,0.6,20);
	glTexCoord2d(1,0);
	glVertex3f(-12,12,20);
	glTexCoord2d(1,1);
	glVertex3f(-10,12,20);
	glTexCoord2d(0,1);
	glVertex3f(-10,0.6,20);
	glEnd();

	//glass place right
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2d(0,0);
	glVertex3f(25,0,20);
	glTexCoord2d(1,0);
	glVertex3f(25,0.6,20);
	glTexCoord2d(1,1);
	glVertex3f(10,0.6,20);
	glTexCoord2d(0,1);
	glVertex3f(10,0,20);
	glEnd();

	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2d(0,0);
	glVertex3f(12,0.6,20);
	glTexCoord2d(1,0);
	glVertex3f(12,12,20);
	glTexCoord2d(1,1);
	glVertex3f(10,12,20);
	glTexCoord2d(0,1);
	glVertex3f(10,0.6,20);
	glEnd();

	//up the door
	glBindTexture(GL_TEXTURE_2D, image2);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2d(0,0);
	glVertex3f(10,8,20);
	glTexCoord2d(1,0);
	glVertex3f(10,12,20);
	glTexCoord2d(1,1);
	glVertex3f(-10,12,20);
	glTexCoord2d(0,1);
	glVertex3f(-10,8,20);
	glEnd();


	/*glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,1);
	glTexCoord2d(0,0);
	glVertex3f(-3,2,-10);
	glTexCoord2d(1,0);
	glVertex3f(3,2,-10);
	glTexCoord2d(1,1);
	glVertex3f(3,4,-10);
	glTexCoord2d(0,1);
	glVertex3f(-3,4,-10);
	glEnd();
back put now not impo*/
	

}

void DrawStructureFloor(int image)
{
	glBindTexture(GL_TEXTURE_2D,image);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,1,0);
	glTexCoord2d(0,0);
	glVertex3f(-5,0,0);
	glTexCoord2d(1,0);
	glVertex3f(-5,0,-10);
	glTexCoord2d(1,1);
	glVertex3f(5,0,-10);
	glTexCoord2d(0,1);
	glVertex3f(5,0,0);
	glEnd();
}


void DrawStructureGlass(float x,float y,float z,float x1,float y1,float z1,int image)
{

	glBindTexture(GL_TEXTURE_2D, image);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2d(0,0);
	glVertex3f(x,y,z);
	glTexCoord2d(1,0);
	glVertex3f(x,y1,z);
	glTexCoord2d(1,1);
	glVertex3f(x1,y1,z);
	glTexCoord2d(0,1);
	glVertex3f(x1,y,z);
	glEnd();
}

void DrawStructurebeu(int image)
{
	glBindTexture(GL_TEXTURE_2D, image);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2d(0,0);
	glVertex3f(-18.2,0.6,20);
	glTexCoord2d(1,0);
	glVertex3f(-18.2,12,20);
	glTexCoord2d(1,1);
	glVertex3f(-18.0,12,20);
	glTexCoord2d(0,1);
	glVertex3f(-18.0,0.6,20);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, image);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2d(0,0);
	glVertex3f(18.2,0.6,20);
	glTexCoord2d(1,0);
	glVertex3f(18.2,12,20);
	glTexCoord2d(1,1);
	glVertex3f(18.0,12,20);
	glTexCoord2d(0,1);
	glVertex3f(18.0,0.6,20);
	glEnd();
}

void DrawGround(float x,float y,float z,float x1,float y1,float z1,int image)
{
	glBindTexture(GL_TEXTURE_2D, image);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2d(0,0);
	glVertex3f(x,y,z);
	glTexCoord2d(1,0);
	glVertex3f(x,y1,z1);
	glTexCoord2d(1,1);
	glVertex3f(x1,y1,z1);
	glTexCoord2d(0,1);
	glVertex3f(x1,y,z);
	glEnd();
}

void rectangleXY(float x, float y, float z, float w, float h,int N, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu) {
		
		glBindTexture(GL_TEXTURE_2D, texture);
		
		glNormal3d(0, 0, N);
		glBegin(GL_QUADS);
		glTexCoord2d(sld, tld);
		glVertex3f(x, y, z);
		glTexCoord2d(srd, trd);
		glVertex3f(x + w, y, z);
		glTexCoord2d(sru, tru);
		glVertex3f(x + w, y + h, z);
		glTexCoord2d(slu, tlu);
		glVertex3f(x, y + h, z);
		glEnd();

	}

void parallel_rectangles(float x, float y, float z, float w, float h, float d, int texture)
	{
		rectangleXY(x, y, z, w, h,1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectangleXY(x, y, z-d, w, h,-1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectangleXZ(x, y, z, w, d,-1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectangleXZ(x, y+h, z, w, d,1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectangleYZ(x, y, z, d, h,-1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		rectangleYZ(x+w, y, z, d, h,1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
	}
void rectangleXZ(float x, float y, float z, float w, float h,int N, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu) {
		
		glBindTexture(GL_TEXTURE_2D, texture);

		glNormal3d(0, N, 0);
		glBegin(GL_QUADS);
		glTexCoord2d(sld, tld);
		glVertex3f(x, y, z);
		glTexCoord2d(srd, trd);
		glVertex3f(x + w, y, z);
		glTexCoord2d(sru, tru);
		glVertex3f(x + w, y, z - h);
		glTexCoord2d(slu, tlu);
		glVertex3f(x, y, z - h);
		glEnd();

	}

	void rectangleYZ(float x, float y, float z, float w, float h, int N, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu) {
		
		glBindTexture(GL_TEXTURE_2D, texture);

		glNormal3d(N, 0, 0);
		glBegin(GL_QUADS);
		glTexCoord2d(sld, tld);
		glVertex3f(x, y, z);
		glTexCoord2d(srd, trd);
		glVertex3f(x, y, z - w);
		glTexCoord2d(sru, tru);
		glVertex3f(x, y + h, z - w);
		glTexCoord2d(slu, tlu);
		glVertex3f(x, y + h, z);
		glEnd();

	}
	void table(float x, float y, float z, float w, float h, float d, int tableTexture ,int tablelegTexture)
	{
		parallel_rectangles(x, y, z, w, 0.1, d, tableTexture);
		parallel_rectangles(x + 0.2, y - h, z - 0.3, 0.1, h,0.1,tablelegTexture);
		parallel_rectangles(x +w- 0.3, y - h, z - 0.3, 0.1, h, 0.1, tablelegTexture);
		parallel_rectangles(x +w-0.3 , y - h, z -d+ 0.3, 0.1, h, 0.1, tablelegTexture);
		parallel_rectangles(x + 0.2, y - h, z -d+ 0.3, 0.1, h, 0.1, tablelegTexture);
	}
	void chair(float x, float y, float z,int texture)
	{
		// رسم المقعد بحجم أكبر
    parallel_rectangles(x, y + 1.8, z, 1.5, 0.3, 1.5, texture); // المقعد
    
    // رسم الأرجل الأربع عند الزوايا المناسبة
    parallel_rectangles(x, y, z, 0.3, 1.8, 0.3, texture);           // الرجل الأمامية اليسرى
    parallel_rectangles(x + 1.2, y, z, 0.3, 1.8, 0.3, texture);      // الرجل الأمامية اليمنى
    parallel_rectangles(x, y, z - 1.2, 0.3, 1.8, 0.3, texture);      // الرجل الخلفية اليسرى
    parallel_rectangles(x + 1.2, y, z - 1.2, 0.3, 1.8, 0.3, texture); // الرجل الخلفية اليمنى
    
    // رسم الظهر
    parallel_rectangles(x, y + 1.8, z - 1.2, 1.5, 1.8, 0.3, texture); // الظهر
	}

	void cone(float x, float y, float z, float h, float r, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu)
	{
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		for (float i = 0; i < 2 * 3.14; i += 0.3)
		{
			glNormal3d(sin(i), atan2(r , h)+pai, cos(i));
			float xx = r * cos(i);
			float zz = r * sin(i);
			float xxx = r * cos(i + 0.3);
			float zzz = r * sin(i + 0.3);
			glTexCoord2d(sld, tld);
			glVertex3f(x + xx, y, z - zz);
			glTexCoord2d(srd, trd);
			glVertex3f(x + xxx, y, z - zzz);
			glTexCoord2d(sru, tru);
			glVertex3f(x + xxx, y + h, z - zzz);
			glTexCoord2d(slu, tlu);
			glVertex3f(x + xx, y + h, z - zz);

		}
		glEnd();
	}
	void drawPlank(float x, float y, float z, float width, float height, float depth,int texture) {
	glBindTexture(GL_TEXTURE_2D, texture);
    glColor3f(1.0f, 1.0f, 1.0f); 
    glBegin(GL_QUADS);

    glTexCoord2d(0,0);
    glVertex3f(x, y, z);
	glTexCoord2d(1,0);
    glVertex3f(x + width, y, z);
	glTexCoord2d(1,1);
    glVertex3f(x + width, y + height, z);
	glTexCoord2d(0,1);
    glVertex3f(x, y + height, z);

	glTexCoord2d(0,0);
    glVertex3f(x, y, z - depth);
	glTexCoord2d(1,0);
    glVertex3f(x + width, y, z - depth);
	glTexCoord2d(1,1);
    glVertex3f(x + width, y + height, z - depth);
	glTexCoord2d(0,1);
    glVertex3f(x, y + height, z - depth);

	glTexCoord2d(0,0);
    glVertex3f(x, y + height, z);
	glTexCoord2d(1,0);
    glVertex3f(x + width, y + height, z);
	glTexCoord2d(1,1);
    glVertex3f(x + width, y + height, z - depth);
	glTexCoord2d(0,1);
    glVertex3f(x, y + height, z - depth);

	glTexCoord2d(0,0);
    glVertex3f(x, y, z);
	glTexCoord2d(1,0);
    glVertex3f(x + width, y, z);
	glTexCoord2d(1,1);
    glVertex3f(x + width, y, z - depth);
	glTexCoord2d(0,1);
    glVertex3f(x, y, z - depth);

	glTexCoord2d(0,0);
    glVertex3f(x + width, y, z);
	glTexCoord2d(1,0);
    glVertex3f(x + width, y, z - depth);
	glTexCoord2d(1,1);
    glVertex3f(x + width, y + height, z - depth);
	glTexCoord2d(0,1);
    glVertex3f(x + width, y + height, z);

    glTexCoord2d(0,0);
    glVertex3f(x, y, z);
	glTexCoord2d(1,0);
    glVertex3f(x, y, z - depth);
	glTexCoord2d(1,1);
    glVertex3f(x, y + height, z - depth);
	glTexCoord2d(0,1);
    glVertex3f(x, y + height, z);

    glEnd();
}

void drawFence(float startX, float startY, float startZ, int numPlanks, float plankWidth, float plankHeight, float plankDepth, float spacing,int texture) {
    
    for (int i = 0; i < numPlanks; i++) {
        float x = startX + i * (plankWidth + spacing);
        drawPlank(x, startY, startZ, plankWidth, plankHeight, plankDepth,texture);
    }

    
    float horizontalWidth = (numPlanks - 1) * (plankWidth + spacing) + plankWidth;
    float horizontalHeight = 0.1f;
    float horizontalDepth = plankDepth / 2;

   
    drawPlank(startX, startY + plankHeight - 0.5f, startZ, horizontalWidth, horizontalHeight, horizontalDepth,texture);

   
    drawPlank(startX, startY + 0.5f, startZ, horizontalWidth, horizontalHeight, horizontalDepth,texture);
}
void DrawTableChair(int texture1,int texture2,int texture3)
{
	table(-20, 1.5, 7.5, 4, 2, 4,  texture1,texture2);
	table(-20, 1.5, 17.5, 4, 2, 4, texture1,texture2);
	table(-20, 1.5, 0, 4, 2, 4, texture1,texture2);
	glPushMatrix();
	chair(-19, -0.5, 13.5, texture3);
	chair(-19, -0.5, 3.0, texture3);
	chair(-19, -0.5, -4.5, texture3);
	glRotated(90, 0, 1, 0);
	chair( -6.5, -0.5, -20, texture3);
	chair(-15.5, -0.5, -20 , texture3);
	chair(2, -0.5, -20 , texture3);
	glRotated(180, 0, 1, 0);
	chair( 5, -0.5, 15, texture3);
	chair(-3, -0.5, 15 , texture3);
	chair(13.5, -0.5, 15 , texture3);
	glPopMatrix();
}

void drawDecore(int texture1,int texture2, int texture3,int texture4)
{
	glPushMatrix();
	
	glRotated(90, 0, 1, 0);
	
	glRotated(180, 0, 1, 0);
	
	cone(15, 0, -12, 12, 2, texture1, 0, 0, 1, 0, 1, 1, 0, 1);
	cone(15, 0, -20, 12, 2, texture1, 0, 0, 1, 0, 1, 1, 0, 1);
	cone(15, 0, -28, 12, 2, texture1, 0, 0, 1, 0, 1, 1, 0, 1);
	glPopMatrix();
	DrawGround(9,0,10,30,0,20,texture2);
	drawFence(9, 0, 10, 30, 0.5f, 2.0f, 0.2f, 0.2f, texture3);
	glPushMatrix();
	glRotated(90,0,1,0);
	drawFence(-20, 0, 9, 15, 0.5f, 2.0f, 0.2f, 0.2f, texture3);
	rectangleXZ(-19, 0, 16, 2, 2,1, texture4, 0, 0, 1, 0, 1, 10, 0, 10);
	rectangleXZ(-15, 0, 16, 2, 2,1, texture4, 0, 0, 1, 0, 1, 10, 0, 10);
	rectangleXZ(-19, 0, 25, 2, 2,1, texture4, 0, 0, 1, 0, 1, 10, 0, 10);
	rectangleXZ(-15, 0, 25, 2, 2,1, texture4, 0, 0, 1, 0, 1, 10, 0, 10);
	glPopMatrix();
}
void DrawStructureGlass(float x,float y,float z,float x1,float y1,float z1,int image,int f,int c)
{

	glBindTexture(GL_TEXTURE_2D, image);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2d(c,f);
	glVertex3f(x,y,z);
	glTexCoord2d(c,c);
	glVertex3f(x,y1,z);
	glTexCoord2d(f,c);
	glVertex3f(x1,y1,z);
	glTexCoord2d(f,f);
	glVertex3f(x1,y,z);
	glEnd();
}
	
void DrawResturant(int floorTexture ,int fixglass ,int glassTexture,int screen,int doorTexture ,int wallRe,int chairTexture,int tableTexture,int tablelegTexture,int fruitcone,int fenceTexture,int flowresTexture,int grass,int logoTexture)
{
	DrawGround(-30,0,-10,30,0,20,floorTexture);
	DrawTableChair(tableTexture,tablelegTexture,chairTexture);
	drawDecore(fruitcone,grass,fenceTexture,flowresTexture);
	drawStructure(wallRe,floorTexture);
	DrawStructurebeu(fixglass);
	//DrawStructureGlass(-6,2,-10,6,12,-10,logoTexture);
	DrawStructureGlass(-6,2,-10,6,12,-10,logoTexture,0,1);
	DrawStructureGlass(-25,0.6,20,-18.2,12,20,glassTexture);
	DrawStructureGlass(-18,0.6,20,-12,12,20,glassTexture);
	DrawStructureGlass(25,0.6,20,18.2,12,20,glassTexture);
	DrawStructureGlass(18,0.6,20,12,12,20,glassTexture);
	DrawStructureGlass(-10,0,20,-7,12,20,doorTexture);
	DrawStructureGlass(10,0,20,7,12,20,doorTexture);
	DrawStructureGlass(-4,8,20,4,12,20,screen);
}
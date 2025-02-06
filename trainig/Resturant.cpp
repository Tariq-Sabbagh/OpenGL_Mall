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
#include "Decore.h"
#define pai 3.14159265359






void drawDoor(float d, int image)
{
	glEnable(GL_TEXTURE_2D);
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
	glDisable(GL_TEXTURE_2D);
}

void drawStructure(int image, int image2)
{
	glEnable(GL_TEXTURE_2D);
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
	glDisable(GL_TEXTURE_2D);


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
	glEnable(GL_TEXTURE_2D);
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
	glDisable(GL_TEXTURE_2D);
}


void DrawStructureGlass(float x,float y,float z,float x1,float y1,float z1,int image)
{
	glEnable(GL_TEXTURE_2D);
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
	glDisable(GL_TEXTURE_2D);
}

void DrawStructurebeu(int image)
{
	glEnable(GL_TEXTURE_2D);
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
	glDisable(GL_TEXTURE_2D);
}

void DrawGround(float x,float y,float z,float x1,float y1,float z1,int image)
{
	glEnable(GL_TEXTURE_2D);
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
	glDisable(GL_TEXTURE_2D);
}

void DrawXY(float x, float y, float z, float w, float h,int N, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu) {
		glEnable(GL_TEXTURE_2D);
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
		 glDisable(GL_TEXTURE_2D);

	}

void rectangles(float x, float y, float z, float w, float h, float d, int texture)
	{
		DrawXY(x, y, z, w, h,1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		DrawXY(x, y, z-d, w, h,-1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		DrawDe(x, y, z, w, d,-1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		DrawDe(x, y+h, z, w, d,1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		DrawXZ(x, y, z, d, h,-1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
		DrawXZ(x+w, y, z, d, h,1, texture, 0, 0, 1, 0, 1, 1, 0, 1);
	}
void DrawDe(float x, float y, float z, float w, float h,int N, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu) {
		glEnable(GL_TEXTURE_2D);
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
		 glDisable(GL_TEXTURE_2D);

	}

	void DrawXZ(float x, float y, float z, float w, float h, int N, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu) {
		
		glEnable(GL_TEXTURE_2D);
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
		 glDisable(GL_TEXTURE_2D);

	}
	void table(float x, float y, float z, float w, float h, float d, int tableTexture ,int tablelegTexture)
	{
		rectangles(x, y, z, w, 0.1, d, tableTexture);
		rectangles(x + 0.2, y - h, z - 0.3, 0.1, h,0.1,tablelegTexture);
		rectangles(x +w- 0.3, y - h, z - 0.3, 0.1, h, 0.1, tablelegTexture);
		rectangles(x +w-0.3 , y - h, z -d+ 0.3, 0.1, h, 0.1, tablelegTexture);
		rectangles(x + 0.2, y - h, z -d+ 0.3, 0.1, h, 0.1, tablelegTexture);
	}
	void chair(float x, float y, float z,int texture)
	{
		// رسم المقعد بحجم أكبر
    rectangles(x, y + 1.8, z, 1.5, 0.3, 1.5, texture); // المقعد
    
    // رسم الأرجل الأربع عند الزوايا المناسبة
    rectangles(x, y, z, 0.3, 1.8, 0.3, texture);           // الرجل الأمامية اليسرى
    rectangles(x + 1.2, y, z, 0.3, 1.8, 0.3, texture);      // الرجل الأمامية اليمنى
    rectangles(x, y, z - 1.2, 0.3, 1.8, 0.3, texture);      // الرجل الخلفية اليسرى
    rectangles(x + 1.2, y, z - 1.2, 0.3, 1.8, 0.3, texture); // الرجل الخلفية اليمنى
    
    
    rectangles(x, y + 1.8, z - 1.2, 1.5, 1.8, 0.3, texture);
	}

	void cone(float x, float y, float z, float h, float r, int texture, float sld, float tld, float srd, float trd, float sru, float tru, float slu, float tlu)
	{
		glEnable(GL_TEXTURE_2D);
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
		glDisable(GL_TEXTURE_2D);
	}
	void drawPlank(float x, float y, float z, float width, float height, float depth,int texture) {
		glEnable(GL_TEXTURE_2D);
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
	glDisable(GL_TEXTURE_2D);
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
	DrawDe(-19, 0, 16, 2, 2,1, texture4, 0, 0, 1, 0, 1, 10, 0, 10);
	DrawDe(-15, 0, 16, 2, 2,1, texture4, 0, 0, 1, 0, 1, 10, 0, 10);
	DrawDe(-19, 0, 25, 2, 2,1, texture4, 0, 0, 1, 0, 1, 10, 0, 10);
	DrawDe(-15, 0, 25, 2, 2,1, texture4, 0, 0, 1, 0, 1, 10, 0, 10);
	glPopMatrix();
}
void DrawStructureGlass(float x, float y, float z, float x1, float y1, float z1, int image,int f,int c)
{
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, image);
    glColor3f(1, 1, 1);
    
    glBegin(GL_QUADS);
    glNormal3f(0, 0, -1);

    glTexCoord2d(0, 0); glVertex3f(x, y, z);     
    glTexCoord2d(0, 1); glVertex3f(x, y1, z);    
    glTexCoord2d(1, 1); glVertex3f(x1, y1, z);   
    glTexCoord2d(1, 0); glVertex3f(x1, y, z); 
    glEnd();
	glDisable(GL_TEXTURE_2D);
}

void drawHalfCylinder(float radius, float height, int segments, int texture) {
    float angleStep = pai / segments;
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);  

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        
        float u = (float)i / segments;

        glTexCoord2f(u, 0.0f);  
        glVertex3f(x, 0.0f, z);

        glTexCoord2f(u, 1.0f);  
        glVertex3f(x, height, z);
    }
    glEnd();
	glDisable(GL_TEXTURE_2D);
}

void drawTopSurface(float radius, int segments, float thickness, int texture) {
    float angleStep = pai / segments;
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);  

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, thickness-0.2, 0.2f);  
    
    
    for (int i = 0; i <= segments; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        
        float u = (float)i / segments;

        glTexCoord2f(u, 1.0f);  
        glVertex3f(x, thickness-0.2, z+0.2);
    }
    glEnd();
	glDisable(GL_TEXTURE_2D);
}

void drawCurvedReceptionDesk(int texture1, int texture2) {
	glPushMatrix();
	glTranslated(0,0,-10);
    float radius = 8.0f;
    float height = 3.0f;
    int segments = 50;
    float topThickness = 0.2f;  

    
    glColor3f(1.0f, 1.0f, 1.0f);  
    drawHalfCylinder(radius, height, segments, texture1);

    
    drawTopSurface(radius, segments, height + topThickness, texture2);

   
    glColor3f(1.0f, 1.0f, 1.0f);
    drawHalfCylinder(radius, height, segments, texture1);
	glPopMatrix();
}


void drawHollowRing(float outerRadius, float innerRadius, float height, int segments) {
    float angleStep = 2 * pai / segments;

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float angle = i * angleStep;
        float outerX = outerRadius * cos(angle);
        float outerZ = outerRadius * sin(angle);
        float innerX = innerRadius * cos(angle);
        float innerZ = innerRadius * sin(angle);

        glVertex3f(outerX, height, outerZ);
        glVertex3f(innerX, height, innerZ);
    }
    glEnd();
}



// Function to draw a vertical leg (cylinder)
void drawLeg(float radius, float height, int segments) {
    float angleStep = 2 * pai / segments;

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        glVertex3f(x, 0.0f, z);
        glVertex3f(x, height, z);
    }
    glEnd();
}

// Function to draw a closed cylinder (seat)
void drawClosedCylinder(float radius, float height, int segments) {
    float angleStep = 2 * pai / segments;


    // رسم السطح الجانبي مع إضافة الإحداثيات الملمسية
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        float texCoord = (float)i / segments;  // الإحداثي الملمسي U موزع خطيًا

        glTexCoord2f(texCoord, 0.0f);  // الإحداثي السفلي
        glVertex3f(x, 0.0f, z);
        glTexCoord2f(texCoord, 1.0f);  // الإحداثي العلوي
        glVertex3f(x, height, z);
    }
    glEnd();

    // رسم القاعدة العلوية مع إضافة الإحداثيات الملمسية
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f);  // مركز القاعدة
    glVertex3f(0.0f, height, 0.0f);
    for (int i = 0; i <= segments; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        float u = 0.5f + 0.5f * cos(angle);  // تحويل الإحداثيات إلى [0, 1]
        float v = 0.5f + 0.5f * sin(angle);

        glTexCoord2f(u, v);  // الإحداثي الملمسي لكل نقطة
        glVertex3f(x, height, z);
    }
    glEnd();

    // رسم القاعدة السفلية مع إضافة الإحداثيات الملمسية
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f);  // مركز القاعدة
    glVertex3f(0.0f, 0.0f, 0.0f);
    for (int i = 0; i <= segments; ++i) {
        float angle = i * angleStep;
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        float u = 0.5f + 0.5f * cos(angle);  // تحويل الإحداثيات إلى [0, 1]
        float v = 0.5f + 0.5f * sin(angle);

        glTexCoord2f(u, v);  // الإحداثي الملمسي لكل نقطة
        glVertex3f(x, 0.0f, z);
    }
    glEnd();
	 

}



void drawBarStool(int chairTexture) {
    glPushMatrix(); // حفظ الحالة الحالية للمصفوفة

    int segments = 100;  
    float seatRadius = 1.5f;
    float seatHeight = 0.4f;  
    float ringOuterRadius = 1.2f;
    float ringInnerRadius = 0.8f;
    float ringHeight = 1.0f;
    float legRadius = 0.1f;
    float legHeight = 2.0f;
    float footRadius = 0.05f;
    float footLength = 0.5f;

    // رسم المقعد مع التكسشر
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, chairTexture);//right door
    glColor3f(1.0f, 1.0f, 1.0f); // إعادة اللون إلى الأبيض قبل التكسشر
    
    glPushMatrix();
    glTranslatef(0.0f, legHeight + seatHeight - 0.5, 0.0f);
    drawClosedCylinder(seatRadius, seatHeight, segments);
    glPopMatrix();

  glDisable(GL_TEXTURE_2D);

    // رسم الحلقة المعدنية
    glColor3f(0.5f, 0.5f, 0.5f);  
    glPushMatrix();
    glTranslatef(0.0f, ringHeight, 0.0f);
    drawHollowRing(ringOuterRadius, ringInnerRadius, 0.1f, segments);
    glPopMatrix();

    // رسم الأرجل
    glColor3f(0.3f, 0.3f, 0.3f);
    drawLeg(legRadius, legHeight, segments);

    glPopMatrix(); // استعادة الحالة السابقة للمصفوفة
	
}

void drawFourBarStools(int chairTexture) {
   
	
		
	    glPushMatrix();
        glTranslatef(0.0f, 0.0f, -0.5f);  // نقل كل كرسي بمسافة معينة على المحور X
        drawBarStool(chairTexture);
        glPopMatrix();

		glPushMatrix();
        glTranslatef(4.0f, 0.0f, -1.0f);  // نقل كل كرسي بمسافة معينة على المحور X
        drawBarStool(chairTexture);
        glPopMatrix();

		glPushMatrix();
        glTranslatef(-4.0f, 0.0f, -1.0f);  // نقل كل كرسي بمسافة معينة على المحور X
        drawBarStool(chairTexture);
        glPopMatrix();
		
		glColor3f(1.0f, 1.0f, 1.0f);

  
}



	
void DrawResturant(int floorTexture ,int fixglass ,int glassTexture,int screen,int doorTexture ,int wallRe,int chairTexture,int tableTexture,int tablelegTexture,int fruitcone,int fenceTexture,int flowresTexture,int grass,int logoTexture,int deskTexture,int topDeskTexture)
{

	drawCurvedReceptionDesk(deskTexture,topDeskTexture);
	DrawGround(-30,0,-10,30,0,20,floorTexture);
	DrawTableChair(tableTexture,tablelegTexture,chairTexture);
	drawFourBarStools(chairTexture);
	drawDecore(fruitcone,grass,fenceTexture,flowresTexture);
	drawStructure(wallRe,floorTexture);
	DrawStructurebeu(fixglass);
	//DrawStructureGlass(-6,2,-10,6,12,-10,logoTexture);
	DrawStructureGlass(-6,4,-10,6,14,-10,logoTexture,0,1);
	DrawStructureGlass(-25,0.6,20,-18.2,12,20,glassTexture);
	DrawStructureGlass(-18,0.6,20,-12,12,20,glassTexture);
	DrawStructureGlass(25,0.6,20,18.2,12,20,glassTexture);
	DrawStructureGlass(18,0.6,20,12,12,20,glassTexture);
	DrawStructureGlass(-10,0,20,-7,12,20,doorTexture);
	DrawStructureGlass(10,0,20,7,12,20,doorTexture);
	DrawStructureGlass(-4,8,20,4,12,20,screen);
	
}
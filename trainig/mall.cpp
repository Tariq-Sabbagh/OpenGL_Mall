#include "mall.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "gltexture.h"
#include "Model_3DS.h"
#include "texture.h"
#include "Resturant.h"
#include "backgorund.h"
#include "Decore.h"
#include "display_rectangular_parallelepiped.h"
#include <math.h>
#define M_PI 3.14140265358979323846
#define radian(deg) ((deg) * M_PI / 180.0)




void DrawMall(int upfront,int wall,int glass,int up,int floorMall)
{
	glEnable(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D, upfront);
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
    // front1
				glTexCoord2f(0, 0); 
	  glVertex3f(-60, 40, -60);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-5, 40, -60);   
				glTexCoord2f(1,1); 
	  glVertex3f(-5, 25, -60);    // منتصف الوجه
				glTexCoord2f(0, 1); 
	  glVertex3f(-60, 25, -60);
	  glEnd();

	// front 2 
	//1
	  glBindTexture(GL_TEXTURE_2D, wall);
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glVertex3f(-60, 25, -60);  
			glTexCoord2f(0, 0); 
	glVertex3f(-35, 25, -60);   // النقطة عند الثلث الأيمن
			glTexCoord2f(1, 0); 
	glVertex3f(-35, 0, -60);    
			glTexCoord2f(1, 1); 
	glVertex3f(-60, 0, -60);
			glTexCoord2f(0, 1); 
			glEnd();
	// 2
			glBindTexture(GL_TEXTURE_2D, glass);
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
			glTexCoord2f(0, 0); 
	glVertex3f(-35, 25, -60);  
			glTexCoord2f(1, 0); 
	glVertex3f(-20, 25, -60);   // النقطة في المنتصف
			glTexCoord2f(1, 1); 
	glVertex3f(-20, 0, -60);    
			glTexCoord2f(0, 1); 
	glVertex3f(-35, 0, -60);
	glEnd();

	// 3
	glBindTexture(GL_TEXTURE_2D, wall);
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
			glTexCoord2f(0, 0); 
	glVertex3f(-20, 25, -60);  
			glTexCoord2f(1, 0); 
	glVertex3f(-5, 25, -60);    // النقطة عند الثلث الأيسر
			glTexCoord2f(1, 1); 
	glVertex3f(-5, 0, -60);    
			glTexCoord2f(0, 1); 
	glVertex3f(-20, 0, -60);
	glEnd();


		// back
	glBindTexture(GL_TEXTURE_2D, wall);
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-60, 40, -5);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-60, 0, -5);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-5, 0, -5);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-5, 40, -5);
	  glEnd();

		// up
	  glBindTexture(GL_TEXTURE_2D, up);
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-60, 40, -60);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-5, 40, -60);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-5, 40, -5);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-60, 40, -5);
	  glEnd();

		// floor
	  glBindTexture(GL_TEXTURE_2D, floorMall);
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
	 
				glTexCoord2f(0, 0); 
	  glVertex3f(-60, 0, -60);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-60, 0, -5);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-5, 0, -5);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-5, 0, -60);
	  glEnd();

		// right
	  glBindTexture(GL_TEXTURE_2D, floorMall);
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-5, 40, -60);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-5, 40, -5);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-5, 0, -5);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-5, 0, -60);
	  glEnd();

		// left
	  glBindTexture(GL_TEXTURE_2D, wall);
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-60, 40, -60);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-60, 40, -5);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-60, 0, -5);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-60, 0, -60);

		glEnd(); 
	
	 
    glDisable(GL_TEXTURE_2D);
}

void drawMall(int glassTexture,int wallTexture,int logo,int door)
{
	glEnable(GL_TEXTURE_2D);//right
	 glBindTexture(GL_TEXTURE_2D, wallTexture);
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-60, 40, -40);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-5, 40, -40);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-5, 1.1, -40);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-60, 1.1, -40);

		glEnd(); 
		 glBindTexture(GL_TEXTURE_2D, wallTexture);//back
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-60, 40, -40);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-60, 40, 40);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-60, 1.1, 40);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-60, 1.1, -40);

		glEnd(); 
			 glBindTexture(GL_TEXTURE_2D, wallTexture);//left
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-60, 40, 40);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-5, 40, 40);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-5, 1.1, 40);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-60, 1.1, 40);

		glEnd(); 

		 glBindTexture(GL_TEXTURE_2D, glassTexture);//cilinet
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-60, 40, 40);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-5, 40, 40);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-5, 40, -40);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-60, 40, -40);

		glEnd(); 

		 glBindTexture(GL_TEXTURE_2D, wallTexture);//front left
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-5, 40, 40);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-5, 1.1, 40);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-5, 1.1, 20);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-5, 40, 20);

		glEnd(); 
		glBindTexture(GL_TEXTURE_2D, wallTexture);//back left
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-5, 40, 20);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-5, 1.1, 20);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-15, 1.1, 20);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-15, 40, 20);

		glEnd(); 
		glBindTexture(GL_TEXTURE_2D, wallTexture);//back front left
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-15, 40, 20);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-15, 1.1, 20);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-15, 1.1, 10);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-15, 40, 10);

		glEnd(); 


		glBindTexture(GL_TEXTURE_2D, wallTexture);//front right
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-5, 40, -40);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-5, 1.1, -40);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-5, 1.1, -20);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-5, 40, -20);

		glBindTexture(GL_TEXTURE_2D, wallTexture);//back right
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-5, 40, -20);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-5, 1.1, -20);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-15, 1.1, -20);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-15, 40, -20);

		glEnd(); 
		glBindTexture(GL_TEXTURE_2D, wallTexture);//back front right
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-15, 40, -20);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-15, 1.1, -20);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-15, 1.1, -10);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-15, 40, -10);

		glEnd(); 

		glBindTexture(GL_TEXTURE_2D, logo);//back front front
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-15, 40, -40);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-15, 20, -10);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-15, 20, 10);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-15, 40, 10);

		glEnd(); 

	

		

		




}

void drawleftDoor(int door)
{
	glBindTexture(GL_TEXTURE_2D, door);//left door
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-15, 20, 10);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-15, 1.1, 10);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-15, 1.1, 0);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-15, 20, 0);

		glEnd(); 
}


void drawRightDoor(int door)
{
	glBindTexture(GL_TEXTURE_2D, door);//right door
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-15, 20, 0);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-15, 1.1, 0);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-15, 1.1, -10);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-15, 20, -10);

		glEnd(); 
}


void drawLoby(int image)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);
    glColor3f(1,1,1);
	glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-60, 12, -40);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-15, 12, -40);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-15, 12, -10);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-60, 12, -10);

		glEnd(); 

		glBegin(GL_QUADS);
				glTexCoord2f(0, 0); 
	  glVertex3f(-60, 12, 40);  
				glTexCoord2f(1, 0); 
	  glVertex3f(-15, 12, 40);   
				glTexCoord2f(1, 1); 
	  glVertex3f(-15, 12, 10);    
				glTexCoord2f(0, 1); 
	  glVertex3f(-60, 12, 10);

		glEnd(); 


		glDisable(GL_TEXTURE_2D);


}














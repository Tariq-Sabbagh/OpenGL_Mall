#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include "texture.h"
#include "corridor.h"
#include "staircase.h"



// x and y are teh frist coordinates from the top left;
void drawFloor(float cooridorWidth, float corridorLength, float x, float y, float z, int image);
void wallPiece(float corridorHeight, float corridorLength, float doorWidth, float doorHeight,float x, float y, float z, bool leftPiece, int image);
void corridor(float corridorLength, float corridorWidth, float corridorHeight, float doorWidth, float doorHeight, float x, float y,float z , int wallImage, int floorImage, int ceilImage);


void corridor(float corridorLength, float corridorWidth, float corridorHeight, float doorWidth, float doorHeight, float x, float y, float z, int wallImage, int floorImage, int ceilImage){

	// the roof
	drawFloor(corridorWidth, corridorLength, x,y,z, ceilImage);
	bool isLeftPiece = true;

	// the left wall


	  for(float i = z; i> -corridorLength+z;i-=(corridorLength/4)){
	  	wallPiece(corridorHeight, corridorLength, doorWidth, doorHeight, x, y, i, isLeftPiece, wallImage);
	  	isLeftPiece=!isLeftPiece;
	  }


	  for(float i = z; i> -corridorLength+z;i-=(corridorLength/4)){
	  	wallPiece(corridorHeight, corridorLength, doorWidth, doorHeight, x + corridorWidth, y, i, isLeftPiece, wallImage);
	  	isLeftPiece=!isLeftPiece;
	  }

	// the bottom drawFloor
	drawFloor(corridorWidth, corridorLength, x, y - corridorHeight, z,floorImage);

	// draw back wall
	drawRect(x, y - corridorHeight, z - corridorLength, corridorWidth, corridorHeight, wallImage);
}


void wallPiece(float corridorHeight, float corridorLength, float doorWidth, float doorHeight,float x, float y, float z, bool leftPiece, int image){

	float topLength = corridorLength / 4.0;
	float bottomLength = topLength - (0.5 * doorWidth);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);
	if(leftPiece){
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, corridorHeight - doorHeight);	 glVertex3f(x, y, z);
		glTexCoord2f(0.0f, 0.0f);							 glVertex3f(x, y - corridorHeight + doorHeight, z);
		glTexCoord2f(topLength, 0.0f);						 glVertex3f(x, y - corridorHeight + doorHeight, z-topLength);
		glTexCoord2f(topLength, corridorHeight -doorHeight); glVertex3f(x, y , z-topLength);
 

		glTexCoord2f(0.0f, doorHeight);				glVertex3f(x, y - corridorHeight + doorHeight, z);
		glTexCoord2f(0.0f, 0.0f);					glVertex3f(x , y - corridorHeight , z);
		glTexCoord2f(bottomLength, 0.0f);			glVertex3f(x, y - corridorHeight , z - bottomLength);
		glTexCoord2f(bottomLength, doorHeight);		glVertex3f(x , y - corridorHeight + doorHeight, z - bottomLength);
	glEnd();
	} else {

		glBegin(GL_QUADS);

		glTexCoord2f(0.0f, corridorHeight - doorHeight);	 	glVertex3f(x , y, z);
		glTexCoord2f(0.0f, 0.0f);							 	glVertex3f(x , y - corridorHeight + doorHeight, z );
		glTexCoord2f(topLength, 0.0f);						 	glVertex3f(x , y - corridorHeight + doorHeight, z - topLength);
		glTexCoord2f(topLength, corridorHeight -doorHeight); 	glVertex3f(x , y, z - topLength);

		glTexCoord2f(0.0f, doorHeight);						glVertex3f(x, y - corridorHeight + doorHeight, z - topLength + bottomLength);
		glTexCoord2f(0.0f, 0.0f);							glVertex3f(x , y - corridorHeight , z - topLength + bottomLength);
		glTexCoord2f(bottomLength, 0.0f);					glVertex3f(x, y - corridorHeight , z - topLength);
		glTexCoord2f(bottomLength, doorHeight);				glVertex3f(x , y, z - topLength);
		glEnd();

	}
	glDisable(GL_TEXTURE_2D);
}

// x and y are the coordinates of the front top left point
void drawFloor(float corridorWidth, float corridorLength, float x, float y, float z, int image){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);glVertex3f(x, y, z);
	glTexCoord2f(corridorWidth, 0.0f);glVertex3f(x + corridorWidth , y, z);
	glTexCoord2f(corridorWidth, corridorLength);glVertex3f(x + corridorWidth , y, z-corridorLength);
	glTexCoord2f(0.0f,corridorLength);glVertex3f(x , y, z-corridorLength);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}


void drawFloorStretch(float corridorWidth, float corridorLength, float x, float y, float z, int image){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);glVertex3f(x + corridorWidth , y, z);
	glTexCoord2f(1.0f, 1.0f);glVertex3f(x + corridorWidth , y, z-corridorLength);
	glTexCoord2f(0.0f,1.0f);glVertex3f(x , y, z-corridorLength);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}


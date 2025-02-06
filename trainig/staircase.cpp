#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include "texture.h"
#include "staircase.h"



void drawStep(float rise, float run, float width, float x, float y, float z, int frontFacingStep, int topFacingStep){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, frontFacingStep);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(width, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(width, run); glVertex3f(x + width, y + rise, z);
	glTexCoord2f(0.0f, run); glVertex3f(x, y + rise, z);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, topFacingStep);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y + rise, z);
	glTexCoord2f(width, 0.0f); glVertex3f(x + width, y + rise, z);
	glTexCoord2f(width, run); glVertex3f(x + width, y + rise, z - run);
	glTexCoord2f(0.0f, run); glVertex3f(x, y + rise, z - run);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}


void drawSteps(int numOfSteps, float run, float rise, float width, float x, float y, float z, int frontFacingStep, int topFacingStep, int sidesImage){
	for(int i=0; i< numOfSteps ; i++){
		drawStep(rise, run, width, x, y+i*rise, z-i*run, frontFacingStep, topFacingStep);
	}
}

// x, y, z are the coords of the bottom front left facing corner


void drawRect(float x, float y, float z, float width, float height, int image){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
		glTexCoord2f(width, 0.0f);glVertex3f(x+width, y, z);
		glTexCoord2f(width, height);glVertex3f(x+width, y+height, z);
		glTexCoord2f(0.0f, height);glVertex3f(x, y+height, z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}


void drawVerticalFenceLeg(float x, float y, float z, float width, float height, int image){
	glPushMatrix();
	drawRect(x, y, z, width, height, image);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(90, 0, 1, 0);
	drawRect(0,0,0, width, height, image);
	glPopMatrix();

	 glPushMatrix();
	 glTranslatef(x + width, y, z);
	 glRotatef(90, 0, 1, 0);
	 drawRect(0, 0, 0, width, height, image);
	 glPopMatrix();

	glPushMatrix();
	glTranslated(x, y, z-width);
	drawRect(0, 0, 0, width, height, image);
	glPopMatrix();
}

// x y z are the front top left after rotation
void drawHorizontalFenceLeg(float x, float y, float z, float width, float length, int image){
	glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(-90, 1, 0, 0);
		drawVerticalFenceLeg(0, 0, 0, width, length, image);
	glPopMatrix();
}


void drawInclinedFenceLeg(float x1, float y1, float z1, float x2, float y2, float z2, float width, int image){
	// top side
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(x1, y1, z1);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(x1 + width, y1, z1);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(x1 + width, y2, z2);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(x1 , y2, z2);
	glEnd();
	glPopMatrix();

	// bottom side
	glPushMatrix();
	glTranslatef(0.0f, -width, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(x1, y1, z1);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(x1 + width, y1, z1);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(x1 + width, y2, z2);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(x1 , y2, z2);
	glEnd();
	glPopMatrix();

	// left side
	glPushMatrix();
	glTranslatef(0.0f, -width, 0.0f);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(x2, y2, z2);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(x1, y1 , z1);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(x1, y1 + width, z1);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(x2, y2 + width, z2);
	glEnd();
	glPopMatrix();


	// right side
	glPushMatrix();
	glTranslatef(width, -width, 0.0f);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(x2, y2, z2);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(x1, y1 , z1);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(x1, y1 + width, z1);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(x2, y2 + width, z2);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

}


void drawFence(float x, float y, float z, float frontHeight, float backHeight, float bottomLength,float extraLength, float fenceWidth, float fenceHeight,float rise, float run , float numOfSteps,float extraRise,float margin, int image){
	// draw front vertical leg
	glPushMatrix();
		drawVerticalFenceLeg(x, y, z, fenceWidth, fenceHeight, image);
	glPopMatrix();

	// draw second front vertical leg
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, -(extraLength - margin));
		drawVerticalFenceLeg(x, y, z, fenceWidth, fenceHeight, image);
	glPopMatrix();

	// middle front vertical leg
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, - 0.5 * (extraLength - margin) + 0.5 * fenceWidth);
		drawVerticalFenceLeg(x, y, z, fenceWidth, fenceHeight, image);
	glPopMatrix();

	// draw front horizontal leg

	glPushMatrix();
		drawHorizontalFenceLeg(x, y+fenceHeight, z, fenceWidth, extraLength - margin, image);
	glPopMatrix();


	// draw bottom front horizontal leg

	glPushMatrix();
	glTranslatef(0.0f, -fenceHeight * 0.61, 0.0f);
		drawHorizontalFenceLeg(x, y+fenceHeight, z, fenceWidth, extraLength - margin, image);
	glPopMatrix();



	// draw the back horizontal Leg

	glPushMatrix();
	// y is already at the front height
		drawHorizontalFenceLeg(x, y + backHeight - frontHeight + fenceHeight,z + margin - bottomLength + extraLength + run, fenceWidth, extraLength - margin + run, image);
	glPopMatrix();


	// draw the bottom back horizontal leg
	glPushMatrix();
	// y is already at the front height
		glTranslatef(0.0f, -fenceHeight * 0.61, 0.0f);
		drawHorizontalFenceLeg(x, y + backHeight - frontHeight + fenceHeight,z + margin - bottomLength + extraLength + run, fenceWidth, extraLength - margin + run, image);
	glPopMatrix();


	// draw the back vertical leg

	glPushMatrix();
		drawVerticalFenceLeg(x, y + backHeight - frontHeight, z + 2 * margin - bottomLength , fenceWidth, fenceHeight, image);
	glPopMatrix();


	// draw the second back vertical leg
	glPushMatrix();
		glTranslatef(0.0f,0.0f, extraLength - margin + run);
		drawVerticalFenceLeg(x, y + backHeight - frontHeight, z + 2 * margin - bottomLength , fenceWidth, fenceHeight, image);
	glPopMatrix();


	// draw the middle vertical leg

	glPushMatrix();
		glTranslatef(0.0f,0.0f, 0.5 * (extraLength - margin + run) - 0.5 * fenceWidth);
		drawVerticalFenceLeg(x, y + backHeight - frontHeight, z + 2 * margin - bottomLength , fenceWidth, fenceHeight, image);
	glPopMatrix();



	// draw the top inclined leg
	glPushMatrix();

		drawInclinedFenceLeg(x, y+fenceHeight, z-extraLength+margin, x, y + backHeight - frontHeight + fenceHeight,z + margin - bottomLength + extraLength + run, fenceWidth, image);
	glPopMatrix();

	// draw the bottom inclined leg
	glPushMatrix();
		glTranslatef(0.0f, -fenceHeight * 0.61, 0.0f);
		drawInclinedFenceLeg(x, y+fenceHeight, z-extraLength+margin, x, y + backHeight - frontHeight + fenceHeight,z + margin - bottomLength + extraLength + run, fenceWidth, image);
	glPopMatrix();


	for(int i=2;i<=numOfSteps-2;i+=2){
		glPushMatrix();
		drawVerticalFenceLeg(x, y + i*rise  , z + margin - extraLength - i * run, fenceWidth, fenceHeight, image);
		glPopMatrix();
	}

}

void drawSide(float x, float y, float z, float rise, float run, float numOfSteps, float extraLength, float sideWidth, int image, int fenceImage){

	float extraRise =  0.25 * rise; 
	float bottomLength = (extraLength * 2) + (run * numOfSteps);

	float backHeight = (numOfSteps * rise) + extraRise;

	float frontHeight = rise + extraRise;

	// front face
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + sideWidth, y, z);
	glTexCoord2f(1.0f, 0.1f); glVertex3f(x + sideWidth, y + frontHeight, z);
	glTexCoord2f(0.0f,1.0f); glVertex3f(x, y + frontHeight, z);
	glEnd();



	// back face

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z - bottomLength);
	glTexCoord2f(1.0f, sideWidth); glVertex3f(x + sideWidth, y, z - bottomLength);
	glTexCoord2f(sideWidth, backHeight); glVertex3f(x + sideWidth, y + backHeight, z - bottomLength);
	glTexCoord2f(0.0f,backHeight); glVertex3f(x, y + backHeight, z -bottomLength);
	glEnd();

	// front top

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y + frontHeight, z);
	glTexCoord2f(sideWidth, 0.0f); glVertex3f(x + sideWidth, y + frontHeight, z);
	glTexCoord2f(sideWidth, extraLength); glVertex3f(x + sideWidth, y + frontHeight, z - extraLength);
	glTexCoord2f(0.0f,extraLength); glVertex3f(x, y + frontHeight, z - extraLength);
	glEnd();


	// middle top
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y + frontHeight, z - extraLength);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + sideWidth, y + frontHeight, z - extraLength);
	glTexCoord2f(1.0f, 3.0f); glVertex3f(x + sideWidth, y + backHeight, z - bottomLength + extraLength + run);
	glTexCoord2f(0.0f,3.0f); glVertex3f(x, y + backHeight, z - bottomLength + extraLength + run);
	glEnd();

	//back top

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y + backHeight, z - bottomLength + extraLength + run);
	glTexCoord2f(sideWidth, 0.0f); glVertex3f(x + sideWidth, y + backHeight, z - bottomLength + extraLength + run );
	glTexCoord2f(sideWidth, extraLength); glVertex3f(x + sideWidth, y + backHeight, z - bottomLength);
	glTexCoord2f(0.0f,extraLength); glVertex3f(x, y + backHeight, z - bottomLength);
	glEnd();


	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y + frontHeight, z);
	glTexCoord2f(sideWidth, 0.0f); glVertex3f(x + sideWidth, y + frontHeight, z);
	glTexCoord2f(sideWidth, extraLength); glVertex3f(x + sideWidth, y + frontHeight, z - extraLength);
	glTexCoord2f(0.0f,extraLength); glVertex3f(x, y + frontHeight, z - extraLength);
	glEnd();

	// left side
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
		glTexCoord2f(extraLength, 0.0f); glVertex3f(x, y, z-extraLength);
		glTexCoord2f(extraLength, frontHeight); glVertex3f(x, y+frontHeight, z-extraLength);
		glTexCoord2f(0.0f,frontHeight); glVertex3f(x, y + frontHeight, z);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z-extraLength);
		glTexCoord2f((numOfSteps -1) * run, 0.0f); glVertex3f(x, y, z-extraLength-((numOfSteps -1)*run));
		glTexCoord2f((numOfSteps - 1) * run, backHeight); glVertex3f(x, y+backHeight, z-extraLength-((numOfSteps -1)*run));
		glTexCoord2f(0.0f,frontHeight); glVertex3f(x, y + frontHeight, z - extraLength);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z-bottomLength+extraLength+run);
		glTexCoord2f(extraLength + run, 0.0f); glVertex3f(x, y, z-bottomLength);
		glTexCoord2f(extraLength + run, backHeight); glVertex3f(x, y+backHeight, z-bottomLength);
		glTexCoord2f(0.0f,backHeight); glVertex3f(x, y + backHeight, z - bottomLength+extraLength+run);
	glEnd();



	// right side

	glPushMatrix();
	glTranslated(sideWidth, 0, 0);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
		glTexCoord2f(extraLength, 0.0f); glVertex3f(x, y, z-extraLength);
		glTexCoord2f(extraLength, frontHeight); glVertex3f(x, y+frontHeight, z-extraLength);
		glTexCoord2f(0.0f,frontHeight); glVertex3f(x, y + frontHeight, z);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z-extraLength);
		glTexCoord2f((numOfSteps -1) * run, 0.0f); glVertex3f(x, y, z-extraLength-((numOfSteps -1)*run));
		glTexCoord2f((numOfSteps - 1) * run, backHeight); glVertex3f(x, y+backHeight, z-extraLength-((numOfSteps -1)*run));
		glTexCoord2f(0.0f,frontHeight); glVertex3f(x, y + frontHeight, z - extraLength);
	glEnd();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z-bottomLength+extraLength+run);
		glTexCoord2f(extraLength + run, 0.0f); glVertex3f(x, y, z-bottomLength);
		glTexCoord2f(extraLength + run, backHeight); glVertex3f(x, y+backHeight, z-bottomLength);
		glTexCoord2f(0.0f,backHeight); glVertex3f(x, y + backHeight, z - bottomLength+extraLength+run);
	glEnd();
	glPopMatrix();


	float fenceWidth = 0.1;
	float fenceHeight = 1.5;
	float margin = 0.5;
	glPushMatrix();
	drawFence(x + (sideWidth * 0.5) - (fenceWidth * 0.5), y + frontHeight, z-margin, frontHeight, backHeight, bottomLength, extraLength, fenceWidth, fenceHeight, rise, run,  numOfSteps,extraRise,margin, fenceImage);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}


void drawStaircaseFloor(float x, float y, float z, float width, float length, int image){
		glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
		glTexCoord2f(width, 0.0f); glVertex3f(x + width, y , z);
		glTexCoord2f(width, length); glVertex3f(x + width, y, z- length);
		glTexCoord2f(0.0f,length); glVertex3f(x, y, z-length);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}



// x, y, z are the coords of the bottom front left facing corner
void drawStairCase(int numOfSteps, float run, float rise, float width, float x, float y, float z,float sideWidth ,float frontAndBackExtraLength, int frontFacingStep, int topFacingStep, int sidesImage, int fenceImage){

	 glPushMatrix();
	  drawStaircaseFloor(x, y, z+frontAndBackExtraLength, width, frontAndBackExtraLength, topFacingStep);
	  drawStaircaseFloor(x, y + (numOfSteps * rise), z-(numOfSteps * run), width, frontAndBackExtraLength, topFacingStep);
	  drawSteps(numOfSteps,  run,  rise, width,  x, y, z, frontFacingStep, topFacingStep, sidesImage);
	 drawSide(x-sideWidth, y, z + frontAndBackExtraLength, rise, run ,numOfSteps, frontAndBackExtraLength, sideWidth, sidesImage, fenceImage);
	 drawSide(x+width-sideWidth, y, z + frontAndBackExtraLength, rise, run ,numOfSteps, frontAndBackExtraLength, sideWidth, sidesImage, fenceImage);
	 glPopMatrix();
}



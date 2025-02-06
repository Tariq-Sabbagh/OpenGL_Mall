#include "mall_lobby.h"

using namespace std;

void mall_lobby::drawMallLobbyWithoutPoints(int light_brown_wood,int green_leaves,int brown_wood,int glass,int frontFacingStep,
	int topFacingStep,
	int sidesImage,
	int fenceImage,
	int whiteMarbleImage,
	int hallFloorImage,
	int the_grass) {
	mall_lobby object;
	
	Point point1 = {0,0,0};
	Point point2 = {0,0,-30};
	Point point3 = {30,0,-30};
	Point point4 = {30,0,0};

	object.drawMallLobby(
		point1,
		point2,
		point3,
		point4,
		light_brown_wood,
		green_leaves,
		brown_wood,
		glass,
		the_grass
		);

	
	float CORRIDOR_HEIGHT = 30,
		CORRIDOR_WIDTH = 30 ,
		CORRIDOR_LENGTH = 80,
		DOOR_WIDTH = 7,
		DOOR_HEIGHT = 5,
		// staircase, keep it odd
		NUM_OF_STEPS=20,
		STAIRCASE_WIDTH = 7,
		STAIRCASE_RISE=0.5,
		STAIRCASE_RUN=1,
		STAIRCASE_SIDE_WIDTH=1,
		STAIRCASE_FENCE_WIDTH=0.1,
		STAIRCASE_EXTRA_LENGTH=4,
		// staircase total length
		staircaseTotalLength = STAIRCASE_EXTRA_LENGTH + NUM_OF_STEPS * STAIRCASE_RUN,
		staircaseTotalWidth = STAIRCASE_WIDTH + 2 * STAIRCASE_SIDE_WIDTH;

	// corridor coordinates
	// هون بس انت بتحط الاحداثيات تبع الزاوية الاولانية من فوق عاليسار من قدام للكوريدور مطرح ما بدك وهو بيعمل الباقي
	float secondFloorBackSpace =20;
	float x1 =0, y1 = 30, z1 = +5,
		//staircase coordinates
		x2 = x1+(CORRIDOR_WIDTH*0.5)-(staircaseTotalWidth*0.5) + 1.5 * STAIRCASE_SIDE_WIDTH,
		y2= y1-CORRIDOR_HEIGHT + 0.0001,
		z2= z1-CORRIDOR_LENGTH + staircaseTotalLength + secondFloorBackSpace;
	/*
		// هاد بينعمل تابع واحد مو مشكلة
		 glPushMatrix();
		 corridor(CORRIDOR_LENGTH, CORRIDOR_WIDTH, CORRIDOR_HEIGHT, DOOR_WIDTH, DOOR_HEIGHT, x1, y1, z1, whiteMarbleImage, hallFloorImage, whiteMarbleImage );
		 glPopMatrix();
		 */
		 glPushMatrix();
		 drawStairCase(NUM_OF_STEPS, STAIRCASE_RUN, STAIRCASE_RISE, STAIRCASE_WIDTH, x2, y2 , z2 , STAIRCASE_SIDE_WIDTH, STAIRCASE_EXTRA_LENGTH , frontFacingStep, topFacingStep, sidesImage, fenceImage) ;
		 glPopMatrix();


		 // second floor
		 float secondFloorSideWidth = (CORRIDOR_WIDTH - staircaseTotalWidth) / 2.0;
		 float secondFloorSideLength = CORRIDOR_LENGTH - 30.0 - z1 - secondFloorBackSpace;

		  glPushMatrix();
		  drawFloorStretch(secondFloorSideWidth, secondFloorSideLength, x1, 10, -30, light_brown_wood);
		  glPopMatrix();

		  glPushMatrix();
		  drawFloorStretch(secondFloorSideWidth, secondFloorSideLength, x1 + CORRIDOR_WIDTH - secondFloorSideWidth, 10, -30, light_brown_wood); glPopMatrix();


		  float middlePieceLength = 5;
		  glPushMatrix();
		  drawFloorStretch(CORRIDOR_WIDTH - 2*secondFloorSideWidth, middlePieceLength, x1 + secondFloorSideWidth, 10, -30, light_brown_wood);
		  glPopMatrix();
		  
		  // the back piece of the second floor
		 glPushMatrix();
		 drawFloorStretch(CORRIDOR_WIDTH, CORRIDOR_LENGTH - 30 - z1  - secondFloorSideLength, x1, 10, z1 - CORRIDOR_LENGTH + secondFloorBackSpace, light_brown_wood);
		 glPopMatrix();

		 // drawing a fence
		 float margin = 0.5;
		 float fenceLegWidth = 0.1;
		 float fenceLegHeight = 2;
		 // left fence
		 for(float i=0;i<secondFloorSideLength - middlePieceLength -margin ;i+=4){
			drawVerticalFenceLeg(x1+secondFloorSideWidth-margin-fenceLegWidth, 10 + 0.02, z1 - CORRIDOR_LENGTH + secondFloorBackSpace + margin + fenceLegWidth + i, fenceLegWidth, fenceLegHeight, fenceImage);
		 }
		 // right fence
		 for(float i=0;i<secondFloorSideLength - middlePieceLength - margin;i+=4){
			drawVerticalFenceLeg(x1+CORRIDOR_WIDTH-secondFloorSideWidth+margin, 10 + 0.02, z1 - CORRIDOR_LENGTH + secondFloorBackSpace + margin + fenceLegWidth + i, fenceLegWidth, fenceLegHeight, fenceImage);
		 }



		 float middlePieceWidth = CORRIDOR_WIDTH - 2*secondFloorSideWidth;
		 //front fence
		 for(float i=0;i<middlePieceWidth - margin;i+=middlePieceLength/2){
			drawVerticalFenceLeg(x1 + secondFloorSideWidth + margin + i, 10 + 0.02, -30 -middlePieceLength+ margin+2*fenceLegWidth, fenceLegWidth, fenceLegHeight, fenceImage);
		 }

		 // left fence horizontal
		 drawHorizontalFenceLeg(x1+secondFloorSideWidth-margin-fenceLegWidth, 10 + fenceLegHeight + 0.02, -30 - middlePieceLength + margin + fenceLegWidth, fenceLegWidth, secondFloorSideLength - middlePieceLength, fenceImage);

		 glPushMatrix();
		 glTranslatef(0,-0.6*fenceLegHeight,0);
		 drawHorizontalFenceLeg(x1+secondFloorSideWidth-margin-fenceLegWidth, 10 + fenceLegHeight + 0.02, -30 - middlePieceLength + margin + fenceLegWidth, fenceLegWidth, secondFloorSideLength - middlePieceLength, fenceImage);
		 glPopMatrix();

		 // right fence horizontal
		 glPushMatrix();
		 glTranslatef(CORRIDOR_WIDTH-2*secondFloorSideWidth+2*margin+fenceLegWidth, 0, 0);
		 drawHorizontalFenceLeg(x1+secondFloorSideWidth-margin-fenceLegWidth, 10 + fenceLegHeight+0.02, -30 - middlePieceLength + margin + fenceLegWidth, fenceLegWidth, secondFloorSideLength - middlePieceLength, fenceImage);
		glPopMatrix();


		 glPushMatrix();
		 glTranslatef(CORRIDOR_WIDTH-2*secondFloorSideWidth+2*margin+fenceLegWidth, -0.6*fenceLegHeight, 0);
		 drawHorizontalFenceLeg(x1+secondFloorSideWidth-margin-fenceLegWidth, 10 + fenceLegHeight+0.02, -30 - middlePieceLength + margin + fenceLegWidth, fenceLegWidth, secondFloorSideLength - middlePieceLength, fenceImage);
		glPopMatrix();


		// front fence horizontal
		glPushMatrix();
		glTranslatef(x1+secondFloorSideWidth-margin-fenceLegWidth,10 + fenceLegHeight+0.02,-30 - middlePieceLength + margin + fenceLegWidth);
		glRotatef(-90, 0.0, 1.0, 0.0);
		drawHorizontalFenceLeg(0, 0,0, fenceLegWidth, middlePieceWidth + 2* margin + 2*fenceLegWidth, fenceImage);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(x1+secondFloorSideWidth-margin-fenceLegWidth,10 + fenceLegHeight+0.02 - 0.6*fenceLegHeight,-30 - middlePieceLength + margin + fenceLegWidth);
		glRotatef(-90, 0.0, 1.0, 0.0);
		drawHorizontalFenceLeg(0, 0,0, fenceLegWidth, middlePieceWidth + 2* margin + 2*fenceLegWidth, fenceImage);
		glPopMatrix();
}

void mall_lobby::drawMallLobby(Point point1,Point point2,Point point3,Point point4,int floor_texture,int green_leaves,int brown_wood,int glass,int the_grass) {
	mall_lobby object;
	object.drawSecondFloor(point1,point2,point3,point4,floor_texture,glass);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, floor_texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(point1.x, point1.y, point1.z);
	glTexCoord2f(1, 0); glVertex3f(point2.x, point2.y, point2.z - 40);
	glTexCoord2f(1, 1); glVertex3f(point3.x, point3.y, point3.z - 40);
	glTexCoord2f(0, 1); glVertex3f(point4.x, point4.y, point4.z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, the_grass);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(point1.x + 10, point1.y, point1.z - 10);
	glTexCoord2f(1, 0); glVertex3f(point1.x + 10, point1.y, point1.z - 18);
	glTexCoord2f(1, 1); glVertex3f(point1.x + 16, point1.y, point1.z - 18);
	glTexCoord2f(0, 1); glVertex3f(point1.x + 16, point1.y, point1.z - 10);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, glass);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(point1.x + 10, point1.y, point1.z - 10);
	glTexCoord2f(1, 0); glVertex3f(point1.x + 10, point1.y, point1.z - 18);
	glTexCoord2f(1, 1); glVertex3f(point1.x + 10, point1.y + 1, point1.z - 18);
	glTexCoord2f(0, 1); glVertex3f(point1.x + 10, point1.y + 1, point1.z - 10);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, glass);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(point1.x + 10, point1.y, point1.z - 18);
	glTexCoord2f(1, 0); glVertex3f(point1.x + 16, point1.y, point1.z - 18);
	glTexCoord2f(1, 1); glVertex3f(point1.x + 16, point1.y + 1, point1.z - 18);
	glTexCoord2f(0, 1); glVertex3f(point1.x + 10, point1.y + 1, point1.z - 18);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, glass);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(point1.x + 16, point1.y, point1.z - 18);
	glTexCoord2f(1, 0); glVertex3f(point1.x + 16, point1.y, point1.z - 10);
	glTexCoord2f(1, 1); glVertex3f(point1.x + 16, point1.y + 1, point1.z - 10);
	glTexCoord2f(0, 1); glVertex3f(point1.x + 16, point1.y + 1, point1.z - 18);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, glass);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(point1.x + 10, point1.y, point1.z - 10);
	glTexCoord2f(1, 0); glVertex3f(point1.x + 16, point1.y, point1.z - 10);
	glTexCoord2f(1, 1); glVertex3f(point1.x + 16, point1.y + 1, point1.z - 10);
	glTexCoord2f(0, 1); glVertex3f(point1.x + 10, point1.y + 1, point1.z - 10);
	glEnd();

	Point palm_tree_1 = {point1.x + 14,point1.y,point1.z-17};
	Point palm_tree_2 = {point1.x + 11,point1.y,point1.z-14};
	Point palm_tree_3 = {point1.x + 13,point1.y,point1.z-11};
	object.drawPalmTree(palm_tree_1,15,green_leaves,brown_wood);
	object.drawPalmTree(palm_tree_2,10,green_leaves,brown_wood);
	object.drawPalmTree(palm_tree_3,7,green_leaves,brown_wood);
	glDisable(GL_TEXTURE_2D);
}

void mall_lobby::drawSecondFloor(Point point1,Point point2,Point point3,Point point4,int floor_texture,int glass) {
	GLdouble height_of_the_mall_looby = 20;
	GLdouble the_width_of_the_second_floor = 4;
	point1.y = point1.y + height_of_the_mall_looby/2;
	point2.y = point2.y + height_of_the_mall_looby/2;
	point3.y = point3.y + height_of_the_mall_looby/2;
	point4.y = point4.y + height_of_the_mall_looby/2;

	Point point_1 = {point1.x + the_width_of_the_second_floor,point1.y,point1.z - the_width_of_the_second_floor};
	Point point_2 = {point2.x + the_width_of_the_second_floor,point2.y,point2.z + the_width_of_the_second_floor};
	Point point_3 = {point3.x - the_width_of_the_second_floor,point3.y,point3.z + the_width_of_the_second_floor};
	Point point_4 = {point4.x - the_width_of_the_second_floor,point4.y,point4.z - the_width_of_the_second_floor};
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, glass);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(point_1.x, point_1.y, point_1.z);
	glTexCoord2f(1, 0); glVertex3f(point_1.x, point_1.y + 2, point_1.z);
	glTexCoord2f(1, 1); glVertex3f(point_2.x, point_2.y + 2, point_2.z);
	glTexCoord2f(0, 1); glVertex3f(point_2.x, point_2.y, point_2.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(point_3.x, point_3.y, point_3.z);
	glTexCoord2f(1, 0); glVertex3f(point_3.x, point_3.y + 2, point_3.z);
	glTexCoord2f(1, 1); glVertex3f(point_4.x, point_4.y + 2, point_4.z);
	glTexCoord2f(0, 1); glVertex3f(point_4.x, point_4.y, point_4.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(point_1.x, point_1.y, point_1.z);
	glTexCoord2f(1, 0); glVertex3f(point_1.x, point_1.y + 2, point_1.z);
	glTexCoord2f(1, 1); glVertex3f(point_4.x, point_4.y + 2, point_4.z);
	glTexCoord2f(0, 1); glVertex3f(point_4.x, point_4.y, point_4.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(point_2.x, point_2.y, point_2.z);
	glTexCoord2f(1, 0); glVertex3f(point_2.x, point_2.y + 2, point_2.z);
	glTexCoord2f(1, 1); glVertex3f(point_3.x, point_3.y + 2, point_3.z);
	glTexCoord2f(0, 1); glVertex3f(point_3.x, point_3.y, point_3.z);
	glEnd();

	Point point11 = {point1.x,point1.y,point1.z - the_width_of_the_second_floor};
	Point point22 = {point2.x,point2.y,point2.z + the_width_of_the_second_floor};
	Point point33 = {point3.x,point3.y,point3.z + the_width_of_the_second_floor};
	Point point44 = {point4.x,point4.y,point4.z - the_width_of_the_second_floor};

	Point point111 = {point1.x + the_width_of_the_second_floor,point1.y,point1.z};
	Point point222 = {point2.x + the_width_of_the_second_floor,point2.y,point2.z};
	Point point333 = {point3.x - the_width_of_the_second_floor,point3.y,point3.z};
	Point point444 = {point4.x - the_width_of_the_second_floor,point4.y,point4.z};

	glBindTexture(GL_TEXTURE_2D, floor_texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(point1.x, point1.y, point1.z);
	glTexCoord2f(1, 0); glVertex3f(point11.x, point11.y, point11.z);
	glTexCoord2f(1, 1); glVertex3f(point44.x, point44.y, point44.z);
	glTexCoord2f(0, 1); glVertex3f(point4.x, point4.y, point4.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(point22.x, point22.y, point22.z);
	glTexCoord2f(1, 0); glVertex3f(point2.x, point2.y, point2.z);
	glTexCoord2f(1, 1); glVertex3f(point3.x, point3.y, point3.z);
	glTexCoord2f(0, 1); glVertex3f(point33.x, point33.y, point33.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(point1.x, point1.y, point1.z);
	glTexCoord2f(1, 0); glVertex3f(point2.x, point2.y, point2.z);
	glTexCoord2f(1, 1); glVertex3f(point222.x, point222.y, point222.z);
	glTexCoord2f(0, 1); glVertex3f(point111.x, point111.y, point111.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(point444.x, point444.y, point444.z);
	glTexCoord2f(1, 0); glVertex3f(point333.x, point333.y, point333.z);
	glTexCoord2f(1, 1); glVertex3f(point3.x, point3.y, point3.z);
	glTexCoord2f(0, 1); glVertex3f(point4.x, point4.y, point4.z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void mall_lobby::drawCylinder(float baseRadius, float topRadius, float height, int slices, int stacks) {
    GLUquadric* quad = gluNewQuadric();
    gluCylinder(quad, baseRadius, topRadius, height, slices, stacks);
    gluDeleteQuadric(quad);
}

void mall_lobby::drawPalmTree(Point point,float height,int green_leaves,int brown_wood) {
    float trunkHeight = height * 0.8f;
    float trunkRadius = height * 0.05f;
    float leafLength = height * 0.3f;
	glEnable(GL_TEXTURE_2D);
    glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, brown_wood);
    glTranslatef(point.x, point.y, point.z);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(trunkRadius, trunkRadius * 0.2f, trunkHeight, 16, 16);
    glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, green_leaves);
	for (int i = 0; i < 360; i += 60) {
		glPushMatrix();
		glTranslatef(point.x, point.y + trunkHeight, point.z);
        glRotatef(i, 0.0f, 1.0f, 0.0f);
        glBegin(GL_TRIANGLES);
		glTexCoord2f(0.5f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-leafLength * 0.2f, 0.0f, leafLength);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(leafLength * 0.2f, 0.0f, leafLength);
        glEnd();
		glPopMatrix();
    }
	for (int i = 0; i < 360; i += 60) {
		glPushMatrix();
		glTranslatef(point.x, point.y + trunkHeight, point.z);
        glRotatef(i, 0.0f, 1.0f, 0.0f);
        glBegin(GL_TRIANGLES);
		glTexCoord2f(0.5f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-leafLength * 0.2f, 0.0f + 1, leafLength);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(leafLength * 0.2f, 0.0f + 1, leafLength);
        glEnd();
		glPopMatrix();
    }
	for (int i = 0; i < 360; i += 60) {
		glPushMatrix();
		glTranslatef(point.x, point.y + trunkHeight, point.z);
        glRotatef(i, 0.0f, 1.0f, 0.0f);
        glBegin(GL_TRIANGLES);
		glTexCoord2f(0.5f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-leafLength * 0.2f, 0.0f -1, leafLength);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(leafLength * 0.2f, 0.0f - 1, leafLength);
        glEnd();
		glPopMatrix();
    }
	for (int i = 0; i < 360; i += 60) {
		glPushMatrix();
		glTranslatef(point.x, point.y + trunkHeight, point.z);
        glRotatef(i, 0.0f, 1.0f, 0.0f);
        glBegin(GL_TRIANGLES);
		glTexCoord2f(0.5f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-leafLength * 0.2f, 0.0f - 2, leafLength);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(leafLength * 0.2f, 0.0f - 2, leafLength);
        glEnd();
		glPopMatrix();
    }
	glDisable(GL_TEXTURE_2D);
}

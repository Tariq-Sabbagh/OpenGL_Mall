#include <windows.h>
#include <gl.h>
#include <glu.h>
#include <glaux.h>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include "point.h"
#include <fstream>
#include "staircase.h"
#include "corridor.h"

class mall_lobby
{
public:
	void drawMallLobbyWithoutPoints(int light_brown_wood,int green_leaves,int brown_wood,int glass,int frontFacingStep,
	int topFacingStep,
	int sidesImage,
	int fenceImage,
	int whiteMarbleImage,
	int hallFloorImage,
	int the_grass);

	void drawMallLobby(Point point1,Point point2,Point point3,Point point4,int floor_texture,int green_leaves,int brown_wood,int glass,int the_grass);
	void drawSecondFloor(Point point1,Point point2,Point point3,Point point4,int floor_texture,int glass);

	void drawCylinder(float baseRadius, float topRadius, float height, int slices, int stacks);
	void drawPalmTree(Point point,float height,int green_leaves,int brown_wood);
};


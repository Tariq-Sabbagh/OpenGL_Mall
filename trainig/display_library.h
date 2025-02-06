#include <windows.h>
#include <gl.h>
#include <glu.h>
#include <glaux.h>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include "point.h"

class DisplayLibrary {
public:
	void drawLibraryWithoutPoints(
		int brown_wood,
		int wooden_bookshelf,
		int light_brown_wood,
		int glass,
		int library_store
		);
	void drawLibrary(
		Point point1,
		Point point2,
		Point point3,
		Point point4,
		GLdouble height,
		int brown_wood,
		int wooden_bookshelf,
		int light_brown_wood,
		int glass,
		int library_store
		);
	void drawOneBookshelf(
		Point point1,
		Point point2,
		Point point3,
		Point point4,
		GLdouble height,
		int brown_wood,
		int wooden_bookshelf
		);
};


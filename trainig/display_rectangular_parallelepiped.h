#include <windows.h>
#include <gl.h>
#include <glu.h>
#include <glaux.h>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include "point.h"

class DisplayRectangularParallelepiped {
public: 
	void displayElectronicStore(
		int brown_wood,
		int mobile_screen,
		int laptop_screen,
		int keyboard,
		int TV_screen,
		int grey_wood,
		int grey,
		int black,
		int light_brown_wood,
		int glass,
		int electronics_store
		);
	void displayAppleStore(
		Point point1,
		Point point2,
		Point point3,
		Point point4,
		GLdouble height,
		int brown_wood,
		int mobile_screen,
		int laptop_screen,
		int keyboard,
		int TV_screen,
		int grey_wood,
		int grey,
		int black,
		int light_brown_wood,
		int glass,
		int electronics_store
		);
	void displayWoodenRectangularParallelepiped(
		Point point1,
		Point point2,
		Point point3,
		Point point4,
		GLdouble thickness,
		int brown_wood
		);
	void displayMobileShelf(
		Point point1,
		Point point2,
		Point point3,
		Point point4,
		GLdouble thickness,
		int brown_wood,
		int mobile_screen,
		int grey
		);
	void displayOneMobile(
		Point point1,
		Point point2,
		Point point3,
		Point point4,
		int mobile_screen,
		int grey
		);
	void displayLaptopShelf(
		Point point1,
		Point point2,
		Point point3,
		Point point4,
		GLdouble thickness,
		int brown_wood,
		int laptop_screen,
		int keyboard,
		int grey
		);
	void displayOneLaptop(
		Point point1,
		Point point2,
		Point point3,
		Point point4,
		int laptop_screen,
		int keyboard,
		int grey
		);
	void displayTV(
		Point point1,
		Point point2,
		Point point3,
		Point point4,
		int TV_screen,
		int black
		);
};


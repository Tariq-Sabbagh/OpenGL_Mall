#include "display_rectangular_parallelepiped.h"

using namespace std;

void DisplayRectangularParallelepiped::displayElectronicStore(
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
	) {
		Point point1 = {0,0,0};
		Point point2 = {0,0,-10};
		Point point3 = {10,0,-10};
		Point point4 = {10,0,0};
		GLdouble height = 5;

		DisplayRectangularParallelepiped object;
		object.displayAppleStore(
			point1,
			point2,
			point3,
			point4,
			height,
			brown_wood,
			mobile_screen,
			laptop_screen,
			keyboard,
			TV_screen,
			grey_wood,
			grey,
			black,
			light_brown_wood,
			glass,
			electronics_store
			);
}

void DisplayRectangularParallelepiped::displayAppleStore(
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
	) {
		GLdouble the_height_of_the_mobile_shelf = height/4;
		GLdouble the_width_of_the_mobile_shelf = 1;
		DisplayRectangularParallelepiped object;
		if (point1.x == point2.x) {
			GLdouble x = max(point1.z,point2.z) - min(point1.z,point2.z);
			GLdouble xx = (std::abs(x))/2;
			Point point_one_of_the_mobile_shelf_one = {point1.x + the_width_of_the_mobile_shelf,point1.y + the_height_of_the_mobile_shelf,point1.z};
			Point point_two_of_the_mobile_shelf_one = {point1.x,point1.y + the_height_of_the_mobile_shelf,point1.z};
			Point point_three_of_the_mobile_shelf_one = {point1.x,point1.y + the_height_of_the_mobile_shelf,point1.z - xx};
			Point point_four_of_the_mobile_shelf_one = {point_two_of_the_mobile_shelf_one.x + the_width_of_the_mobile_shelf,point1.y + the_height_of_the_mobile_shelf,point1.z - xx};
			object.displayMobileShelf(
				point_one_of_the_mobile_shelf_one,
				point_two_of_the_mobile_shelf_one,
				point_three_of_the_mobile_shelf_one,
				point_four_of_the_mobile_shelf_one,
				0.1,
				brown_wood,
				mobile_screen,
				black
				);
			Point point_one_of_the_mobile_shelf_two = point_four_of_the_mobile_shelf_one;
			Point point_two_of_the_mobile_shelf_two = point_three_of_the_mobile_shelf_one;
			Point point_three_of_the_mobile_shelf_two = {point2.x,point2.y + the_height_of_the_mobile_shelf,point2.z};
			Point point_four_of_the_mobile_shelf_two = {point2.x + the_width_of_the_mobile_shelf,point2.y + the_height_of_the_mobile_shelf,point2.z};
			object.displayMobileShelf(
				point_one_of_the_mobile_shelf_two,
				point_two_of_the_mobile_shelf_two,
				point_three_of_the_mobile_shelf_two,
				point_four_of_the_mobile_shelf_two,
				0.1,
				brown_wood,
				mobile_screen,
				grey
				);
			Point point_one_of_the_mobile_shelf_three = {point4.x - the_width_of_the_mobile_shelf,point4.y + the_height_of_the_mobile_shelf,point4.z};
			Point point_two_of_the_mobile_shelf_three = {point4.x,point4.y + the_height_of_the_mobile_shelf,point4.z};
			Point point_three_of_the_mobile_shelf_three = {point4.x,point1.y + the_height_of_the_mobile_shelf,point4.z - xx};
			Point point_four_of_the_mobile_shelf_three = {point_two_of_the_mobile_shelf_three.x - the_width_of_the_mobile_shelf,point4.y + the_height_of_the_mobile_shelf,point4.z - xx};
			object.displayMobileShelf(
				point_one_of_the_mobile_shelf_three,
				point_two_of_the_mobile_shelf_three,
				point_three_of_the_mobile_shelf_three,
				point_four_of_the_mobile_shelf_three,
				0.1,
				brown_wood,
				mobile_screen,
				grey
				);
			Point point_one_of_the_mobile_shelf_four = point_four_of_the_mobile_shelf_three;
			Point point_two_of_the_mobile_shelf_four = point_three_of_the_mobile_shelf_three;
			Point point_three_of_the_mobile_shelf_four = {point3.x,point3.y + the_height_of_the_mobile_shelf,point3.z};
			Point point_four_of_the_mobile_shelf_four = {point3.x - the_width_of_the_mobile_shelf,point3.y + the_height_of_the_mobile_shelf,point3.z};
			object.displayMobileShelf(
				point_one_of_the_mobile_shelf_four,
				point_two_of_the_mobile_shelf_four,
				point_three_of_the_mobile_shelf_four,
				point_four_of_the_mobile_shelf_four,
				0.1,
				brown_wood,
				mobile_screen,
				grey
				);
		} else if (point1.z == point2.z) {
			GLdouble x = max(point1.x,point2.x) - min(point1.x,point2.x);
			GLdouble xx = (std::abs(x))/2;
			Point point_one_of_the_mobile_shelf_one = {point1.x,point1.y + the_height_of_the_mobile_shelf,point1.z + the_width_of_the_mobile_shelf};
			Point point_two_of_the_mobile_shelf_one = {point1.x,point1.y + the_height_of_the_mobile_shelf,point1.z};
			Point point_three_of_the_mobile_shelf_one = {point1.x + xx,point1.y + the_height_of_the_mobile_shelf,point1.z};
			Point point_four_of_the_mobile_shelf_one = {point_two_of_the_mobile_shelf_one.x + xx,point1.y + the_height_of_the_mobile_shelf,point1.z + the_width_of_the_mobile_shelf};
			object.displayMobileShelf(
				point_one_of_the_mobile_shelf_one,
				point_two_of_the_mobile_shelf_one,
				point_three_of_the_mobile_shelf_one,
				point_four_of_the_mobile_shelf_one,
				0.1,
				brown_wood,
				mobile_screen,
				grey
				);
			Point point_one_of_the_mobile_shelf_two = point_four_of_the_mobile_shelf_one;
			Point point_two_of_the_mobile_shelf_two = point_three_of_the_mobile_shelf_one;
			Point point_three_of_the_mobile_shelf_two = {point2.x,point2.y + the_height_of_the_mobile_shelf,point2.z};
			Point point_four_of_the_mobile_shelf_two = {point2.x,point2.y + the_height_of_the_mobile_shelf,point2.z + the_width_of_the_mobile_shelf};
			object.displayMobileShelf(
				point_one_of_the_mobile_shelf_two,
				point_two_of_the_mobile_shelf_two,
				point_three_of_the_mobile_shelf_two,
				point_four_of_the_mobile_shelf_two,
				0.1,
				brown_wood,
				mobile_screen,
				grey
				);
			Point point_one_of_the_mobile_shelf_three = {point4.x,point4.y + the_height_of_the_mobile_shelf,point4.z - the_width_of_the_mobile_shelf};
			Point point_two_of_the_mobile_shelf_three = {point4.x,point4.y + the_height_of_the_mobile_shelf,point4.z};
			Point point_three_of_the_mobile_shelf_three = {point4.x + xx,point4.y + the_height_of_the_mobile_shelf,point4.z};
			Point point_four_of_the_mobile_shelf_three = {point_two_of_the_mobile_shelf_three.x + xx,point4.y + the_height_of_the_mobile_shelf,point4.z - the_width_of_the_mobile_shelf};
			object.displayMobileShelf(
				point_one_of_the_mobile_shelf_three,
				point_two_of_the_mobile_shelf_three,
				point_three_of_the_mobile_shelf_three,
				point_four_of_the_mobile_shelf_three,
				0.1,
				brown_wood,
				mobile_screen,
				grey
				);
			Point point_one_of_the_mobile_shelf_four = point_four_of_the_mobile_shelf_three;
			Point point_two_of_the_mobile_shelf_four = point_three_of_the_mobile_shelf_three;
			Point point_three_of_the_mobile_shelf_four = {point3.x,point3.y + the_height_of_the_mobile_shelf,point3.z};
			Point point_four_of_the_mobile_shelf_four = {point3.x,point3.y + the_height_of_the_mobile_shelf,point3.z - the_width_of_the_mobile_shelf};
			object.displayMobileShelf(
				point_one_of_the_mobile_shelf_four,
				point_two_of_the_mobile_shelf_four,
				point_three_of_the_mobile_shelf_four,
				point_four_of_the_mobile_shelf_four,
				0.1,
				brown_wood,
				mobile_screen,
				grey
				);
	}
	if (point1.x == point2.x) {
		GLdouble x = max(point1.z,point2.z) - min(point1.z,point2.z);
		GLdouble xx = (std::abs(x))/3;
		GLdouble y = max(point2.x,point3.x) - min(point2.x,point3.x);
		GLdouble yy = (std::abs(y))/3;

		Point point_1_of_the_laptop_shelf = {point2.x + yy,point1.y + the_height_of_the_mobile_shelf,point2.z + xx};
		Point point_2_of_the_laptop_shelf = {point3.x - yy,point1.y + the_height_of_the_mobile_shelf,point3.z + xx};
		Point point_3_of_the_laptop_shelf = {point4.x - yy,point1.y + the_height_of_the_mobile_shelf,point4.z - xx};
		Point point_4_of_the_laptop_shelf = {point1.x + yy,point1.y + the_height_of_the_mobile_shelf,point1.z - xx};

		object.displayLaptopShelf(
			point_1_of_the_laptop_shelf,
			point_2_of_the_laptop_shelf,
			point_3_of_the_laptop_shelf,
			point_4_of_the_laptop_shelf,
			the_height_of_the_mobile_shelf,
			brown_wood,
			laptop_screen,
			keyboard,
			grey
			);
	} else if (point1.z == point2.z) {
		GLdouble x = max(point1.x,point2.x) - min(point1.x,point2.x);
		GLdouble xx = (std::abs(x))/3;
		GLdouble y = max(point2.z,point3.z) - min(point2.z,point3.z);
		GLdouble yy = (std::abs(y))/3;

		Point point_1_of_the_laptop_shelf = {point2.x - xx,point1.y + the_height_of_the_mobile_shelf,point2.z + yy};
		Point point_2_of_the_laptop_shelf = {point3.x - xx,point1.y + the_height_of_the_mobile_shelf,point3.z - yy};
		Point point_3_of_the_laptop_shelf = {point4.x + xx,point1.y + the_height_of_the_mobile_shelf,point4.z - yy};
		Point point_4_of_the_laptop_shelf = {point1.x + xx,point1.y + the_height_of_the_mobile_shelf,point1.z + yy};

		object.displayLaptopShelf(
			point_1_of_the_laptop_shelf,
			point_2_of_the_laptop_shelf,
			point_3_of_the_laptop_shelf,
			point_4_of_the_laptop_shelf,
			the_height_of_the_mobile_shelf,
			brown_wood,
			laptop_screen,
			keyboard,
			grey
			);
	}

	GLdouble the_height_of_the_TV_screen = height/3;
	GLdouble the_width_of_the_TV_screen;
	if (point2.x == point3.x) {
		the_width_of_the_TV_screen = (max(point2.z,point3.z) - min(point2.z,point3.z))/3;
		Point point_1_of_the_TV_screen = {point2.x,point2.y + the_height_of_the_TV_screen,point2.z + the_width_of_the_TV_screen};
		Point point_2_of_the_TV_screen = {point2.x,point2.y + 2*the_height_of_the_TV_screen,point2.z + the_width_of_the_TV_screen};
		Point point_3_of_the_TV_screen = {point2.x,point2.y + 2*the_height_of_the_TV_screen,point2.z + 2*the_width_of_the_TV_screen};
		Point point_4_of_the_TV_screen = {point2.x,point2.y + the_height_of_the_TV_screen,point2.z + 2*the_width_of_the_TV_screen};
		object.displayTV(
			point_1_of_the_TV_screen,
			point_2_of_the_TV_screen,
			point_3_of_the_TV_screen,
			point_4_of_the_TV_screen,
			TV_screen,
			black
			);
	} else {
		the_width_of_the_TV_screen = (max(point2.x,point3.x) - min(point2.x,point3.x))/3;
		Point point_1_of_the_TV_screen = {point2.x + the_width_of_the_TV_screen,point2.y + the_height_of_the_TV_screen,point2.z};
		Point point_2_of_the_TV_screen = {point2.x + the_width_of_the_TV_screen,point2.y + 2*the_height_of_the_TV_screen,point2.z};
		Point point_3_of_the_TV_screen = {point2.x + 2*the_width_of_the_TV_screen,point2.y + 2*the_height_of_the_TV_screen,point2.z};
		Point point_4_of_the_TV_screen = {point2.x + 2*the_width_of_the_TV_screen,point2.y + the_height_of_the_TV_screen,point2.z};
		object.displayTV(
			point_1_of_the_TV_screen,
			point_2_of_the_TV_screen,
			point_3_of_the_TV_screen,
			point_4_of_the_TV_screen,
			TV_screen,
			black
			);
	}
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, grey_wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(point2.x, point2.y, point2.z);
	glTexCoord2d(1,0); glVertex3d(point3.x, point3.y, point3.z);
	glTexCoord2d(0,1); glVertex3d(point3.x, point3.y + height, point3.z);
	glTexCoord2d(1,1); glVertex3d(point2.x, point2.y + height, point2.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(point3.x, point3.y, point3.z);
	glTexCoord2d(1,0); glVertex3d(point4.x, point4.y, point4.z);
	glTexCoord2d(0,1); glVertex3d(point4.x, point4.y + height, point4.z);
	glTexCoord2d(1,1); glVertex3d(point3.x, point3.y + height, point3.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z);
	glTexCoord2d(1,0); glVertex3d(point2.x, point2.y, point2.z);
	glTexCoord2d(0,1); glVertex3d(point2.x, point2.y + height, point2.z);
	glTexCoord2d(1,1); glVertex3d(point1.x, point1.y + height, point1.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,light_brown_wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(point1.x, point1.y + height, point1.z);
	glTexCoord2d(1,0); glVertex3d(point2.x, point2.y + height, point2.z);
	glTexCoord2d(0,1); glVertex3d(point3.x, point3.y + height, point3.z);
	glTexCoord2d(1,1); glVertex3d(point4.x, point4.y + height, point4.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z);
	glTexCoord2d(1,0); glVertex3d(point2.x, point2.y, point2.z);
	glTexCoord2d(0,1); glVertex3d(point3.x, point3.y, point3.z);
	glTexCoord2d(1,1); glVertex3d(point4.x, point4.y, point4.z);
	glEnd();

	GLdouble the_width_of_the_interface = (point1.x + point4.x)/3;
	Point point_1_of_the_column_1 = {point1.x + the_width_of_the_interface - 0.2,point1.y,point1.z};
	Point point_2_of_the_column_1 = {point1.x + the_width_of_the_interface - 0.2,point1.y + height,point1.z};
	Point point_3_of_the_column_1 = {point1.x + the_width_of_the_interface,point1.y + height,point1.z};
	Point point_4_of_the_column_1 = {point1.x + the_width_of_the_interface,point1.y,point1.z};

	Point point_1_of_the_column_2 = {point4.x - the_width_of_the_interface + 0.2,point4.y,point4.z};
	Point point_2_of_the_column_2 = {point4.x - the_width_of_the_interface + 0.2,point4.y + height,point4.z};
	Point point_3_of_the_column_2 = {point4.x - the_width_of_the_interface,point4.y + height,point4.z};
	Point point_4_of_the_column_2 = {point4.x - the_width_of_the_interface,point4.y,point4.z};

	Point point_1_of_the_row_1 = {point1.x,point1.y + 3*the_height_of_the_mobile_shelf,point1.z};
	Point point_2_of_the_row_1 = {point1.x,point1.y + height,point1.z};
	Point point_3_of_the_row_1 = {point1.x + the_width_of_the_interface - 0.2,point1.y + height,point1.z};
	Point point_4_of_the_row_1 = {point1.x + the_width_of_the_interface - 0.2,point1.y + 3*the_height_of_the_mobile_shelf,point1.z};

	Point point_1_of_the_row_2 = {point4.x - the_width_of_the_interface + 0.2,point4.y + 3*the_height_of_the_mobile_shelf,point4.z};
	Point point_2_of_the_row_2 = {point4.x - the_width_of_the_interface + 0.2,point4.y + height,point4.z};
	Point point_3_of_the_row_2 = {point4.x,point4.y + height,point4.z};
	Point point_4_of_the_row_2 = {point4.x,point4.y + 3*the_height_of_the_mobile_shelf,point4.z};

	Point point_1_of_the_glass_1 = point1;
	Point point_2_of_the_glass_1 = {point1.x,point1.y + 3*the_height_of_the_mobile_shelf,point1.z};
	Point point_3_of_the_glass_1 = {point1.x + the_width_of_the_interface - 0.2,point1.y + 3*the_height_of_the_mobile_shelf,point1.z};
	Point point_4_of_the_glass_1 = {point1.x + the_width_of_the_interface - 0.2,point1.y,point1.z};

	Point point_1_of_the_glass_2 = {point4.x - the_width_of_the_interface + 0.2,point4.y,point4.z};
	Point point_2_of_the_glass_2 = {point4.x - the_width_of_the_interface + 0.2,point4.y + 3*the_height_of_the_mobile_shelf,point4.z};
	Point point_3_of_the_glass_2 = {point4.x,point4.y + 3*the_height_of_the_mobile_shelf,point4.z};
	Point point_4_of_the_glass_2 = point4;

	Point point_1_of_the_store_name = {point1.x + the_width_of_the_interface,point1.y + 3*the_height_of_the_mobile_shelf,point1.z};
	Point point_2_of_the_store_name = {point1.x + the_width_of_the_interface,point1.y + height,point1.z};
	Point point_3_of_the_store_name = {point1.x + 2*the_width_of_the_interface,point1.y + height,point1.z};
	Point point_4_of_the_store_name = {point1.x + 2*the_width_of_the_interface,point1.y + 3*the_height_of_the_mobile_shelf,point1.z};

	glBindTexture(GL_TEXTURE_2D, grey_wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(point_1_of_the_column_1.x, point_1_of_the_column_1.y, point_1_of_the_column_1.z);
	glTexCoord2d(1,0); glVertex3d(point_2_of_the_column_1.x, point_2_of_the_column_1.y, point_2_of_the_column_1.z);
	glTexCoord2d(0,1); glVertex3d(point_3_of_the_column_1.x, point_3_of_the_column_1.y, point_3_of_the_column_1.z);
	glTexCoord2d(1,1); glVertex3d(point_4_of_the_column_1.x, point_4_of_the_column_1.y, point_4_of_the_column_1.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(point_1_of_the_column_2.x, point_1_of_the_column_2.y, point_1_of_the_column_2.z);
	glTexCoord2d(1,0); glVertex3d(point_2_of_the_column_2.x, point_2_of_the_column_2.y, point_2_of_the_column_2.z);
	glTexCoord2d(0,1); glVertex3d(point_3_of_the_column_2.x, point_3_of_the_column_2.y, point_3_of_the_column_2.z);
	glTexCoord2d(1,1); glVertex3d(point_4_of_the_column_2.x, point_4_of_the_column_2.y, point_4_of_the_column_2.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(point_1_of_the_row_1.x, point_1_of_the_row_1.y, point_1_of_the_row_1.z);
	glTexCoord2d(1,0); glVertex3d(point_2_of_the_row_1.x, point_2_of_the_row_1.y, point_2_of_the_row_1.z);
	glTexCoord2d(0,1); glVertex3d(point_3_of_the_row_1.x, point_3_of_the_row_1.y, point_3_of_the_row_1.z);
	glTexCoord2d(1,1); glVertex3d(point_4_of_the_row_1.x, point_4_of_the_row_1.y, point_4_of_the_row_1.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(point_1_of_the_row_2.x, point_1_of_the_row_2.y, point_1_of_the_row_2.z);
	glTexCoord2d(1,0); glVertex3d(point_2_of_the_row_2.x, point_2_of_the_row_2.y, point_2_of_the_row_2.z);
	glTexCoord2d(0,1); glVertex3d(point_3_of_the_row_2.x, point_3_of_the_row_2.y, point_3_of_the_row_2.z);
	glTexCoord2d(1,1); glVertex3d(point_4_of_the_row_2.x, point_4_of_the_row_2.y, point_4_of_the_row_2.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, glass);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(point_1_of_the_glass_1.x, point_1_of_the_glass_1.y, point_1_of_the_glass_1.z);
	glTexCoord2d(1,0); glVertex3d(point_2_of_the_glass_1.x, point_2_of_the_glass_1.y, point_2_of_the_glass_1.z);
	glTexCoord2d(0,1); glVertex3d(point_3_of_the_glass_1.x, point_3_of_the_glass_1.y, point_3_of_the_glass_1.z);
	glTexCoord2d(1,1); glVertex3d(point_4_of_the_glass_1.x, point_4_of_the_glass_1.y, point_4_of_the_glass_1.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(point_1_of_the_glass_2.x, point_1_of_the_glass_2.y, point_1_of_the_glass_2.z);
	glTexCoord2d(1,0); glVertex3d(point_2_of_the_glass_2.x, point_2_of_the_glass_2.y, point_2_of_the_glass_2.z);
	glTexCoord2d(0,1); glVertex3d(point_3_of_the_glass_2.x, point_3_of_the_glass_2.y, point_3_of_the_glass_2.z);
	glTexCoord2d(1,1); glVertex3d(point_4_of_the_glass_2.x, point_4_of_the_glass_2.y, point_4_of_the_glass_2.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, electronics_store);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(point_1_of_the_store_name.x, point_1_of_the_store_name.y, point_1_of_the_store_name.z);
	glTexCoord2d(0,1); glVertex3d(point_2_of_the_store_name.x, point_2_of_the_store_name.y, point_2_of_the_store_name.z);
	glTexCoord2d(1,1); glVertex3d(point_3_of_the_store_name.x, point_3_of_the_store_name.y, point_3_of_the_store_name.z);
	glTexCoord2d(1,0); glVertex3d(point_4_of_the_store_name.x, point_4_of_the_store_name.y, point_4_of_the_store_name.z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void DisplayRectangularParallelepiped::displayWoodenRectangularParallelepiped(
	Point point1,
	Point point2,
	Point point3,
	Point point4,
	GLdouble thickness,
	int brown_wood
	) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, brown_wood);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point2.x, point2.y, point2.z);
		glTexCoord2d(1,0); glVertex3d(point3.x, point3.y, point3.z);
		glTexCoord2d(0,1); glVertex3d(point3.x, point3.y - thickness, point3.z);
		glTexCoord2d(1,1); glVertex3d(point2.x, point2.y - thickness, point2.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y - thickness, point1.z);
		glTexCoord2d(1,0); glVertex3d(point2.x, point2.y - thickness, point2.z);
		glTexCoord2d(0,1); glVertex3d(point3.x, point3.y - thickness, point3.z);
		glTexCoord2d(1,1); glVertex3d(point4.x, point4.y - thickness, point4.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point3.x, point3.y, point3.z);
		glTexCoord2d(1,0); glVertex3d(point4.x, point4.y, point4.z);
		glTexCoord2d(0,1); glVertex3d(point4.x, point4.y - thickness, point4.z);
		glTexCoord2d(1,1); glVertex3d(point3.x, point3.y - thickness, point3.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z);
		glTexCoord2d(1,0); glVertex3d(point2.x, point2.y, point2.z);
		glTexCoord2d(0,1); glVertex3d(point2.x, point2.y - thickness, point2.z);
		glTexCoord2d(1,1); glVertex3d(point1.x, point1.y - thickness, point1.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z);
		glTexCoord2d(1,0); glVertex3d(point4.x, point4.y, point4.z);
		glTexCoord2d(0,1); glVertex3d(point4.x, point4.y - thickness, point4.z);
		glTexCoord2d(1,1); glVertex3d(point1.x, point1.y - thickness, point1.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z);
		glTexCoord2d(1,0); glVertex3d(point2.x, point2.y, point2.z);
		glTexCoord2d(0,1); glVertex3d(point3.x, point3.y, point3.z);
		glTexCoord2d(1,1); glVertex3d(point4.x, point4.y, point4.z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
}

void DisplayRectangularParallelepiped::displayMobileShelf(
	Point point1,
	Point point2,
	Point point3,
	Point point4,
	GLdouble thickness,
	int brown_wood,
	int mobile_screen,
	int grey
	) {
	DisplayRectangularParallelepiped object;
	object.displayWoodenRectangularParallelepiped(point1,point2,point3,point4,thickness,brown_wood);

	if (point1.x == point2.x) {
		GLdouble x = max(point1.z,point2.z) - min(point1.z,point2.z);
		GLdouble the_difference_between_two_centers = (std::abs(x))/3;
		Point first_center_of_left_side;
		Point second_center_of_left_side;
		if (point1.z > point2.z) {
			first_center_of_left_side.x = point1.x;
			first_center_of_left_side.y = point1.y;
			first_center_of_left_side.z = point1.z - the_difference_between_two_centers;
			second_center_of_left_side.x = point1.x;
			second_center_of_left_side.y = point1.y;
			second_center_of_left_side.z = point1.z - 2*the_difference_between_two_centers;
		} else {
			first_center_of_left_side.x = point1.x;
			first_center_of_left_side.y = point1.y;
			first_center_of_left_side.z = point1.z + the_difference_between_two_centers;
			second_center_of_left_side.x = point1.x;
			second_center_of_left_side.y = point1.y;
			second_center_of_left_side.z = point1.z + 2*the_difference_between_two_centers;
		}
		
		GLdouble xx = max(point2.x,point3.x)-min(point2.x,point3.x);
		GLdouble the_difference = (std::abs(xx))/9;

		Point point1_for_the_first_mobile = {first_center_of_left_side.x + 1*the_difference,first_center_of_left_side.y,first_center_of_left_side.z};
		Point point2_for_the_first_mobile = {second_center_of_left_side.x + 1*the_difference,second_center_of_left_side.y,second_center_of_left_side.z};
		Point point3_for_the_first_mobile = {second_center_of_left_side.x + 2*the_difference,second_center_of_left_side.y,second_center_of_left_side.z};
		Point point4_for_the_first_mobile = {first_center_of_left_side.x + 2*the_difference,first_center_of_left_side.y,first_center_of_left_side.z};

		Point point1_for_the_second_mobile = {first_center_of_left_side.x + 3*the_difference,first_center_of_left_side.y,first_center_of_left_side.z};
		Point point2_for_the_second_mobile = {second_center_of_left_side.x + 3*the_difference,second_center_of_left_side.y,second_center_of_left_side.z};
		Point point3_for_the_second_mobile = {second_center_of_left_side.x + 4*the_difference,second_center_of_left_side.y,second_center_of_left_side.z};
		Point point4_for_the_second_mobile = {first_center_of_left_side.x + 4*the_difference,first_center_of_left_side.y,first_center_of_left_side.z};

		Point point1_for_the_third_mobile = {first_center_of_left_side.x + 5*the_difference,first_center_of_left_side.y,first_center_of_left_side.z};
		Point point2_for_the_third_mobile = {second_center_of_left_side.x + 5*the_difference,second_center_of_left_side.y,second_center_of_left_side.z};
		Point point3_for_the_third_mobile = {second_center_of_left_side.x + 6*the_difference,second_center_of_left_side.y,second_center_of_left_side.z};
		Point point4_for_the_third_mobile = {first_center_of_left_side.x + 6*the_difference,first_center_of_left_side.y,first_center_of_left_side.z};

		Point point1_for_the_fourth_mobile = {first_center_of_left_side.x + 7*the_difference,first_center_of_left_side.y,first_center_of_left_side.z};
		Point point2_for_the_fourth_mobile = {second_center_of_left_side.x + 7*the_difference,second_center_of_left_side.y,second_center_of_left_side.z};
		Point point3_for_the_fourth_mobile = {second_center_of_left_side.x + 8*the_difference,second_center_of_left_side.y,second_center_of_left_side.z};
		Point point4_for_the_fourth_mobile = {first_center_of_left_side.x + 8*the_difference,first_center_of_left_side.y,first_center_of_left_side.z};

		object.displayOneMobile(point1_for_the_first_mobile,point2_for_the_first_mobile,point3_for_the_first_mobile,point4_for_the_first_mobile,mobile_screen,grey);
		object.displayOneMobile(point1_for_the_second_mobile,point2_for_the_second_mobile,point3_for_the_second_mobile,point4_for_the_second_mobile,mobile_screen,grey);
		object.displayOneMobile(point1_for_the_third_mobile,point2_for_the_third_mobile,point3_for_the_third_mobile,point4_for_the_third_mobile,mobile_screen,grey);
		object.displayOneMobile(point1_for_the_fourth_mobile,point2_for_the_fourth_mobile,point3_for_the_fourth_mobile,point4_for_the_fourth_mobile,mobile_screen,grey);
	} else if (point1.z == point2.z) {
		GLdouble x = max(point1.x,point2.x) - min(point1.x,point2.x);
		GLdouble the_difference_between_two_centers = (std::abs(x))/3;
		Point first_center_of_left_side;
		Point second_center_of_left_side;
		if (point1.x > point2.x) {
			first_center_of_left_side.x = point1.x - the_difference_between_two_centers;
			first_center_of_left_side.y = point1.y;
			first_center_of_left_side.z = point1.z;
			second_center_of_left_side.x = point1.x - 2*the_difference_between_two_centers;
			second_center_of_left_side.y = point1.y;
			second_center_of_left_side.z = point1.z;
		} else {
			first_center_of_left_side.x = point1.x + the_difference_between_two_centers;
			first_center_of_left_side.y = point1.y;
			first_center_of_left_side.z = point1.z;
			second_center_of_left_side.x = point1.x + 2*the_difference_between_two_centers;
			second_center_of_left_side.y = point1.y;
			second_center_of_left_side.z = point1.z;
		}
		
		GLdouble xx = max(point2.z,point3.z)-min(point2.z,point3.z);
		GLdouble the_difference = (std::abs(xx))/9;

		Point point1_for_the_first_mobile = {first_center_of_left_side.x,first_center_of_left_side.y,first_center_of_left_side.z - 1*the_difference};
		Point point2_for_the_first_mobile = {second_center_of_left_side.x,second_center_of_left_side.y,second_center_of_left_side.z - 1*the_difference};
		Point point3_for_the_first_mobile = {second_center_of_left_side.x,second_center_of_left_side.y,second_center_of_left_side.z - 2*the_difference};
		Point point4_for_the_first_mobile = {first_center_of_left_side.x,first_center_of_left_side.y,first_center_of_left_side.z - 2*the_difference};

		Point point1_for_the_second_mobile = {first_center_of_left_side.x,first_center_of_left_side.y,first_center_of_left_side.z - 3*the_difference};
		Point point2_for_the_second_mobile = {second_center_of_left_side.x,second_center_of_left_side.y,second_center_of_left_side.z - 3*the_difference};
		Point point3_for_the_second_mobile = {second_center_of_left_side.x,second_center_of_left_side.y,second_center_of_left_side.z - 4*the_difference};
		Point point4_for_the_second_mobile = {first_center_of_left_side.x,first_center_of_left_side.y,first_center_of_left_side.z - 4*the_difference};

		Point point1_for_the_third_mobile = {first_center_of_left_side.x,first_center_of_left_side.y,first_center_of_left_side.z - 5*the_difference};
		Point point2_for_the_third_mobile = {second_center_of_left_side.x,second_center_of_left_side.y,second_center_of_left_side.z - 5*the_difference};
		Point point3_for_the_third_mobile = {second_center_of_left_side.x,second_center_of_left_side.y,second_center_of_left_side.z - 6*the_difference};
		Point point4_for_the_third_mobile = {first_center_of_left_side.x,first_center_of_left_side.y,first_center_of_left_side.z - 6*the_difference};

		Point point1_for_the_fourth_mobile = {first_center_of_left_side.x,first_center_of_left_side.y,first_center_of_left_side.z - 7*the_difference};
		Point point2_for_the_fourth_mobile = {second_center_of_left_side.x,second_center_of_left_side.y,second_center_of_left_side.z - 7*the_difference};
		Point point3_for_the_fourth_mobile = {second_center_of_left_side.x,second_center_of_left_side.y,second_center_of_left_side.z - 8*the_difference};
		Point point4_for_the_fourth_mobile = {first_center_of_left_side.x,first_center_of_left_side.y,first_center_of_left_side.z - 8*the_difference};

		object.displayOneMobile(point1_for_the_first_mobile,point2_for_the_first_mobile,point3_for_the_first_mobile,point4_for_the_first_mobile,mobile_screen,grey);
		object.displayOneMobile(point1_for_the_second_mobile,point2_for_the_second_mobile,point3_for_the_second_mobile,point4_for_the_second_mobile,mobile_screen,grey);
		object.displayOneMobile(point1_for_the_third_mobile,point2_for_the_third_mobile,point3_for_the_third_mobile,point4_for_the_third_mobile,mobile_screen,grey);
		object.displayOneMobile(point1_for_the_fourth_mobile,point2_for_the_fourth_mobile,point3_for_the_fourth_mobile,point4_for_the_fourth_mobile,mobile_screen,grey);
	}
}

void DisplayRectangularParallelepiped::displayOneMobile(
	Point point1,
	Point point2, 
	Point point3, 
	Point point4,
	int mobile_screen,
	int grey
	) {
	Point point11 = point1;
	Point point22 = {point2.x,point2.y + 0.2,point2.z};
	Point point33 = {point3.x,point3.y + 0.2,point3.z};
	Point point44 = point4;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, grey);
	glBegin(GL_QUADS);
	glVertex3d(point22.x, point22.y, point22.z);
	glVertex3d(point33.x, point33.y, point33.z);
	glVertex3d(point33.x, point33.y + 0.01, point33.z);
	glVertex3d(point22.x, point22.y + 0.01, point22.z);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(point11.x, point11.y, point11.z);
	glVertex3d(point22.x, point22.y, point22.z);
	glVertex3d(point33.x, point33.y, point33.z);
	glVertex3d(point44.x, point44.y, point44.z);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(point33.x, point33.y, point33.z);
	glVertex3d(point44.x, point44.y, point44.z);
	glVertex3d(point44.x, point44.y + 0.01, point44.z);
	glVertex3d(point33.x, point33.y + 0.01, point33.z);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(point11.x, point11.y, point11.z);
	glVertex3d(point22.x, point22.y, point22.z);
	glVertex3d(point22.x, point22.y + 0.01, point22.z);
	glVertex3d(point11.x, point11.y + 0.01, point11.z);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(point11.x, point11.y, point11.z);
	glVertex3d(point44.x, point44.y, point44.z);
	glVertex3d(point44.x, point44.y + 0.01, point44.z);
	glVertex3d(point11.x, point11.y + 0.01, point11.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, mobile_screen);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(point11.x, point11.y + 0.01, point11.z);
	glTexCoord2d(0,1); glVertex3d(point22.x, point22.y + 0.01, point22.z);
	glTexCoord2d(1,1); glVertex3d(point33.x, point33.y + 0.01, point33.z);
	glTexCoord2d(1,0); glVertex3d(point44.x, point44.y + 0.01, point44.z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void DisplayRectangularParallelepiped::displayLaptopShelf(
	Point point1,
	Point point2, 
	Point point3,
	Point point4,
	GLdouble thickness,
	int brown_wood,
	int laptop_screen,
	int keyboard,
	int grey
	) {
	DisplayRectangularParallelepiped object;
	object.displayWoodenRectangularParallelepiped(point1,point2,point3,point4,thickness,brown_wood);

	if (point1.x == point2.x) {
		GLdouble x = max(point1.z,point2.z) - min(point1.z,point2.z);
		GLdouble the_difference_between_two_centers = (std::abs(x))/5;
		Point first_center_of_left_side;
		Point second_center_of_left_side;
		Point third_center_of_left_side;
		Point fourth_center_of_left_side;
		if (point1.z > point2.z) {
			first_center_of_left_side.x = point1.x;
			first_center_of_left_side.y = point1.y;
			first_center_of_left_side.z = point1.z - the_difference_between_two_centers;
			second_center_of_left_side.x = point1.x;
			second_center_of_left_side.y = point1.y;
			second_center_of_left_side.z = point1.z - 2*the_difference_between_two_centers;
			third_center_of_left_side.x = point1.x;
			third_center_of_left_side.y = point1.y;
			third_center_of_left_side.z = point1.z - 3*the_difference_between_two_centers;
			fourth_center_of_left_side.x = point1.x;
			fourth_center_of_left_side.y = point1.y;
			fourth_center_of_left_side.z = point1.z - 4*the_difference_between_two_centers;
		} else {
			first_center_of_left_side.x = point1.x;
			first_center_of_left_side.y = point1.y;
			first_center_of_left_side.z = point1.z + the_difference_between_two_centers;
			second_center_of_left_side.x = point1.x;
			second_center_of_left_side.y = point1.y;
			second_center_of_left_side.z = point1.z + 2*the_difference_between_two_centers;
			third_center_of_left_side.x = point1.x;
			third_center_of_left_side.y = point1.y;
			third_center_of_left_side.z = point1.z + 3*the_difference_between_two_centers;
			fourth_center_of_left_side.x = point1.x;
			fourth_center_of_left_side.y = point1.y;
			fourth_center_of_left_side.z = point1.z + 4*the_difference_between_two_centers;
		}
		
		GLdouble xx = max(point2.x,point3.x)-min(point2.x,point3.x);
		GLdouble the_difference = (std::abs(xx))/7;

		Point point1_for_the_1_laptop = {first_center_of_left_side.x - 1*the_difference,first_center_of_left_side.y,first_center_of_left_side.z};
		Point point2_for_the_1_laptop = {second_center_of_left_side.x - 1*the_difference,second_center_of_left_side.y,second_center_of_left_side.z};
		Point point3_for_the_1_laptop = {second_center_of_left_side.x - 2*the_difference,second_center_of_left_side.y,second_center_of_left_side.z};
		Point point4_for_the_1_laptop = {first_center_of_left_side.x - 2*the_difference,first_center_of_left_side.y,first_center_of_left_side.z};

		Point point1_for_the_2_laptop = {first_center_of_left_side.x - 3*the_difference,first_center_of_left_side.y,first_center_of_left_side.z};
		Point point2_for_the_2_laptop = {second_center_of_left_side.x - 3*the_difference,second_center_of_left_side.y,second_center_of_left_side.z};
		Point point3_for_the_2_laptop = {second_center_of_left_side.x - 4*the_difference,second_center_of_left_side.y,second_center_of_left_side.z};
		Point point4_for_the_2_laptop = {first_center_of_left_side.x - 4*the_difference,first_center_of_left_side.y,first_center_of_left_side.z};

		Point point1_for_the_3_laptop = {first_center_of_left_side.x - 5*the_difference,first_center_of_left_side.y,first_center_of_left_side.z};
		Point point2_for_the_3_laptop = {second_center_of_left_side.x - 5*the_difference,second_center_of_left_side.y,second_center_of_left_side.z};
		Point point3_for_the_3_laptop = {second_center_of_left_side.x - 6*the_difference,second_center_of_left_side.y,second_center_of_left_side.z};
		Point point4_for_the_3_laptop = {first_center_of_left_side.x - 6*the_difference,first_center_of_left_side.y,first_center_of_left_side.z};

		Point point1_for_the_4_laptop = {fourth_center_of_left_side.x - 2*the_difference,fourth_center_of_left_side.y,fourth_center_of_left_side.z};
		Point point2_for_the_4_laptop = {third_center_of_left_side.x - 2*the_difference,third_center_of_left_side.y,third_center_of_left_side.z};
		Point point3_for_the_4_laptop = {third_center_of_left_side.x - 1*the_difference,third_center_of_left_side.y,third_center_of_left_side.z};
		Point point4_for_the_4_laptop = {fourth_center_of_left_side.x - 1*the_difference,fourth_center_of_left_side.y,fourth_center_of_left_side.z};
		
		Point point1_for_the_5_laptop = {fourth_center_of_left_side.x - 4*the_difference,fourth_center_of_left_side.y,fourth_center_of_left_side.z};
		Point point2_for_the_5_laptop = {third_center_of_left_side.x - 4*the_difference,third_center_of_left_side.y,third_center_of_left_side.z};
		Point point3_for_the_5_laptop = {third_center_of_left_side.x - 3*the_difference,third_center_of_left_side.y,third_center_of_left_side.z};
		Point point4_for_the_5_laptop = {fourth_center_of_left_side.x - 3*the_difference,fourth_center_of_left_side.y,fourth_center_of_left_side.z};

		Point point1_for_the_6_laptop = {fourth_center_of_left_side.x - 6*the_difference,fourth_center_of_left_side.y,fourth_center_of_left_side.z};
		Point point2_for_the_6_laptop = {third_center_of_left_side.x - 6*the_difference,third_center_of_left_side.y,third_center_of_left_side.z};
		Point point3_for_the_6_laptop = {third_center_of_left_side.x - 5*the_difference,third_center_of_left_side.y,third_center_of_left_side.z};
		Point point4_for_the_6_laptop = {fourth_center_of_left_side.x - 5*the_difference,fourth_center_of_left_side.y,fourth_center_of_left_side.z};

		object.displayOneLaptop(point1_for_the_1_laptop,point2_for_the_1_laptop,point3_for_the_1_laptop,point4_for_the_1_laptop,laptop_screen,keyboard,grey);
		object.displayOneLaptop(point1_for_the_2_laptop,point2_for_the_2_laptop,point3_for_the_2_laptop,point4_for_the_2_laptop,laptop_screen,keyboard,grey);
		object.displayOneLaptop(point1_for_the_3_laptop,point2_for_the_3_laptop,point3_for_the_3_laptop,point4_for_the_3_laptop,laptop_screen,keyboard,grey);
		object.displayOneLaptop(point1_for_the_4_laptop,point2_for_the_4_laptop,point3_for_the_4_laptop,point4_for_the_4_laptop,laptop_screen,keyboard,grey);
		object.displayOneLaptop(point1_for_the_5_laptop,point2_for_the_5_laptop,point3_for_the_5_laptop,point4_for_the_5_laptop,laptop_screen,keyboard,grey);
		object.displayOneLaptop(point1_for_the_6_laptop,point2_for_the_6_laptop,point3_for_the_6_laptop,point4_for_the_6_laptop,laptop_screen,keyboard,grey);
	} else if (point1.z == point2.z) {
		GLdouble x = max(point1.x,point2.x) - min(point1.x,point2.x);
		GLdouble the_difference_between_two_centers = (std::abs(x))/5;
		Point first_center_of_left_side;
		Point second_center_of_left_side;
		Point third_center_of_left_side;
		Point fourth_center_of_left_side;
		if (point1.x > point2.x) {
			first_center_of_left_side.x = point1.x - the_difference_between_two_centers;
			first_center_of_left_side.y = point1.y;
			first_center_of_left_side.z = point1.z;
			second_center_of_left_side.x = point1.x - 2*the_difference_between_two_centers;
			second_center_of_left_side.y = point1.y;
			second_center_of_left_side.z = point1.z;
			third_center_of_left_side.x = point1.x - 3*the_difference_between_two_centers;
			third_center_of_left_side.y = point1.y;
			third_center_of_left_side.z = point1.z;
			fourth_center_of_left_side.x = point1.x - 4*the_difference_between_two_centers;
			fourth_center_of_left_side.y = point1.y;
			fourth_center_of_left_side.z = point1.z;
		} else {
			first_center_of_left_side.x = point1.x + the_difference_between_two_centers;
			first_center_of_left_side.y = point1.y;
			first_center_of_left_side.z = point1.z;
			second_center_of_left_side.x = point1.x + 2*the_difference_between_two_centers;
			second_center_of_left_side.y = point1.y;
			second_center_of_left_side.z = point1.z;
			third_center_of_left_side.x = point1.x + 3*the_difference_between_two_centers;
			third_center_of_left_side.y = point1.y;
			third_center_of_left_side.z = point1.z;
			fourth_center_of_left_side.x = point1.x + 4*the_difference_between_two_centers;
			fourth_center_of_left_side.y = point1.y;
			fourth_center_of_left_side.z = point1.z;
		}
		
		GLdouble xx = max(point2.z,point3.z)-min(point2.z,point3.z);
		GLdouble the_difference = (std::abs(xx))/7;

		Point point1_for_the_1_laptop = {first_center_of_left_side.x,first_center_of_left_side.y,first_center_of_left_side.z + 1*the_difference};
		Point point2_for_the_1_laptop = {second_center_of_left_side.x,second_center_of_left_side.y,second_center_of_left_side.z + 1*the_difference};
		Point point3_for_the_1_laptop = {second_center_of_left_side.x,second_center_of_left_side.y,second_center_of_left_side.z + 2*the_difference};
		Point point4_for_the_1_laptop = {first_center_of_left_side.x,first_center_of_left_side.y,first_center_of_left_side.z + 2*the_difference};

		Point point1_for_the_2_laptop = {first_center_of_left_side.x,first_center_of_left_side.y,first_center_of_left_side.z + 3*the_difference};
		Point point2_for_the_2_laptop = {second_center_of_left_side.x,second_center_of_left_side.y,second_center_of_left_side.z + 3*the_difference};
		Point point3_for_the_2_laptop = {second_center_of_left_side.x,second_center_of_left_side.y,second_center_of_left_side.z + 4*the_difference};
		Point point4_for_the_2_laptop = {first_center_of_left_side.x,first_center_of_left_side.y,first_center_of_left_side.z + 4*the_difference};

		Point point1_for_the_3_laptop = {first_center_of_left_side.x,first_center_of_left_side.y,first_center_of_left_side.z + 5*the_difference};
		Point point2_for_the_3_laptop = {second_center_of_left_side.x,second_center_of_left_side.y,second_center_of_left_side.z + 5*the_difference};
		Point point3_for_the_3_laptop = {second_center_of_left_side.x,second_center_of_left_side.y,second_center_of_left_side.z + 6*the_difference};
		Point point4_for_the_3_laptop = {first_center_of_left_side.x,first_center_of_left_side.y,first_center_of_left_side.z + 6*the_difference};

		Point point1_for_the_4_laptop = {fourth_center_of_left_side.x,fourth_center_of_left_side.y,fourth_center_of_left_side.z + 2*the_difference};
		Point point2_for_the_4_laptop = {third_center_of_left_side.x,third_center_of_left_side.y,third_center_of_left_side.z + 2*the_difference};
		Point point3_for_the_4_laptop = {third_center_of_left_side.x,third_center_of_left_side.y,third_center_of_left_side.z + 1*the_difference};
		Point point4_for_the_4_laptop = {fourth_center_of_left_side.x,fourth_center_of_left_side.y,fourth_center_of_left_side.z + 1*the_difference};

		Point point1_for_the_5_laptop = {fourth_center_of_left_side.x,fourth_center_of_left_side.y,fourth_center_of_left_side.z + 4*the_difference};
		Point point2_for_the_5_laptop = {third_center_of_left_side.x,third_center_of_left_side.y,third_center_of_left_side.z + 4*the_difference};
		Point point3_for_the_5_laptop = {third_center_of_left_side.x,third_center_of_left_side.y,third_center_of_left_side.z + 3*the_difference};
		Point point4_for_the_5_laptop = {fourth_center_of_left_side.x,fourth_center_of_left_side.y,fourth_center_of_left_side.z + 3*the_difference};

		Point point1_for_the_6_laptop = {fourth_center_of_left_side.x,fourth_center_of_left_side.y,fourth_center_of_left_side.z + 6*the_difference};
		Point point2_for_the_6_laptop = {third_center_of_left_side.x,third_center_of_left_side.y,third_center_of_left_side.z + 6*the_difference};
		Point point3_for_the_6_laptop = {third_center_of_left_side.x,third_center_of_left_side.y,third_center_of_left_side.z + 5*the_difference};
		Point point4_for_the_6_laptop = {fourth_center_of_left_side.x,fourth_center_of_left_side.y,fourth_center_of_left_side.z + 5*the_difference};

		object.displayOneLaptop(point1_for_the_1_laptop,point2_for_the_1_laptop,point3_for_the_1_laptop,point4_for_the_1_laptop,laptop_screen,keyboard,grey);
		object.displayOneLaptop(point1_for_the_2_laptop,point2_for_the_2_laptop,point3_for_the_2_laptop,point4_for_the_2_laptop,laptop_screen,keyboard,grey);
		object.displayOneLaptop(point1_for_the_3_laptop,point2_for_the_3_laptop,point3_for_the_3_laptop,point4_for_the_3_laptop,laptop_screen,keyboard,grey);
		object.displayOneLaptop(point1_for_the_4_laptop,point2_for_the_4_laptop,point3_for_the_4_laptop,point4_for_the_4_laptop,laptop_screen,keyboard,grey);
		object.displayOneLaptop(point1_for_the_5_laptop,point2_for_the_5_laptop,point3_for_the_5_laptop,point4_for_the_5_laptop,laptop_screen,keyboard,grey);
		object.displayOneLaptop(point1_for_the_6_laptop,point2_for_the_6_laptop,point3_for_the_6_laptop,point4_for_the_6_laptop,laptop_screen,keyboard,grey);
	}
}

void DisplayRectangularParallelepiped::displayOneLaptop(
	Point point1,
	Point point2, 
	Point point3,
	Point point4,
	int laptop_screen,
	int keyboard,
	int grey
	) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, grey);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point2.x, point2.y, point2.z);
		glTexCoord2d(0,1); glVertex3d(point3.x, point3.y, point3.z);
		glTexCoord2d(1,1); glVertex3d(point3.x, point3.y + 0.01, point3.z);
		glTexCoord2d(1,0); glVertex3d(point2.x, point2.y + 0.01, point2.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z);
		glTexCoord2d(0,1); glVertex3d(point2.x, point2.y, point2.z);
		glTexCoord2d(1,1); glVertex3d(point3.x, point3.y, point3.z);
		glTexCoord2d(1,0); glVertex3d(point4.x, point4.y, point4.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point3.x, point3.y, point3.z);
		glTexCoord2d(0,1); glVertex3d(point4.x, point4.y, point4.z);
		glTexCoord2d(1,1); glVertex3d(point4.x, point4.y + 0.01, point4.z);
		glTexCoord2d(1,0); glVertex3d(point3.x, point3.y + 0.01, point3.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z);
		glTexCoord2d(0,1); glVertex3d(point2.x, point2.y, point2.z);
		glTexCoord2d(1,1); glVertex3d(point2.x, point2.y + 0.01, point2.z);
		glTexCoord2d(1,0); glVertex3d(point1.x, point1.y + 0.01, point1.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z);
		glTexCoord2d(0,1); glVertex3d(point4.x, point4.y, point4.z);
		glTexCoord2d(1,1); glVertex3d(point4.x, point4.y + 0.01, point4.z);
		glTexCoord2d(1,0); glVertex3d(point1.x, point1.y + 0.01, point1.z);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, keyboard);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y + 0.01, point1.z);
		glTexCoord2d(0,1); glVertex3d(point2.x, point2.y + 0.01, point2.z);
		glTexCoord2d(1,1); glVertex3d(point3.x, point3.y + 0.01, point3.z);
		glTexCoord2d(1,0); glVertex3d(point4.x, point4.y + 0.01, point4.z);
		glEnd();
		
		GLdouble the_screen_width = 0.5;
		Point point11 = {point2.x,point2.y,point2.z};
		Point point22 = {point2.x,point2.y + the_screen_width,point2.z};
		Point point33 = {point3.x,point3.y + the_screen_width,point3.z};
		Point point44 = {point3.x,point3.y,point3.z};
		
		if (point1.x == point2.x) {
			if (point1.z > point11.z) {
				glBindTexture(GL_TEXTURE_2D, grey);
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point22.x, point22.y, point22.z);
				glTexCoord2d(0,1); glVertex3d(point33.x, point33.y, point33.z);
				glTexCoord2d(1,1); glVertex3d(point33.x, point33.y, point33.z - 0.01);
				glTexCoord2d(1,0); glVertex3d(point22.x, point22.y, point22.z - 0.01);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point33.x, point33.y, point33.z);
				glTexCoord2d(0,1); glVertex3d(point44.x, point44.y, point44.z);
				glTexCoord2d(1,1); glVertex3d(point44.x, point44.y, point44.z - 0.01);
				glTexCoord2d(1,0); glVertex3d(point33.x, point33.y, point33.z - 0.01);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point11.x, point11.y, point11.z);
				glTexCoord2d(0,1); glVertex3d(point22.x, point22.y, point22.z);
				glTexCoord2d(1,1); glVertex3d(point22.x, point22.y, point22.z - 0.01);
				glTexCoord2d(1,0); glVertex3d(point11.x, point11.y, point11.z - 0.01);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point11.x, point11.y, point11.z);
				glTexCoord2d(0,1); glVertex3d(point44.x, point44.y, point44.z);
				glTexCoord2d(1,1); glVertex3d(point44.x, point44.y, point44.z - 0.01);
				glTexCoord2d(1,0); glVertex3d(point11.x, point11.y, point11.z - 0.01);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point11.x, point11.y, point11.z - 0.01);
				glTexCoord2d(0,1); glVertex3d(point22.x, point22.y, point22.z - 0.01);
				glTexCoord2d(1,1); glVertex3d(point33.x, point33.y, point33.z - 0.01);
					glTexCoord2d(1,0); glVertex3d(point44.x, point44.y, point44.z - 0.01);
				glEnd();
			} else {
				glBindTexture(GL_TEXTURE_2D, grey);
					glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point22.x, point22.y, point22.z);
				glTexCoord2d(0,1); glVertex3d(point33.x, point33.y, point33.z);
				glTexCoord2d(1,1); glVertex3d(point33.x, point33.y, point33.z + 0.01);
				glTexCoord2d(1,0); glVertex3d(point22.x, point22.y, point22.z + 0.01);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point33.x, point33.y, point33.z);
				glTexCoord2d(0,1); glVertex3d(point44.x, point44.y, point44.z);
				glTexCoord2d(1,1); glVertex3d(point44.x, point44.y, point44.z + 0.01);
				glTexCoord2d(1,0); glVertex3d(point33.x, point33.y, point33.z + 0.01);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point11.x, point11.y, point11.z);
				glTexCoord2d(0,1); glVertex3d(point22.x, point22.y, point22.z);
				glTexCoord2d(1,1); glVertex3d(point22.x, point22.y, point22.z + 0.01);
				glTexCoord2d(1,0); glVertex3d(point11.x, point11.y, point11.z + 0.01);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point11.x, point11.y, point11.z);
				glTexCoord2d(0,1); glVertex3d(point44.x, point44.y, point44.z);
				glTexCoord2d(1,1); glVertex3d(point44.x, point44.y, point44.z + 0.01);
				glTexCoord2d(1,0); glVertex3d(point11.x, point11.y, point11.z + 0.01);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point11.x, point11.y, point11.z + 0.01);
				glTexCoord2d(0,1); glVertex3d(point22.x, point22.y, point22.z + 0.01);
				glTexCoord2d(1,1); glVertex3d(point33.x, point33.y, point33.z + 0.01);
					glTexCoord2d(1,0); glVertex3d(point44.x, point44.y, point44.z + 0.01);
				glEnd();
			}
			glBindTexture(GL_TEXTURE_2D, laptop_screen);
			glBegin(GL_QUADS);
			glTexCoord2d(0,0); glVertex3d(point11.x, point11.y, point11.z);
			glTexCoord2d(0,1); glVertex3d(point22.x, point22.y, point22.z);
			glTexCoord2d(1,1); glVertex3d(point33.x, point33.y, point33.z);
			glTexCoord2d(1,0); glVertex3d(point44.x, point44.y, point44.z);
			glEnd();
		} else {
			if (point1.x > point11.x) {
				glBindTexture(GL_TEXTURE_2D, grey);
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point22.x, point22.y, point22.z);
				glTexCoord2d(0,1); glVertex3d(point33.x, point33.y, point33.z);
				glTexCoord2d(1,1); glVertex3d(point33.x - 0.01, point33.y, point33.z);
				glTexCoord2d(1,0); glVertex3d(point22.x - 0.01, point22.y, point22.z);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point33.x, point33.y, point33.z);
				glTexCoord2d(0,1); glVertex3d(point44.x, point44.y, point44.z);
				glTexCoord2d(1,1); glVertex3d(point44.x - 0.01, point44.y, point44.z);
				glTexCoord2d(1,0); glVertex3d(point33.x - 0.01, point33.y, point33.z);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point11.x, point11.y, point11.z);
				glTexCoord2d(0,1); glVertex3d(point22.x, point22.y, point22.z);
				glTexCoord2d(1,1); glVertex3d(point22.x - 0.01, point22.y, point22.z);
				glTexCoord2d(1,0); glVertex3d(point11.x - 0.01, point11.y, point11.z);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point11.x, point11.y, point11.z);
				glTexCoord2d(0,1); glVertex3d(point44.x, point44.y, point44.z);
				glTexCoord2d(1,1); glVertex3d(point44.x - 0.01, point44.y, point44.z);
				glTexCoord2d(1,0); glVertex3d(point11.x - 0.01, point11.y, point11.z);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point11.x - 0.01, point11.y, point11.z);
				glTexCoord2d(0,1); glVertex3d(point22.x - 0.01, point22.y, point22.z);
				glTexCoord2d(1,1); glVertex3d(point33.x - 0.01, point33.y, point33.z);
				glTexCoord2d(1,0); glVertex3d(point44.x - 0.01, point44.y, point44.z);
				glEnd();
			} else {
				glBindTexture(GL_TEXTURE_2D, grey);
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point22.x, point22.y, point22.z);
				glTexCoord2d(0,1); glVertex3d(point33.x, point33.y, point33.z);
				glTexCoord2d(1,1); glVertex3d(point33.x + 0.01, point33.y, point33.z);
				glTexCoord2d(1,0); glVertex3d(point22.x + 0.01, point22.y, point22.z);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point33.x, point33.y, point33.z);
				glTexCoord2d(0,1); glVertex3d(point44.x, point44.y, point44.z);
				glTexCoord2d(1,1); glVertex3d(point44.x + 0.01, point44.y, point44.z);
				glTexCoord2d(1,0); glVertex3d(point33.x + 0.01, point33.y, point33.z);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point11.x, point11.y, point11.z);
				glTexCoord2d(0,1); glVertex3d(point22.x, point22.y, point22.z);
				glTexCoord2d(1,1); glVertex3d(point22.x + 0.01, point22.y, point22.z);
				glTexCoord2d(1,0); glVertex3d(point11.x + 0.01, point11.y, point11.z);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point11.x, point11.y, point11.z);
				glTexCoord2d(0,1); glVertex3d(point44.x, point44.y, point44.z);
				glTexCoord2d(1,1); glVertex3d(point44.x + 0.01, point44.y, point44.z);
				glTexCoord2d(1,0); glVertex3d(point11.x + 0.01, point11.y, point11.z);
				glEnd();
				glBegin(GL_QUADS);
				glTexCoord2d(0,0); glVertex3d(point11.x + 0.01, point11.y, point11.z);
				glTexCoord2d(0,1); glVertex3d(point22.x + 0.01, point22.y, point22.z);
				glTexCoord2d(1,1); glVertex3d(point33.x + 0.01, point33.y, point33.z);
				glTexCoord2d(1,0); glVertex3d(point44.x + 0.01, point44.y, point44.z);
				glEnd();
			}
			glBindTexture(GL_TEXTURE_2D, laptop_screen);
			glBegin(GL_QUADS);
			glTexCoord2d(0,0); glVertex3d(point11.x, point11.y, point11.z);
			glTexCoord2d(0,1); glVertex3d(point22.x, point22.y, point22.z);
			glTexCoord2d(1,1); glVertex3d(point33.x, point33.y, point33.z);
			glTexCoord2d(1,0); glVertex3d(point44.x, point44.y, point44.z);
			glEnd();
		}
		glDisable(GL_TEXTURE_2D);
}

void DisplayRectangularParallelepiped::displayTV(
	Point point1,
	Point point2, 
	Point point3, 
	Point point4,
	int TV_screen,
	int black
	) {
		glEnable(GL_TEXTURE_2D);
	if (point1.x == point2.x) {
		glBindTexture(GL_TEXTURE_2D, black);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point2.x, point2.y, point2.z);
		glTexCoord2d(0,1); glVertex3d(point3.x, point3.y, point3.z);
		glTexCoord2d(1,1); glVertex3d(point3.x, point3.y, point3.z + 0.05);
		glTexCoord2d(1,0); glVertex3d(point2.x, point2.y, point2.z + 0.05);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point3.x, point3.y, point3.z);
		glTexCoord2d(0,1); glVertex3d(point4.x, point4.y, point4.z);
		glTexCoord2d(1,1); glVertex3d(point4.x, point4.y, point4.z + 0.05);
		glTexCoord2d(1,0); glVertex3d(point3.x, point3.y, point3.z + 0.05);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z);
		glTexCoord2d(0,1); glVertex3d(point2.x, point2.y, point2.z);
		glTexCoord2d(1,1); glVertex3d(point2.x, point2.y, point2.z + 0.05);
		glTexCoord2d(1,0); glVertex3d(point1.x, point1.y, point1.z + 0.05);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z);
		glTexCoord2d(0,1); glVertex3d(point4.x, point4.y, point4.z);
		glTexCoord2d(1,1); glVertex3d(point4.x, point4.y, point4.z + 0.05);
		glTexCoord2d(1,0); glVertex3d(point1.x, point1.y, point1.z + 0.05);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z);
		glTexCoord2d(0,1); glVertex3d(point2.x, point2.y, point2.z);
		glTexCoord2d(1,1); glVertex3d(point3.x, point3.y, point3.z);
		glTexCoord2d(1,0); glVertex3d(point4.x, point4.y, point4.z);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, TV_screen);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z + 0.05);
		glTexCoord2d(0,1); glVertex3d(point2.x, point2.y, point2.z + 0.05);
		glTexCoord2d(1,1); glVertex3d(point3.x, point3.y, point3.z + 0.05);
		glTexCoord2d(1,0); glVertex3d(point4.x, point4.y, point4.z + 0.05);
		glEnd();
	} else {
		glBindTexture(GL_TEXTURE_2D, black);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point2.x, point2.y, point2.z);
		glTexCoord2d(0,1); glVertex3d(point3.x, point3.y, point3.z);
		glTexCoord2d(1,1); glVertex3d(point3.x + 0.05, point3.y, point3.z);
		glTexCoord2d(1,0); glVertex3d(point2.x + 0.05, point2.y, point2.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point3.x, point3.y, point3.z);
		glTexCoord2d(0,1); glVertex3d(point4.x, point4.y, point4.z);
		glTexCoord2d(1,1); glVertex3d(point4.x + 0.05, point4.y, point4.z);
		glTexCoord2d(1,0); glVertex3d(point3.x + 0.05, point3.y, point3.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z);
		glTexCoord2d(0,1); glVertex3d(point2.x, point2.y, point2.z);
		glTexCoord2d(1,1); glVertex3d(point2.x + 0.05, point2.y, point2.z);
		glTexCoord2d(1,0); glVertex3d(point1.x + 0.05, point1.y, point1.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z);
		glTexCoord2d(0,1); glVertex3d(point4.x, point4.y, point4.z);
		glTexCoord2d(1,1); glVertex3d(point4.x + 0.05, point4.y, point4.z);
		glTexCoord2d(1,0); glVertex3d(point1.x + 0.05, point1.y, point1.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z);
		glTexCoord2d(0,1); glVertex3d(point2.x, point2.y, point2.z);
		glTexCoord2d(1,1); glVertex3d(point3.x, point3.y, point3.z);
		glTexCoord2d(1,0); glVertex3d(point4.x, point4.y, point4.z);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, TV_screen);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x + 0.05, point1.y, point1.z);
		glTexCoord2d(0,1); glVertex3d(point2.x + 0.05, point2.y, point2.z);
		glTexCoord2d(1,1); glVertex3d(point3.x + 0.05, point3.y, point3.z);
		glTexCoord2d(1,0); glVertex3d(point4.x + 0.05, point4.y, point4.z);
		glEnd();
	}
	glDisable(GL_TEXTURE_2D);
}
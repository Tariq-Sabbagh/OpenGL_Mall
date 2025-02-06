#include "display_library.h"

void DisplayLibrary::drawLibraryWithoutPoints(
	int brown_wood,
	int wooden_bookshelf,
	int light_brown_wood,
	int glass,
	int library_store
	) {
		Point point1 = {0,0,0};
		Point point2 = {0,0,-10};
		Point point3 = {10,0,-10};
		Point point4 = {10,0,0};
		GLdouble height = 5;
		
		DisplayLibrary displayLibrary;
		displayLibrary.drawLibrary(
			point1,
			point2,
			point3,
			point4,
			height,
			brown_wood,
			wooden_bookshelf,
			light_brown_wood,
			glass,
			library_store
			);
}

void DisplayLibrary::drawLibrary(
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
	) {
		DisplayLibrary object;
		GLdouble the_height_of_the_bookshelf = (max(point1.z,point2.z) - min(point1.z,point2.z))/3;
		GLdouble the_width_of_the_bookshelf = (max(point2.x,point3.x) - min(point2.x,point3.x))/3;

		Point point_1_of_the_bookshelf_1 = {point1.x + the_width_of_the_bookshelf - 0.5,point1.y,point1.z - the_height_of_the_bookshelf};
		Point point_2_of_the_bookshelf_1 = {point1.x + the_width_of_the_bookshelf + 0.5,point1.y,point1.z - the_height_of_the_bookshelf};
		Point point_3_of_the_bookshelf_1 = {point1.x + the_width_of_the_bookshelf + 0.5,point1.y,point1.z - 2*the_height_of_the_bookshelf};
		Point point_4_of_the_bookshelf_1 = {point1.x + the_width_of_the_bookshelf - 0.5,point1.y,point1.z - 2*the_height_of_the_bookshelf};
		GLdouble the_height_for_book_shelf = 4;
		Point point_1_of_the_bookshelf_2 = {point1.x + 2*the_width_of_the_bookshelf - 0.5,point1.y,point1.z - the_height_of_the_bookshelf};
		Point point_2_of_the_bookshelf_2 = {point1.x + 2*the_width_of_the_bookshelf + 0.5,point1.y,point1.z - the_height_of_the_bookshelf};
		Point point_3_of_the_bookshelf_2 = {point1.x + 2*the_width_of_the_bookshelf + 0.5,point1.y,point1.z - 2*the_height_of_the_bookshelf};
		Point point_4_of_the_bookshelf_2 = {point1.x + 2*the_width_of_the_bookshelf - 0.5,point1.y,point1.z - 2*the_height_of_the_bookshelf};

		object.drawOneBookshelf(
			point_1_of_the_bookshelf_1,
			point_2_of_the_bookshelf_1,
			point_3_of_the_bookshelf_1,
			point_4_of_the_bookshelf_1,
			the_height_for_book_shelf,
			brown_wood,
			wooden_bookshelf
			);
		object.drawOneBookshelf(
			point_1_of_the_bookshelf_2,
			point_2_of_the_bookshelf_2,
			point_3_of_the_bookshelf_2,
			point_4_of_the_bookshelf_2,
			the_height_for_book_shelf,
			brown_wood,
			wooden_bookshelf
			);

		Point point_1_of_the_bookshelf_3 = {point1.x + 1,point1.y,point1.z - 0.5};
		Point point_2_of_the_bookshelf_3 = {point1.x,point1.y,point1.z - 0.5};
		Point point_3_of_the_bookshelf_3 = {point2.x,point2.y,point2.z + 0.5};
		Point point_4_of_the_bookshelf_3 = {point2.x + 1,point2.y,point2.z + 0.5};
		the_height_for_book_shelf = 5;
		Point point_1_of_the_bookshelf_4 = {point4.x,point4.y,point4.z - 0.5};
		Point point_2_of_the_bookshelf_4 = {point4.x - 1,point4.y,point4.z - 0.5};
		Point point_3_of_the_bookshelf_4 = {point3.x - 1,point3.y,point3.z + 0.5};
		Point point_4_of_the_bookshelf_4 = {point3.x,point3.y,point3.z + 0.5};

		object.drawOneBookshelf(
			point_1_of_the_bookshelf_3,
			point_2_of_the_bookshelf_3,
			point_3_of_the_bookshelf_3,
			point_4_of_the_bookshelf_3,
			the_height_for_book_shelf,
			brown_wood,
			wooden_bookshelf
			);
		object.drawOneBookshelf(
			point_1_of_the_bookshelf_4,
			point_2_of_the_bookshelf_4,
			point_3_of_the_bookshelf_4,
			point_4_of_the_bookshelf_4,
			the_height_for_book_shelf,
			brown_wood,
			wooden_bookshelf
			);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, light_brown_wood);
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

		GLdouble height_of_the_library_name = height/4;

		glBindTexture(GL_TEXTURE_2D, library_store);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y + 3*height_of_the_library_name, point1.z);
		glTexCoord2d(0,1); glVertex3d(point1.x, point1.y + height, point1.z);
		glTexCoord2d(1,1); glVertex3d(point4.x, point4.y + height, point4.z);
		glTexCoord2d(1,0); glVertex3d(point4.x, point4.y + 3*height_of_the_library_name, point4.z);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, glass);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x,point1.y,point1.z);
		glTexCoord2d(1,0); glVertex3d(point1.x, point1.y + 3*height_of_the_library_name, point1.z);
		glTexCoord2d(0,1); glVertex3d(point4.x - 7, point4.y + 3*height_of_the_library_name, point4.z);
		glTexCoord2d(1,1); glVertex3d(point4.x - 7,point4.y,point4.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x + 7,point1.y,point1.z);
		glTexCoord2d(1,0); glVertex3d(point1.x + 7, point1.y + 3*height_of_the_library_name, point1.z);
		glTexCoord2d(0,1); glVertex3d(point4.x, point4.y + 3*height_of_the_library_name, point4.z);
		glTexCoord2d(1,1); glVertex3d(point4.x,point4.y,point4.z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
}

void DisplayLibrary::drawOneBookshelf(
	Point point1,
	Point point2,
	Point point3,
	Point point4,
	GLdouble height,
	int brown_wood,
	int wooden_bookshelf
	) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, wooden_bookshelf);
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point2.x, point2.y, point2.z);
		glTexCoord2d(1,0); glVertex3d(point3.x, point3.y, point3.z);
		glTexCoord2d(0,1); glVertex3d(point3.x, point3.y + height, point3.z);
		glTexCoord2d(1,1); glVertex3d(point2.x, point2.y + height, point2.z);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0); glVertex3d(point1.x, point1.y, point1.z);
		glTexCoord2d(1,0); glVertex3d(point4.x, point4.y, point4.z);
		glTexCoord2d(0,1); glVertex3d(point4.x, point4.y + height, point4.z);
		glTexCoord2d(1,1); glVertex3d(point1.x, point1.y + height, point1.z);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, brown_wood);
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
		glDisable(GL_TEXTURE_2D);
}
//////////////////////////////////////////////////////////////////////
//
// OpenGL Texture Class
// by: Matthew Fairfax
//

#ifdef UNICODE
#undef UNICODE
#endif
#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include "GLAUX.h"		// Header File For The Glaux Library

#pragma comment(lib,"glaux.lib")

class GLTexture  
{
public:
	char *texturename;								// The textures name
	unsigned int texture[1];						// OpenGL's number for the texture
	int width;										// Texture's width
	int height;										// Texture's height
	void Use();										// Binds the texture for use
	void BuildColorTexture(unsigned char r, unsigned char g, unsigned char b);	// Sometimes we want a texture of uniform color
	void LoadTGAResource(char *name);				// Load a targa from the resources
	void LoadBMPResource(char *name);				// Load a bitmap from the resources
	void LoadFromResource(char *name);				// Load the texture from a resource
	void LoadTGA(char *name);						// Loads a targa file
	void LoadBMP(char *name);						// Loads a bitmap file
	void Load(char *name);							// Load the texture
	GLTexture();									// Constructor
	virtual ~GLTexture();							// Destructor

};

#endif GLTEXTURE_H
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
#include "mall.h"
#include "display_library.h"
#include "ElectronicsStore.h"

#include "mall_lobby.h"


HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default
bool isNight=false,Ni=false;

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

Model_3DS* tableModel,*sofaModel,*carModel,*car2Model;
int pressed,rot=0;
int grey_wood;
int light_brown_wood;
int brown_wood;
int TV_screen;
int mobile_screen;
int laptop_screen;
int keyboard;
int grey;
int black;
int WallBTexture;int buildingTexture2;
int electronics_store;
int buildingNightTexture;
int upfront, wall, glass, up, floorMall;
int night1Texture, night2Texture, night3Texture, night4Texture;
int mallglass;
int logoMall;
int wallMall;
int wooden_bookshelf;
int library_store;

int frontFacingStep;
int topFacingStep;
int sidesImage;
int fenceImage;
int whiteMarbleImage;
int hallFloorImage;

int green_leaves;

int the_grass;


int refrigerator ; 
int refrigerator2 ; 
int wallELE ; 
int roofELE ; 
int airconditioner ; 
int airconditioner2 ; 
int washmachine ;
int washmachine2 ; 
int SolarPanel ; 
int solarpanel2 ;
int dishwasher  ; 
int dishwasher2  ;

int floorTexture,wallTexture,groundTexture,doorTexture,grassTexture,glassTexture,wallRe,fixglass,screen,tableTexture,tablelegTexture,chairTexture,fruitcone,fenceTexture,flowresTexture,logoTexture,torDeskTexture,deskTexture,sky1Texture,sky2Texture,sky3Texture,sky4Texture,sky5Texture,sidewalkTexture,roadTexture;
float i =20.0f, j = 0.0f, k = 50.0f;  
float angle = 4.7f; 
float pitch = 0.0f;
float angleSpeed = 0.007f;  
float moveSpeed = 0.07f;  
float lx,ly,lz;


bool open=false,lp=false,first=false;

void key(bool* keys)
{
    if(keys[VK_LEFT])  
    {
        angle -= angleSpeed;  
    }
    if(keys[VK_RIGHT])  
    {
        angle += angleSpeed;      }

    if(keys['S']) 
    {
        i -= moveSpeed * cos(angle); 
        k -= moveSpeed * sin(angle);
    }

    if(keys['W']) 
    {
        i += moveSpeed * cos(angle); 
        k += moveSpeed * sin(angle);
    }

    if (keys[VK_UP]) 
    {
        j += moveSpeed; 
    }    
    if (keys[VK_DOWN])    
    {
        j -= moveSpeed; 
    }

    if(keys['A']) 
    {
        i += moveSpeed * sin(angle); 
        k -= moveSpeed * cos(angle);
    }

    if(keys['D']) 
    {
        i -= moveSpeed * sin(angle); 
        k += moveSpeed * cos(angle);
    }

	if (keys['Q']) 
{
    pitch += angleSpeed; // زيادة زاوية النظر للأعلى
    if (pitch > 1.5f) pitch = 1.5f; // تحديد الحد الأقصى للنظر للأعلى (تقريباً 90 درجة)
}

if (keys['E']) 
{
    pitch -= angleSpeed; // تقليل زاوية النظر للأسفل
    if (pitch < -1.5f) pitch = -1.5f; // تحديد الحد الأدنى للنظر للأسفل (تقريباً -90 درجة)
}

    if(keys['O']&& !lp)
    {
        lp = true;
        open = !open;
    }
    if(!keys['O'])
    {
        lp = false;
    }
    if (keys['N'] && !Ni)
    {
        Ni = true;
        isNight = !isNight;
    }    
    if(!keys['N'])
    {
        Ni = false;
    }

   
}



float pos0[4] = { 31,0,-6,1 };
float diff0[4] = { 1,1,1,1 };
float spec0[4] = { 1,1,1,1 };
float amb0[4] = { 0.2,0.2,0.2,1 };

float pos1[4] = { -10.5,5.5,5.5,1 };
float diff1[4] = { 1,1,1,1 };
float spec1[4] = { 0.2,0.2,0.2,1 };
float amb1[4] = { 0.2,0.2,0.2,1 };


GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}


int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(1.0f, 1.0f, 1.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diff0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, spec0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb0);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, diff1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, spec1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, amb1);

	glEnable(GL_TEXTURE_2D); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	floorTexture = LoadTexture((char*)"assets/textures/Wood.bmp");
	wallTexture = LoadTexture((char*)"assets/textures/kk.bmp");
	groundTexture = LoadTexture((char*)"assets/textures/ground.bmp");
	doorTexture = LoadTexture((char*)"assets/textures/whitetiles.bmp");
	grassTexture = LoadTexture((char*)"assets/textures/grass2.bmp");
	glassTexture = LoadTexture((char*)"assets/textures/glass.bmp",100);
	wallRe=LoadTexture((char*)"assets/textures/whiteBlock.bmp");
	fixglass=LoadTexture((char*)"assets/textures/blackfloor.bmp");
	screen=LoadTexture((char*)"assets/textures/test.bmp");
	tableTexture = LoadTexture((char*)"assets/textures/RestureantTable/clothTable.bmp");
	tablelegTexture = LoadTexture((char*)"assets/textures/table/3.bmp");
	chairTexture = LoadTexture((char*)"assets/textures/table/1.bmp");
	fenceTexture = LoadTexture((char*)"assets/textures/table/2.bmp");
	fruitcone=LoadTexture((char*)"assets/textures/fruit.bmp");
	flowresTexture=LoadTexture((char*)"assets/textures/flowers.bmp");
	logoTexture=LoadTexture((char*)"assets/textures/aboabdo1.bmp");
	deskTexture=LoadTexture((char*)"assets/textures/Gr.bmp");
	torDeskTexture=LoadTexture((char*)"assets/textures/rrr.bmp");
	mallglass=LoadTexture((char*)"assets/textures/glass roof.bmp",200);
	logoMall=LoadTexture((char *)"assets/textures/logoMall.bmp");

	grey_wood = LoadTexture((char *)"assets/textures/grey_wood.bmp");
  light_brown_wood = LoadTexture((char *)"assets/textures/light_brown_wood.bmp");
  brown_wood = LoadTexture((char *)"assets/textures/brown_wood.bmp");
  TV_screen = LoadTexture((char *)"assets/textures/TV_screen.bmp");
  mobile_screen = LoadTexture((char *)"assets/textures/mobile_screen.bmp");
  laptop_screen = LoadTexture((char *)"assets/textures/laptop_screen.bmp");
  keyboard = LoadTexture((char *)"assets/textures/keyboard.bmp");
  grey = LoadTexture((char *)"assets/textures/grey.bmp");
  black = LoadTexture((char *)"assets/textures/black.bmp");
  electronics_store = LoadTexture((char *)"assets/textures/electronics_store.bmp");

  wooden_bookshelf = LoadTexture((char *)"assets/textures/wooden_bookshelf.bmp");
  library_store = LoadTexture((char *)"assets/textures/library_store.bmp");

  wallMall=LoadTexture((char *)"assets/textures/cone.bmp");


  sky1Texture = LoadTexture((char *)"assets/textures/sky1.bmp");
  sky2Texture = LoadTexture((char *)"assets/textures/sky2.bmp");
  sky3Texture = LoadTexture((char *)"assets/textures/sky3.bmp");
  sky4Texture = LoadTexture((char *)"assets/textures/sky4.bmp");
  sky5Texture = LoadTexture((char *)"assets/textures/sky.bmp");	
  sidewalkTexture=LoadTexture((char *)"assets/textures/ground.bmp");
  roadTexture=LoadTexture((char *)"assets/textures/road.bmp");

  WallBTexture=LoadTexture((char *)"assets/textures/i.bmp");
  buildingTexture2=LoadTexture((char *)"assets/textures/f2.bmp");

  buildingNightTexture=LoadTexture((char *)"assets/textures/buildingelec.bmp");


	night1Texture = LoadTexture((char*)"assets/textures/night1.bmp");
	night2Texture = LoadTexture((char*)"assets/textures/night2.bmp");
	night3Texture = LoadTexture((char*)"assets/textures/night3.bmp");
	night4Texture = LoadTexture((char*)"assets/textures/night4.bmp");

	 upfront=LoadTexture((char*)"assets/textures/upfront.bmp");
	 wall=LoadTexture((char*)"assets/textures/wall1.bmp");
	 glass=LoadTexture((char*)"assets/textures/glass3.bmp");
	 up=LoadTexture((char*)"assets/textures/up.bmp");
	floorMall=LoadTexture((char*)"assets/textures/floor1.bmp");


	refrigerator = LoadTexture("assets/textures/refrigeration.bmp");
  refrigerator2 = LoadTexture("assets/textures/refrigeration2.bmp");
  roofELE= LoadTexture("assets/textures/roof.bmp");  
  wallELE = LoadTexture("assets/textures/floor.bmp");
  airconditioner = LoadTexture("assets/textures/airconditioner.bmp");
  airconditioner2 = LoadTexture("assets/textures/airconditioner2.bmp");
  washmachine = LoadTexture("assets/textures/washmachine.bmp");
    washmachine2 = LoadTexture("assets/textures/washmachine2.bmp");
    SolarPanel = LoadTexture ("assets/textures/solarpanel.bmp");
    dishwasher = LoadTexture ("assets/textures/dishwasher.bmp");
    dishwasher2 = LoadTexture ("assets/textures/dishwasher2.bmp");
    solarpanel2 = LoadTexture ("assets/textures/solarpanel2.bmp");


	sidesImage = LoadTexture("assets/textures/top-facing-step.bmp");
  fenceImage = LoadTexture("assets/textures/darkwood.bmp");
  hallFloorImage = LoadTexture("assets/textures/beige-marble-tiles.bmp");
  whiteMarbleImage = LoadTexture("assets/textures/white-marble.bmp");
  frontFacingStep = LoadTexture("assets/textures/front-facing-step.bmp");
  topFacingStep = LoadTexture("assets/textures/top-facing-step.bmp");
  green_leaves = LoadTexture((char *)"assets/textures/green_leaves.bmp",200);
  the_grass = LoadTexture((char *)"assets/textures/opengl_rt0.bmp");








	/*sofaModel = new Model_3DS();
	sofaModel->Load((char*)"assets/models/sofa/sofa.3DS");
	sofaModel->Materials[0].tex.LoadBMP((char*)"assets/models/sofa/legs.bmp");
	sofaModel->Materials[1].tex.LoadBMP((char*)"assets/models/sofa/leather.bmp");
	sofaModel->Materials[2].tex.LoadBMP((char*)"assets/models/sofa/buttons.bmp");

	sofaModel->scale = 0.07;*/

	carModel= new Model_3DS();
	carModel->Load((char*)"assets/models/car/car.3DS");
	carModel->Materials[0].tex.LoadBMP((char*)"assets/models/car/car.bmp");
	carModel->scale=0.1;
	carModel->rot.y = 0;
	carModel->pos.x = 7;
	carModel->pos.y = 1.6;
	carModel->pos.z = -10;

	car2Model= new Model_3DS();
	car2Model->Load((char*)"assets/models/car/car.3DS");
	car2Model->Materials[0].tex.LoadBMP((char*)"assets/models/car/car.bmp");
	car2Model->scale=0.1;
	car2Model->rot.y = 180;
	car2Model->pos.x = 19;
	car2Model->pos.y = 1.6;
	car2Model->pos.z = 20;


	return TRUE;										// Initialization Went OK
}


mall_lobby malllobby;

float door=0;
int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	if(open)
  {
    if(!first)
    {
      door+=0.001;
      if(door>4)
      {
        first=true;
      }
    }
  }
  else
  {
    if(first)
    {
      door-=0.001;
    }
    if(door<0)
    {
      first=false  ;
    }
  }
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	key(keys);

	  lx = cos(angle) * cos(pitch);
     ly = sin(pitch);
     lz = sin(angle) * cos(pitch);

    gluLookAt(i, j, k, i + lx, j + ly, k + lz, 0, 1, 0);
	glTranslated(0, -2, -10);

	glPushMatrix();
	////function call
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glColor3ub(255,255,255);

	if (isNight) {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		DrawPlace(grassTexture,night1Texture,night2Texture,night3Texture,night4Texture,night1Texture,sidewalkTexture,roadTexture,WallBTexture,buildingNightTexture,upfront,wall,glass,up,floorMall);
	}
	else
	{
	glDisable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);
	DrawPlace(grassTexture,sky1Texture,sky2Texture,sky3Texture,sky4Texture,sky5Texture,sidewalkTexture,roadTexture,WallBTexture,buildingTexture2,upfront,wall,glass,up,floorMall);

	glDisable(GL_TEXTURE);
	glDisable(GL_TEXTURE_2D);
	carModel->Draw();
	car2Model->Draw();
	}

	//resturant
	glPushMatrix();
	glScaled(0.7,0.7,0.7);
	glTranslated(-52.5,1.5,-45);
	DrawResturant( floorTexture , fixglass , glassTexture,  screen, doorTexture , wallRe,chairTexture,tableTexture,tablelegTexture,fruitcone,fenceTexture,flowresTexture,grassTexture,logoTexture ,deskTexture,torDeskTexture);
	glPushMatrix();
	glTranslated(-door,0,0);
	DrawStructureGlass(-7,0,20,0,8,20,glassTexture);
	glPopMatrix();

	//electronic
	glPushMatrix();
	glTranslated(-10,15,18);
	glScaled(3,3,3);
	DisplayRectangularParallelepiped displayRectangularParallelepiped;
    displayRectangularParallelepiped.displayElectronicStore(
    brown_wood,
    mobile_screen,
    laptop_screen,
    keyboard,
    TV_screen,
    grey_wood,
    grey,
    black,
    light_brown_wood,
    glassTexture,
    electronics_store
    );

	glPopMatrix();


	//library
	glPushMatrix();
	glTranslated(10,16,72);
	glRotated(180,0,1,0);
	glScaled(2.9,2.9,2.9);
	DisplayLibrary displayLibrary;
   displayLibrary.drawLibraryWithoutPoints(
    brown_wood,
    wooden_bookshelf,
    light_brown_wood,
    glassTexture,
    library_store
    );
  glPopMatrix();

	glPushMatrix();
	glScaled(0.05,0.05,0.05);
	glTranslated(150,100,1750);
	glRotated(180,0,1,0);
	drawCube(roofELE, wallELE, refrigerator2,refrigerator, airconditioner2,  airconditioner,  washmachine2, washmachine , SolarPanel, solarpanel2, dishwasher2, dishwasher  );
	glPopMatrix();


	glPushMatrix();
	glScaled(1.5,1.5,1.5);
	glTranslated(20,0.5,50);
	glRotated(90,0,1,0);
	malllobby.drawMallLobbyWithoutPoints(
    light_brown_wood,
    green_leaves,
    brown_wood,
    glassTexture,
    frontFacingStep,
    topFacingStep,
    sidesImage,
    fenceImage,
    whiteMarbleImage,
    hallFloorImage,
    the_grass
    );
	glPopMatrix();


	glPushMatrix();
	glTranslated(door,0,0);
	DrawStructureGlass(0,0,20,7,8,20,glassTexture);
	glPopMatrix();
	glPopMatrix();

	drawMall(mallglass,wallMall,logoMall,glassTexture);
	glPushMatrix();
	glTranslated(0,0,-door);
	drawRightDoor(glassTexture);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,door);
	drawleftDoor(glassTexture);
	glPopMatrix();
	glPopMatrix();
	drawLoby(light_brown_wood);





	

	
	
	/*sofaModel->rot.y = 90;
	sofaModel->pos.x = 6.2;
	sofaModel->pos.y = 1;
	sofaModel->pos.z = -29.8;
	sofaModel->Draw();*/
	//glPopMatrix();


	
	glPopMatrix();

	return TRUE;
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{
	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
													if (!HIWORD(wParam))					// Check Minimization State
													{
														active = TRUE;						// Program Is Active
													}
													else
													{
														active = FALSE;						// Program Is No Longer Active
													}

													return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
													switch (wParam)							// Check System Calls
													{
													case SC_SCREENSAVE:					// Screensaver Trying To Start?
													case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
														return 0;							// Prevent From Happening
													}
													break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
													PostQuitMessage(0);						// Send A Quit Message
													return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
													keys[wParam] = TRUE;					// If So, Mark It As TRUE
													return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
													keys[wParam] = FALSE;					// If So, Mark It As FALSE
													return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
													ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
													return 0;								// Jump Back
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Mall", 800, 750, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
				// Recreate Our OpenGL Window
				if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}

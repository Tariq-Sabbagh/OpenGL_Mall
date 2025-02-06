




// old 

/*


#include <windows.h>    // Header File For Windows
#include <gl.h>          // Header File For The OpenGL32 Library
#include <glu.h>         // Header File For The GLu32 Library
#include <cmath>         // For mathematical functions
#include <texture.h> 
#include "camera.h"




HDC hDC;
HGLRC hRC;
HWND hWnd;
HINSTANCE	hInstance;		// Holds The Instance Of The Application
bool keys[256] ; 
Camera MyCamera ; 
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default

int RightBuilding;
int LeftBuilding;
int ground;
int sky;
int glass;






int setupScene(GLvoid) {
    glEnable(GL_DEPTH_TEST);  // تمكين اختبار العمق
    glMatrixMode(GL_PROJECTION); // ضبط نمط المصفوفة إلى العرض
    glLoadIdentity();  // إعادة تعيين المصفوفة

    // إعدادات المنظور لعرض كامل المكعب (زاوية حقل رؤية 45 درجة)
    gluPerspective(45.0, 1.0, 0.1, 10.0);  // تم تعديل المسافة القصوى إلى 10
    glTranslatef(0.0f, 0.0f, -20.0f);  // تحريك الكاميرا للوراء لتغطية كامل المكعب

    glEnable(GL_TEXTURE_2D);
    
    // تحميل النُسخ من الصور (التكسترات)
    RightBuilding = LoadTexture("RightBuilding.bmp", 255);
    LeftBuilding = LoadTexture("LeftBuilding.bmp", 255);
    ground = LoadTexture("ground.bmp", 255);
    sky = LoadTexture("sky.bmp", 255);
    glass = LoadTexture("glass.bmp", 255);
    
    // تحقق من تحميل الصور
    if (RightBuilding == 0) {
        MessageBox(NULL, "Failed to load RightBuilding texture!", "Error", MB_OK);
    }

    MyCamera = Camera();
    MyCamera.Position.x = 0;
    MyCamera.Position.y = 0;
    MyCamera.Position.z = +15;

    return true; 
}


void Key(bool* keys, float speed)
{
	if (keys['S'])
		MyCamera.RotateX(-1 * speed);
	if (keys['W'])
		MyCamera.RotateX(1 * speed);
	if (keys['D'])
		MyCamera.RotateY(-1 * speed);
	if (keys['Z'])
		MyCamera.RotateZ(1 * speed);
	if (keys['X'])
		MyCamera.RotateZ(-1 * speed);
	if (keys['A'])
		MyCamera.RotateY(1 * speed);
	if (keys[VK_UP])
		MyCamera.MoveForward(1 * speed);
	if (keys[VK_DOWN])
		MyCamera.MoveForward(-1 * speed);
	if (keys[VK_RIGHT])
		MyCamera.MoveRight(1 * speed);
	if (keys[VK_LEFT])
		MyCamera.MoveRight(-1 * speed);
	if (keys['O'])
		MyCamera.MoveUpward(1 * speed);
	if (keys['L'])
		MyCamera.MoveUpward(-1 * speed);
	
}

GLfloat i=0 , j =0 , z=0 ; 


int drawCube(GLvoid) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	



    // الوجه العلوي
    glBindTexture(GL_TEXTURE_2D, sky);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  
        glVertex3f(-1.5f, 1.5f, -1.5f);  
        glTexCoord2f(1, 0);
        glVertex3f(1.5f, 1.5f, -1.5f);   
        glTexCoord2f(1, 1);
        glVertex3f(1.5f, 1.5f, 1.5f);    
        glTexCoord2f(0, 1);
        glVertex3f(-1.5f, 1.5f, 1.5f);   
    glEnd();

    // الوجه السفلي
    glBindTexture(GL_TEXTURE_2D, glass);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex3f(-1.5f, -1.5f, -1.5f); 
        glTexCoord2f(1, 0);
        glVertex3f(1.5f, -1.5f, -1.5f);  
        glTexCoord2f(1, 1);
        glVertex3f(1.5f, -1.5f, 1.5f);   
        glTexCoord2f(0, 1);
        glVertex3f(-1.5f, -1.5f, 1.5f);  
    glEnd();

    // الجدار الخلفي
    glBindTexture(GL_TEXTURE_2D, sky);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  
        glVertex3f(-1.5f, -1.5f, -1.5f); 
        glTexCoord2f(1, 0);
        glVertex3f(1.5f, -1.5f, -1.5f);  
        glTexCoord2f(1, 1);
        glVertex3f(1.5f, 1.5f, -1.5f);   
        glTexCoord2f(0, 1);
        glVertex3f(-1.5f, 1.5f, -1.5f);  
    glEnd();

    // الجدار الأيمن
	glBindTexture(GL_TEXTURE_2D, sky);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  
        glVertex3f(1.5f, -1.5f, -1.5f);  
        glTexCoord2f(1, 0);
        glVertex3f(1.5f, -1.5f, 1.5f);   
        glTexCoord2f(1, 1);
        glVertex3f(1.5f, 1.5f, 1.5f);    
        glTexCoord2f(0, 1);
        glVertex3f(1.5f, 1.5f, -1.5f);   
    glEnd();

    // الجدار الأيسر
    glBindTexture(GL_TEXTURE_2D, LeftBuilding);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  
        glVertex3f(-1.5f, -1.5f, -1.5f); 
        glTexCoord2f(1, 0);
        glVertex3f(-1.5f, -1.5f, 1.5f);  
        glTexCoord2f(1, 1);
        glVertex3f(-1.5f, 1.5f, 1.5f);   
        glTexCoord2f(0, 1);
        glVertex3f(-1.5f, 1.5f, -1.5f);  
    glEnd();


		MyCamera.Render();
	Key(keys, 2);


	return true ;
}






















// Create and return a window that spans the entire screen, including taskbar
HWND createOpenGLWindow(const char* title) {
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = GetModuleHandle(0);
    wc.lpszClassName = "OpenGLWindowClass";
    RegisterClass(&wc);





    // الحصول على أبعاد الشاشة (عرض وارتفاع)
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // تحديد حجم النافذة لتشغل كامل الشاشة مع شريط العنوان
    hWnd = CreateWindow("OpenGLWindowClass", title, WS_OVERLAPPEDWINDOW, 
                        0, 0, screenWidth, screenHeight, 
                        NULL, NULL, wc.hInstance, NULL);

    hDC = GetDC(hWnd);
    PIXELFORMATDESCRIPTOR pfd = { sizeof(PIXELFORMATDESCRIPTOR), 1,
                                  PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
                                  PFD_TYPE_RGBA, 24, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0 };

    int pixelFormat = ChoosePixelFormat(hDC, &pfd);
    SetPixelFormat(hDC, pixelFormat, &pfd);

    hRC = wglCreateContext(hDC);
    wglMakeCurrent(hDC, hRC);

    return hWnd;
}

int main() {
    // إعداد النافذة لتشغل كامل الشاشة مع شريط العنوان
    HWND hWnd = createOpenGLWindow("OpenGL Cube");
    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    setupScene();  // إعداد المشهد

    MSG msg;
    while (true) {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                return 0;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
		drawCube();  // رسم المشهد
    }

    return 0;
}










































#include <windows.h>    // Header File For Windows
#include <gl.h>          // Header File For The OpenGL32 Library
#include <glu.h>         // Header File For The GLu32 Library
#include <cmath>       // For mathematical functions
#include <texture.h> 


HDC hDC;
HGLRC hRC;
HWND hWnd;

// ++ 
int RightBuilding  ;
int LeftBuilding ;
int ground ;
int sky ; 
int glass ; 

void setupScene() {
  //  glClearColor(0.5, 0.5, 0.5, 1.0); // تعيين اللون الخلفي للنافذة (رمادي)
    glEnable(GL_DEPTH_TEST);  // تمكين اختبار العمق
    glMatrixMode(GL_PROJECTION); // ضبط نمط المصفوفة إلى العرض
    glLoadIdentity();  // إعادة تعيين المصفوفة

    // إعدادات المنظور (نصف الزاوية العلوية لرؤية كاملة)
    gluPerspective(45.0, 1.0, 0.1, 100.0);  
    glTranslatef(0.0f, -0.5f, -5.0f);  // تحريك المشهد للتركيز على القسم الثاني من الشاشة




	// ++ 
	glEnable(GL_TEXTURE_2D);
	
	RightBuilding = LoadTexture("RightBuilding.bmp",255);
	LeftBuilding = LoadTexture("LeftBuilding.bmp",255);
	ground = LoadTexture("ground.bmp",255);
	sky = LoadTexture ("sky.bmp",255);
	glass = LoadTexture("glass.bmp",255);



}



void drawRoom() {
    // الوجه العلوي
    glBindTexture(GL_TEXTURE_2D, sky);  // تكسترة السماء
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  
        glVertex3f(-2.5f, 2.5f, -2.5f);  // الزاوية العلوية اليسرى الخلفية
        glTexCoord2f(1, 0);
        glVertex3f(2.5f, 2.5f, -2.5f);   // الزاوية العلوية اليمنى الخلفية
        glTexCoord2f(1, 1);
        glVertex3f(2.5f, 2.5f, 2.5f);    // الزاوية العلوية اليمنى الأمامية
        glTexCoord2f(0, 1);
        glVertex3f(-2.5f, 2.5f, 2.5f);   // الزاوية العلوية اليسرى الأمامية
    glEnd();

    // الوجه السفلي
	glBindTexture(GL_TEXTURE_2D, glass);  // تكسترة السماء
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex3f(-2.5f, -2.5f, -2.5f); // الزاوية السفلية اليسرى الخلفية
        glTexCoord2f(1, 0);
        glVertex3f(2.5f, -2.5f, -2.5f);  // الزاوية السفلية اليمنى الخلفية
        glTexCoord2f(1, 1);
        glVertex3f(2.5f, -2.5f, 2.5f);   // الزاوية السفلية اليمنى الأمامية
        glTexCoord2f(0, 1);
        glVertex3f(-2.5f, -2.5f, 2.5f);  // الزاوية السفلية اليسرى الأمامية
    glEnd();

    // الجدار الخلفي
    glBindTexture(GL_TEXTURE_2D, sky);  // تكسترة السماء
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  
        glVertex3f(-2.5f, -2.5f, -2.5f); // الزاوية السفلية اليسرى
        glTexCoord2f(1, 0);
        glVertex3f(2.5f, -2.5f, -2.5f);  // الزاوية السفلية اليمنى
        glTexCoord2f(1, 1);
        glVertex3f(2.5f, 2.5f, -2.5f);   // الزاوية العلوية اليمنى
        glTexCoord2f(0, 1);
        glVertex3f(-2.5f, 2.5f, -2.5f);  // الزاوية العلوية اليسرى
    glEnd();

    // الجدار الأيمن
	glBindTexture(GL_TEXTURE_2D,RightBuilding );// تكسترة السماء
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  
        glVertex3f(2.5f, -2.5f, -2.5f);  // الزاوية السفلية اليسرى
        glTexCoord2f(1, 0);
        glVertex3f(2.5f, -2.5f, 2.5f);   // الزاوية السفلية اليمنى
        glTexCoord2f(1, 1);
        glVertex3f(2.5f, 2.5f, 2.5f);    // الزاوية العلوية اليمنى
        glTexCoord2f(0, 1);
        glVertex3f(2.5f, 2.5f, -2.5f);   // الزاوية العلوية اليسرى
    glEnd();

    // الجدار الأيسر
	glBindTexture(GL_TEXTURE_2D, LeftBuilding);  // تكسترة السماء
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0);  
        glVertex3f(-2.5f, -2.5f, -2.5f); // الزاوية السفلية اليسرى
        glTexCoord2f(1, 0);
        glVertex3f(-2.5f, -2.5f, 2.5f);  // الزاوية السفلية اليمنى
        glTexCoord2f(1, 1);
        glVertex3f(-2.5f, 2.5f, 2.5f);   // الزاوية العلوية اليمنى
        glTexCoord2f(0, 1);
        glVertex3f(-2.5f, 2.5f, -2.5f);  // الزاوية العلوية اليسرى
    glEnd();
}






/*
void drawRoom() {



	// sky
	glBindTexture(GL_TEXTURE_2D,sky);
	glBegin(GL_QUADS);
    glTexCoord2f(0,0);
    // الزاوية العلوية اليسرى
    glVertex3f(-2.5f, 3.0f, -1.0f);  
    glTexCoord2f(1,0);
    // الزاوية العلوية اليمنى
    glVertex3f(2.5f, 3.0f, -1.0f);   
	glTexCoord2f(1,1);
    // الزاوية السفلية اليمنى (في الثلث العلوي من الشاشة)
    glVertex3f(2.5f,+ 1.0f, -1.0f);    
	glTexCoord2f(0,1);
    // الزاوية السفلية اليسرى (في الثلث العلوي من الشاشة)
    glVertex3f(-2.5f,+ 1.0f, -1.0f);   

glEnd();





	// ++ 
	glBindTexture(GL_TEXTURE_2D,ground);
    // أرضية (أسفل المتوازي المستطيل)
    glBegin(GL_QUADS);

		glTexCoord2f(0,0);
		glVertex3f(-1.66f, -1.0f, -1.0f);  // الزاوية السفلية اليسرى الخلفية
        glTexCoord2f(1,0);
		glVertex3f(1.66f, -1.0f, -1.0f);   // الزاوية السفلية اليمنى الخلفية
        glTexCoord2f(1,1);
		glVertex3f(1.66f, -1.0f, 1.0f);    // الزاوية السفلية اليمنى الأمامية
        glTexCoord2f(0,1);
		glVertex3f(-1.66f, -1.0f, 1.0f);   // الزاوية السفلية اليسرى الأمامية
    glEnd();

	

    // السقف (الجزء العلوي من المتوازي المستطيل)
	glBindTexture(GL_TEXTURE_2D,glass);
    glBegin(GL_QUADS);


	glTexCoord2f(0,0);	
	glVertex3f(-1.66f, 1.0f, -1.0f);  // الزاوية العلوية اليسرى الخلفية

		glTexCoord2f(1,0);
	glVertex3f(1.66f, 1.0f, -1.0f);   // الزاوية العلوية اليمنى الخلفية

	glTexCoord2f(1,1);
	glVertex3f(1.66f, 1.0f, 1.0f);    // الزاوية العلوية اليمنى الأمامية

	glTexCoord2f(0,1);
	glVertex3f(-1.66f, 1.0f, 1.0f);   // الزاوية العلوية اليسرى الأمامية
    glEnd();
	
	

    // الجدار الخلفي (المواجهة للمشاهد)
    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0); // تعيين اللون (أزرق)
        glVertex3f(-1.66f, -1.0f, -1.0f);  // الزاوية السفلية اليسرى
        glVertex3f(1.66f, -1.0f, -1.0f);   // الزاوية السفلية اليمنى
        glVertex3f(1.66f, 1.0f, -1.0f);    // الزاوية العلوية اليمنى
        glVertex3f(-1.66f, 1.0f, -1.0f);   // الزاوية العلوية اليسرى
    glEnd();

	// ++
		glBindTexture(GL_TEXTURE_2D,sky);

    // الجدار الأيمن
    glBegin(GL_QUADS);

        glTexCoord2f(0,0);
		glVertex3f(1.66f, -1.0f, -1.0f);  // الزاوية السفلية اليسرى
        glTexCoord2f(1,0);
		glVertex3f(1.66f, -1.0f, 1.0f);   // الزاوية السفلية اليمنى
        glTexCoord2f(1,1);
		glVertex3f(1.66f, 1.0f, 1.0f);    // الزاوية العلوية اليمنى
        glTexCoord2f(0,1);
		glVertex3f(1.66f, 1.0f, -1.0f);   // الزاوية العلوية اليسرى
    glEnd();

    // الجدار الأيسر
	glBindTexture(GL_TEXTURE_2D,sky);
	glBegin(GL_QUADS);

        glTexCoord2f(0,0);
		glVertex3f(-1.66f, -1.0f, -1.0f);  // الزاوية السفلية اليسرى
        glTexCoord2f(1,0);
		glVertex3f(-1.66f, -1.0f, 1.0f);   // الزاوية السفلية اليمنى
        glTexCoord2f(1,1);
		glVertex3f(-1.66f, 1.0f, 1.0f);    // الزاوية العلوية اليمنى
        glTexCoord2f(0,1);
		glVertex3f(-1.66f, 1.0f, -1.0f);   // الزاوية العلوية اليسرى
    glEnd();
}


void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // مسح الشاشة والعمق
    drawRoom();  // رسم المتوازي المستطيلات (الغرفة)
    glFlush();  // تنفيذ الأوامر
    SwapBuffers(hDC);  // تحديث الشاشة
}

// Create and return a window that spans the entire screen, including taskbar
HWND createOpenGLWindow(const char* title) {
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = GetModuleHandle(0);
    wc.lpszClassName = "OpenGLWindowClass";
    RegisterClass(&wc);

    // الحصول على أبعاد الشاشة (عرض وارتفاع)
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // تحديد حجم النافذة لتشغل كامل الشاشة مع شريط العنوان
    hWnd = CreateWindow("OpenGLWindowClass", title, WS_OVERLAPPEDWINDOW, 
                        0, 0, screenWidth, screenHeight, 
                        NULL, NULL, wc.hInstance, NULL);

    hDC = GetDC(hWnd);
    PIXELFORMATDESCRIPTOR pfd = { sizeof(PIXELFORMATDESCRIPTOR), 1,
                                  PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
                                  PFD_TYPE_RGBA, 24, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0 };

    int pixelFormat = ChoosePixelFormat(hDC, &pfd);
    SetPixelFormat(hDC, pixelFormat, &pfd);

    hRC = wglCreateContext(hDC);
    wglMakeCurrent(hDC, hRC);

    return hWnd;
}

int main() {
    // إعداد النافذة لتشغل كامل الشاشة مع شريط العنوان
    HWND hWnd = createOpenGLWindow("OpenGL Room");
    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    setupScene();  // إعداد المشهد

    MSG msg;
    while (true) {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                return 0;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        renderScene();  // رسم المشهد
    }

    return 0;
}
*/
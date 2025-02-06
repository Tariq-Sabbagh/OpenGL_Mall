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

#define M_PI 3.14159265359




void drawWall(float x, float y, float z, float width, float height) {
    // رسم الحائط الخلفي للشلال بلون بني فاتح
    glColor3f(0.6, 0.4, 0.3);
    glBegin(GL_QUADS);
    glVertex3f(x, y, z);
    glVertex3f(x + width, y, z);
    glVertex3f(x + width, y + height, z);
    glVertex3f(x, y + height, z);
    glEnd();
}

void drawImprovedChocolateStream(float x, float y, float z, float width, float height, float time) {
    int numStrips = 10;          // عدد الخطوط العمودية المتوازية
    float stripWidth = width / numStrips; // عرض كل خط عمودي

    float waveAmplitude = 0.05;  // سعة التموج (التعرج)
    float waveFrequency = 8.0;   // تكرار التموج

    // رسم عدة خطوط متموجة
    for (int i = 0; i < numStrips; i++) {
        float offsetX = i * stripWidth; // الإزاحة الأفقية لكل خط
        glBegin(GL_QUAD_STRIP);
        for (float j = 0; j <= height; j += 0.05) {
            // حساب التعرج باستخدام دالة الجيب مع إزاحة مختلفة لكل خط
            float offset = waveAmplitude * sin(waveFrequency * j + time + i * 0.5);
            glColor3f(0.4, 0.2, 0.1); // لون الشوكولاتة الداكن
            glVertex3f(x + offsetX + offset, y - j, z);
            glVertex3f(x + offsetX + stripWidth + offset, y - j, z);
        }
        glEnd();
    }
}

void DrawSphere(float radius, int slices, int stacks) {
    float pi = 3.14159265359f;

    // التكرار عبر الـ slices (التقسيمات على المحور الأفقي)
    for (int i = 0; i < slices; ++i) {
        float theta1 = (i * 2.0f * pi) / slices;
        float theta2 = ((i + 1) * 2.0f * pi) / slices;

        // التكرار عبر الـ stacks (التقسيمات على المحور الرأسي)
        for (int j = 0; j < stacks; ++j) {
            float phi1 = (j * pi) / stacks - pi / 2;  // زاوية إزاحة
            float phi2 = ((j + 1) * pi) / stacks - pi / 2;

            // حساب إحداثيات النقاط باستخدام معادلات الكرة
            float x1 = radius * cos(phi1) * cos(theta1);
            float y1 = radius * cos(phi1) * sin(theta1);
            float z1 = radius * sin(phi1);

            float x2 = radius * cos(phi1) * cos(theta2);
            float y2 = radius * cos(phi1) * sin(theta2);
            float z2 = radius * sin(phi1);

            float x3 = radius * cos(phi2) * cos(theta1);
            float y3 = radius * cos(phi2) * sin(theta1);
            float z3 = radius * sin(phi2);

            float x4 = radius * cos(phi2) * cos(theta2);
            float y4 = radius * cos(phi2) * sin(theta2);
            float z4 = radius * sin(phi2);

            // رسم المثلثات باستخدام هذه النقاط
            glBegin(GL_TRIANGLES);
                glVertex3f(x1, y1, z1);
                glVertex3f(x2, y2, z2);
                glVertex3f(x3, y3, z3);

                glVertex3f(x2, y2, z2);
                glVertex3f(x4, y4, z4);
                glVertex3f(x3, y3, z3);
            glEnd();
        }
    }
}

void drawFallingDrops(float x, float y, float z, float radius, int numDrops, float time) {
    // رسم قطرات شوكولا متساقطة من الشلال
    glColor3f(0.3, 0.15, 0.1);
    for (int i = 0; i < numDrops; i++) {
        float dropX = x + ((rand() % 100) / 100.0f) * radius - radius / 2;
        float dropY = y - fmod(time + i * 0.5, 6.0); // تساقط القطرات بشكل دوري
        float dropZ = z;
        glPushMatrix();
        glTranslatef(dropX, dropY, dropZ);
        DrawSphere(0.05, 10, 10); // رسم القطرة على شكل كرة صغيرة
        glPopMatrix();
    }
}

void drawWellImproved(float x, float y, float z, float radius, float height,int stoneTextureID ) {
    GLUquadric *quad = gluNewQuadric();

    glEnable(GL_TEXTURE_2D);  // تفعيل الخامات
    glBindTexture(GL_TEXTURE_2D, stoneTextureID);  // ربط خامة الحجارة
    glColor3f(1.0, 1.0, 1.0);  // اللون الأبيض لضمان ظهور الخامة بشكل صحيح

    glPushMatrix();
    gluQuadricTexture(quad, GL_TRUE);  // تمكين الخامة على الأسطوانة
    glPushMatrix();
	glTranslatef(x, y - height, z);  // التأكد من أن البئر في الموضع الصحيح
	gluCylinder(quad, radius, radius, height, 32, 32);
	glPopMatrix();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);  // تعطيل الخامات بعد الرسم

    gluDeleteQuadric(quad);
}


void drawFallingDropsImproved(float x, float y, float z, float width, int numDrops, float time) {
    //glEnable(GL_LIGHTING);  // تفعيل الإضاءة لتفاعل القطرات مع الضوء

    for (int i = 0; i < numDrops; i++) {
        float dropX = x + ((rand() % 100) / 100.0f) * width - width / 2;
        float dropY = y - fmod(time * 3 + i * 0.3, 6.0);  // حركة متكررة للقطرات
        float dropSize = 0.03 + 0.02 * sin(time + i);      // حجم متغير للقطرة

        glPushMatrix();
        glTranslatef(dropX, dropY, z);
        glColor3f(0.5, 0.25, 0.1);  // لون الشوكولا مع تأثير لمعان خفيف
        DrawSphere(dropSize, 12, 12);  // رسم القطرة على شكل كرة صغيرة
        glPopMatrix();
    }

    //glDisable(GL_LIGHTING);  // تعطيل الإضاءة بعد الانتهاء
}
void DrawDecor(int texture1,int texture2,int texture3)
{

}


void drawChocolateFountain(int stoneTextureID) {
    // حساب الوقت الحالي للحركة
   DWORD start_time = GetTickCount();  // الوقت بداية

    // في دالة الرسوم الخاصة بك:
    DWORD current_time = GetTickCount();
	float time = (current_time - start_time) / 1000.0f;  // الوقت بالثواني

    ////// رسم الحائط الخلفي
    ////drawWall(-5, 0, -10, 10, 8);

    // رسم الشلال المتعرج
   drawImprovedChocolateStream(-1, 6, -9.9, 2, 6, time);

   drawFallingDropsImproved(0, 6, -9.9, 2, 20, time);


    // رسم القطرات المتساقطة من الشلال
    drawFallingDrops(0, 6, -9.9, 2, 20, time);

    // رسم البئر في الأسفل
    drawWellImproved(0, 0, -10, 1.5, 2,stoneTextureID);
}



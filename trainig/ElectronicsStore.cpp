
#include "ElectronicsStore.h";

int drawCube(int roof,int wall,int refrigerator2,int refrigerator,int airconditioner2,int  airconditioner, int washmachine2,int washmachine, int SolarPanel,int solarpanel2,int dishwasher2,int dishwasher  ) {
  


  
  glEnable(GL_TEXTURE_2D);
    float ff=250.0 ; 
  //glPushMatrix();
    

float newHeight = 70.0; 

//roof
glBindTexture(GL_TEXTURE_2D, roof);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-ff-100, newHeight + 20.0, -ff);  
    glTexCoord2f(1, 0);
    glVertex3f(ff+100, newHeight + 20.0, -ff);   
    glTexCoord2f(1, 1);
    glVertex3f(ff+100, newHeight + 20.0, ff);    
    glTexCoord2f(0, 1);
    glVertex3f(-ff-100, newHeight + 20.0, ff);   
glEnd();



// floor
glBindTexture(GL_TEXTURE_2D, wall); 

glBegin(GL_QUADS);



glTexCoord2f(0, 0);
glVertex3f(-ff - 100.0, -newHeight - 20.0, -ff );


glTexCoord2f(1, 0);
glVertex3f(ff + 200.0 - 100.0, -newHeight - 20.0, -ff );

glTexCoord2f(1, 1);
glVertex3f(ff + 200.0 - 100.0, -newHeight - 20.0, ff );

glTexCoord2f(0, 1);
glVertex3f(-ff - 100.0, -newHeight - 20.0, ff );

glEnd();





// back
glBindTexture(GL_TEXTURE_2D, wall);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-ff-100, -newHeight - 20.0, -ff); 
    glTexCoord2f(1, 0);
    glVertex3f(ff+100, -newHeight - 20.0, -ff);  
    glTexCoord2f(1, 1);
    glVertex3f(ff+100, newHeight + 20.0, -ff);   
    glTexCoord2f(0, 1);
    glVertex3f(-ff-100, newHeight + 20.0, -ff);  
glEnd();

// right
glBindTexture(GL_TEXTURE_2D, wall);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(ff+100, -newHeight - 20.0, -ff);  
    glTexCoord2f(1, 0);
    glVertex3f(ff+100, -newHeight - 20.0, ff);   
    glTexCoord2f(1, 1);
    glVertex3f(ff+100, newHeight + 20.0, ff);    
    glTexCoord2f(0, 1);
    glVertex3f(ff+100, newHeight + 20.0, -ff);   
glEnd();

// left
glBindTexture(GL_TEXTURE_2D, wall);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-ff-100, -newHeight - 20.0, -ff); 
    glTexCoord2f(1, 0);
    glVertex3f(-ff-100, -newHeight - 20.0, ff);  
    glTexCoord2f(1, 1);
    glVertex3f(-ff-100, newHeight + 20.0, ff);   
    glTexCoord2f(0, 1);
    glVertex3f(-ff-100, newHeight + 20.0, -ff);  
glEnd();

// front
glBindTexture(GL_TEXTURE_2D, wall); 
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-350, -newHeight - 20.0, ff);   
    glTexCoord2f(1, 0);
    glVertex3f(-100, -newHeight - 20.0, ff);   
    glTexCoord2f(1, 1);
    glVertex3f(-100, newHeight + 20.0, ff);    
    glTexCoord2f(0, 1);
    glVertex3f(-350, newHeight + 20.0, ff);   
glEnd();


glBindTexture(GL_TEXTURE_2D, wall); 
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(100.0, -newHeight - 20.0, ff);   
    glTexCoord2f(1, 0);
    glVertex3f(+350, -newHeight - 20.0, ff);   
    glTexCoord2f(1, 1);
    glVertex3f(+350, newHeight + 20.0, ff);    
    glTexCoord2f(0, 1);
    glVertex3f(100.0, newHeight + 20.0, ff);   
glEnd();














float lb = 40.0 ; 
// refrigerator



float offsetY = -350.0f;
glBindTexture(GL_TEXTURE_2D, refrigerator2);

// roof
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-260.0, 8.0f * lb + offsetY+70, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-200.0, 8.0f * lb + offsetY+70, -lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-200.0, 8.0f * lb + offsetY+70, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-260.0, 8.0f * lb + offsetY+70, lb);   
glEnd();

// floor
glBindTexture(GL_TEXTURE_2D, refrigerator2);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-260.0, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-200.0, 7.0f * lb + offsetY, -lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-200.0, 7.0f * lb + offsetY, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-260.0, 7.0f * lb + offsetY, lb);   
glEnd();

// back
glBindTexture(GL_TEXTURE_2D, refrigerator2);


glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-260.0, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-200.0, 7.0f * lb + offsetY, -lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-200.0, 8.0f * lb + offsetY+70, -lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-260.0, 8.0f * lb + offsetY+70, -lb);   
glEnd();


//front
glBindTexture(GL_TEXTURE_2D, refrigerator);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-260.0, 7.0f * lb + offsetY, lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-200.0, 7.0f * lb + offsetY, lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-200.0, 8.0f * lb + offsetY+70, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-260.0, 8.0f * lb + offsetY+70, lb);   
glEnd();

//right
glBindTexture(GL_TEXTURE_2D, refrigerator2);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-200.0, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-200.0, 7.0f * lb + offsetY, lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-200.0, 8.0f * lb + offsetY+70, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-200.0, 8.0f * lb + offsetY+70, -lb);   
glEnd();

// left
glBindTexture(GL_TEXTURE_2D, refrigerator2);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-260.0, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-260.0, 7.0f * lb + offsetY, lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-260.0, 8.0f * lb + offsetY+70, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-260.0, 8.0f * lb + offsetY+70, -lb);   
glEnd();










// air conditioner




glBindTexture(GL_TEXTURE_2D, airconditioner2);

// roof
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-150.0, 8.0f * lb + offsetY+70, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-100.0, 8.0f * lb + offsetY+70, -lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-150.0, 8.0f * lb + offsetY+70, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-100.0, 8.0f * lb + offsetY+70, lb);   
glEnd();

// floor
glBindTexture(GL_TEXTURE_2D, airconditioner2);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-150.0, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-100.0, 7.0f * lb + offsetY, -lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-100.0, 7.0f * lb + offsetY, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-150.0, 7.0f * lb + offsetY, lb);   
glEnd();

// back
glBindTexture(GL_TEXTURE_2D, airconditioner2);

glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-150.0, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-100.0, 7.0f * lb + offsetY, -lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-100.0, 8.0f * lb + offsetY+70, -lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-150.0, 8.0f * lb + offsetY+70, -lb);   
glEnd();


//front
glBindTexture(GL_TEXTURE_2D, airconditioner);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-150.0, 7.0f * lb + offsetY, lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-100.0, 7.0f * lb + offsetY, lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-100.0, 8.0f * lb + offsetY+70, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-150.0, 8.0f * lb + offsetY+70, lb);   
glEnd();

//right
glBindTexture(GL_TEXTURE_2D, airconditioner2);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-100.0, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-100.0, 7.0f * lb + offsetY, lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-100.0, 8.0f * lb + offsetY+70, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-100.0, 8.0f * lb + offsetY+70, -lb);   
glEnd();

// left
glBindTexture(GL_TEXTURE_2D, airconditioner2);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-150.0, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-150.0, 7.0f * lb + offsetY, lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-150.0, 8.0f * lb + offsetY+70, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-150.0, 8.0f * lb + offsetY+70, -lb);   
glEnd();









// wash machine




glBindTexture(GL_TEXTURE_2D, washmachine2);


// roof
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-60.0, 8.0f * lb + offsetY+20, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-10.0, 8.0f * lb + offsetY+20, -lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-10.0, 8.0f * lb + offsetY+20, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-60.0, 8.0f * lb + offsetY+20, lb);   
glEnd();

// floor
glBindTexture(GL_TEXTURE_2D, washmachine2);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-60.0, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-10.0, 7.0f * lb + offsetY, -lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-10.0, 7.0f * lb + offsetY, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-60.0, 7.0f * lb + offsetY, lb);   
glEnd();

// back
glBindTexture(GL_TEXTURE_2D, washmachine2);

glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-60.0, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-10.0, 7.0f * lb + offsetY, -lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-10.0, 8.0f * lb + offsetY+20, -lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-60.0, 8.0f * lb + offsetY+20, -lb);   
glEnd();


//front
glBindTexture(GL_TEXTURE_2D, washmachine);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-60.0, 7.0f * lb + offsetY, lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-10.0, 7.0f * lb + offsetY, lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-10.0, 8.0f * lb + offsetY+20, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-60.0, 8.0f * lb + offsetY+20, lb);   
glEnd();

//right
glBindTexture(GL_TEXTURE_2D, washmachine2);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-10.0, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-10.0, 7.0f * lb + offsetY, lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-10.0, 8.0f * lb + offsetY+20, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-10.0, 8.0f * lb + offsetY+20, -lb);   
glEnd();

// left
glBindTexture(GL_TEXTURE_2D, washmachine2);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(-60.0, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(-60.0, 7.0f * lb + offsetY, lb);   
    glTexCoord2f(1, 1);
    glVertex3f(-60.0, 8.0f * lb + offsetY+20, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(-60.0, 8.0f * lb + offsetY+20, -lb);   
glEnd();




//   2 solar panel


glBindTexture(GL_TEXTURE_2D, SolarPanel);

glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(+30.0, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(+80.0, 7.0f * lb + offsetY, -lb);   
    glTexCoord2f(1, 1);
    glVertex3f(+80.0, 8.0f * lb + offsetY+70, -lb-100);    
    glTexCoord2f(0, 1);
    glVertex3f(+30.0, 8.0f * lb + offsetY+70, -lb-100);   
glEnd();

glBindTexture(GL_TEXTURE_2D, solarpanel2);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(+100.0, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(+140.0, 7.0f * lb + offsetY, -lb);   
    glTexCoord2f(1, 1);
    glVertex3f(+140.0, 8.0f * lb + offsetY+70, -lb-100);    
    glTexCoord2f(0, 1);
    glVertex3f(+100.0, 8.0f * lb + offsetY+70, -lb-100);   
glEnd();




// Dishwasher





glBindTexture(GL_TEXTURE_2D, dishwasher2);

// roof
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(240, 8.0f * lb + offsetY+20, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(190, 8.0f * lb + offsetY+20, -lb);   
    glTexCoord2f(1, 1);
    glVertex3f(190, 8.0f * lb + offsetY+20, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(240, 8.0f * lb + offsetY+20, lb);   
glEnd();

// floor
glBindTexture(GL_TEXTURE_2D, dishwasher2);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(+240, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(+190, 7.0f * lb + offsetY, -lb);   
    glTexCoord2f(1, 1);
    glVertex3f(+190, 7.0f * lb + offsetY, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(+240, 7.0f * lb + offsetY, lb);   
glEnd();

// back
glBindTexture(GL_TEXTURE_2D, dishwasher2);


glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(240, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(190, 7.0f * lb + offsetY, -lb);   
    glTexCoord2f(1, 1);
    glVertex3f(190, 8.0f * lb + offsetY+20, -lb);    
    glTexCoord2f(0, 1);
    glVertex3f(+240, 8.0f * lb + offsetY+20, -lb);   
glEnd();


//front
glBindTexture(GL_TEXTURE_2D, dishwasher);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(240, 7.0f * lb + offsetY, lb);  
    glTexCoord2f(1, 0);
    glVertex3f(190, 7.0f * lb + offsetY, lb);   
    glTexCoord2f(1, 1);
    glVertex3f(190, 8.0f * lb + offsetY+20, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(240, 8.0f * lb + offsetY+20, lb);   
glEnd();

//right
glBindTexture(GL_TEXTURE_2D, dishwasher2);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(190, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(190, 7.0f * lb + offsetY, lb);   
    glTexCoord2f(1, 1);
    glVertex3f(190, 8.0f * lb + offsetY+20, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(190, 8.0f * lb + offsetY+20, -lb);   
glEnd();

// left
glBindTexture(GL_TEXTURE_2D, dishwasher2);
glBegin(GL_QUADS);
    glTexCoord2f(0, 0);  
    glVertex3f(240, 7.0f * lb + offsetY, -lb);  
    glTexCoord2f(1, 0);
    glVertex3f(240, 7.0f * lb + offsetY, lb);   
    glTexCoord2f(1, 1);
    glVertex3f(240, 8.0f * lb + offsetY+20, lb);    
    glTexCoord2f(0, 1);
    glVertex3f(240, 8.0f * lb + offsetY+20, -lb);   
glEnd();





glDisable(GL_TEXTURE_2D);

  return true ;
}





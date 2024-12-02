#pragma once
#include<iostream>
#include<GL/glut.h>
#include"Draw.h"
#include "point.h"
class Furniture
{
public:
    Draw draw;
    float leftDoorAngle = 0.0f;  
    float rightDoorAngle = 0.0f; 
    bool isOpening = false;      
    

    void drawCeilingFan() {// to draw 3 rectanle and 
        


        glPushMatrix();

        glColor3f(0.5f, 0.5f, 0.5f);
        glScaled(0.1f, 0.5f, 0.1f);
        glTranslatef(0.0f, 0.5f, 0.0f);
        glutSolidCube(1.0f);// draw cube (Fan holder)
        glPopMatrix();


        glColor3f(0.7f, 0.7f, 0.7f);
        glutSolidSphere(0.1f, 20, 20);// to draw a ball (Solid sphere)

       
        for (int i = 0; i < 3; ++i) {// draw three Fan blades
            glPushMatrix();
            glRotatef(i * 120.0f, 0.0f, 1.0f, 0.0f);
            point p1 = point(-0.1f,0.0f,-0.4f);
            point p2 = point(0.1f, 0.0f, 0.0f);
            Draw d;
            d.drawQuds(p1, p2, 204, 204, 204);
            glPopMatrix();
        }

        glPopMatrix();
    }

    void drawTable() {
        glPushMatrix();

        glTranslated(-0.5f, -1.4f, 0.0);//to draw the table wood
        glScaled(0.6, 0.6, 0.3);
        glPushMatrix();
        glColor3f(0.5f, 0.3f, 0.1f); 
        glTranslatef(0.0f, 0.69f, 0.0f); 
        glScaled(1.5f, 0.1f, 0.6f); 
        glutSolidCube(1.0f); 
        glPopMatrix();

       
        glColor3f(0.4f, 0.2f, 0.1f); 

       
        glPushMatrix();//back left
        glTranslatef(-0.55f, 0.35f, 0.25f); 
        glScaled(0.1f, 0.6f, 0.1f); 
        glutSolidCube(1.0f);
        glPopMatrix();

        glPushMatrix();//back right
        glTranslatef(0.6f, 0.3f, 0.25f);
        glScaled(0.1f, 0.55f, 0.1f);
        glutSolidCube(1.0f);
        glPopMatrix();

        
        glPushMatrix();//left
        glTranslatef(-0.6f, 0.3f, -0.25f);
        glScaled(0.1f, 0.6f, 0.1f);
        glutSolidCube(1.0f);
        glPopMatrix();

       
        glPushMatrix();//right
        glTranslatef(0.6f, 0.3f, -0.25f);
        glScaled(0.1f, 0.6f, 0.1f);
        glutSolidCube(1.0f);
        glPopMatrix();

        

        glPopMatrix();
    }

    void animateDoors() {// animate door speed of open and close
        if (isOpening) {
            if (leftDoorAngle < 90.0f) leftDoorAngle += 0.5f;
            if (rightDoorAngle < 90.0f) rightDoorAngle += 0.5f;
        }
        else {
            if (leftDoorAngle > 0.0f) leftDoorAngle -= 0.5f;
            if (rightDoorAngle > 0.0f) rightDoorAngle -= 0.5f;
        }
        glutPostRedisplay(); 
    }

    void keyboard(unsigned char key, int x, int y) {// press key to actions
        if (key == 'o') {
            isOpening = true;
        }
        else if (key == 'c') {
            isOpening = false;
        }
        switch (key) {
        case '1':
            drawer1Offset = (drawer1Offset == 0.0f) ? 0.5f : 0.0f;
            break;
        case '2': 
            drawer2Offset = (drawer2Offset == 0.0f) ? 0.5f : 0.0f;
            break;
        case '3': 
            drawer3Offset = (drawer3Offset == 0.0f) ? 0.5f : 0.0f;
            break;
        default:
            break;
        }
        glutPostRedisplay(); 
    }




    
    
    

    void drawCabinetStructure3D() {// draw cabiens
       
        glPushMatrix();
        glTranslated(-0.5f, -0.5f, 0.0f);  
        draw.drawCuboid(0.0f, 0.0f, 0.5f, 1.0f, 2.0f, 0.5f, 0.4f, 0.2f, 0.1f, true);

       
        draw.drawCuboid(-0.45f, -0.4f, 0.5f, 0.4f, 1.6f, 0.05f, 0.5f, 0.25f, 0.1f, true);
        


        glPopMatrix();
    }

    void drawDoors3D() {// draw door
       
        glPushMatrix();//right door
        glTranslatef(0.25f, -0.5f, 0.0f);
        glRotatef(rightDoorAngle, 0.0f, 0.0f, 0.0f);
        glTranslatef(-0.25f, 0.5f, 0.0f);
        draw.drawCuboid(0.0f, -0.5f, 0.5f, 0.5f, 2.0f, 0.05f, 0.5f, 0.25f, 0.1f, true);
        draw.drawCuboid(0.1f, 0.0f, 0.525f, 0.05f, 0.1f, 0.025f, 1.0f, 0.8f, 0.0f);//hand door
        glPopMatrix();

      
        glPushMatrix();//left door
        glTranslatef(-0.25f, -0.5f, 0.0f);
        glRotatef(-leftDoorAngle, 0.0f, 0.0f, 0.0f);
        glTranslatef(0.25f, 0.5f, 0.0f);
        draw.drawCuboid(-0.5f, -0.5f, 0.5f, 0.5f, 2.0f, 0.05f, 0.5f, 0.25f, 0.1f, true);
        draw.drawCuboid(-0.15f, 0.0f, 0.525f, 0.05f, 0.1f, 0.025f, 1.0f, 0.8f, 0.0f);//hand door
        glPopMatrix();
    }

    
    float drawer1Offset = 0.0f; 
    float drawer2Offset = 0.0f; 
    float drawer3Offset = 0.0f; 

    

  
    

    void drawHandle(float x, float y, float z, float radius) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glutSolidSphere(radius, 20, 20);
        glPopMatrix();
    }

    void drawDrawer(float x, float y, float z, float offset, float width, float height, float depth) {
        glColor3f(0.5f, 0.3f, 0.2f); 
        draw.drawCube(x, y, z + offset, width, height, depth);//draw big size drawer

        
        glColor3f(0.7f, 0.5f, 0.4f); 
        draw.drawCube(x, y, z + offset - 0.05f, width * 0.9f, height * 0.8f, depth * 0.2f);//draw small size drawer

        
        glColor3f(0.3f, 0.3f, 0.3f);
        drawHandle(x, y, z + offset - 0.12f, 0.05f);//hand drawer
    }
     void bedside()
     {
        
        
         glScaled(0.5, 0.5, 1);
         glTranslated(1.5, -1.1, 0);
         glRotated(-10, 0, 1, 0);

         glColor3f(0.4f, 0.2f, 0.1f); 
         draw.drawCube(-0.9f, -1.0f, -0.45f, 0.2f, 1.0f, 0.2f);
         draw.drawCube(0.9f, -1.0f, -0.45f, 0.2f, 1.0f, 0.2f);
         draw.drawCube(-0.9f, -1.0f, 0.45f, 0.2f, 1.0f, 0.2f);
         draw.drawCube(0.87f, -1.0f, 0.45f, 0.2f, 1.0f, 0.2f);
         
         glColor3f(0.4f, 0.2f, 0.1f); 
         draw.drawCube(0.0f, 0.0f, 0.0f, 2.0f, 2.0f, 1.0f);

         
         drawDrawer(0.0f, -0.6f, 0.45f, drawer1Offset, 1.8f, 0.4f, 0.2f); //draw numbre 3 drawer up
         drawDrawer(0.0f, 0.0f, 0.45f, drawer2Offset, 1.8f, 0.4f, 0.2f);  //draw numbre 2 drawer mid
         drawDrawer(0.0f, 0.6f, 0.45f, drawer3Offset, 1.8f, 0.4f, 0.2f);  //draw numbre 1 drawer down

      

        
     }
     

  
};


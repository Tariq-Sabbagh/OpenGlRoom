// Neighbours_From_Hell.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<GL/glut.h>
#include<GL/GL.h>
#include<GL/GLU.h>
#include<gl/glut.h>
#include<gl/GLU.h>
#include<gl/GL.h>

#include "point.h"
#include "RoomTemplate.h"
#include "Furniture.h"

Furniture fr;
RoomTemplate temp;
Draw d;
float fanAngle = 0.0f;
using namespace std;
void setupProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.33, 0.1, 10.0); 
    glMatrixMode(GL_MODELVIEW);
}
void drawCeilingFan() {
    glPushMatrix();
    glTranslatef(0.0f, 1.4f, -1.0f);
    glRotatef(fanAngle, 0.0f, 1.0f, 0.0f); 
    fr.drawCeilingFan();

    
}

void update(int value) {//move the CeilingFan
    
    fanAngle += 5.0f;
    if (fanAngle > 360.0f) fanAngle -= 360.0f;


    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}
int DrawGLScene(GLvoid)
{

   

    temp.roof();
    
    temp.Walls();
   
    temp.backWall();
  
    temp.drawcarpit();
    drawCeilingFan();
    fr.drawTable();
    fr.drawCabinetStructure3D();
    fr.drawDoors3D();
    
    d.drawLines();
    fr.bedside();
   



    return 1;

}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glLoadIdentity(); 


    gluLookAt(0.0, 0.0, 5.0,  
        0.0, 0.0, 0.0,  
        0.0, 1.0, 0.0);

    DrawGLScene();
    //glutPostRedisplay();
    glutSwapBuffers();
}
//void keyboardbedside(unsigned char key, int x, int y)
//{
//    fr.keyboardBed(key, x, y);
//}
void animateDoors()
{
    fr.animateDoors();
}
void keyboardDoor(unsigned char key, int x, int y)
{
    fr.keyboard(key, x, y);
}
void init()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   
    glEnable(GL_DEPTH_TEST);

    int width = 1400;
    int hight = 700;
    glutInitWindowSize(width, hight);

    int x = 200;
    int y = 100;
    glutInitWindowPosition(x, y);
    int win = glutCreateWindow("test");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);





    GLclampf Red = 0.0f, Green = 0.0f, Blue = 0.0f, Alpha = 0.0f;
    glClearColor(Red, Green, Blue, Alpha);

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    init();

    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutKeyboardFunc(keyboardDoor);
    glutIdleFunc(animateDoors);
    

    glutMainLoop();
    return 0;
}



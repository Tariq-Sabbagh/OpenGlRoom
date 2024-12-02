#pragma once

#include<iostream>
#include<GL/glut.h>
#include<GL/GL.h>
#include<GL/GLU.h>
#include<gl/glut.h>
#include<gl/GLU.h>
#include<gl/GL.h>
#include "point.h"


using namespace std;
class Draw
{
public:
    void drawLines()
    {
        glPushMatrix();
        glTranslated(-1.6, 0.9, 0);
        glRotated(12, 0, 1, 0);
        glScaled(0.5, 0.4, 1);
        glColor3f(0.5f, 0.25f, 0.0f);
        glBegin(GL_LINE_STRIP);
        glVertex3f(-1, -0.3, 0);
        glVertex3f(-1, 0, 0);
        glVertex3f(-0.5, 0, 0);
        glVertex3f(-0.5, 0.5, 0);
        glVertex3f(-0.3, 0.5, 0);
        glVertex3f(-0.3, 1, 0);
        glVertex3f(0.3, 1, 0);
        glVertex3f(0.3, 0.5, 0);
        glVertex3f(0.5, 0.5, 0);
        glVertex3f(0.5, 0, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(1, -0.3, 0);
        glVertex3f(-1, -0.3, 0);
        glEnd();

        glPopMatrix();
    }
    void drawQuds(point p1, point p2, int R, int G, int B)
    {
        glColor4ub(R, G, B, 1);
        glBegin(GL_QUADS);
        glVertex3f(p1.x, p1.y, p1.z);
        glVertex3f(p2.x, p1.y, p1.z);
        glVertex3f(p2.x, p2.y, p2.z);
        glVertex3f(p1.x, p2.y, p2.z);
        glEnd();
    }
	void drawQudsBlock(point p1,point p2,int R,int G,int B)
	{
        glColor4ub(R, G, B, 1);
		glBegin(GL_QUADS);
		glVertex3f(p1.x, p1.y, 0);
		glVertex3f(p1.x, p2.y, 0);
		glVertex3f(p2.x, p1.y, 0);
		glVertex3f(p2.x, p2.y, 0);
		glEnd();
	}
	void drawLines(point p1,point p2)
	{
        glColor3f(1.0f, 1.0f, 1.0f);
        glLineWidth(1.0f);
		glBegin(GL_LINE_LOOP);
		glVertex3f(p1.x, p1.y, 0);
		glVertex3f(p2.x, p1.y, 0);
		glVertex3f(p2.x, p2.y, 0);
		glVertex3f(p1.x, p2.y, 0);
		glEnd();
	}
    void drawCube(float x, float y, float z, float width, float height, float depth) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glScaled(width, height, depth);
        glutSolidCube(1.0f);
        glPopMatrix();
    }
    void drawCuboid(float x, float y, float z, float width, float height, float depth, float r, float g, float b, bool withBorder = false) {
        glPushMatrix();
        glTranslated(-1.5, -0.8, 0);
        glRotated(12, 0, 1, 0);
        glColor3f(r, g, b);


        glBegin(GL_QUADS);


        glVertex3f(x, y, z);
        glVertex3f(x + width, y, z);
        glVertex3f(x + width, y + height, z);
        glVertex3f(x, y + height, z);


        glVertex3f(x, y, z - depth);
        glVertex3f(x + width, y, z - depth);
        glVertex3f(x + width, y + height, z - depth);
        glVertex3f(x, y + height, z - depth);


        glVertex3f(x + width, y, z);
        glVertex3f(x + width, y, z - depth);
        glVertex3f(x + width, y + height, z - depth);
        glVertex3f(x + width, y + height, z);

        glVertex3f(x, y, z);
        glVertex3f(x, y, z - depth);
        glVertex3f(x, y + height, z - depth);
        glVertex3f(x, y + height, z);


        glVertex3f(x, y + height, z);
        glVertex3f(x + width, y + height, z);
        glVertex3f(x + width, y + height, z - depth);
        glVertex3f(x, y + height, z - depth);


        glVertex3f(x, y, z);
        glVertex3f(x + width, y, z);
        glVertex3f(x + width, y, z - depth);
        glVertex3f(x, y, z - depth);

        glEnd();


        glColor3f(0.3f, 0.15f, 0.075f);
        glBegin(GL_LINE_LOOP);


        glVertex3f(x, y, z);
        glVertex3f(x + width, y, z);
        glVertex3f(x + width, y + height, z);
        glVertex3f(x, y + height, z);


        glVertex3f(x, y, z - depth);
        glVertex3f(x + width, y, z - depth);
        glVertex3f(x + width, y + height, z - depth);
        glVertex3f(x, y + height, z - depth);

        glEnd();
        glPopMatrix();
    }

    void drawBlocks(float x1, float y1, float x2, float y2, int rows, int cols) {//draw block block in roof
       
        float blockWidth = (x2 - x1) / cols;
        float blockHeight = (y1 - y2) / rows;

        int R = 180, G = 41, B = 24; 

       
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
             
                float x_start = x1 + j * blockWidth;  
                float y_start = y1 - i * blockHeight; 
                float x_end = x_start + blockWidth;   
                float y_end = y_start - blockHeight;  

                if (i % 2 != 0 && j == cols - 1) continue; 
                if (i % 2 != 0) {
                    x_start += blockWidth / 2;
                    x_end += blockWidth / 2;
                }
                point p1 = point(x_start, y_start, 0);
                point p2 = point(x_end, y_end, 0);
                drawQudsBlock(p1, p2, R, G, B);  

                
                drawLines(p1, p2);
            }
        }
    }


};


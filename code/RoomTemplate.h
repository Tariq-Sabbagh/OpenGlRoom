#pragma once
#include<iostream>
#include<GL/glut.h>
#include<GL/GL.h>
#include<GL/GLU.h>
#include<gl/glut.h>
#include<gl/GLU.h>
#include<gl/GL.h>
#include <cstdlib> 
#include <ctime>
#include "point.h"
#include "Draw.h"

using namespace std;

class RoomTemplate //walls and roof and script
{
public:
Draw draw;
	void roof() //draw roof
	{
		//glTranslatef(0.0f, 0.0f, -0.15f);
		point p1 = point(-2.1f, 2.1f, 0);   
		point p2 = point(2.1f, 1.54f, 0);   
		int row = 20, col = 20;
	
		draw.drawBlocks(p1.x, p1.y, p2.x, p2.y, row, col);
		//draw.drawQuds(p1, p2, 255, 255, 255);

	}
	void Walls()
	{
		point p1 = point(1.8f, 1.54f, 0);
		point p2 = point(2.5f, -2.5f, 0);
		int R = 255, G = 198, B = 192;
		glPushMatrix();

	
		//glRotated(5.0, 1.0, 1.0, -1.0); 
		draw.drawQuds(p1, p2, R, G, B); 
		glPopMatrix();


	}
	void backWall()
	{
		point p1 = point(-2.1f, 1.54f, 0.0f);
		point p2 = point(1.8f, -1.2f, 0.0f);
		int R = 255, G = 227, B = 224;

		glPushMatrix();

		//glTranslated(0, 0, 0.5);
		//glRotated(5.0, 1.0, 1.0, 0.0);
		draw.drawQuds(p1, p2, R, G, B);
		glPopMatrix();
	}
	void drawcarpit()
	{
		point p1 = point(-2.1f, -1.2f, 0.0f);
		point p2 = point(1.8f, -2.1, 0.0f);
		int R = 16, G = 11, B = 145;
		glPushMatrix();
		//glRotated(5.0, 1.0, 1.0, 0.0);
		draw.drawQuds(p1, p2, R, G, B);
		glPopMatrix();
	}

   


    


};


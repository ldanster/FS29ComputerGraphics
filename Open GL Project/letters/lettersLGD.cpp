////////////////////////////////////////////////////////////////
//
// lettersLGD - Code to produce the letters LGD
// 
// Author: Charl Cilliers
// Date:   23-03-2012
//
////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include "3DCurve.h"

void drawL(){
	glBegin(GL_QUADS);
        glColor3f(0, 1, 0);
		glVertex3f(0.5,0.5,1);
		glVertex3f(0.5,3,1);
		glVertex3f(0,3,1);
		glVertex3f(0,0.5,1);
	glEnd();

	glBegin(GL_QUADS);
        glColor3f(0, 1, 0);
		glVertex3f(0.5,0.5,-1);
		glVertex3f(0.5,3,-1);
		glVertex3f(0,3,-1);
		glVertex3f(0,0.5,-1);
	glEnd();

	// bottom piece
	glBegin(GL_QUADS);
		glColor3f(1, 0, 0);
		glVertex3f(0,0,-1);
		glVertex3f(0,0,1);
		glVertex3f(2,0,1);
		glVertex3f(2,0,-1);
	glEnd();


	// back pieces
	// back of long
	glBegin(GL_QUADS);
		glColor3f(1,0.2,1);
		glVertex3f(0,0,-1);
		glVertex3f(0,0,1);
		glVertex3f(0,3,1);
		glVertex3f(0,3,-1);
	glEnd();

	//back of long front
	glBegin(GL_QUADS);
		glColor3f(1,0.2,0.6);
		glVertex3f(0.5,0.5,1);
		glVertex3f(0.5,0.5,-1);
		glVertex3f(0.5,3,-1);
		glVertex3f(0.5,3,1);
	glEnd();

	//back of short front
	glBegin(GL_QUADS);
		glColor3f(.2,0.2,.5);
		glVertex3f(2,0,1);
		glVertex3f(2,0,-1);
		glVertex3f(2,0.5,-1);
		glVertex3f(2,0.5,1);
	glEnd();

	// top pieces
	// top point top
	glBegin(GL_QUADS);
		glColor3f(1,0.6,1);
		glVertex3f(0,3,-1);
		glVertex3f(0,3,1);
		glVertex3f(0.5,3,1);
		glVertex3f(0.5,3,-1);
	glEnd();

	// bottom point top
	glBegin(GL_QUADS);
		glColor3f(1,0.6,1);
		glVertex3f(0,0.5,-1);
		glVertex3f(0,0.5,1);
		glVertex3f(2,0.5,1);
		glVertex3f(2,0.5,-1);
	glEnd();


	// back bottom piece of L
	glBegin(GL_QUADS);
        glColor3f(0, 0, -1);
		glVertex3f(0,0,-1);
		glVertex3f(2,0,-1);
		glVertex3f(2,0.5,-1);
		glVertex3f(0,0.5,-1);
	glEnd();

	// front bottom piece of L
	glBegin(GL_QUADS);
        glColor3f(0, 0, 1);
		glVertex3f(0,0,1);
		glVertex3f(2,0,1);
		glVertex3f(2,0.5,1);
		glVertex3f(0,0.5,1);
	glEnd();


}

void drawG(){
	glPushMatrix();
	glRotatef(45,0,0,1);
	draw3Dcurve  (2,          //depth  
		1,				//inner radius
		1.5,			//outer radius
		0,				//start angle
		255,			//stop angle
		1.0);			//anular increments
	glPopMatrix();
	
	//Front Pieces
	// Front Upper Piece
	glBegin(GL_QUADS);
        glColor3f(1, 0, 0);
		glVertex3f(0.5,0,1);
		glVertex3f(0.5,-1.5,1);
		glVertex3f(1,-1.5,1);
		glVertex3f(1,0,1);

	glEnd();

	glBegin(GL_QUADS);
        glColor3f(1, 0, 0);
		glVertex3f(0.5,0,-1);
		glVertex3f(0.5,-1.5,-1);
		glVertex3f(1,-1.5,-1);
		glVertex3f(1,0,-1);

	glEnd();

	// Back Pieces
	// Back of Upper Piece 
	glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glVertex3f(0.5,-1.5,-1);
		glVertex3f(0.5,-1.5,1);
		glVertex3f(0.5,0,1);
		glVertex3f(0.5,0,-1);
	glEnd();

	// Front Back of Upper Piece
	glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glVertex3f(1,-1.5,1);
		glVertex3f(1,-1.5,-1);
		glVertex3f(1,0,-1);
		glVertex3f(1,0,1);
	glEnd();

	// Top Pieces
	// Top Of Upper Piece
	glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glVertex3f(1,0,1);
		glVertex3f(1,0,-1);
		glVertex3f(0.5,0,-1);
		glVertex3f(0.5,0,1);
	glEnd();

	// Bottom of Upper Piece
	glBegin(GL_QUADS);
		glColor3f(1,-1.5,0);
		glVertex3f(1,-1.5,1);
		glVertex3f(1,-1.5,-1);
		glVertex3f(0.5,-1.5,-1);
		glVertex3f(0.5,-1.5,1);
	glEnd();

}

void drawD(){
}
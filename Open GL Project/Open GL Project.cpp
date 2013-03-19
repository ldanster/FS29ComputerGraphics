// Open GL Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL/glut.h>
#include "3DCurve.h"

//======================================================
// GLOBAL VARIABLES & FUNCTIONS
//======================================================
float pitch = 0.0f;
float yaw = 0.0f;
float neckAngle = 70.0;
float headAngle = -80.0;
bool increaseNeckAngle = true;
bool increaseHeadAngle = true;
float zoomFactor = 10.0;
float pitch0, yaw0;
bool MousePressed;
int mouseX0, mouseY0;
bool rotating=false;
bool moving=false;

void drawSomething(){

	//glTranslatef(1.5, 0.5, 0);
	//glRotatef(180, 0, 0, 1);
	draw3Dcurve  (1.0,          //depth  
				1,          //inner radius
				1.5,          //outer radius
				0,          //start angle
				180,  //stop angle
				5.0);         //anular increments

}

void executeViewControl (float y, float p){
	glRotatef(y, 0.0f, 1.0f, 0.0f); //yaw about y-axis
    glRotatef(p, 1.0f, 0.0f, 0.0f); //pitch about x-axis 
}

void displayCallBack() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	executeViewControl (yaw, pitch);
	
	drawSomething();
	glutSwapBuffers();
}

void reshapeCallBack(int w, int h) 
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	if (w == 0 || h == 0) return;
    if (w <= h) glOrtho(-zoomFactor, zoomFactor, -zoomFactor * (GLfloat) h / (GLfloat) w, zoomFactor * (GLfloat) h / (GLfloat) w, -20.0, 20.0);
    else        glOrtho(-zoomFactor* (GLfloat) w / (GLfloat) h, zoomFactor * (GLfloat) w / (GLfloat) h, -zoomFactor, zoomFactor, -20.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

int _tmain(int argc, char* argv[])
{
   // Allow cmd line arguments to be passed to the glut
	glutInit(&argc, argv);

	// Create and name window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Need both double buffering and z buffer
    glutInitWindowSize(700, 700);
    glutCreateWindow("Computer Graphics");

	// Add Display & Mouse CallBacks
	glutReshapeFunc(reshapeCallBack);
	glutDisplayFunc(displayCallBack);
	//glutIdleFunc(NULL); // Starts the Idle Function as having no routine attached to it. This is modified in rotateView()
	//glutMouseFunc(mouseClickCallBack);
	//glutMotionFunc(mouseMotionCallBack);
	//glutKeyboardFunc(keyboardCallBack);


	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */

	// Print Application Usage
	printf("Program Controls:\n");
	printf("Left Mouse Button & Drag - Changes the View.\n");
	printf("Key \"b\" - Back Fill.\n");
	printf("Key \"f\" - Front Fill.\n");
	printf("Key \"l\" - Wire Frame/Line Fill.\n");
	printf("Key \"i\" - Increment Sections of Curve.\n");
	printf("Key \"d\" - Decrement Sections of Curve.\n");
	printf("Key \"r\" - Automated Rotation.\n");
	printf("Key \"R\" - Reset the View.\n");

	glutMainLoop();

	return 0;
}


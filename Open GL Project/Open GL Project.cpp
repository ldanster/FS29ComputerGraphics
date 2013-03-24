// Open GL Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL/glut.h>
#include "3DCurve.h"
#include "lettersLGD.h"
#include "3DPipe.h"


//======================================================
float pitch = 0.0f;
float yaw = 0.0f;
float zoomFactor = 10.0;
float pitch0, yaw0;
bool MousePressed;
int mouseX0, mouseY0;
bool rotating=false;
bool moving=false;

void drawFloor(){
	glBegin(GL_QUADS);
		glColor3f(0,0,0);
		glVertex3f(-20000,-2,20000);
		glVertex3f(20000,-2,20000);
		glVertex3f(20000,-2,-20000);
		glVertex3f(-20000,-2,-20000);
	glEnd();
}

void drawSomething(){
	//glTranslatef(-3,0,0);
	//drawLShape();
	//glTranslatef(3,0,0);
	//drawHShape();
	//glTranslatef(3,0,0);
	//drawGShape();
	//drawFloor();



	for(int i = 90; i > -100 ; i -= 10){
		glPushMatrix();
			glRotatef(90,0,0,1);
			glRotatef(i,0,1,0);
			glTranslatef(2,0,0);
			glScalef(1,3,0.1);
			drawDShape();
		glPopMatrix();
	}

	glPushMatrix();
		glTranslatef(-3,-1,1);
		glScalef(1,1,0.3);
		drawLShape();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-3,-1,-1);
		glScalef(1,1,0.3);
		drawLShape();
	glPopMatrix();

	//front arms

	glPushMatrix();
		glTranslatef(3,-0.5,-1);
		glScalef(0.1,0.8,0.3);
		drawLShape();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(3,-0.5,1);
		glScalef(0.1,0.8,0.3);
		drawLShape();
	glPopMatrix();


}

void incrementYaw(){
	//pitch=pitch+.25;
	yaw=yaw+.25;
}

void idleCallBack (){
	if(rotating) incrementYaw();
    glutPostRedisplay();
}

void rotateView(bool r){
	rotating = r;
	if (moving | rotating) glutIdleFunc(idleCallBack); else glutIdleFunc(NULL);
}


void keyboardCallBack(unsigned char key, int x, int y) {
	printf("Keyboard call back: key=%c, x=%d, y=%d\n", key, x, y);
	switch(key)
	{
	case 'r': 
		rotating= !rotating;
		rotateView(rotating);
	break;
	case 'R':
        //resetView();
	break;
	case 'm': 
		//moving= !moving;
		//moveView(moving);
	break;
	case 'z': 
		if (zoomFactor > 1) zoomFactor = zoomFactor - 1;
	break;
	case 'Z':
        zoomFactor = zoomFactor + 1;
	break;
	default:
		printf("Press b - back fill; f - front fill; l - line; i - increment; or d - decrement; r - rotate; R - reset view\n");
	}

	glutPostRedisplay();
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

int main(int argc, char* argv[])
{
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
	glutKeyboardFunc(keyboardCallBack);


	glClearColor(1, 1.0, 1.0, 1.0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_DEPTH_TEST);

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


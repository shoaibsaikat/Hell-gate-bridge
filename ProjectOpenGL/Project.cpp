/*--------------------------------------------------------------------
Name: Mina Shoaib Rahman Saikat
Roll: 0705096
Sec : B
CSE, BUET
---------------------------------------------------------------------*/
/*--------------------------------------------------------------------
Controls:
Left, right, up, down arrow for camera movement
x, X, y, Y, z, Z for spaceship movement
' '(space) for showing or hiding structure
---------------------------------------------------------------------*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Position.h"
#include "Graphics Engine.h"
#include "Camera.h"
#include "texture.h"

using namespace std;

#define BLACK		0, 0, 0
#define DISPHEIGHT	1152
#define DISPWIDTH	864
#define OFFSET		2
#define CAMVAL		1
#define CAMROT		0.05

bool isWire = true, showAxis = false;
float red, green, blue, scale;
Position ship = Position();

void resetView() {
	camReset();
	ship.reset();
	red = 1.0, green = 1.0, blue = 1.0, scale = 1;
}

void display() {
	glClearColor(BLACK, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Problem: Two lines below have no effect why?
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(posX, posY, posZ,		tarX, tarY, tarZ,	upX, upY, upZ);

	if (!isWire) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if(!showAxis) drawAxis();

	setLight0(-2000, -2000, -500, 0,	red, green, blue);
	setLight1(2000, 2000, 500, 0,		red, green, blue);
	setLight2(100, -20, 100, 0,		red, green, blue);
	setLight3(-100, -20, -100, 0,		red, green, blue);
	///setLight1(2000, 2000, 500, 0,		red, green, blue);

	ship.translateObject();
	ship.rollObject();
	ship.pitchObject();
	ship.yawObject();

	/*
		TO DO:

		1. Applying texture
		2. Applying river and trees

		NB: 
			1. See the command prompt when code is executing for movement and other commands
			2. Engine.h contains all drawing objects
			3. Vector.h contains vector and normal calculations
			4. Camera.h contains movements of the camera
			5. Position.h contains movements of bridge itself
	*/
		
	glEnable(GL_NORMALIZE);

	glPushMatrix();
	glTranslatef(0, -50, 0);
	glScalef(scale, scale, scale);
		fullBridge();
	glPopMatrix();

	glDisable(GL_NORMALIZE);
	

	glutSwapBuffers();
}

void animate() {
	glutPostRedisplay();
}

void init(float h, float w) {
	red =0.85, green = 0.85, blue = 0.85, scale = 1;

	glMatrixMode(GL_PROJECTION);
	loadImages();
	GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);

	gluPerspective(75,	h/w,	0.1,	10000.0);
}

void keyboard(unsigned char key, int x, int y) {
	setTarget(ship.getX(), ship.getY(), ship.getZ());

	switch (key) {
		case ' ':
			isWire = !isWire;
			break;

		//axis movement
		case 'x':
			ship.xInc(OFFSET);
			break;
		case 'X':
			ship.xDec(OFFSET);
			break;
		case 'y':
			ship.yInc(OFFSET);
			break;
		case 'Y':
			ship.yDec(OFFSET);
			break;
		case 'z':
			ship.zInc(OFFSET);
			break;
		case 'Z':
			ship.zDec(OFFSET);
			break;

		//ship roll, pitch, yaw
		case 'w':
			ship.xAngleInc(OFFSET);
			break;
		case 's':
			ship.xAngleDec(OFFSET);
			break;
		case 'a':
			ship.yAngleInc(OFFSET);
			break;
		case 'd':
			ship.yAngleDec(OFFSET);
			break;
		case 'q':
			ship.zAngleInc(OFFSET);
			break;
		case 'e':
			ship.zAngleDec(OFFSET);
			break;

		//camera movement
		case '1':
			posX += CAMVAL;
			break;
		case '2':
			posX -= CAMVAL;
			break;
		case '4':
			posY += CAMVAL;
			break;
		case '5':
			posY -= CAMVAL;
			break;
		case '7':
			posZ += CAMVAL;
			break;
		case '8':
			posZ -= CAMVAL;
			break;

		//reset
		case 'o':
			resetView();
			break;
		//show or hide axis
		case 'p':
			showAxis = !showAxis;
			break;

		//day, night effect
		case '+':
			if(red < 1.0) {
				red += 0.01;
				green += 0.01;
				blue += 0.01;
			}
			break;
		case '-':
			if(red > -0.3) {
				red -= 0.01;
				green -= 0.01;
				blue -= 0.01;
			}
			break;

		case '3':
			scale += 0.1;
			break;

		case '.':
			if(scale > 0.1) {
				scale -= 0.1;
			}
			break;

		default:
			break;
	}
}

void specialKeyListener(int key, int x, int y) {
	setTarget(ship.getX(), ship.getY(), ship.getZ());

	switch(key) {
		case GLUT_KEY_DOWN:
			checkFlag(rotY);
			angY -= CAMROT;
			break;
		case GLUT_KEY_UP:
			checkFlag(rotY);
			angY += CAMROT;
			break;

		case GLUT_KEY_RIGHT:
			checkFlag(rotX);
			angX += CAMROT;
			break;
		case GLUT_KEY_LEFT:
			checkFlag(rotX);
			angX -= CAMROT;
			break;

		case GLUT_KEY_PAGE_UP:
			checkFlag(rotZ);
			angZ += CAMROT;
			break;
		case GLUT_KEY_PAGE_DOWN:
			checkFlag(rotZ);
			angZ -= CAMROT;
			break;

		default:
			break;
	}
}

void printInputs() {
	cout << "Object Movements:" << endl;
	cout << "x, X, y, Y, z, Z" << endl << endl;
	cout << "Object Rotations:" << endl;
	cout << "Roll: a, d; Pitch: w, s; Yaw: q, e" << endl << endl;
	cout << "Camera Movements:" << endl;
	cout << "1, 2, 4, 5, 7, 8" << endl << endl;
	cout << "Camera Rotations:" << endl;
	cout << "Roll: up, down arrow; Pitch: left, right arrow; Yaw: page up, down" << endl << endl;
	cout << "Light:" << endl;
	cout << "+, -" << endl << endl;
	cout << "Light:" << endl;
	cout << "Press 3 for scale up and . for down" << endl << endl;
	cout << "Press space to show wires" << endl;
	cout << "Press p to hide axis" << endl;
	cout << "Press o hide to reset" << endl;
}

int main(int argc, char **argv) {
	glutInit(&argc,argv);
	glutInitWindowSize(DISPHEIGHT, DISPWIDTH);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Hell gate bridge");
	printInputs();

	init(DISPHEIGHT, DISPWIDTH);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutIdleFunc(animate);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyListener);
	glutMainLoop();

	return 0;
}

#include <stdio.h>     // - Just for some ASCII messages
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>

#include <GL/glut.h>   // - An interface and windows management library
#include "visuals.h"   // Header file for our OpenGL functions

# define M_PI           3.14159265358979323846
model md;

int lives=3;	//Number of lives

static float tx = 0.0;//Position of racket, x axis
static float ty = 0.0;//Position of racket, y axis
static float tz = 0.0;//Position of racket, z axis
static float vx = 0.0;//Speed of racket, x axis
static float vy = 0.0;//Speed of racket, y axis
static float vz = 0.0;//Speed of racket, z axis
static float px = 0.0;//Position of sphere, x axis
static float py = 0.0;//Position of sphere, y axis
static float pz = -30.0;//Position of sphere, z axis
float closeball = 10.0;//Colour of ball (closest distance)
float middleball = 0.0;//Colour of ball (middle distance)
float farball = 0.0;//Colour of ball (furthest distance)
static float sx = 17.0;//Dimensions of bricks, x axis
static float sy = 17.0;//Dimensions of bricks, y axis
static float sz = 3.0;//Dimensions of bricks, z axis
static float r = 5; //Sphere radiant
int flag[49] = { 0 }; //Collision detection flag variables
float angle[49] = { 0 }; //Rotation detection flag
float deep[49] = { 0 }; //Drop detection flag

static float rsx = 25.0;//Dimensions of bricks, x axis
static float rsy = 25.0;//Dimensions of bricks, y axis
static float rsz = 3.0;//Dimensions of bricks, z axis


static GLfloat camx = 1; //Camera postion, x axis
static GLfloat camy = 1; //Camera postion, y axis
static GLfloat camz = -5;//Camera postion, z axis

static GLfloat lookx = 0; //Lookat vector, x axis
static GLfloat looky= 0;  //Lookat vector, y axis
static GLfloat lookz = 0; //Lookat vector, z axis



int c = 0; //Number of bricks hit
int mode = 0;	//Play mode (automatic (A.I.) or manual)


static bool animate = false;	//Begin animate


using namespace std;

void Render()
{



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_CULL_FACE);
	glLoadIdentity();
	gluLookAt(lookx, looky , lookz, camx, camy, camz, 0, 1, 0);	//Camera 

	//Code producing the bricks
	glPushMatrix();
	if (flag[1] != 0)
	{
		glTranslatef(-30, 30 - deep[1], -100);
		glRotatef(angle[1], 1, 0, 0);
	}
	else
		glTranslatef(-30, 30, -100);
	glColor4f(3.0, 0.0, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[2] != 0)
	{
		glTranslatef(-10, 30 - deep[2], -100);
		glRotatef(angle[2], 1, 0, 0);
	}
	else
		glTranslatef(-10, 30, -100);

	glColor4f(3.0, 0.5, 0.0, 3);

	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	if (flag[3] != 0)
	{
		glTranslatef(10, 30 - deep[3], -100);
		glRotatef(angle[3], 1, 0, 0);
	}
	else
		glTranslatef(10, 30, -100);
	glColor4f(3.0, 1.0, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[4] != 0)
	{
		glTranslatef(30, 30 - deep[4], -100);
		glRotatef(angle[4], 1, 0, 0);
	}
	else
		glTranslatef(30, 30, -100);
	glColor4f(3.0, 1.5, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[5] != 0)
	{
		glTranslatef(-30, 10 - deep[5], -100);
		glRotatef(angle[5], 1, 0, 0);
	}
	else
		glTranslatef(-30, 10, -100);
	glColor4f(3.0, 2.0, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[6] != 0)
	{
		glTranslatef(-10, 10 - deep[6], -100);
		glRotatef(angle[6], 1, 0, 0);
	}
	else
		glTranslatef(-10, 10, -100);
	glColor4f(3.0, 2.5, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[7] != 0)
	{
		glTranslatef(10, 10 - deep[7], -100);
		glRotatef(angle[7], 1, 0, 0);
	}
	else
		glTranslatef(10, 10, -100);
	glColor4f(3.0, 3.0, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[8] != 0)
	{
		glTranslatef(30, 10 - deep[8], -100);
		glRotatef(angle[8], 1, 0, 0);
	}
	else
		glTranslatef(30, 10, -100);
	glColor4f(3.0, 3.5, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[9] != 0)
	{
		glTranslatef(-30, -10 - deep[9], -100);
		glRotatef(angle[9], 1, 0, 0);
	}
	else
		glTranslatef(-30, -10, -100);
	glColor4f(3.0, 3.5, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[10] != 0)
	{
		glTranslatef(-10, -10 - deep[10], -100);
		glRotatef(angle[10], 1, 0, 0);
	}
	else
		glTranslatef(-10, -10, -100);
	glColor4f(3.0, 3.0, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	if (flag[11] != 0)
	{
		glTranslatef(10, -10 - deep[11], -100);
		glRotatef(angle[11], 1, 0, 0);
	}
	else
		glTranslatef(10, -10, -100);
	glColor4f(3.0, 2.5, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	if (flag[12] != 0)
	{
		glTranslatef(30, -10 - deep[12], -100);
		glRotatef(angle[12], 1, 0, 0);
	}
	else
		glTranslatef(30, -10, -100);
	glColor4f(3.0, 2.0, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[13] != 0)
	{
		glTranslatef(-30, -30 - deep[13], -100);
		glRotatef(angle[13], 1, 0, 0);
	}
	else
		glTranslatef(-30, -30, -100);
	glColor4f(3.0, 1.5, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[14] != 0)
	{
		glTranslatef(-10, -30 - deep[14], -100);
		glRotatef(angle[14], 1, 0, 0);
	}
	else
		glTranslatef(-10, -30, -100);
	glColor4f(3.0, 1.0, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	if (flag[15] != 0)
	{
		glTranslatef(10, -30 - deep[15], -100);
		glRotatef(angle[15], 1, 0, 0);
	}
	else
		glTranslatef(10, -30, -100);
	glColor4f(3.0, 0.5, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	if (flag[16] != 0)
	{
		glTranslatef(30, -30 - deep[16], -100);
		glRotatef(angle[16], 1, 0, 0);
	}
	else
		glTranslatef(30, -30, -100);
	glColor4f(3.0, 0.0, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	//change of brick layer
	////////////////////////////////////////////////////////////////////////////////////




	glPushMatrix();
	if (flag[17] != 0)
	{
		glTranslatef(-30, 30 - deep[17], -110);
		glRotatef(angle[17], 1, 0, 0);
	}
	else
		glTranslatef(-30, 30, -110);
	glColor4f(0.0, 3.0, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[18] != 0)
	{
		glTranslatef(-10, 30 - deep[18], -110);
		glRotatef(angle[18], 1, 0, 0);
	}
	else
		glTranslatef(-10, 30, -110);
	glColor4f(0.0, 3.0, 0.5, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[19] != 0)
	{
		glTranslatef(10, 30 - deep[19], -110);
		glRotatef(angle[19], 1, 0, 0);
	}
	else
		glTranslatef(10, 30, -110);
	glColor4f(0.0, 3.0, 1.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[20] != 0)
	{
		glTranslatef(30, 30 - deep[20], -110);
		glRotatef(angle[20], 1, 0, 0);
	}
	else
		glTranslatef(30, 30, -110);
	glColor4f(0.0, 3.0, 1.5, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[21] != 0)
	{
		glTranslatef(-30, 10 - deep[21], -110);
		glRotatef(angle[21], 1, 0, 0);
	}
	else
		glTranslatef(-30, 10, -110);
	glColor4f(0.0, 3.0, 2.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[22] != 0)
	{
		glTranslatef(-10, 10 - deep[22], -110);
		glRotatef(angle[22], 1, 0, 0);
	}
	else
		glTranslatef(-10, 10, -110);
	glColor4f(0.0, 3.0, 2.5, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[23] != 0)
	{
		glTranslatef(10, 10 - deep[23], -110);
		glRotatef(angle[23], 1, 0, 0);
	}
	else
		glTranslatef(10, 10, -110);
	glColor4f(0.0, 3.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[24] != 0)
	{
		glTranslatef(30, 10 - deep[24], -110);
		glRotatef(angle[24], 1, 0, 0);
	}
	else
		glTranslatef(30, 10, -110);
	glColor4f(0.0, 3.0, 3.5, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[25] != 0)
	{
		glTranslatef(-30, -10 - deep[25], -110);
		glRotatef(angle[25], 1, 0, 0);
	}
	else
		glTranslatef(-30, -10, -110);
	glColor4f(0.0, 3.0, 3.5, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[26] != 0)
	{
		glTranslatef(-10, -10 - deep[26], -110);
		glRotatef(angle[26], 1, 0, 0);
	}
	else
		glTranslatef(-10, -10, -110);
	glColor4f(0.0, 3.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	if (flag[27] != 0)
	{
		glTranslatef(10, -10 - deep[27], -110);
		glRotatef(angle[27], 1, 0, 0);
	}
	else
		glTranslatef(10, -10, -110);
	glColor4f(0.0, 3.0, 2.5, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	if (flag[28] != 0)
	{
		glTranslatef(30, -10 - deep[28], -110);
		glRotatef(angle[28], 1, 0, 0);
	}
	else
		glTranslatef(30, -10, -110);
	glColor4f(0.0, 3.0, 2.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[29] != 0)
	{
		glTranslatef(-30, -30 - deep[29], -110);
		glRotatef(angle[29], 1, 0, 0);
	}
	else
		glTranslatef(-30, -30, -110);
	glColor4f(0.0, 3.0, 1.5, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[30] != 0)
	{
		glTranslatef(-10, -30 - deep[30], -110);
		glRotatef(angle[30], 1, 0, 0);
	}
	else
		glTranslatef(-10, -30, -110);
	glColor4f(0.0, 3.0, 1.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	if (flag[31] != 0)
	{
		glTranslatef(10, -30 - deep[31], -110);
		glRotatef(angle[31], 1, 0, 0);
	}
	else
		glTranslatef(10, -30, -110);
	glColor4f(0.0, 3.0, 0.5, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	if (flag[32] != 0)
	{
		glTranslatef(30, -30 - deep[32], -110);
		glRotatef(angle[32], 1, 0, 0);
	}
	else
		glTranslatef(30, -30, -110);
	glColor4f(0.0, 3.0, 0.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	//change of brick layer
	/////////////////////////////////////////////


	glPushMatrix();
	if (flag[33] != 0)
	{
		glTranslatef(-30, 30 - deep[33], -120);
		glRotatef(angle[33], 1, 0, 0);
	}
	else
		glTranslatef(-30, 30, -120);
	glColor4f(0.0, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[34] != 0)
	{
		glTranslatef(-10, 30 - deep[34], -120);
		glRotatef(angle[34], 1, 0, 0);
	}
	else
		glTranslatef(-10, 30, -120);
	glColor4f(0.5, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[35] != 0)
	{
		glTranslatef(10, 30 - deep[35], -120);
		glRotatef(angle[35], 1, 0, 0);
	}
	else
		glTranslatef(10, 30, -120);
	glColor4f(1.0, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[36] != 0)
	{
		glTranslatef(30, 30 - deep[36], -120);
		glRotatef(angle[36], 1, 0, 0);
	}
	else
		glTranslatef(30, 30, -120);
	glColor4f(1.5, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[37] != 0)
	{
		glTranslatef(-30, 10 - deep[37], -120);
		glRotatef(angle[37], 1, 0, 0);
	}
	else
		glTranslatef(-30, 10, -120);
	glColor4f(2.0, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[38] != 0)
	{
		glTranslatef(-10, 10 - deep[38], -120);
		glRotatef(angle[38], 1, 0, 0);
	}
	else
		glTranslatef(-10, 10, -120);
	glColor4f(2.5, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[39] != 0)
	{
		glTranslatef(10, 10 - deep[39], -120);
		glRotatef(angle[39], 1, 0, 0);
	}
	else
		glTranslatef(10, 10, -120);
	glColor4f(3.0, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[40] != 0)
	{
		glTranslatef(30, 10 - deep[40], -120);
		glRotatef(angle[40], 1, 0, 0);
	}
	else
		glTranslatef(30, 10, -120);
	glColor4f(3.5, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[41] != 0)
	{
		glTranslatef(-30, -10 - deep[41], -120);
		glRotatef(angle[41], 1, 0, 0);
	}
	else
		glTranslatef(-30, -10, -120);
	glColor4f(3.5, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	if (flag[42] != 0)
	{
		glTranslatef(-10, -10 - deep[42], -120);
		glRotatef(angle[42], 1, 0, 0);
	}
	else
		glTranslatef(-10, -10, -120);
	glColor4f(3.0, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	if (flag[43] != 0)
	{
		glTranslatef(10, -10 - deep[43], -120);
		glRotatef(angle[43], 1, 0, 0);
	}
	else
		glTranslatef(10, -10, -120);
	glColor4f(2.5, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	if (flag[44] != 0)
	{
		glTranslatef(30, -10 - deep[44], -120);
		glRotatef(angle[44], 1, 0, 0);
	}
	else
		glTranslatef(30, -10, -120);
	glColor4f(2.0, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[45] != 0)
	{
		glTranslatef(-30, -30 - deep[45], -120);
		glRotatef(angle[45], 1, 0, 0);
	}
	else
		glTranslatef(-30, -30, -120);
	glColor4f(1.5, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[46] != 0)
	{
		glTranslatef(-10, -30 - deep[46], -120);
		glRotatef(angle[46], 1, 0, 0);
	}
	else
		glTranslatef(-10, -30, -120);
	glColor4f(1.0, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	if (flag[47] != 0)
	{
		glTranslatef(10, -30 - deep[47], -120);
		glRotatef(angle[47], 1, 0, 0);
	}
	else
		glTranslatef(10, -30, -120);
	glColor4f(0.5, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();



	glPushMatrix();
	if (flag[48] != 0)
	{
		glTranslatef(30, -30 - deep[48], -120);
		glRotatef(angle[48], 1, 0, 0);
	}
	else
		glTranslatef(30, -30, -120);
	glColor4f(0.0, 0.0, 3.0, 3);
	glScalef(sx, sy, sz);
	glutSolidCube(1.0);
	glPopMatrix();




	///
	//Sphere producing code 
	glPushMatrix();
	glColor3f(closeball, middleball, farball); //allagi xrwmatos mpalas analoga tin apostasi
	glTranslatef(px, py, pz);
	glutSolidSphere(r, 20.0, 20.0);
	glPopMatrix();

	///
	//Racket producing code 
	glPushMatrix();
	glColor4f(3, 8, 4, 0.80);
	glTranslatef(tx, ty, 0.0);
	glScalef(rsx, rsy, rsz);
	glutSolidCube(1.0);
	glPopMatrix();

	///
	//Creating the box that contains the game components
	glColor4f(0.5, 0.0, 0.9, 0.30);// Set drawing colour
	DisplayModel(md);

	if (c == 48)	//Checking if all the bricks are hit
	{
		printf("WELL DONE !!!\n");
	}

	glutSwapBuffers();
}









void Resize(int w, int h)	//Changing window dimensions
{
	if (h == 0) h = 1;


	glViewport(0, 0, w, h);



	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();



	glOrtho(-50.0f, 50.0f, -50.0f, 50.0f, -100.0f, -100.0f);
	float aspect = (float)w / (float)h;
	gluPerspective(60.0, aspect, 1.0, 500.0);


}


int i;

int oldTime;

bool flookz=true;	

void Idle()
{

	if (flookz == true)
	{
		if (lookz < 100)
			lookz +=0.5;
		if (lookz == 100)
			flookz = false;
		
	}


	if (animate)
	{
		

		float timeDiff = 0.1;	//Caclulating delta time
		px = px + timeDiff * vx;	//movement of the sphere, x axis
		py = py + timeDiff * vy;	//movement of the sphere, y axis
		pz = pz + timeDiff * vz;	//movement of the sphere, z axis

		if (pz > -50 && pz < 10)	//Changing colour depending on brick distance
		{
			closeball = 10.0;	
			middleball = 0.0;
			farball = 0;
		}
		else if (pz < -50 && pz > -70)
		{
			closeball = 4.0;
			middleball = 4.0;
			farball = 4.0;
		}
		else if (pz < -70)
		{
			closeball = 0.0;
			middleball = 0.0;
			farball = 10.0;
		}

		if (mode == 2)	//Auto play mode
		{
			if (px < -35 || px > 35)
			{
				tx = tx;
			}
			else
			{
				tx = px;
			}

			if (py < -23 || py > 23)
			{
				ty = ty;
			}
			else
			{
				ty = py;
			}
		}

		for (i = 1; i < 49; i++)
		{
			if (flag[i] != 0)
			{
				angle[i] += ((1.0f) *  3);	//Brick rotation animation
				deep[i] += ((1.0f) * 2 );	//Brick drop animation
			}
		}

		if (px - r < -50 && pz - r < 10)
		{
			vx = abs(vx);	
		}
		else if (pz - r > 10 && lives > 0)	//Checking if the sphere is out of box. If it is the player loses a life
		{
			lives--;
			printf("You have %d lifes left.", lives);
			px = 0.0;
			py = 0.0;
			pz = -30.0;
			tx = 0;
			ty = 0;
			tz = 0;
			vz = -vz;
			animate = !animate;
		}
		else if (lives == 0)
		{
			printf("Game over !");
			exit(0);
		}

		if (px + r > 50 && pz + r < 10)
		{
			vx = -vx;
		}
		else if (pz - r > 10 && lives > 0)
		{
			lives--;
			printf("You have %d lifes left.", lives);
			px = 0.0;
			py = 0.0;
			pz = -30.0;
			tx = 0;
			ty = 0;
			tz = 0;
			vz = -vz;
			animate = !animate;
		}
		else if (lives == 0)
		{
			printf("Game over !");
			exit(0);
		}

		if (py - r < -40 && pz - r < 10)
		{
			vy = abs(vy);
		}
		else if (pz - r > 10 && lives > 0)
		{
			lives--;
			printf("You have %d lifes left.", lives);
			px = 0.0;
			py = 0.0;
			pz = -30.0;
			tx = 0;
			ty = 0;
			tz = 0;
			vz = -vz;
			animate = !animate;
		}
		else if (lives == 0)
		{
			printf("Game over !");
			exit(0);
		}

		if (py + r > 40 && pz + r < 10)
		{
			vy = -vy;
		}
		else if (pz - r > 10 && lives > 0)
		{
			lives--;
			printf("You have %d lifes left.", lives);
			px = 0.0;
			py = 0.0;
			pz = -30.0;
			tx = 0;
			ty = 0;
			tz = 0;
			vz = -vz;
			animate = !animate;
		}
		else if (lives == 0)
		{
			printf("Game over !");
			exit(0);
		}
		if (pz - r < -130)
		{
			vz = -vz;
		}



		if ((abs(tx - px) < (rsx / 2) + r) && (abs(ty - py) < (rsy / 2) + r) && (abs(tz - pz) < (rsz / 2) + r))	//racket collision
		{
			printf("racket collision ");
			vz = -vz;
		}

		


		//brick collision

		if ((abs(-30 - px) < (sx / 2) + r) && (abs(30 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[1] == 0))
		{
			printf("collision ");
			vz = -vz;
			flag[1] = 1;
			c++;
			return;
		}

		if ((abs(-10 - px) < (sx / 2) + r) && (abs(30 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[2] == 0))
		{
			printf("collision ");
			vz = -vz;
			flag[2] = 1;
			c++;
			return;
		}

		if ((abs(10 - px) < (sx / 2) + r) && (abs(30 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[3] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[3] = 1;
			c++;

			return;
		}

		if ((abs(30 - px) < (sx / 2) + r) && (abs(30 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[4] == 0))
		{
			printf("collision ");
		
			vz = -vz;
			flag[4] = 1;
			c++;

			return;
		}

		if ((abs(-30 - px) < (sx / 2) + r) && (abs(10 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[5] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[5] = 1;
			c++;
			return;

		}

		if ((abs(-10 - px) < (sx / 2) + r) && (abs(10 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[6] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[6] = 1;
			c++;
			return;
		}

		if ((abs(10 - px) < (sx / 2) + r) && (abs(10 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[7] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[7] = 1;
			c++;
			return;
		}

		if ((abs(30 - px) < (sx / 2) + r) && (abs(10 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[8] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[8] = 1;
			c++;

			return;
		}

		if ((abs(-30 - px) < (sx / 2) + r) && (abs(-10 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[9] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[9] = 1;
			c++;

			return;
		}


		if ((abs(-10 - px) < (sx / 2) + r) && (abs(-10 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[10] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[10] = 1;
			c++;

			return;
		}

		if ((abs(10 - px) < (sx / 2) + r) && (abs(-10 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[11] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[11] = 1;
			c++;

			return;
		}

		if ((abs(30 - px) < (sx / 2) + r) && (abs(-10 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[12] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[12] = 1;
			c++;

			return;
		}

		if ((abs(-30 - px) < (sx / 2) + r) && (abs(-30 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[13] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[13] = 1;
			c++;

			return;
		}

		if ((abs(-10 - px) < (sx / 2) + r) && (abs(-30 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[14] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[14] = 1;
			c++;

			return;
		}

		if ((abs(10 - px) < (sx / 2) + r) && (abs(-30 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[15] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[15] = 1;
			c++;

			return;
		}

		if ((abs(30 - px) < (sx / 2) + r) && (abs(-30 - py) < (sy / 2) + r) && (abs(-100 - pz) < (sz / 2) + r) && (flag[16] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[16] = 1;
			c++;

			return;
		}

		//


		if ((abs(-30 - px) < (sx / 2) + r) && (abs(30 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[17] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[17] = 1;
			c++;

			return;
		}

		if ((abs(-10 - px) < (sx / 2) + r) && (abs(30 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[18] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[18] = 1;
			c++;

			return;
		}

		if ((abs(10 - px) < (sx / 2) + r) && (abs(30 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[19] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[19] = 1;
			c++;
			return;

		}

		if ((abs(30 - px) < (sx / 2) + r) && (abs(30 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[20] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[20] = 1;
			c++;

			return;
		}

		if ((abs(-30 - px) < (sx / 2) + r) && (abs(10 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[21] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[21] = 1;
			c++;

			return;
		}

		if ((abs(-10 - px) < (sx / 2) + r) && (abs(10 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[22] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[22] = 1;
			c++;

			return;
		}

		if ((abs(10 - px) < (sx / 2) + r) && (abs(10 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[23] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[23] = 1;
			c++;

			return;
		}

		if ((abs(30 - px) < (sx / 2) + r) && (abs(10 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[24] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[24] = 1;
			c++;

			return;
		}

		if ((abs(-30 - px) < (sx / 2) + r) && (abs(-10 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[25] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[25] = 1;
			c++;

			return;
		}


		if ((abs(-10 - px) < (sx / 2) + r) && (abs(-10 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[26] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[26] = 1;
			c++;

			return;
		}

		if ((abs(10 - px) < (sx / 2) + r) && (abs(-10 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[27] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[27] = 1;
			c++;

			return;
		}

		if ((abs(30 - px) < (sx / 2) + r) && (abs(-10 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[28] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[28] = 1;
			c++;

			return;
		}


		if ((abs(-30 - px) < (sx / 2) + r) && (abs(-30 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[29] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[29] = 1;
			c++;

			return;
		}

		if ((abs(-10 - px) < (sx / 2) + r) && (abs(-30 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[30] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[30] = 1;
			c++;

			return;
		}

		if ((abs(10 - px) < (sx / 2) + r) && (abs(-30 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[31] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[31] = 1;
			c++;

			return;
		}

		if ((abs(30 - px) < (sx / 2) + r) && (abs(-30 - py) < (sy / 2) + r) && (abs(-110 - pz) < (sz / 2) + r) && (flag[32] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[32] = 1;
			c++;

			return;
		}

		//


		if ((abs(-30 - px) < (sx / 2) + r) && (abs(30 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[33] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[33] = 1;
			c++;

			return;
		}

		if ((abs(-10 - px) < (sx / 2) + r) && (abs(30 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[34] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[34] = 1;
			c++;

			return;
		}

		if ((abs(10 - px) < (sx / 2) + r) && (abs(30 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[35] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[35] = 1;
			c++;

			return;
		}

		if ((abs(30 - px) < (sx / 2) + r) && (abs(30 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[36] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[36] = 1;
			c++;

			return;
		}

		if ((abs(-30 - px) < (sx / 2) + r) && (abs(10 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[37] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[37] = 1;
			c++;

			return;
		}

		if ((abs(-10 - px) < (sx / 2) + r) && (abs(10 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[38] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[38] = 1;
			c++;

			return;
		}

		if ((abs(10 - px) < (sx / 2) + r) && (abs(10 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[39] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[39] = 1;
			c++;

			return;
		}

		if ((abs(30 - px) < (sx / 2) + r) && (abs(10 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[40] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[40] = 1;
			c++;

			return;
		}

		if ((abs(-30 - px) < (sx / 2) + r) && (abs(-10 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[41] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[41] = 1;
			c++;

			return;
		}


		if ((abs(-10 - px) < (sx / 2) + r) && (abs(-10 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[42] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[42] = 1;
			c++;

			return;
		}

		if ((abs(10 - px) < (sx / 2) + r) && (abs(-10 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[43] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[43] = 1;
			c++;

			return;
		}

		if ((abs(30 - px) < (sx / 2) + r) && (abs(-10 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[44] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[44] = 1;
			c++;

			return;
		}

		if ((abs(-30 - px) < (sx / 2) + r) && (abs(-30 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[45] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[45] = 1;
			c++;

			return;
		}

		if ((abs(-10 - px) < (sx / 2) + r) && (abs(-30 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[46] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[46] = 1;
			c++;

			return;
		}

		if ((abs(10 - px) < (sx / 2) + r) && (abs(-30 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[47] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[47] = 1;
			c++;

			return;
		}

		if ((abs(30 - px) < (sx / 2) + r) && (abs(-30 - py) < (sy / 2) + r) && (abs(-120 - pz) < (sz / 2) + r) && (flag[48] == 0))
		{
			printf("collision ");
			
			vz = -vz;
			flag[48] = 1;
			c++;

			return;
		}
		if (c == 48)
		{
			printf("WELL DONE !!!");
			exit(0);
		}

	}
	glutPostRedisplay();

}


void Keyboard(unsigned char key, int x, int y)  
{
	float theta = 2.042033;
	float phi = 8.639376;


	float lon = 1 * cos(theta) * cos(phi);
	float lat = 1 * sin(theta);
	float lonlat = 1 * cos(theta) * sin(phi);

	if (flookz == false)
	{
		switch (key) {	//control assignment switch
		case 'q': exit(0);
			break;
		case 'a':
			if (tx < -35)
				tx = tx;
			else
				tx -= 2.5f;
			printf("tx=%f\n", tx);
			break;

		case 'd':
			if (tx > 35)
				tx = tx;
			else
				tx += 2.5f;
			printf("tx=%f\n", tx);
			break;
		case 'w':
			if (ty > 23)
				ty = ty;
			else
				ty += 2.5f;
			printf("ty=%f\n", ty);
			break;
		case 's':
			if (ty < -23)
				ty = ty;
			else
				ty -= 2.5f;
			printf("ty=%f\n", ty);
			break;

		case '+':
		{
			camz = camz + 10;
			break;
		}
		case '-':
		{
			camz = camz - 10;
			break;
		}

		case '8':
		{
			theta += M_PI / 20;
			camy = lat;
			camx = lon;
			camz = lonlat;
			printf("camy=%f\n", camy);
			break;
		}

		case '2':
		{
			theta -= M_PI / 20;
			camy = lat;
			camx = lon;
			camz = lonlat;
			printf("camy=%f\n", camy);
			break;
		}

		case '4':
		{
			camx = lon;
			camx = camx - M_PI;
			camy = lat;
			camz = lonlat;
			printf("camx=%f\n", camx);
			break;
		}

		case '6':
		{

			camx = lon;
			camx = camx + M_PI;
			camy = lat;
			camz = lonlat;
			printf("camx=%f\n", camx);
			break;
		}

		case 'z':
			lookx++;
			printf("lookx=%f\n", lookx);
			break;
		case 'x':
			lookx--;
			printf("lookx=%f\n", lookx);
			break;
		case 'c':
			looky++;
			printf("looky=%f\n", looky);
			break;
		case 'v':
			looky--;
			printf("looky=%f\n", looky);
			break;
		case 'b':
			lookz++;
			printf("lookz=%f\n", lookz);
			break;
		case 'n':
			if (flookz == false)
			{
				lookz--;
				printf("lookz=%f\n", lookz);
			}
			break;
		case 't':
			camx++;
			printf("camx=%f\n", camx);
			break;
		case 'y':
			camx--;
			printf("camx=%f\n", camx);
			break;
		case 'u':
			camy++;
			printf("camy=%f\n", camy);
			break;
		case 'i':
			camy--;
			printf("camy=%f\n", camy);
			break;
		case 'o':
			camz++;
			printf("camz=%f\n", camz);
			break;
		case 'p':
			camz--;
			printf("camz=%f\n", camz);
			break;
		case'k'://Forward upper right
			lookx = 133;
			looky = 62;
			lookz = 67.099045;
			camx = -54;
			camy = -39;
			camz = -138;
			break;
		case'j'://Forward upper left
			lookx = -133;
			looky = 62;
			lookz = 76.099045;
			camx = 54;
			camy = -39;
			camz = -138;
			break;
		case'h'://Forward
			lookx = 0;
			looky = 0;
			lookz = 100.099045;
			camx = 0;
			camy = 0;
			camz = -150;
			break;
		case'g'://Forward up
			lookx = 0;
			looky = 113;
			lookz = 62.099045;
			camx = 0;
			camy = -93;
			camz = -150;
			break;
		case'f'://Up
			lookx = 0;
			looky = 156;
			lookz = -6.900955;
			camx = 0;
			camy = -249;
			camz = -150;
			break;
		case'l'://Down
			lookx = 0;
			looky = -137;
			lookz = 67.900955;
			camx = 0;
			camy = 88;
			camz = -150;
			break;

		}
	}

	glutPostRedisplay();
}


void Mouse(int button, int state, int x, int y)	//Mouse functions
{
	if (flookz == false)
	{
		if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
			animate = !animate;
			mode = 2;
			glutPostRedisplay();
		}
		else if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON) {
			animate = !animate;
			mode = 1;
			glutPostRedisplay();
		}

	}
	
}



void Setup() 
{
	srand(time(NULL));
	oldTime = glutGet(GLUT_ELAPSED_TIME);



	vx = (rand() % 7) - 2; // Limits: [-2,2]
	while (vx == 0)
	{
		vx = (rand() % 7) - 2; // Limits: [-2,2]
	};
	vy = (rand() % 7) - 2; // Limits: [-2,2]
	while (vy == 0)
	{
		vy = (rand() % 7) - 2; // Limits: [-2,2]
	}
	vz = -8;


	ReadFile(&md);

	//Parameter handling
	glShadeModel(GL_SMOOTH);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL); //renders a fragment if its z value is less or equal of the stored value
	glClearDepth(1);

	// polygon rendering mode
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	//Set up light source
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_CULL_FACE);


	glFrontFace(GL_CCW);

	// background colour
	glClearColor(0.0f, 0.8f, 0.6f, 1.0f);

}

void ReadFile(model* md)
{

	ifstream obj_file("OBJINFO.TXT"); // Open the file for reading OBJINFO.TXT

	if (obj_file.fail()) {
		cout << "Could not load file" << endl; 
		exit(1);
	}

	obj_file >> md->vertices;

	obj_file >> md->faces;

	for (int i = 0; i < md->vertices; i++) { // Get the vertex coordinates 

		obj_file >> md->obj_points[i].x;
		obj_file >> md->obj_points[i].y;
		obj_file >> md->obj_points[i].z;

	}

	for (int i = 0; i < md->faces; i++) { // Get the face structure

		obj_file >> md->obj_faces[i].vtx[0];
		obj_file >> md->obj_faces[i].vtx[1];
		obj_file >> md->obj_faces[i].vtx[2];
	}

	obj_file.close(); 
}

void DisplayModel(model md)	//creating the outter box with the use of triangle design
{
	glPushMatrix();
	glBegin(GL_TRIANGLES);

	for (int i = 0; i < md.faces; i++) {
		glVertex3f(md.obj_points[md.obj_faces[i].vtx[0] - 1].x, md.obj_points[md.obj_faces[i].vtx[0] - 1].y, md.obj_points[md.obj_faces[i].vtx[0] - 1].z);
		glVertex3f(md.obj_points[md.obj_faces[i].vtx[1] - 1].x, md.obj_points[md.obj_faces[i].vtx[1] - 1].y, md.obj_points[md.obj_faces[i].vtx[1] - 1].z);
		glVertex3f(md.obj_points[md.obj_faces[i].vtx[2] - 1].x, md.obj_points[md.obj_faces[i].vtx[2] - 1].y, md.obj_points[md.obj_faces[i].vtx[2] - 1].z);

	}

	glEnd();
	glPopMatrix();
}

#pragma once
#include <stdio.h>     // - Just for some ASCII messages
#include <GL/glut.h>   // - An interface and windows management library
#include "objects.h"   // Header file for our OpenGL functions
#include "visuals.h"

static float tx = 0.0;
static float ty = 0.0;

static float rotx = 0.0;

void brick()
{

	glPushMatrix();
	glColor3f(5.0, 0.5, 0.2);
	glTranslatef(-30, 15, -60);
	glScalef(1.0, 1.0, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(5.0, 0.5, 0.2);
	glTranslatef(-15, 15, -60);
	glScalef(1.0, 1.0, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(2.0, 5, 0.2);
	glTranslatef(0, 15, -60);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();


	glPushMatrix();
	glColor3f(2.0, 0.5, 5);
	glTranslatef(15, 15, -60);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(2.0, 0.5, 2);
	glTranslatef(-30, 0, -60);
	glScalef(1.0, 1.0, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(2.0, 0.5, 2);
	glTranslatef(-15, 0, -60);
	glScalef(1.0, 1.0, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();


	glPushMatrix();
	glColor3f(2.0, 3, 0.2);
	glTranslatef(0, 0, -60);
	glScalef(1.0, 1.0, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();


	glPushMatrix();
	glColor3f(2.0, 0.5, 0.2);
	glTranslatef(15, 0, -60);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(2.0, 0.5, 2);
	glTranslatef(-30, -15, -60);
	glScalef(1.0, 1.0, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(10, 0.5, 0.2);
	glTranslatef(-15, -15, -60);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();



	glPushMatrix();
	glColor3f(2.0, 0.5, 9);
	glTranslatef(0, -15, -60);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();



	glPushMatrix();
	glColor3f(2.0, 8, 0.2);
	glTranslatef(15, -15, -60);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();



	//




	glPushMatrix();
	glColor3f(5.0, 6, 0.2);
	glTranslatef(-30, 15, -70);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(5.0, 6, 0.2);
	glTranslatef(-15, 15, -70);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(2.0, 5, 3);
	glTranslatef(0, 15, -70);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(2.0, 9, 5);
	glTranslatef(15, 15, -70);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(4, 0.5, 2);
	glTranslatef(-30, 0, -70);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(4, 0.5, 2);
	glTranslatef(-15, 0, -70);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();


	glPushMatrix();
	glColor3f(2.0, 3, 7);
	glTranslatef(0, 0, -70);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();


	glPushMatrix();
	glColor3f(7, 0.5, 0.2);
	glTranslatef(15, 0, -70);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(10, 0.5, 8);
	glTranslatef(-30, -15, -70);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(10, 0.5, 8);
	glTranslatef(-15, -15, -70);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(6, 0.5, 9);
	glTranslatef(0, -15, -70);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(2.0, 8, 4);
	glTranslatef(15, -15, -70);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();






	//
	glPushMatrix();
	glColor3f(5.0, 6, 8);
	glTranslatef(-30, 15, -80);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(5.0, 6, 8);
	glTranslatef(-15, 15, -80);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(2, 5, 3);
	glTranslatef(0, 15, -80);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(2.0, 9, 8);
	glTranslatef(15, 15, -80);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.5, 2);
	glTranslatef(-30, 0, -80);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.5, 2);
	glTranslatef(-15, 0, -80);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();


	glPushMatrix();
	glColor3f(4, 3, 7);
	glTranslatef(0, 0, -80);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();


	glPushMatrix();
	glColor3f(7, 3, 2);
	glTranslatef(15, 0, -80);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(10, 3, 8);
	glTranslatef(-30, -15, -80);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(10, 3, 8);
	glTranslatef(-15, -15, -80);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();



	glPushMatrix();
	glColor3f(6, 7, 9);
	glTranslatef(0, -15, -80);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();



	glPushMatrix();
	glColor3f(3, 8, 4);
	glTranslatef(15, -15, -80);
	glScalef(1, 1, 0.3);
	glutSolidCube(10.0);
	glPopMatrix();

}


void Sphere()
{
	glPushMatrix();
	glColor3f(0, 0, 9);
	glTranslatef(-10, 0, -10);
	glTranslatef(0, 0, rotx);
	glutSolidSphere(3.0, 15.0, 15.0);
	glPopMatrix();
}

void Racket()
{
	glPushMatrix();
	glColor4f(3, 8, 4, 0.80);
	glTranslatef(tx, ty, 0.0);
	glTranslatef(-10, 0, 0);
	glScalef(1, 1, 0.1);
	glutSolidCube(16.0);
	glPopMatrix();
}


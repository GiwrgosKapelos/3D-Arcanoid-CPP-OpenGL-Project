#include <stdio.h>     
#include <GL/glut.h>   
#include "visuals.h"   
#include "time.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>


int main(int argc, char* argv[])
{

	glutInit(&argc, argv);

	
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

	srand(time(0));


	glutInitWindowSize(1000, 1000);	//Setting window size
	glutInitWindowPosition(50, 50);	//Setting window screen poisition


	glutCreateWindow("Arkanoid");	//Setting window name

	
	Setup();


	//Calling the gameplay functions

	glutDisplayFunc(Render);
	glutReshapeFunc(Resize);
	glutIdleFunc(Idle);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(Mouse);

	glutMainLoop();
	return 0;
}

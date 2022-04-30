#pragma once

struct point //Coordinats of a single point 
{
    float x;
    float y;
    float z;
};

struct face //Vertices
{
    int vtx[3];
};

struct model
{
    point obj_points[8]; //8 points
    face obj_faces[10];  //10 triangles
    int vertices;
    int faces;
};



void Render();

void Resize(int w, int h);

void Setup();

void srand();

void Idle();

void ReadFile(model*);

void DisplayModel(model);

void Keyboard(unsigned char key, int x, int y);
// Function for handling keyboard events.

void Mouse(int button, int state, int x, int y);
// Function for handling mouse events

//Not used anymore
void brick();

void Sphere();

void Racket();
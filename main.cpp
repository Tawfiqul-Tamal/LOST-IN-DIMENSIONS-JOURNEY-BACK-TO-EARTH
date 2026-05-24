// SPDX-License-Identifier: MIT

#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include<iostream>
using namespace std;


int level = 0; //for Next level
//Tamal Global
float y = 0.0f;
float v = 0.0f;
int j = 0;

//Asma
float manX = 0.0f;

float moveX = 0.0f;
float moveY = 0.0f;

//Alvi

float velocityY = 0.0f;
int isJumping = 0;


float velocityX = 0.0f;


int playerVisible = 1;   // 1 = visible, 0 = hidden (dead)


//Shithil


float yz = 0.0f;
float vz = 0.0f;
int count = 0;

float tx = 0.0f, ty = 0.0f;
float txz = 0.0f, tyz = 0.0f;



bool humanVisible = true;



//Tamal
// Helper function
bool checkCollision(float playerX, float playerY, float coinX, float coinY, float radius = 0.3f)

{
    float dx = playerX - coinX;
    /*

    X axis borabor player and coin er distance

    */

    float dy = playerY - coinY;
    return (dx * dx + dy * dy) < (radius * radius);

}


bool rain = false;// starting a no rain


//Global Variable
//Tamal Coins
int coinB3 = 1;
int coinD3 = 1;
int coinE3 = 1;
int coinF3 = 1;
int coinH3 = 1;
int coinJ3 = 1;
int coinB7 = 1;
int coinC7 = 1;


//Alvi Coins

// Coin visibility (1 = visible, 0 = collected)

int coin10 = 1;
int coin11 = 1;
int coin12 = 1;
int coin13 = 1;
int coin14 = 1;
int coin15 = 1;
int coin16 = 1;



//Shithil Coins
bool coin1 = true;
bool coin2 = true;
bool coin3 = true;
bool coin4 = true;
bool coin5 = true;
bool coin6 = true;
bool coin7 = true;
bool coin8 = true;
bool coin9 = true;




//Tamal text
void drawText1(float x, float y, const char *string)             //Text lebeling
{
    glRasterPos2f(x, y);

    while (*string)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string);  //*string = value at that position (actual character)
        string++;
    }
}


//Alvi Text
void drawText2(float x, float y, const char *string)
{
    glRasterPos2f(x, y);

    while (*string)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string);
        string++;
    }
}



//Shithil Text

void drawText3(float x, float y, const char* string) {
    glRasterPos2f(x, y);

    while (*string) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string);
        string++;
    }
}



//Asma Display
void display0()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);  //no 7
     glLoadIdentity();

   glBegin(GL_POLYGON);
glColor3f(0.40f, 0.65f, 0.95f);
glVertex2f(-6, 4);

glColor3f(0.40f, 0.65f, 0.95f);
glVertex2f(6, 4);

glColor3f(0.25f, 0.45f, 0.75f);
glVertex2f(6, 3);

glColor3f(0.25f, 0.45f, 0.75f);
glVertex2f(-6, 3);

glEnd();

     glBegin(GL_POLYGON);  //no 8

    glColor3f(0.60f, 0.80f, 1.00f);
    glVertex2f(-6,3);
     glVertex2f(-6,1);
     glVertex2f(6,1);
     glVertex2f(6,3);
     glEnd();


     glBegin(GL_POLYGON);  //no 9

   glColor3f(0.75f, 0.85f, 0.95f);
    glVertex2f(-6,1);
     glVertex2f(-6,0);
     glVertex2f(6,0);
     glVertex2f(6,1);
     glEnd();



   glBegin(GL_POLYGON);  //no 1

    glColor3f(1.0f, 0.85f, 0.7f);
    glVertex2f(-6,3);
     glVertex2f(-6,0);
     glVertex2f(-4.7,0);
     glVertex2f(-4.7,3);
     glEnd();

    glBegin(GL_POLYGON);  //no 2
  glColor3f(0.5f, 0.9f, 0.5f);
    glVertex2f(-4.26,3.63);
     glVertex2f(-4.26,0);
     glVertex2f(-3,0);
     glVertex2f(-3,3.63);
     glEnd();

     glBegin(GL_POLYGON);  //no 3
 glColor3f(1.0f, 0.85f, 0.3f);
    glVertex2f(-2.51,3.85);
     glVertex2f(-2.51,0);
     glVertex2f(-1.02,0);
     glVertex2f(-1.02,3.85);
     glEnd();

     glBegin(GL_POLYGON);  //no 4

    glColor3f(0.55f, 0.27f, 0.07f);
    glVertex2f(-0.31,3.39);
     glVertex2f(-0.31,0);
     glVertex2f(1,0);
     glVertex2f(1,3.39);
     glEnd();

     glBegin(GL_POLYGON);  //no 5
 glColor3f(0.2f, 0.2f, 0.5f);
    glVertex2f(1.56,3.58);
     glVertex2f(1.56,0);
     glVertex2f(3,0);
     glVertex2f(3,3.58);
     glEnd();

 glBegin(GL_POLYGON); //Sun
   glColor3f(1.0f, 0.45f, 0.1f);

    float cx = 5.3f;
    float cy = 3.26f;
    float ra  = 0.5326f;

    for (float t = 0; t < 360; t += 0.01)
    {
        float angle = t * 3.1416f / 180.0f;
        float x = cx + ra * cos(angle );
        float y = cy + ra * sin(angle);

        glVertex2f(x, y);
    }

    glEnd();


     glBegin(GL_POLYGON);  //no 6

   glColor3f(0.6f, 0.2f, 0.8f);
    glVertex2f(3.5,3.68);
     glVertex2f(3.5,0);
     glVertex2f(5,0);
     glVertex2f(5.0,3.68);
     glEnd();

     glBegin(GL_POLYGON);  //no 11


 glColor3f(0.83f, 0.83f, 0.83f);
      glVertex2f(-6,0);
     glVertex2f(-6,-1.77);
     glVertex2f(6,-1.77);
     glVertex2f(6,0);
     glEnd();

     glBegin(GL_POLYGON);  //no 12

    glColor3f(0.21f, 0.27f, 0.31f);
    glVertex2f(-6,-1.77);
     glVertex2f(-6,-2.14);
     glVertex2f(6,-2.14);
     glVertex2f(6,-1.77);
     glEnd();

     glBegin(GL_POLYGON);  //no 10
     glColor3f(0.44f, 0.50f, 0.56f);
    glVertex2f(-6,-2.14);
     glVertex2f(-6,-4);
     glVertex2f(6,-4);
     glVertex2f(5.99,-2.14);
     glEnd();

     glBegin(GL_POLYGON);  //no 13
     glColor3f(1,1,1);
    glVertex2f(-5.58,-1);
     glVertex2f(-5.58,-1.25);
     glVertex2f(-4,-1.25);
     glVertex2f(-4,-1);
     glEnd();

     glBegin(GL_POLYGON);  //no 14
   glColor3f(1,1,1);
    glVertex2f(-3.39,-1);
     glVertex2f(-3.39,-1.27);
     glVertex2f(-2,-1.27);
     glVertex2f(-2,-1);
     glEnd();

     glBegin(GL_POLYGON);  //no 15
    glColor3f(1,1,1);
    glVertex2f(-1.41,-1);
     glVertex2f(-1.41,-1.28);
     glVertex2f(0,-1.28);
     glVertex2f(0,-1);
     glEnd();

    glBegin(GL_POLYGON);  //no 16
  glColor3f(1,1,1);
    glVertex2f(0.4,-1);
     glVertex2f(0.4,-1.27);
     glVertex2f(1.59,-1.27);
     glVertex2f(1.59,-1);
     glEnd();

     glBegin(GL_POLYGON);  //no 17
    glColor3f(1,1,1);
    glVertex2f(2.5,-1);
     glVertex2f(2.5,-1.28);
     glVertex2f(3.6,-1.28);
     glVertex2f(3.6,-1);
     glEnd();


     glBegin(GL_POLYGON);  //no 19
     glColor3f(1.0f, 0.6f, 0.0f);
    glVertex2f(-5.81,2.61);
     glVertex2f(-5.81,2);
     glVertex2f(-5,2);
     glVertex2f(-5,2.61);
     glEnd();

      glBegin(GL_POLYGON);  //no 20
   glColor3f(1.0f, 0.6f, 0.0f);
    glVertex2f(-5.5,1.5);
     glVertex2f(-5.5,1);
     glVertex2f(-5,1);
     glVertex2f(-5,1.5);
     glEnd();

      glBegin(GL_POLYGON);  //no 21
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-4.01,3.3);
     glVertex2f(-4.01,2.88);
     glVertex2f(-3.61,2.88);
     glVertex2f(-3.61,3.3);
     glEnd();

    glBegin(GL_POLYGON);  //no 22
   glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-3.52,2.5);
     glVertex2f(-3.52,2.1);
     glVertex2f(-3.13,2.1);
     glVertex2f(-3.13,2.5);
     glEnd();

    glBegin(GL_POLYGON);  //no 23
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(-4.01,1.71);
     glVertex2f(-4.01,1.32);
     glVertex2f(-3.61,1.32);
     glVertex2f(-3.61,1.71);
     glEnd();

     glBegin(GL_POLYGON);  //no 24
     glColor3f(0.8f, 0.7f, 0.1f);
    glVertex2f(-2,3.31);
     glVertex2f(-2,2.91);
     glVertex2f(-1.5,2.91);
     glVertex2f(-1.5,3.31);
     glEnd();

glBegin(GL_POLYGON);  //no 25
  glColor3f(0.8f, 0.7f, 0.1f);
    glVertex2f(-2,2.4);
     glVertex2f(-2,2);
     glVertex2f(-1.5,2);
     glVertex2f(-1.5,2.4);
     glEnd();


glBegin(GL_POLYGON);  //no 26
    glColor3f(0.8f, 0.7f, 0.1f);
    glVertex2f(-2.01,1.61);
     glVertex2f(-2.01,1.21);
     glVertex2f(-1.5,1.21);
     glVertex2f(-1.5,1.61);
     glEnd();

     glBegin(GL_POLYGON);  //no 27
    glColor3f(0.8f, 0.7f, 0.1f);
    glVertex2f(-2,0.91);
     glVertex2f(-2,0.5);
     glVertex2f(-1.5,0.5);
     glVertex2f(-1.5,0.91);
     glEnd();

     glBegin(GL_POLYGON);  //no 28
     glColor3f(1.0f, 0.85f, 0.7f);
    glVertex2f(0.31,3.01);
     glVertex2f(0.31,2.61);
     glVertex2f(0.8,2.61);
     glVertex2f(0.8,3.01);
     glEnd();

glBegin(GL_POLYGON);  //no 29
      glColor3f(1.0f, 0.85f, 0.7f);
    glVertex2f(-0.1,2.19);
     glVertex2f(-0.1,1.71);
     glVertex2f(0.31,1.7);
     glVertex2f(0.31,2.19);
     glEnd();

     glBegin(GL_POLYGON);  //no 30
     glColor3f(1.0f, 0.85f, 0.7f);
    glVertex2f(0.3,1.3);
     glVertex2f(0.3,1.01);
     glVertex2f(0.79,1.01);
     glVertex2f(0.79,1.3);
     glEnd();

     glBegin(GL_POLYGON);  //no 31
        glColor3f(1.0f, 0.85f, 0.7f);
    glVertex2f(0,0.71);
     glVertex2f(0,0.4);
     glVertex2f(0.41,0.4);
     glVertex2f(0.41,0.71);
     glEnd();

     glBegin(GL_POLYGON);  //no 32
    glColor3f(0.2f, 0.6f, 0.9f);
    glVertex2f(2,3.32);
     glVertex2f(2,3);
     glVertex2f(2.6,3);
     glVertex2f(2.6,3.32);
     glEnd();

     glBegin(GL_POLYGON);  //no 33
    glColor3f(0.2f, 0.6f, 0.9f);
    glVertex2f(2,2.6);
     glVertex2f(2,2.29);
     glVertex2f(2.61,2.29);
     glVertex2f(2.61,2.6);
     glEnd();

     glBegin(GL_POLYGON);  //no 34
  glColor3f(0.2f, 0.6f, 0.9f);
    glVertex2f(2,1.8);
     glVertex2f(2,1.49);
     glVertex2f(2.61,1.49);
     glVertex2f(2.61,1.8);
     glEnd();

     glBegin(GL_POLYGON);  //no 35
     glColor3f(0.2f, 0.6f, 0.9f);
    glVertex2f(2,1);
     glVertex2f(2,0.6);
     glVertex2f(2.6,0.6);
     glVertex2f(2.6,1);
     glEnd();

     glBegin(GL_POLYGON);  //no 36
    glColor3f(0.93f, 0.84f, 0.93f);
    glVertex2f(4.02,3.21);
     glVertex2f(4.02,2.71);
     glVertex2f(4.49,2.71);
     glVertex2f(4.49,3.21);
     glEnd();

     glBegin(GL_POLYGON);  //no 37
   glColor3f(0.93f, 0.84f, 0.93f);
    glVertex2f(4,2);
     glVertex2f(4,1.5);
     glVertex2f(4.5,1.5);
     glVertex2f(4.5,2);
     glEnd();

     glBegin(GL_POLYGON);  //no 38
   glColor3f(0.93f, 0.84f, 0.93f);
    glVertex2f(4,1);
     glVertex2f(4,0.5);
     glVertex2f(4.5,0.5);
     glVertex2f(4.5,1);
     glEnd();

// 39 no line
    float x1 = -5.4, y1 = -1.12;
    float x2 = -4.13, y2 =-1.12;

    float dx = x2 - x1;
    float dy = y2 - y1;

    float m = dy / dx;

    float x = x1;
    float y = y1;

    glPointSize(1);

    glBegin(GL_POINTS);

    glColor3f(0,0,0);
    if (fabs(m) < 1)
    {
        while (x <= x2)
        {
            glVertex2f(x, y);

            x = x + 0.01;
            y = y + m * 0.01;
        }
    }
    else
    {
        while (y <= y2)
        {
            glVertex2f(x, y);

            y = y + 0.01;
            x = x + (1/m) * 0.01;
        }
    }
     glEnd();



      glBegin(GL_LINES);//no 40

     glColor3f(0,0,0);
    glVertex2f(-3.28f, -1.14f);
     glVertex2f(-2.08f, -1.14f);
       glEnd();

       glBegin(GL_LINES);  //no 41
     glColor3f(0,0,0);
    glVertex2f(-1.26f, -1.14f);
     glVertex2f(-0.15f, -1.14f);
       glEnd();

       glBegin(GL_LINES);  //no 42
     glColor3f(0,0,0);
    glVertex2f(0.51f, -1.14f);
     glVertex2f(1.47f, -1.14f);
       glEnd();

       glBegin(GL_LINES);  //no 43
     glColor3f(0,0,0);
    glVertex2f(2.65f, -1.14f);
     glVertex2f(3.49f, -1.14f);
glEnd();

    glPushMatrix();
    glTranslatef(manX, 0, 0);
    glBegin(GL_POLYGON);  //1 head
    glColor3f(0,0,0);
    glVertex2f(-5.39f, -0.28f);
    glVertex2f(-5.2f, -0.26f);
    glVertex2f(-5.12f, -0.21f);
    glVertex2f(-5.21f, -0.17f);
    glVertex2f(-5.31f, -0.13f);
    glVertex2f(-5.44f, -0.14f);
    glVertex2f(-5.54f, -0.2f);
    glVertex2f(-5.57f, -0.33f);
    glVertex2f(-5.53f, -0.42f);
    glVertex2f(-5.48f, -0.44f);
    glVertex2f(-5.49f, -0.39f);
    glVertex2f(-5.46f, -0.37f);
    glVertex2f(-5.4f, -0.4f);
     glEnd();

      glBegin(GL_POLYGON);  // 2 mouth
         glColor3f(0.9f, 0.7f, 0.5f);
         glVertex2f(-5.39f, -0.28f);
    glVertex2f(-5.2f, -0.26f);
    glVertex2f(-5.17f, -0.4f);
    glVertex2f(-5.18f, -0.45f);
    glVertex2f(-5.25f, -0.5f);
    glVertex2f(-5.34f, -0.5f);
    glVertex2f(-5.39f, -0.48f);
    glVertex2f(-5.43f, -0.46f);
    glVertex2f(-5.48f, -0.44f);
    glVertex2f(-5.49f, -0.39f);
    glVertex2f(-5.46f, -0.37f);
    glVertex2f(-5.4f, -0.4f);
     glEnd();

     glBegin(GL_POLYGON);  //3 neck
     glColor3f(0.9f, 0.7f, 0.5f);
     glVertex2f(-5.39f, -0.48f);
    glVertex2f(-5.4f, -0.52f);
    glVertex2f(-5.36f, -0.55f);
    glVertex2f(-5.29f, -0.56f);
    glVertex2f(-5.25f, -0.54f);
    glVertex2f(-5.25f, -0.5f);
    glVertex2f(-5.34f, -0.5f);
     glEnd();

     glBegin(GL_POLYGON);  // 4 dress
     glColor3f(0.9f, 0.2f, 0.2f);
     glVertex2f(-5.4f, -0.52f);
    glVertex2f(-5.47f, -0.52f);
    glVertex2f(-5.53f, -0.59f);
    glVertex2f(-5.55f, -0.67f);
    glVertex2f(-5.45f, -0.71f);
    glVertex2f(-5.47f, -0.79f);
    glVertex2f(-5.45f, -0.85f);
    glVertex2f(-5.31f, -0.86f);
    glVertex2f(-5.19f, -0.83f);
    glVertex2f(-5.2f, -0.8f);
    glVertex2f(-5.21f, -0.68f);
    glVertex2f(-5.17f, -0.67f);
    glVertex2f(-5.17f, -0.59f);
    glVertex2f(-5.25f, -0.54f);
    glVertex2f(-5.29f, -0.56f);
    glVertex2f(-5.36f, -0.55f);
     glEnd();

     glBegin(GL_POLYGON); // 5.left hand
      glColor3f(0.9f, 0.7f, 0.5f);
    glVertex2f(-5.55f, -0.67f);
    glVertex2f(-5.57f, -0.80f);
    glVertex2f(-5.59f, -0.88f);
    glVertex2f(-5.52f, -0.90f);
    glVertex2f(-5.47f, -0.89f);
    glVertex2f(-5.45f, -0.85f);
    glVertex2f(-5.47f, -0.79f);
    glVertex2f(-5.45f, -0.71f);
     glEnd();

     glBegin(GL_POLYGON); // 6.right  hand
      glColor3f(0.9f, 0.7f, 0.5f);
      glVertex2f(-5.21f, -0.68f);
    glVertex2f(-5.20f, -0.80f);
    glVertex2f(-5.12f, -0.83f);
    glVertex2f(-5.10f, -0.87f);
    glVertex2f(-5.05f, -0.85f);
    glVertex2f(-5.03f, -0.81f);
    glVertex2f(-5.07f, -0.77f);
    glVertex2f(-5.03f, -0.78f);
    glVertex2f(-5.05f, -0.74f);
    glVertex2f(-5.12f, -0.74f);
    glVertex2f(-5.17f, -0.64f);
     glEnd();

      glBegin(GL_POLYGON); // 7.Pant
      glColor3f(0,0,0);
      glVertex2f(-5.45f, -0.85f);
    glVertex2f(-5.47f, -0.89f);
    glVertex2f(-5.49f, -1);
    glVertex2f(-5.57f, -1.08f);
    glVertex2f(-5.52f, -1.15f);
    glVertex2f(-5.47f, -1.16f);
    glVertex2f(-5.37f, -1.07f);
    glVertex2f(-5.32f, -0.99f);
    glVertex2f(-5.32f, -0.94f);
    glVertex2f(-5.25f, -1.17f);
    glVertex2f(-5.12f, -1.12f);
    glVertex2f(-5.15f, -0.95f);
    glVertex2f(-5.19f, -0.83f);
    glVertex2f(-5.31f, -0.86f);
     glEnd();

     glBegin(GL_POLYGON); // 8.left leg
      glColor3f( 1,1,1);
     glColor3f(0.4f, 0.25f, 0.1f);
      glVertex2f(-5.57f, -1.08f);
    glVertex2f(-5.57f, -1.22f);
     glVertex2f(-5.61f, -1.12f);
    glVertex2f(-5.50f, -1.27f);
    glVertex2f(-5.43f, -1.25f);
    glVertex2f(-5.42f, -1.20f);
    glVertex2f(-5.47f, -1.16f);
    glVertex2f(-5.52f, -1.15f);
      glEnd();

       glBegin(GL_POLYGON); // 9.right leg
     glColor3f(0.4f, 0.25f, 0.1f);
      glVertex2f(-5.25f, -1.17f);
    glVertex2f(-5.20f, -1.24f);
    glVertex2f(-5.12f, -1.22f);
    glVertex2f(-5.07f, -1.21f);
    glVertex2f(-5.04f, -1.18f);
    glVertex2f(-5.04f, -1.13f);
    glVertex2f(-5.12f, -1.12f);
       glEnd();

    glPopMatrix();
    float radiusXRight = 0.70f;
    float radiusYRight = 1.20f;
    float centerXRight = 5.35f;
    float centerYRight = -0.55f;

    glColor3f(0.0f, 0.6f, 0.9f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
    float angle = i * 3.1416f / 180.0f;
    float x = centerXRight + radiusXRight * cos(angle);
    float y = centerYRight + radiusYRight * sin(angle);
    glVertex2f(x, y);
    }
    glEnd();

    glFlush();
    glutSwapBuffers();
}




//Tamal Display Level 01

void display1() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


// 01
// Polygon color
glColor3f(0.6f, 0.2f, 0.1f);

        glBegin(GL_POLYGON);
        glVertex2f(-6.01f, -3.33f); // C
        glVertex2f(-5.50f, -3.41f); // D
        glVertex2f(-5.02f, -3.33f); // E
        glVertex2f(-4.51f, -3.37f); // F
        glVertex2f(-4.18f, -3.25f); // G
        glVertex2f(-3.72f, -3.38f); // H
        glVertex2f(-2.84f, -3.21f); // I
        glVertex2f(-2.23f, -3.03f); // J
        glVertex2f(-1.65f, -3.03f); // K
        glVertex2f(-1.65f, -2.46f); // L
        glVertex2f(-2.28f, -2.38f); // M
        glVertex2f(-2.87f, -2.37f); // N
        glVertex2f(-3.92f, -1.00f); // O
        glVertex2f(-6.00f, -1.00f); // P
    glEnd();


// 02
// Polygon color
glColor3f(0.6f, 0.2f, 0.1f);

    glBegin(GL_POLYGON);
    glVertex2f(5.99f, -3.33f); // Q
    glVertex2f(5.13f, -3.38f); // R
    glVertex2f(4.20f, -3.26f); // S
    glVertex2f(3.00f, -3.29f); // T
    glVertex2f(2.30f, -3.13f); // U
    glVertex2f(1.64f, -3.02f); // V
    glVertex2f(1.72f, -2.42f); // W
    glVertex2f(2.86f, -2.19f); // Z
    glVertex2f(3.00f, -1.50f); // A1
    glVertex2f(4.00f, -1.00f); // B1
    glVertex2f(6.00f, -1.00f); // C1
glEnd();


//03
glColor3f(0.8f, 0.4f, 0.3f);

    glBegin(GL_QUADS);
    glVertex2f(-6.00f, -1.00f); // p
    glVertex2f(-6.00f, -0.70f); // D1
    glVertex2f(-4.49f, -0.69f); // E1
    glVertex2f(-4.62f, -1.00f); //F1

glEnd();


//04
    glColor3f(0.8f, 0.4f, 0.3f);

    glBegin(GL_QUADS);
    glVertex2f(6.00f, -1.00f); // C1
    glVertex2f(6.00f, -0.65f); // G1
    glVertex2f(4.34f, -0.65f); // H1
    glVertex2f(4.60f, -1.00f); //I1

glEnd();


//14 Green Field

glColor3f(0.93f, 0.79f, 0.69f);

     glBegin(GL_POLYGON);
     glVertex2f(-6.00f, -0.70f); // D1
     glVertex2f(-6.00f, 0.45f); // V2
     glVertex2f(6.00f, 0.46f); // W2
     glVertex2f(6.00f, -0.65f); // G1
     glVertex2f(4.34f, -0.65f); // H1
     glVertex2f(4.06f, -0.63f); // U2
     glVertex2f(3.69f, -0.61f); // T2
     glVertex2f(3.03f, -0.57f); // R2
     glVertex2f(2.44f, -0.53f); // Q2
     glVertex2f(1.89f, -0.50f); // P2
     glVertex2f(1.40f, -0.47f); // O2
     glVertex2f(0.76f, -0.43f); // M2
     glVertex2f(0.46f, -0.42f); // K1
     glVertex2f(0.15f, -0.42f); // K2
     glVertex2f(3.69f, -0.61f); // T2
     glVertex2f(-0.96f, -0.42f); // J2
     glVertex2f(-1.54f, -0.42f); // J1
     glVertex2f(-2.03f, -0.46f); // I2
     glVertex2f(-2.62f, -0.52f); // H2
     glVertex2f(-3.56f, -0.60f); //F2
     glVertex2f(-4.12f, -0.66f); // E2
     glVertex2f(-4.49f, -0.69f); // E1



glEnd();

//05 Bridge

glColor3f(0.85f, 0.65f, 0.30f);

    glBegin(GL_POLYGON);
    glVertex2f(-4.49f, -0.69f); // E1
    glVertex2f(-1.54f, -0.42f); // J1
    glVertex2f(0.46f, -0.42f); // k1
    glVertex2f(4.34f, -0.65f); // H1
     glVertex2f(4.60f, -1.00f); //I1
    glVertex2f(0.00f, -1.00f); // L1
    glVertex2f(-4.62f, -1.00f); // F1

glEnd();


//06

glColor3f(0.85f, 0.65f, 0.30f);

    glBegin(GL_POLYGON);
    glVertex2f(-2.87f, -2.38f); // N
    glVertex2f(-2.85f, -1.00f); // M1
    glVertex2f(-2.33f, -1.00f); // N1
    glVertex2f(-2.32f, -1.54f); // O1
    glVertex2f(-1.67f, -1.00f); //P1
    glVertex2f(-1.37f, -1.00f); // Q1
    glVertex2f(-2.29f, -1.78f); // R1
    glVertex2f(-2.28f, -2.40f); // M

glEnd();



//07


glColor3f(0.85f, 0.65f, 0.30f);

    glBegin(GL_POLYGON);
    glVertex2f(2.31f, -2.30f); // S1
    glVertex2f(2.31f, -1.75f); // T1
    glVertex2f(2.29f, -1.00f); // Z1
    glVertex2f(2.86f, -1.00f); // A2
    glVertex2f(2.86f, -2.19f); // Z


glEnd();


glColor3f(0.85f, 0.65f, 0.30f);

    glBegin(GL_POLYGON);

    glVertex2f(2.31f, -1.75f); // T1
    glVertex2f(1.39f, -1.00f); // U1
    glVertex2f(1.69f, -1.00f); // V1
    glVertex2f(2.29f, -1.49f); // W1
glEnd();


//19


 glColor3f(0.4f, 0.8f, 1.0f);

    glBegin(GL_TRIANGLES);

    glVertex2f(-2.87f, -2.38f); // N
    glVertex2f(-2.86f, -1.78f); // V6
    glVertex2f(-3.33f, -1.78f); // W6

glEnd();


//08

glColor3f(0.93f, 0.79f, 0.69f);


    glBegin(GL_POLYGON);

    glVertex2f(-3.33f, -1.78f); // W6
    glVertex2f(-2.86f, -1.78f); // V6
     glVertex2f(-2.85f, -1.00f); // M1
    glVertex2f(-3.92f, -1.00f); // O
glEnd();


//09

glColor3f(0.93f, 0.79f, 0.69f);


glBegin(GL_TRIANGLES);

    glVertex2f(-2.32f, -1.54f); // O1
    glVertex2f(-1.67f, -1.00f); //P1
    glVertex2f(-2.33f, -1.00f); // N1

glEnd();


//10

glColor3f(0.93f, 0.79f, 0.69f);


glBegin(GL_TRIANGLES);

    glVertex2f(2.29f, -1.49f); // W1
    glVertex2f(2.29f, -1.00f); //Z1
    glVertex2f(1.69f, -1.00f); // V1

glEnd();


//17

glColor3f(0.4f, 0.8f, 1.0f);


glBegin(GL_TRIANGLES);

    glVertex2f(2.86f, -2.19f); // Z
    glVertex2f(2.94f, -1.80f); //Z6
    glVertex2f(2.86f, -1.80f); // A7

glEnd();



//11

glColor3f(0.93f, 0.79f, 0.69f);


    glBegin(GL_POLYGON);

    glVertex2f(2.86f, -1.80f); // A7
    glVertex2f(2.94f, -1.80f); //Z6
     glVertex2f(3.00f, -1.50f); // A1
     glVertex2f(4.00f, -1.00f); // B1
    glVertex2f(2.86f, -1.00f); // A2
glEnd();


//12

glColor3f(0.93f, 0.79f, 0.69f);


    glBegin(GL_POLYGON);

    glVertex2f(-2.29f, -1.78f); // B2
    glVertex2f(2.30f, -1.75f); //C2
     glVertex2f(1.39f, -1.00f); // U1
     glVertex2f(-1.37f, -1.00f); //Q1

glEnd();



//13 Nodi

glColor3f(0.4f, 0.8f, 1.0f);

    glBegin(GL_POLYGON);

     glVertex2f(-6.00f, -4.00f); // A
     glVertex2f(6.00f, -4.00f); // B
     glVertex2f(5.99f, -3.33f); // Q
     glVertex2f(5.13f, -3.38f); // R
     glVertex2f(4.20f, -3.26f); // S
     glVertex2f(3.00f, -3.29f); // T
     glVertex2f(2.30f, -3.13f); // U
     glVertex2f(1.64f, -3.02f); // V

     glVertex2f(-1.65f, -3.03f); // K
     glVertex2f(-2.23f, -3.03f); // J
     glVertex2f(-2.84f, -3.21f); // I
     glVertex2f(-3.72f, -3.38f); // H
     glVertex2f(-4.18f, -3.25f); // G
     glVertex2f(-4.51f, -3.37f); // F
     glVertex2f(-5.02f, -3.33f); // E
     glVertex2f(-5.50f, -3.41f); // D
     glVertex2f(-6.01f, -3.33f); // C



glEnd();


//17
glColor3f(0.4f, 0.8f, 1.0f);

    glBegin(GL_POLYGON);
     glVertex2f(-1.65f, -3.03f); // K
     glVertex2f(1.64f, -3.02f); // V
     glVertex2f(1.72f, -2.42f); // W
     glVertex2f(2.31f, -2.30f); // S1
     glVertex2f(2.30f, -1.75f); // C2
     glVertex2f(-2.29f, -1.78f); // B2
     glVertex2f(-2.28f, -2.40f); // M
     glVertex2f(-1.65f, -2.46f); // L


glEnd();


//15 Sky using shadding
glColor3f(0.0f, 0.0f, 0.25f);

     glBegin(GL_QUADS);

     glColor3f(0.25f, 0.30f, 0.45f);
     glVertex2f(-6.00f, 0.45f); // V2

     glColor3f(0.25f, 0.30f, 0.45f);
     glVertex2f(6.00f, 0.46f); // W2

     glColor3f(0.02f, 0.02f, 0.05f);
     glVertex2f(6.00f, 4.00f); // A3

     glColor3f(0.02f, 0.02f, 0.05f);
     glVertex2f(-6.00f, 4.00f); // S1

glEnd();



//Tamal Lines on the Bridge
glColor3f(0.6f, 0.2f, 0.1f);
glLineWidth(1.5f);


    glBegin(GL_LINES);
    glVertex2f(-4.4f, -1.00f); // D2
    glVertex2f(-4.12f, -0.66f); // E2


     glVertex2f(-3.92f, -1.00f); // O
     glVertex2f(-3.56f, -0.60f); // F2

     glVertex2f(-2.85f, -1.00f); // G2
     glVertex2f(-2.51f, -0.51f); //H2

     glVertex2f(-2.33f, -1.00f); // N1
     glVertex2f(-2.03f, -0.46f); // I2

     glVertex2f(-1.67f, -1.00f); // p1
     glVertex2f(-1.54f, -0.42f); // J1

     glVertex2f(-1.37f, -1.00f); // Q1
     glVertex2f(-0.96f, -0.42f); // J2

     glVertex2f(-0.00f, -1.00f); // L1
     glVertex2f(0.15f, -0.42f); // K2

     glVertex2f(0.48f, -1.00f); // L2
     glVertex2f(0.76f, -0.43f); // M2

     glVertex2f(1.16f, -1.00f); // N2
     glVertex2f(1.40f, -0.47f); // O2

     glVertex2f(1.69f, -1.00f); // V1
     glVertex2f(1.89f, -0.50f); // P2

     glVertex2f(2.29f, -1.00f); // Z1
     glVertex2f(2.44f, -0.53f); // Q2

     glVertex2f(2.86f, -1.00f); // A2
     glVertex2f(3.03f, -0.57f); // R2

     glVertex2f(3.60f, -1.00f); // S2
     glVertex2f(3.69f, -0.61f); // T2

     glVertex2f(4.00f, -1.00f); // B1
     glVertex2f(4.06f, -0.63f); // U2

glEnd();



//Tamal Coins

// Coin at B3
if(coinB3){
float radiusB3 = 0.23f;
float centerXB3 = -1.50f;
float centerYB3 = -0.10f;

glColor3f(1.0f, 0.84f, 0.0f);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float angle = i * 3.1416f / 180.0f;
    float x = centerXB3 + radiusB3 * cos(angle);
    float y = centerYB3 + radiusB3 * sin(angle);
    glVertex2f(x, y);
}
glEnd();
}

// Coin at D3
if(coinD3){
float radiusD3 = 0.23f;
float centerXD3 = -0.84f;
float centerYD3 = -0.10f;

glColor3f(1.0f, 0.84f, 0.0f);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float angle = i * 3.1416f / 180.0f;
    float x = centerXD3 + radiusD3 * cos(angle);
    float y = centerYD3 + radiusD3 * sin(angle);
    glVertex2f(x, y);
}
glEnd();
}
// Coin at E3
if(coinE3){
float radiusE3 = 0.23f;
float centerXE3 = -0.30f;
float centerYE3 = -0.10f;

glColor3f(1.0f, 0.84f, 0.0f);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float angle = i * 3.1416f / 180.0f;
    float x = centerXE3 + radiusE3 * cos(angle);
    float y = centerYE3 + radiusE3 * sin(angle);
    glVertex2f(x, y);
}
glEnd();

}

// Coin at F3
if(coinF3){
float radiusF3 = 0.23f;
float centerXF3 = 0.26f;
float centerYF3 = -0.10f;

glColor3f(1.0f, 0.84f, 0.0f);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float angle = i * 3.1416f / 180.0f;
    float x = centerXF3 + radiusF3 * cos(angle);
    float y = centerYF3 + radiusF3 * sin(angle);
    glVertex2f(x, y);
}
glEnd();

}


// Coin at H3
if(coinH3){
float radiusH3 = 0.23f;
float centerXH3 = 1.07f;
float centerYH3 = -0.10f;

glColor3f(1.0f, 0.84f, 0.0f);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float angle = i * 3.1416f / 180.0f;
    float x = centerXH3 + radiusH3 * cos(angle);
    float y = centerYH3 + radiusH3 * sin(angle);
    glVertex2f(x, y);
}
glEnd();

}


// Coin at J3
if(coinJ3){
float radiusJ3 = 0.23f;
float centerXJ3 = 1.86f;
float centerYJ3 = -0.10f;

glColor3f(1.0f, 0.84f, 0.0f);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float angle = i * 3.1416f / 180.0f;
    float x = centerXJ3 + radiusJ3 * cos(angle);
    float y = centerYJ3 + radiusJ3 * sin(angle);
    glVertex2f(x, y);
}
glEnd();

}
// Coin at B7
if(coinB7){
float radiusB7 = 0.23f;
float centerXB7 = 3.28f;
float centerYB7 = -0.15f;

glColor3f(1.0f, 0.84f, 0.0f);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float angle = i * 3.1416f / 180.0f;
    float x = centerXB7 + radiusB7 * cos(angle);
    float y = centerYB7 + radiusB7 * sin(angle);
    glVertex2f(x, y);
}
glEnd();

}

// Coin at C7
if(coinC7){
float radiusC7 = 0.23f;
float centerXC7 = 3.93f;
float centerYC7 = -0.14f;

glColor3f(1.0f, 0.84f, 0.0f);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float angle = i * 3.1416f / 180.0f;
    float x = centerXC7 + radiusC7 * cos(angle);
    float y = centerYC7 + radiusC7 * sin(angle);
    glVertex2f(x, y);
}
glEnd();

}


//Tamal Stars


// Stars using GL_POINTS
glColor3f(1.0f, 1.0f, 1.0f);
glPointSize(2.0f);

glBegin(GL_POINTS);
    glVertex2f(-3.0f, 2.50f);   // E6
    glVertex2f(-1.96f, 2.83f); // F6
    glVertex2f(-0.40f, 2.89f); // G6
    glVertex2f(1.60f, 2.61f);  // H6
    glVertex2f(1.43f, 3.19f);  // I6
    glVertex2f(-1.24f, 2.44f); // J6
    glVertex2f(-2.63f, 1.97f); // K6
    glVertex2f(1.90f, 1.83f);  // L6
    glVertex2f(3.27f, 2.03f);  // M6
    glVertex2f(3.25f, 2.80f);  // N6
    glVertex2f(0.88f, 2.26f);  // O6
    glVertex2f(0.29f, 2.75f);  // P6
    glVertex2f(-0.63f, 2.20f); // Q6
    glVertex2f(-3.60f, 2.07f); // R6
    glVertex2f(-3.50f, 3.00f); // S6
    glVertex2f(4.78f, 2.81f);  // T6
    glVertex2f(-5.27f, 2.91f); // U6

    glVertex2f(-4.13f, 3.77f); // B7
    glVertex2f(-1.13f, 3.78f); // C7
    glVertex2f(4.36f, 3.77f);  // D7
    glVertex2f(-2.28f, 3.74f); // E7
    glVertex2f(1.96f, 3.77f);  // F7
    glVertex2f(5.72f, 3.52f);  // G7
    glVertex2f(5.63f, 2.76f);  // H7
    glVertex2f(-4.68f, 2.52f); // I7
    glVertex2f(-5.42f, 2.45f); // J7
    glVertex2f(-4.04f, 2.60f); // K7
    glVertex2f(-5.11f, 3.57f); // L7
    glVertex2f(-1.18f, 1.94f); // M7
    glVertex2f(-0.46f, 1.50f); // N7

    glVertex2f(0.61f, 2.01f);  // O7
    glVertex2f(1.08f, 3.46f);  // P7
    glVertex2f(-0.35f, 3.45f); // Q7
    glVertex2f(-3.09f, 3.60f); // R7
    glVertex2f(3.30f, 3.74f);  // S7
    glVertex2f(4.19f, 2.60f);  // T7
    glVertex2f(5.21f, 1.81f);  // U7
    glVertex2f(5.60f, 2.38f);  // V7
    glVertex2f(-5.23f, 2.17f); // W7
    glVertex2f(-5.68f, 3.33f); // Z7
    glVertex2f(-4.56f, 3.60f); // A8
    glVertex2f(-4.30f, 2.34f); // B8
    glVertex2f(-4.16f, 3.42f); // C8
    glVertex2f(-1.62f, 3.40f); // D8
    glVertex2f(0.47f, 3.49f);  // E8
    glVertex2f(3.76f, 3.49f);  // F8
    glVertex2f(4.77f, 3.46f);  // G8
    glVertex2f(4.47f, 2.05f);  // H8
    glVertex2f(-3.44f, 2.66f); // I8

glEnd();


//Tamal Portals


//20 Left Portal

float radiusXLeft = 0.70f;
float radiusYLeft = 1.20f;
float centerXLeft = -5.2f;
float centerYLeft = 0.20f;

glColor3f(0.0f, 0.6f, 0.9f);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float angle = i * 3.1416f / 180.0f;
    float x = centerXLeft + radiusXLeft * cos(angle);
    float y = centerYLeft + radiusYLeft * sin(angle);
    glVertex2f(x, y);
}
glEnd();


// 21 Right Portal

float radiusXRight = 0.70f;
float radiusYRight = 1.20f;
float centerXRight = 5.2f;
float centerYRight = 0.20f;

glColor3f(0.0f, 0.6f, 0.9f);
glBegin(GL_POLYGON);
for (int i = 0; i < 360; i++) {
    float angle = i * 3.1416f / 180.0f;
    float x = centerXRight + radiusXRight * cos(angle);
    float y = centerYRight + radiusYRight * sin(angle);
    glVertex2f(x, y);
}
glEnd();

//Tamal Character

//16 Man Hair

glPushMatrix();


glTranslatef(moveX, moveY, 0.0f);
glColor3f(0.0f, 0.0f, 0.0f);

     glBegin(GL_POLYGON);
     glVertex2f(-3.28f, 0.47f); // M3
     glVertex2f(-3.19f, 0.46f); // L3
     glVertex2f(-3.30f, 0.58f); // B4
     glVertex2f(-3.25f, 0.63f); // A4
     glVertex2f(-3.20f, 0.55f); // Z3
     glVertex2f(-3.16f, 0.58f); // W3
     glVertex2f(-3.19f, 0.67f); // V3
     glVertex2f(-3.14f, 0.75f); // U3
     glVertex2f(-3.00f, 0.73f); // T3
     glVertex2f(-2.85f, 0.78f); // C4
     glVertex2f(-2.80f, 0.80f); // S3
     glVertex2f(-2.74f, 0.86f); // R3
     glVertex2f(-3.00f, 0.97f); // Q3
     glVertex2f(-3.26f, 0.96f); // P3
     glVertex2f(-3.40f, 0.80f); // O3
     glVertex2f(-3.38f, 0.60f); // N3
glEnd();



//Face

glColor3f(1.0f, 0.87f, 0.68f);

     glBegin(GL_POLYGON);
     glVertex2f(-3.19f, 0.46f); // L3
     glVertex2f(-3.16f, 0.45f); // H4
     glVertex2f(-3.00f, 0.40f); // F4
     glVertex2f(-2.90f, 0.42f); // E4
     glVertex2f(-2.82f, 0.54f); // D4
     glVertex2f(-2.85f, 0.78f); // C4
     glVertex2f(-3.00f, 0.73f); // T3
     glVertex2f(-3.14f, 0.75f); // U3
     glVertex2f(-3.19f, 0.67f); // V3
     glVertex2f(-3.16f, 0.58f); // W3
     glVertex2f(-3.20f, 0.55f); // Z3
     glVertex2f(-3.25f, 0.63f); // A4
     glVertex2f(-3.30f, 0.58f); // B4

glEnd();

//Neck

glColor3f(1.0f, 0.87f, 0.68f);

     glBegin(GL_POLYGON);
     glVertex2f(-3.16f, 0.45f); // H4
     glVertex2f(-3.18f, 0.40f); // G4
     glVertex2f(-3.05f, 0.34f); // K4
     glVertex2f(-2.96f, 0.36f); // J4
     glVertex2f(-2.96f, 0.41f); // I4
     glVertex2f(-3.00f, 0.40f); // F4

glEnd();

//T-shirt

glColor3f(0.0f, 0.3f, 0.8f);
     glBegin(GL_POLYGON);
     glVertex2f(-3.40f, 0.18f); // L4
     glVertex2f(-3.26f, 0.11f); // V4
     glVertex2f(-3.19f, 0.24f); // U4
     glVertex2f(-3.26f, 0.10f); // T4
     glVertex2f(-2.83f, 0.10f); // R4
     glVertex2f(-2.90f, 0.20f); // Q4
     glVertex2f(-2.87f, 0.13f); // P4
     glVertex2f(-2.81f, 0.18f); // O4
     glVertex2f(-2.88f, 0.33f); // N4
     glVertex2f(-2.96f, 0.36f); // J4
     glVertex2f(-3.05f, 0.34f); // K4
     glVertex2f(-3.18f, 0.40f); // G4
     glVertex2f(-3.31f, 0.37f); // M4

glEnd();

//Left Hand

glColor3f(1.0f, 0.87f, 0.68f);

     glBegin(GL_POLYGON);
     glVertex2f(-3.38f, 0.17f); // W4
     glVertex2f(-3.43f, -0.16f); // Z4
     glVertex2f(-3.32f, -0.19f); // A5
     glVertex2f(-3.26f, -0.13f); // B5
     glVertex2f(-3.26f, 0.11f); // V4

glEnd();

//Right hand

glColor3f(1.0f, 0.87f, 0.68f);

     glBegin(GL_POLYGON);
     glVertex2f(-2.87f, 0.13f); // P4
     glVertex2f(-2.77f, -0.09f); // C5
     glVertex2f(-2.66f, -0.12f); // D5
     glVertex2f(-2.60f, -0.05f); // E5
     glVertex2f(-2.64f, 0.06f); // F5
     glVertex2f(-2.74f, 0.05f); // G5
     glVertex2f(-2.81f, 0.18f); // O4

glEnd();

//Pant


glColor3f(0.0f, 0.0f, 0.0f);

     glBegin(GL_POLYGON);
     glVertex2f(-3.26f, 0.10f); // T4
     glVertex2f(-3.32f, -0.34f); // I5
     glVertex2f(-3.42f, -0.45f); // H5
     glVertex2f(-3.28f, -0.58f); // M5
     glVertex2f(-3.04f, -0.26f); // L5
     glVertex2f(-2.93f, -0.57f); // K5
     glVertex2f(-2.75f, -0.49f); // J5
     glVertex2f(-2.83f, 0.10f); // R4

glEnd();


//Left Shoe

glColor3f(1.0f, 1.0f, 1.0f);

     glBegin(GL_POLYGON);
     glVertex2f(-3.42f, -0.45f); // H5
     glVertex2f(-3.48f, -0.52f); // N5
     glVertex2f(-3.34f, -0.72f); // o5
     glVertex2f(-3.22f, -0.67f); // p5
     glVertex2f(-3.28f, -0.58f); // M5

glEnd();



//Right Shoe

glColor3f(1.0f, 1.0f, 1.0f);

     glBegin(GL_POLYGON);
     glVertex2f(-2.93f, -0.57f); // K5
     glVertex2f(-2.89f, -0.70f); // Q5
     glVertex2f(-2.62f, -0.62f); // R5
     glVertex2f(-2.62f, -0.52f); // H2
     glVertex2f(-2.75f, -0.49f); // J5

glEnd();


//Rain draw

if (rain) {
    glColor3f(1.0f, 1.0f, 1.0f);

    for (float rain_width = -7; rain_width < 7; rain_width += 0.2) {

        for (float rain_length = -5; rain_length < 5; rain_length += 0.5) {
            glBegin(GL_LINES);
            glVertex2f(rain_width, rain_length);
            glVertex2f(rain_width + 0.05, rain_length - 0.2);
            glEnd();
        }
    }
}


glPopMatrix();

glColor3f(1.0f, 1.0f, 1.0f);
drawText1(4.8f, 3.6f, "Level - 1");


glFlush();
glutSwapBuffers();


}



//Alvi Display

void display2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glBegin(GL_POLYGON);

    glVertex2f(-6, 0);
    glVertex2f(-6, -2);
    glVertex2f(-4.78, -3.01);
    glVertex2f(-3, -2.58);
    glVertex2f(-1, -3);
    glVertex2f(1.4, -2.39);
    glVertex2f(5, -3);
    glVertex2f(6.02, -2.62);
    glVertex2f(6, 0);

    glEnd();


    glBegin(GL_POLYGON);                         // Polygon-20 purple shading

    glColor3f(0.16f, 0.10f, 0.40f);
    glVertex2f(-6, 0);

    glColor3f(0.16f, 0.10f, 0.40f);
    glVertex2f(-6, -2);

    glColor3f(0.22f, 0.14f, 0.50f);
    glVertex2f(-4.78, -3.01);

    glColor3f(0.22f, 0.14f, 0.50f);
    glVertex2f(-3, -2.58);

    glColor3f(0.26f, 0.17f, 0.55f);
    glVertex2f(-1, -3);

    glColor3f(0.30f, 0.20f, 0.60f);
    glVertex2f(1.4, -2.39);

    glColor3f(0.30f, 0.20f, 0.60f);
    glVertex2f(5, -3);

    glColor3f(0.30f, 0.20f, 0.60f);
    glVertex2f(6.02, -2.62);

    glColor3f(0.30f, 0.20f, 0.60f);
    glVertex2f(6, 0);

    glEnd();

    glBegin(GL_POLYGON);   // Polygon 21 (soft elegant gradient)

    glColor3f(0.08f, 0.20f, 0.50f);
    glVertex2f(-6, 1.23);

    glColor3f(0.08f, 0.20f, 0.50f);
    glVertex2f(6.01, 1.25);

    glColor3f(0.14f, 0.28f, 0.60f);
    glVertex2f(6, 0);

    glColor3f(0.14f, 0.28f, 0.60f);
    glVertex2f(-6, 0);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3f(0.05f, 0.02f, 0.20f);
    glVertex2f(-6, 4);

    glColor3f(0.05f, 0.02f, 0.20f);
    glVertex2f(6, 4);

    glColor3f(0.25f, 0.15f, 0.45f);
    glVertex2f(6.01, 1.25);

    glColor3f(0.25f, 0.15, 0.45f);
    glVertex2f(-6, 1.23);

    glEnd();


    float radiusX1Left = 0.36f;                      //Portal (Ellipse left)
    float radiusY1Left = 0.86f;
    float centerX1Left = -4.98f;
    float centerY1Left = -0.2f;

    glColor3f(0.20f, 0.60f, 0.90f);

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float angle = i * 3.1416f / 180.0f;

        float x = centerX1Left + radiusX1Left * cos(angle);
        float y = centerY1Left + radiusY1Left * sin(angle);

        glVertex2f(x, y);
    }
    glEnd();


    float radiusX2Right = 0.36f;                        //Portal (Ellipse right)
    float radiusY2Right = 0.82f;
    float centerX2Right = 4.87f;
    float centerY2Right = -0.2f;

    glColor3f(0.20f, 0.60f, 0.90f);

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float angle = i * 3.1416f / 180.0f;

        float x = centerX2Right + radiusX2Right * cos(angle);
        float y = centerY2Right + radiusY2Right * sin(angle);

        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.35f, 0.75f, 0.25f);             //polygon 0

    glVertex2f(-6,-1.04);
    glVertex2f(-6,-1.52);
    glVertex2f(-3.88,-1.52);
    glVertex2f(-3.89,-1.03);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.55f, 0.27f, 0.07f);                           //polygon 1

    glVertex2f(-6,-1.52);
    glVertex2f(-6,-1.68);
    glVertex2f(-5.66,-1.69);
    glVertex2f(-5.66,-1.83);
    glVertex2f(-5.5,-1.83);
    glVertex2f(-5.49,-2.04);
    glVertex2f(-5.08,-2.05);
    glVertex2f(-4.92,-2.31);
    glVertex2f(-4.78,-2.3);
    glVertex2f(-4.77,-2.38);
    glVertex2f(-4.62,-2.49);
    glVertex2f(-4.42,-2.26);
    glVertex2f(-4.28,-2.3);
    glVertex2f(-4.17,-2.2);
    glVertex2f(-4,-2);
    glVertex2f(-4,-1.89);
    glVertex2f(-3.91,-1.84);
    glVertex2f(-3.92,-1.64);
    glVertex2f(-3.89,-1.52);

    glEnd();

    glBegin(GL_POLYGON);                            //polygon 3

    glColor3f(0.35f, 0.75f, 0.25f);

    glVertex2f(-4,-0.5);
    glVertex2f(-4,-0.64);
    glVertex2f(-1.72,-0.63);
    glVertex2f(-1.72,-0.5);

    glEnd();

    glBegin(GL_POLYGON);                            //polygon 4

    glColor3f(0.60f, 0.32f, 0.10f);

    glVertex2f(-4,-0.64);
    glVertex2f(-4,-0.78);
    glVertex2f(-3.79,-0.78);
    glVertex2f(-3.79,-0.84);
    glVertex2f(-3.56,-1);
    glVertex2f(-3.44,-0.93);
    glVertex2f(-3.24,-1.26);
    glVertex2f(-3.14,-1.17);
    glVertex2f(-2.92,-1.51);
    glVertex2f(-2.72,-1.24);
    glVertex2f(-2.64,-1.32);
    glVertex2f(-2.37,-1);
    glVertex2f(-2.28,-1.05);
    glVertex2f(-1.94,-0.82);
    glVertex2f(-1.94,-0.76);
    glVertex2f(-1.72,-0.76);
    glVertex2f(-1.72,-0.63);

    glEnd();

  if(playerVisible)
{
    glPushMatrix();
    glTranslatef(moveX, moveY, 0.0f);

    // Human

    glBegin(GL_POLYGON);                                    //Hair

    glColor3f(0.40f, 0.20f, 0.10f);

    glVertex2f(-3.88,0.69);
    glVertex2f(-3.88,0.36);
    glVertex2f(-3.8,0.33);
    glVertex2f(-3.8,0.52);
    glVertex2f(-3.6,0.6);
    glVertex2f(-3.48,0.65);
    glVertex2f(-3.55,0.72);

    glEnd();

    glBegin(GL_POLYGON);                                    //Face

    glColor3f(0.95f, 0.80f, 0.65f);

    glVertex2f(-3.8, 0.52);
    glVertex2f(-3.8, 0.33);
    glVertex2f(-3.6, 0.28);
    glVertex2f(-3.52, 0.44);
    glVertex2f(-3.6, 0.6);

    glEnd();

    glBegin(GL_POLYGON);                                //Neck

    glColor3f(0.90f, 0.75f, 0.60f);

    glVertex2f(-3.76, 0.32);
    glVertex2f(-3.76, 0.2);
    glVertex2f(-3.6, 0.2);
    glVertex2f(-3.6, 0.28);

    glEnd();

    glBegin(GL_POLYGON);                                //Body

    glColor3f(0.95f, 0.90f, 0.60f);

    glVertex2f(-3.92, 0.2);
    glVertex2f(-4.05, -0.11);
    glVertex2f(-3.92, -0.12);
    glVertex2f(-3.84, 0.09);
    glVertex2f(-3.84, -0.2);
    glVertex2f(-3.48, -0.2);
    glVertex2f(-3.48, 0.08);
    glVertex2f(-3.4, -0.12);
    glVertex2f(-3.28, -0.12);
    glVertex2f(-3.44, 0.2);

    glEnd();

    glBegin(GL_POLYGON);                                //Left hand

    glColor3f(0.95f, 0.80f, 0.65f);

    glVertex2f(-4, -0.12);
    glVertex2f(-4.02, -0.16);
    glVertex2f(-3.92, -0.18);
    glVertex2f(-3.92, -0.12);

    glEnd();

    glBegin(GL_POLYGON);                            //Pant

    glColor3f(0.20f, 0.40f, 0.80f);

    glVertex2f(-3.84, -0.2);
    glVertex2f(-3.84, -0.44);
    glVertex2f(-3.68, -0.44);
    glVertex2f(-3.68, -0.28);
    glVertex2f(-3.6, -0.28);
    glVertex2f(-3.6, -0.44);
    glVertex2f(-3.48, -0.44);
    glVertex2f(-3.48, -0.2);

    glEnd();

    glBegin(GL_POLYGON);                            //left leg

    glColor3f(0.20f, 0.40f, 0.80f);

    glVertex2f(-3.8, -0.44);
    glVertex2f(-3.82, -0.5);
    glVertex2f(-3.68, -0.5);
    glVertex2f(-3.72, -0.44);

    glEnd();

    glBegin(GL_POLYGON);                            //Right leg

    glColor3f(0.20f, 0.40f, 0.80f);

    glVertex2f(-3.58, -0.44);
    glVertex2f(-3.6, -0.5);
    glVertex2f(-3.48, -0.5);
    glVertex2f(-3.51, -0.44);

    glEnd();

    glBegin(GL_POLYGON);                            //Right hand

    glColor3f(0.95f, 0.80f, 0.65f);

    glVertex2f(-3.38, -0.12);
    glVertex2f(-3.39, -0.18);
    glVertex2f(-3.29, -0.18);
    glVertex2f(-3.3, -0.12);

    glEnd();

    //  human finish
   glPopMatrix();

}

    if(coin10)
{
    float centerX1 = -2.84;
    float centerY1 = -0.27;
    float radius1 = 0.23;

    glBegin(GL_POLYGON);

    glColor3f(1.00f, 0.84f, 0.00f);

    for (int degree1 = 0; degree1 <360; degree1 ++)
    {
        float radian1 = degree1 * 3.1416/180;

        float X1 = centerX1 + radius1 * cos(radian1);
        float Y1 = centerY1 + radius1 * sin(radian1);

        glVertex2f(X1 , Y1);
    }

    glEnd();
}



    if(coin11)
{

    float centerX2 = -2.28;                                      //Circle 2 - C2
    float centerY2 = -0.26;
    float radius2 = 0.23;

    glBegin(GL_POLYGON);

    glColor3f(1.00f, 0.84f, 0.00f);

    for (int degree2 = 0; degree2 <360; degree2 ++)
    {
        float radian2 = degree2 * 3.1416/180;

        float X2 = centerX2 + radius2 * cos(radian2);
        float Y2 = centerY2 + radius2 * sin(radian2);

        glVertex2f(X2 , Y2);
    }

    glEnd();
}


                                //DDA Algorithm use

    float x1 = -1, y1 = -0.5;
    float x2 = 2.38, y2 = -0.52;

    float dx = x2 - x1;
    float dy = y2 - y1;

    float m = dy / dx;

    float x = x1;
    float y = y1;

    glPointSize(5);

    glBegin(GL_POINTS);

    glColor3f(0.35f, 0.75f, 0.25f);

    if (fabs(m) < 1)
    {
        while (x <= x2)
        {
            glVertex2f(x, y);

            x = x + 0.01;       // Move a little to the right. Why 0.01? Because your coordinate system is large (-6 to 6)
            y = y + m * 0.01;
        }
    }
    else
    {
        while (y <= y2)
        {
            glVertex2f(x, y);

            y = y + 0.01;
            x = x + (1/m) * 0.01;
        }
    }

    glEnd();



    glBegin(GL_POLYGON);                            //polygon 14

    glColor3f(0.35f, 0.75f, 0.25f);

    glVertex2f(-1,-0.5);
    glVertex2f(-1.02,-0.63);
    glVertex2f(2.38,-0.64);
    glVertex2f(2.38,-0.52);

    glEnd();


    glBegin(GL_POLYGON);                                //polygon 15

    glColor3f(0.55f, 0.27f, 0.07f);

    glVertex2f(-1.02, -0.63);
    glVertex2f(-1.0, -0.75);
    glVertex2f(-0.89, -0.76);
    glVertex2f(-0.89, -0.79);
    glVertex2f(-0.56, -1.0);
    glVertex2f(-0.4, -0.91);
    glVertex2f(-0.13, -1.2);
    glVertex2f(-0.04, -1.13);
    glVertex2f(0.2, -1.55);
    glVertex2f(0.45, -1.36);
    glVertex2f(0.69, -1.64);
    glVertex2f(1.03, -1.21);
    glVertex2f(1.07, -1.27);
    glVertex2f(1.32, -1.08);
    glVertex2f(1.45, -1.17);
    glVertex2f(1.84, -0.93);
    glVertex2f(1.91, -1.0);
    glVertex2f(2.28, -0.83);
    glVertex2f(2.29, -0.76);
    glVertex2f(2.38, -0.75);
    glVertex2f(2.38, -0.64);

    glEnd();




    glBegin(GL_POLYGON);                                  // Polygon 16 (Fire)

    glColor3f(1.0f, 0.3f, 0.0f);
    glVertex2f(1.72, -0.5);

    glColor3f(1.0f, 0.3f, 0.0f);
    glVertex2f(1.72, -0.32);


    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(1.84, -0.32);

    glColor3f(1.0f, 0.6f, 0.0f);
    glVertex2f(1.84, -0.24);


    glColor3f(1.0f, 0.7f, 0.0f);
    glVertex2f(1.96, -0.24);


    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(2.0, 0.0);


    glColor3f(1.0f, 0.7f, 0.0f);
    glVertex2f(2.08, -0.24);

    glColor3f(1.0f, 0.6f, 0.0f);
    glVertex2f(2.16, -0.24);

    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(2.16, -0.35);

    glColor3f(1.0f, 0.4f, 0.0f);
    glVertex2f(2.28, -0.36);

    glColor3f(1.0f, 0.3f, 0.0f);
    glVertex2f(2.28, -0.4);

    glColor3f(0.9f, 0.2f, 0.0f);
    glVertex2f(2.29, -0.51);

    glEnd();



    if(coin14)
{

    float centerX5 = 1.23;                                      //Circle 5 - C5
    float centerY5 = -0.26;
    float radius5 = 0.24;

    glBegin(GL_POLYGON);

    glColor3f(1.00f, 0.84f, 0.00f);

    for (int degree5 = 0; degree5 <360; degree5 ++)
    {
        float radian5 = degree5 * 3.1416/180;

        float X5 = centerX5 + radius5 * cos(radian5);
        float Y5 = centerY5 + radius5 * sin(radian5);

        glVertex2f(X5 , Y5);
    }

    glEnd();
}


    if(coin15)
{
    float centerX6 = 0.64;                                      //Circle 6 - C6
    float centerY6 = -0.26;
    float radius6 = 0.24;

    glBegin(GL_POLYGON);

    glColor3f(1.00f, 0.84f, 0.00f);

    for (int degree6 = 0; degree6 <360; degree6 ++)
    {
        float radian6 = degree6 * 3.1416/180;

        float X6 = centerX6 + radius6 * cos(radian6);
        float Y6 = centerY6+ radius6 * sin(radian6);

        glVertex2f(X6 , Y6);
    }

    glEnd();
}


    if(coin16)
{
    float centerX7 = 0.08;                                      //Circle 7 - C7
    float centerY7 = -0.26;
    float radius7 = 0.24;

    glBegin(GL_POLYGON);

    glColor3f(1.00f, 0.84f, 0.00f);

    for (int degree7 = 0; degree7 <360; degree7 ++)
    {
        float radian7 = degree7 * 3.1416/180;

        float X7 = centerX7 + radius7 * cos(radian7);
        float Y7 = centerY7 + radius7 * sin(radian7);

        glVertex2f(X7 , Y7);
    }

    glEnd();
}




    glBegin(GL_POLYGON);                        //Polygon - 17

    glColor3f(0.35f, 0.75f, 0.25f);

   // glVertex2f(4.16, -1.3);
    glVertex2f(2.6, -1);
    glVertex2f(2.61, -1.49);
    glVertex2f(6.0, -1.5);
    glVertex2f(6.0, -1.0);
    glVertex2f(4.15, -1.0);


    glEnd();


    glBegin(GL_POLYGON);                        //Polygon - 18

    glColor3f(0.55f, 0.27f, 0.07f);

    glVertex2f(2.61, -1.49);
    glVertex2f(2.61, -1.7);
    glVertex2f(3.21, -1.99);
    glVertex2f(3.32, -1.77);
    glVertex2f(3.76, -2.25);
    glVertex2f(3.9, -2.09);
    glVertex2f(4.31, -2.6);
    glVertex2f(4.6, -2.19);
    glVertex2f(4.68, -2.28);
    glVertex2f(4.91, -1.93);
    glVertex2f(5.17, -2.09);
    glVertex2f(5.49, -1.8);
    glVertex2f(5.49, -1.66);
    glVertex2f(6.0, -1.66);
    glVertex2f(6.0, -1.5);

    glEnd();


    if(coin12)
{
    float centerX3 = 3.28;                                      //Circle 3 - C3
    float centerY3 = -0.77;
    float radius3 = 0.23;

    glBegin(GL_POLYGON);

    glColor3f(1.00f, 0.84f, 0.00f);

    for (int degree3 = 0; degree3 <360; degree3 ++)
    {
        float radian3 = degree3 * 3.1416/180;

        float X3 = centerX3 + radius3 * cos(radian3);
        float Y3 = centerY3 + radius3 * sin(radian3);

        glVertex2f(X3 , Y3);
    }

    glEnd();
}

    if(coin13)
{
    float centerX4 = 3.84;                                      //Circle 4 - C4
    float centerY4 = -0.77;
    float radius4 = 0.23;

    glBegin(GL_POLYGON);

    glColor3f(1.00f, 0.84f, 0.00f);

    for (int degree4 = 0; degree4 <360; degree4 ++)
    {
        float radian4 = degree4 * 3.1416/180;

        float X4 = centerX4 + radius4 * cos(radian4);
        float Y4 = centerY4 + radius4 * sin(radian4);

        glVertex2f(X4 , Y4);
    }

    glEnd();
}



        glBegin(GL_POLYGON);                        // Polygon 19 - Ocean Water


        glColor3f(0.12f, 0.42f, 0.65f);
        glVertex2f(-4.78, -3.01);


        glColor3f(0.05f, 0.30f, 0.55f);
        glVertex2f(-6.0, -2.0);

        glColor3f(0.05f, 0.30f, 0.55f);
        glVertex2f(-6.0, -4.0);


        glColor3f(0.40f, 0.80f, 0.95f);
        glVertex2f(6.0, -4.0);

        glColor3f(0.40f, 0.80f, 0.95f);
        glVertex2f(6.02, -2.62);


        glColor3f(0.35f, 0.70f, 0.88f);
        glVertex2f(5.0, -3.0);


        glColor3f(0.28f, 0.60f, 0.82f);
        glVertex2f(1.4, -2.39);


        glColor3f(0.18f, 0.50f, 0.75f);
        glVertex2f(-1.0, -3.0);


        glColor3f(0.15f, 0.45f, 0.68f);
        glVertex2f(-3.0, -2.58);

        glEnd();

glColor3f(1.0f, 1.0f, 1.0f);

drawText2(4.8f, 3.6f, "Level - 2");


glFlush();
glutSwapBuffers();
}





//Shithil Display

void display3() {

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 1);

    glLoadIdentity();

    //sky
    glBegin(GL_POLYGON);
    glColor3f(0.25f, 0.30f, 0.45f);
    glVertex2f(-6.0, 0.8);
    glColor3f(0.25f, 0.30f, 0.45f);
    glVertex2f(6.0, 0.8);
    glColor3f(0.02f, 0.02f, 0.05f);
    glVertex2f(6.0, 4.0);
    glColor3f(0.02f, 0.02f, 0.05f);
    glVertex2f(-6.0, 4.0);
    glEnd();

    //text
    glColor3f(1.0, 1.0, 1.0);
    drawText3(-1.0, 3.5, "Lost in Dimension");

    glColor3f(1.0, 1.0, 1.0);
    drawText3(3.5, 2.75, "Level 3");



    //stars

    //glPointSize(2.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-5.0f, 3.5f);
    glVertex2f(-3.0f, 3.8f);
    glVertex2f(0.0f, 3.6f);
    glVertex2f(2.0f, 3.9f);
    glVertex2f(4.0f, 3.7f);
    glVertex2f(-4.0f, 3.2f);
    glVertex2f(-2.0f, 3.4f);
    glVertex2f(1.0f, 3.3f);
    glVertex2f(3.0f, 3.8f);
    glVertex2f(5.0f, 3.6f);
    glVertex2f(-5.0f, 3.0f);
    glVertex2f(-1.0f, 3.1f);
    glVertex2f(0.0f, 3.0f);
    glVertex2f(2.0f, 3.2f);
    glVertex2f(4.0f, 3.4f);
    glVertex2f(-4.0f, 2.8f);
    glVertex2f(-3.0f, 2.9f);
    glVertex2f(1.0f, 2.7f);
    glVertex2f(3.0f, 3.0f);
    glVertex2f(5.0f, 3.2f);
    glVertex2f(-5.0f, 2.5f);
    glVertex2f(-2.0f, 2.6f);
    glVertex2f(0.0f, 2.5f);
    glVertex2f(2.0f, 2.7f);
    glVertex2f(4.0f, 2.9f);
    glVertex2f(-4.0f, 2.3f);
    glVertex2f(-1.0f, 2.4f);
    glVertex2f(1.0f, 2.3f);
    glVertex2f(3.0f, 2.6f);
    glVertex2f(5.0f, 2.8f);

    glEnd();

    //middle
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.25, 0.6);
    glVertex2f(-6.0, -0.4);
    glColor3f(0.35, 0.2, 0.55);
    glVertex2f(6.0, -0.4);
    glColor3f(0.15, 0.0, 0.3);
    glVertex2f(6.0, 0.8);
    glColor3f(0.1, 0.0, 0.25);
    glVertex2f(-6.0, 0.8);
    glEnd();

    //top of water
    glBegin(GL_POLYGON);
    glColor3f(0.50, 0.00, 0.00);
    glVertex2f(-6.0, -2.32);
    glColor3f(0.80, 0.10, 0.00);
    glVertex2f(6.0, -2.32);
    glColor3f(1.00, 0.35, 0.00);
    glVertex2f(6.0, -0.39);
    glColor3f(1.00, 0.70, 0.10);
    glVertex2f(-6.0, -0.39);
    glEnd();


    //line
    float x1 = -6.00, y1 = -2.32;
    float x2 = 6.00, y2 = -2.32;

    float dxm = x2 - x1;
    float dym = y2 - y1;

    float m = dym / dxm;

    float xm = x1;
    float ym = y1;

    //glPointSize(5);

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);


    float dstart = (2 * dym) - dxm;
    float dnewNE = (2 * dym) - (2 * dxm);
    float dnewE = (2 * dym);
    while (xm <= x2 && ym <= y2)
    {
        glVertex2f(xm, ym);

        if (dstart < 0)
        {
            dstart += dnewE;
            xm = xm + 1;
        }
        else
        {
            dstart += dnewNE;
            xm = xm + 1;
            ym = ym + 1;

        }
    }

    glEnd();

    //bottom water
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.3);
    glVertex2f(-6.0, -4.0);
    glColor3f(0.0, 0.0, 0.4);
    glVertex2f(6.0, -4.0);
    glColor3f(0.0, 0.4, 0.7);
    glVertex2f(6.0, -2.32);
    glColor3f(0.2, 0.6, 0.9);
    glVertex2f(-6.0, -2.32);
    glEnd();


    //middle block
    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.45, 0.25);
    glVertex2f(-1.03, -0.89);
    glVertex2f(2.52, -0.91);
    glVertex2f(2.52, -0.74);
    glVertex2f(0.98, -0.73);
    glVertex2f(0.73, -0.67);
    glVertex2f(0.48, -0.73);
    glVertex2f(-0.06, -0.74);
    glVertex2f(-0.3, -0.64);
    glVertex2f(-0.59, -0.73);
    glVertex2f(-1.03, -0.73);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.2f, 0.05f);
    glVertex2f(-1.03, -1.02);
    glVertex2f(-0.87, -1.03);
    glVertex2f(-0.57, -1.25);
    glVertex2f(-0.42, -1.17);
    glVertex2f(-0.13, -1.44);
    glVertex2f(-0.02, -1.37);
    glVertex2f(0.23, -1.82);
    glVertex2f(0.45, -1.63);
    glVertex2f(0.68, -1.9);
    glVertex2f(1.02, -1.47);
    glVertex2f(1.06, -1.51);
    glVertex2f(1.28, -1.32);
    glVertex2f(1.45, -1.44);
    glVertex2f(1.83, -1.2);
    glVertex2f(1.91, -1.25);
    glVertex2f(2.24, -1.09);
    glVertex2f(2.25, -1.04);
    glVertex2f(2.52, -1.02);
    glVertex2f(2.52, -0.91);
    glVertex2f(-1.03, -0.89);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.5f, 0.15f);
    glVertex2f(-0.49f, -1.12f);
    glVertex2f(-0.41f, -1.14f);
    glVertex2f(-0.25f, -1.33f);
    glVertex2f(-0.14f, -1.27f);
    glVertex2f(-0.14f, -0.98f);
    glVertex2f(-0.49f, -0.98f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.5f, 0.15f);
    glVertex2f(0.02f, -0.97f);
    glVertex2f(0.02f, -1.23f);
    glVertex2f(0.18f, -1.6f);
    glVertex2f(0.35f, -1.44f);
    glVertex2f(0.38f, -1.2f);
    glVertex2f(0.48f, -1.2f);
    glVertex2f(0.49f, -0.97f);
    glEnd();

    //left block
    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.45, 0.25);
    glVertex2f(-4.0, -0.90);
    glVertex2f(-1.72, -0.89);
    glVertex2f(-1.73, -0.74);
    glVertex2f(-2.75, -0.72);
    glVertex2f(-2.92, -0.70);
    glVertex2f(-3.11, -0.73);
    glVertex2f(-3.37, -0.69);
    glVertex2f(-3.55, -0.73);
    glVertex2f(-4.0, -0.74);
    // glVertex2f(-1.03, -0.73);
    glEnd();

    //fire
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.3f, 0.0f);
    glVertex2f(-3.07, -0.39);
    glColor3f(1.0f, 0.3f, 0.0f);
    glVertex2f(-3.0, -0.7);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(-2.75, -0.72);
    glColor3f(1.0f, 0.6f, 0.0f);
    glVertex2f(-2.63, -0.52);
    glColor3f(1.0f, 0.7f, 0.0f);
    glVertex2f(-2.62, -0.37);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-2.69, -0.44);
    glColor3f(1.0f, 0.7f, 0.0f);
    glVertex2f(-2.68, -0.28);
    glColor3f(1.0f, 0.6f, 0.0f);
    glVertex2f(-2.77, -0.17);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(-2.82, -0.3);
    glColor3f(1.0f, 0.7f, 0.0f);
    glVertex2f(-2.94, -0.14);
    glColor3f(1.0f, 0.6f, 0.0f);
    glVertex2f(-2.99, -0.3);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(-2.99, -0.47);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.2f, 0.05f);
    glVertex2f(-4.0, -1.01);
    glVertex2f(-3.81, -1.02);
    glVertex2f(-3.80, -1.08);
    glVertex2f(-3.56, -1.26);
    glVertex2f(-3.45, -1.19);
    glVertex2f(-3.37, -1.28);
    glVertex2f(-3.25, -1.52);
    glVertex2f(-3.16, -1.44);
    glVertex2f(-2.94, -1.77);
    glVertex2f(-2.88, -1.77);
    glVertex2f(-2.7, -1.5);
    glVertex2f(-2.63, -1.59);
    glVertex2f(-2.36, -1.24);
    glVertex2f(-2.27, -1.33);
    glVertex2f(-1.72, -1.0);
    glVertex2f(-1.72, -0.89);
    glVertex2f(-4, -0.9);
    //glVertex2f(2.52, -1.02);
    //glVertex2f(2.52, -0.91);
    //glVertex2f(-1.03, -0.89);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.5f, 0.15f);
    glVertex2f(-3.09, -1.25);
    glVertex2f(-2.92, -1.6);
    glVertex2f(-2.74, -1.30);
    glVertex2f(-2.75, -0.96);
    glVertex2f(-3.08, -0.97);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.5f, 0.15f);
    glVertex2f(-2.56, -1.24);
    glVertex2f(-2.44, -1.34);
    glVertex2f(-2.32, -1.19);
    glVertex2f(-2.32, -0.98);
    glVertex2f(-2.56, -0.98);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.5f, 0.15f);
    glVertex2f(-2.21, -1.13);
    glVertex2f(-2.17, -1.17);
    glVertex2f(-2.13, -1.15);
    glVertex2f(-2.02, -1.11);
    glVertex2f(-2.02, -0.98);
    glVertex2f(-2.21, -0.98);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.5f, 0.15f);
    glVertex2f(-3.45, -1.19);
    glVertex2f(-3.29, -1.39);
    glVertex2f(-3.23, -1.35);
    glVertex2f(-3.26, -0.96);
    glVertex2f(-3.45, -0.98);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.5f, 0.15f);
    glVertex2f(-3.8, -1.08);
    glVertex2f(-3.58, -1.17);
    glVertex2f(-3.58, -0.92);
    glVertex2f(-3.8, -0.95);
    glEnd();

    //right block
    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.45, 0.25);
    glVertex2f(2.6, -1.46);
    glVertex2f(4.29, -1.48);
    glVertex2f(4.3, -1.31);
    glVertex2f(4.05, -1.25);
    glVertex2f(3.9, -1.3);
    glVertex2f(3.56, -1.3);
    glVertex2f(3.42, -1.23);
    glVertex2f(3.27, -1.31);
    glVertex2f(2.56, -1.31);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.2f, 0.05f);
    glVertex2f(3.25, -2.08);
    glVertex2f(3.35, -2.01);
    glVertex2f(3.52, -2.26);
    glVertex2f(3.73, -1.97);
    glVertex2f(3.77, -2.00);
    glVertex2f(3.87, -1.88);
    glVertex2f(3.87, -1.75);
    glVertex2f(3.97, -1.54);
    glVertex2f(4.07, -1.54);
    glVertex2f(4.09, -1.48);
    glVertex2f(2.6, -1.46);
    glVertex2f(2.7, -1.63);
    glVertex2f(2.7, -1.75);
    glVertex2f(2.93, -1.89);
    glVertex2f(3.03, -1.75);
    glEnd();


    //right most block
    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.45, 0.25);
    glVertex2f(3.87, -1.75);
    glVertex2f(6.0, -1.74);
    glVertex2f(6.0, -1.55);
    glVertex2f(3.97, -1.54);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.15, 0.25, 0.10);
    glVertex2f(3.87, -1.92);
    glVertex2f(6.0, -1.93);
    glVertex2f(6.0, -1.74);
    glVertex2f(3.87, -1.75);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.2f, 0.05f);
    glVertex2f(3.92, -2.08);
    glVertex2f(4.09, -2.31);
    glVertex2f(4.33, -2.35);
    glVertex2f(4.45, -2.55);
    glVertex2f(4.51, -2.62);
    glVertex2f(4.6, -2.65);
    glVertex2f(4.72, -2.83);
    glVertex2f(5.00, -2.51);
    glVertex2f(5.1, -2.57);
    glVertex2f(5.19, -2.55);
    glVertex2f(5.37, -2.37);
    glVertex2f(5.51, -2.34);
    glVertex2f(5.61, -2.26);
    glVertex2f(5.61, -2.11);
    glVertex2f(6.0, -2.1);
    glVertex2f(6.0, -1.93);
    glVertex2f(3.92, -1.92);
    glEnd();


    //left most block
    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.45, 0.25);
    glVertex2f(-5.99, -1.74);
    glVertex2f(-3.88, -1.74);
    glVertex2f(-3.88, -1.55);
    glVertex2f(-5.99, -1.55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.15, 0.25, 0.10);
    glVertex2f(-6.0, -1.91);
    glVertex2f(-3.88, -1.91);
    glVertex2f(-3.88, -1.74);
    glVertex2f(-5.99, -1.74);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.2f, 0.05f);
    glVertex2f(-5.98, -2.13);
    glVertex2f(-5.62, -2.12);
    glVertex2f(-5.61, -2.26);
    glVertex2f(-5.33, -2.39);
    glVertex2f(-5.2, -2.36);
    glVertex2f(-5.09, -2.55);
    glVertex2f(-4.91, -2.71);
    glVertex2f(-4.81, -2.67);
    glVertex2f(-4.63, -2.88);
    glVertex2f(-4.41, -2.61);
    glVertex2f(-4.25, -2.64);
    glVertex2f(-4.18, -2.58);
    glVertex2f(-4.17, -2.36);
    glVertex2f(-3.99, -2.37);
    glVertex2f(-3.93, -2.3);
    glVertex2f(-3.98, -2.24);
    glVertex2f(-3.9, -2.14);
    glVertex2f(-3.88, -1.91);
    glVertex2f(-6.0, -1.91);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.5f, 0.15f);
    glVertex2f(-5.43, -2.22);
    glVertex2f(-5.34, -2.32);
    glVertex2f(-5.25, -2.31);
    glVertex2f(-5.16, -2.21);
    glVertex2f(-5.28, -2.07);
    glVertex2f(-5.35, -2.07);
    glVertex2f(-5.43, -2.15);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.5f, 0.15f);
    glVertex2f(-5.08, -2.32);
    glVertex2f(-4.92, -2.45);
    glVertex2f(-4.75, -2.29);
    glVertex2f(-4.95, -2.16);
    glVertex2f(-4.99, -2.04);
    glVertex2f(-5.1, -2.1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.5f, 0.15f);
    glVertex2f(-4.62, -2.28);
    glVertex2f(-4.49, -2.27);
    glVertex2f(-4.42, -2.17);
    glVertex2f(-4.45, -2.08);
    glVertex2f(-4.58, -2.11);
    glVertex2f(-4.63, -2.04);
    glVertex2f(-4.68, -2.05);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.5f, 0.15f);
    glVertex2f(-4.14, -2.26);
    glVertex2f(-3.99, -2.16);
    glVertex2f(-4.02, -2.11);
    glVertex2f(-4.02, -2.05);
    glVertex2f(-4.16, -2.05);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.5f, 0.15f);
    glVertex2f(-4.77, -2.65);
    glVertex2f(-4.56, -2.55);
    glVertex2f(-4.56, -2.55);
    glVertex2f(-4.62, -2.38);
    glVertex2f(-4.71, -2.48);
    glVertex2f(-4.84, -2.55);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.5f, 0.15f);
    glVertex2f(-4.37, -2.46);
    glVertex2f(-4.29, -2.44);
    glVertex2f(-4.22, -2.3);
    glVertex2f(-4.34, -2.19);
    glVertex2f(-4.46, -2.37);
    glEnd();


    //left pair hills
    glBegin(GL_POLYGON);
    glColor3f(0.15, 0.25, 0.10);
    glVertex2f(-4.94, 0.77);
    glVertex2f(-4.31, 0.77);
    glVertex2f(-4.31, 1.53);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.45, 0.25);
    glVertex2f(-4.31, 0.77);
    glVertex2f(-3.6, 0.77);
    glVertex2f(-4.31, 1.53);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.15, 0.25, 0.10);
    glVertex2f(-3.99, 1.19);
    glVertex2f(-3.6, 0.77);
    glVertex2f(-3.58, 2.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.45, 0.25);
    glVertex2f(-3.6, 0.77);
    glVertex2f(-2.57, 0.77);
    glVertex2f(-3.6, 2.0);
    glEnd();



    //middle three hills


    glBegin(GL_POLYGON);
    glColor3f(0.12, 0.15, 0.20);
    //glColor3f(0.20, 0.05, 0.05);
    glVertex2f(-2.57, 0.78);
    glVertex2f(-2.09, 0.78);
    glVertex2f(-2.09, 1.71);
    glVertex2f(-2.69, 0.94);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.40, 0.45);
    //glColor3f(0.45, 0.20, 0.18);
    glVertex2f(-2.09, 0.78);
    glVertex2f(-1.23, 0.78);
    glVertex2f(-2.09, 1.71);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3f(0.20, 0.05, 0.05);
    glColor3f(0.12, 0.15, 0.20);
    glVertex2f(-1.23, 0.78);
    glVertex2f(-0.95, 0.78);
    glVertex2f(-1.2, 2.2);
    glVertex2f(-1.78, 1.34);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3f(0.45, 0.20, 0.18);
    glColor3f(0.35, 0.40, 0.45);
    glVertex2f(-0.95, 0.78);
    glVertex2f(-0.2, 0.78);
    glVertex2f(-1.2, 2.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.12, 0.15, 0.20);
    glVertex2f(-0.68, 1.46);
    glVertex2f(-0.2, 0.78);
    glVertex2f(-0.35, 1.96);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.35, 0.40, 0.45);
    glVertex2f(-0.2, 0.78);
    glVertex2f(0.56, 0.78);
    glVertex2f(-0.35, 1.96);
    glEnd();


    //right three hills
    glBegin(GL_POLYGON);
    glColor3f(0.18, 0.12, 0.15);
    glVertex2f(0.56, 0.78);
    glVertex2f(1.11, 0.78);
    glVertex2f(1.1, 1.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.40, 0.30, 0.35);
    glVertex2f(1.11, 0.78);
    glVertex2f(1.73, 0.78);
    glVertex2f(1.81, 0.95);
    glVertex2f(1.1, 1.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.18, 0.12, 0.15);
    glVertex2f(1.73, 0.78);
    glVertex2f(2.16, 0.78);
    glVertex2f(2.31, 1.67);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.40, 0.30, 0.35);
    glVertex2f(2.16, 0.78);
    glVertex2f(3.03, 0.78);
    glVertex2f(2.31, 1.67);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.18, 0.12, 0.15);
    glVertex2f(3.03, 0.78);
    glVertex2f(3.35, 0.78);
    glVertex2f(3.17, 1.74);
    glVertex2f(2.71, 1.18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.40, 0.30, 0.35);
    glVertex2f(3.35, 0.78);
    glVertex2f(4.0, 0.78);
    glVertex2f(3.17, 1.74);
    glEnd();

    //moon
    /*
    float radius = 0.6;
    float centerX = -2.78;
    float centerY = 2.58;
    glColor3f(1.0, 1.0, 1.39);

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.1416 / 180.0;

        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);

        glVertex2f(x, y);
    }
    glEnd();
    */


    float radius = 0.6;
    float centerX = -2.78;
    float centerY = 2.58;

    glBegin(GL_POLYGON);

    glColor3f(1.0, 1.0, 0.85);
    glVertex2f(centerX, centerY);

    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.1416 / 180.0;

        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);

        glColor3f(0.75, 0.75, 0.65);
        glVertex2f(x, y);
    }

    glEnd();


    //coins

    float radiusCoin = 0.23;

    if (coin1) {


        float centerXCoin1 = -3.42;
        float centerYCoin1 = -0.48;

        glBegin(GL_POLYGON);

        glColor3f(1.0, 0.84, 0.2);
        glVertex2f(centerXCoin1, centerYCoin1);

        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.1416 / 180.0;

            float x = centerXCoin1 + radiusCoin * cos(angle);
            float y = centerYCoin1 + radiusCoin * sin(angle);

            glColor3f(0.8, 0.6, 0.1);
            glVertex2f(x, y);
        }

        glEnd();
    }


    if (coin2) {

        float centerXCoin2 = 1.94;
        float centerYCoin2 = -0.48;

        glBegin(GL_POLYGON);

        glColor3f(1.0, 0.84, 0.2);
        glVertex2f(centerXCoin2, centerYCoin2);

        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.1416 / 180.0;

            float x = centerXCoin2 + radiusCoin * cos(angle);
            float y = centerYCoin2 + radiusCoin * sin(angle);

            glColor3f(0.8, 0.6, 0.1);
            glVertex2f(x, y);
        }

        glEnd();
    }

    if (coin3) {
        float centerXCoin3 = -2.3;
        float centerYCoin3 = -0.48;

        glBegin(GL_POLYGON);

        glColor3f(1.0, 0.84, 0.2);
        glVertex2f(centerXCoin3, centerYCoin3);

        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.1416 / 180.0;

            float x = centerXCoin3 + radiusCoin * cos(angle);
            float y = centerYCoin3 + radiusCoin * sin(angle);

            glColor3f(0.8, 0.6, 0.1);
            glVertex2f(x, y);
        }

        glEnd();

    }



    if (coin4) {
        float centerXCoin4 = -0.55;
        float centerYCoin4 = -0.48;

        glBegin(GL_POLYGON);

        glColor3f(1.0, 0.84, 0.2);
        glVertex2f(centerXCoin4, centerYCoin4);

        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.1416 / 180.0;

            float x = centerXCoin4 + radiusCoin * cos(angle);
            float y = centerYCoin4 + radiusCoin * sin(angle);

            glColor3f(0.8, 0.6, 0.1);
            glVertex2f(x, y);
        }

        glEnd();

    }


    if (coin5) {

        float centerXCoin5 = 0.03;
        float centerYCoin5 = -0.48;

        glBegin(GL_POLYGON);

        glColor3f(1.0, 0.84, 0.2);
        glVertex2f(centerXCoin5, centerYCoin5);

        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.1416 / 180.0;

            float x = centerXCoin5 + radiusCoin * cos(angle);
            float y = centerYCoin5 + radiusCoin * sin(angle);

            glColor3f(0.8, 0.6, 0.1);
            glVertex2f(x, y);
        }

        glEnd();

    }



    if (coin6) {
        float centerXCoin6 = 0.6;
        float centerYCoin6 = -0.48;

        glBegin(GL_POLYGON);

        glColor3f(1.0, 0.84, 0.2);
        glVertex2f(centerXCoin6, centerYCoin6);

        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.1416 / 180.0;

            float x = centerXCoin6 + radiusCoin * cos(angle);
            float y = centerYCoin6 + radiusCoin * sin(angle);

            glColor3f(0.8, 0.6, 0.1);
            glVertex2f(x, y);
        }

        glEnd();

    }

    if (coin7) {
        float centerXCoin7 = 1.17;
        float centerYCoin7 = -0.48;

        glBegin(GL_POLYGON);

        glColor3f(1.0, 0.84, 0.2);
        glVertex2f(centerXCoin7, centerYCoin7);

        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.1416 / 180.0;

            float x = centerXCoin7 + radiusCoin * cos(angle);
            float y = centerYCoin7 + radiusCoin * sin(angle);

            glColor3f(0.8, 0.6, 0.1);
            glVertex2f(x, y);
        }

        glEnd();

    }


    if (coin8) {
        float centerXCoin8 = 3.24;
        float centerYCoin8 = -1.08;

        glBegin(GL_POLYGON);

        glColor3f(1.0, 0.84, 0.2);
        glVertex2f(centerXCoin8, centerYCoin8);

        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.1416 / 180.0;

            float x = centerXCoin8 + radiusCoin * cos(angle);
            float y = centerYCoin8 + radiusCoin * sin(angle);

            glColor3f(0.8, 0.6, 0.1);
            glVertex2f(x, y);
        }

        glEnd();
    }

    if (coin9) {
        float centerXCoin9 = 3.78;
        float centerYCoin9 = -1.08;

        glBegin(GL_POLYGON);

        glColor3f(1.0, 0.84, 0.2);
        glVertex2f(centerXCoin9, centerYCoin9);

        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.1416 / 180.0;

            float x = centerXCoin9 + radiusCoin * cos(angle);
            float y = centerYCoin9 + radiusCoin * sin(angle);

            glColor3f(0.8, 0.6, 0.1);
            glVertex2f(x, y);
        }

        glEnd();

    }



    //portal
    float radiusX = 0.70f;
    float radiusY = 1.20f;
    float centerXPortal = 5.35f;
    float centerYPortal = -0.72f;

    // glColor3f(0.0f, 0.6f, 0.9f);
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2f(centerXPortal, centerYPortal);

    for (int i = 0; i < 360; i++) {
        float angle = i * 3.1416f / 180.0f;
        float x = centerXPortal + radiusX * cos(angle);
        float y = centerYPortal + radiusY * sin(angle);
        glColor3f(0.0f, 0.1f, 0.5f);
        glVertex2f(x, y);
    }
    glEnd();


    glPushMatrix();
    glTranslatef(txz, yz + tyz, 0.0f);
    //zombie figure
    //right hand
    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.30f, 0.20f);
    glVertex2f(1.34, 0.34);
    glVertex2f(1.39, 0.29);
    glVertex2f(1.45, 0.31);
    glVertex2f(1.51, 0.32);
    glVertex2f(1.57, 0.27);
    glVertex2f(1.71, 0.31);
    glVertex2f(1.71, 0.39);
    glVertex2f(1.63, 0.47);
    glVertex2f(1.58, 0.47);
    glVertex2f(1.55, 0.45);
    glVertex2f(1.5, 0.48);
    glVertex2f(1.4, 0.48);
    glVertex2f(1.35, 0.45);
    glEnd();

    //left hand
    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.30f, 0.20f);
    glVertex2f(0.68, 0.4);
    glVertex2f(0.75, 0.35);
    glVertex2f(0.83, 0.35);
    glVertex2f(0.88, 0.36);
    glVertex2f(1.03, 0.35);
    glVertex2f(0.93, 0.53);
    glVertex2f(0.87, 0.53);
    glVertex2f(0.8, 0.57);
    glVertex2f(0.67, 0.47);
    glEnd();

    //Head
    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.30f, 0.20f);
    glVertex2f(0.93, 0.45);
    glVertex2f(0.99, 0.37);
    glVertex2f(1.1, 0.31);
    glVertex2f(1.22, 0.31);
    glVertex2f(1.34, 0.37);
    glVertex2f(1.44, 0.46);
    glVertex2f(1.43, 0.64);
    glVertex2f(1.37, 0.75);
    glVertex2f(1.28, 0.8);
    glVertex2f(1.11, 0.8);
    glVertex2f(1.05, 0.79);
    glVertex2f(0.99, 0.75);
    glVertex2f(0.95, 0.7);
    glVertex2f(0.93, 0.65);
    glEnd();

    //eyes
    float radiusEyes = 0.05;
    float centerXEye1 = 1.04;
    float centerYEye1 = 0.55;

    glBegin(GL_POLYGON);

    glColor3f(1.0, 1.0, 0.85);
    glVertex2f(centerXEye1, centerYEye1);

    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.1416 / 180.0;

        float x = centerXEye1 + radiusEyes * cos(angle);
        float y = centerYEye1 + radiusEyes * sin(angle);

        glColor3f(0.75, 0.75, 0.65);
        glVertex2f(x, y);
    }

    glEnd();

    float centerXEye2 = 1.25;
    float centerYEye2 = 0.55;

    glBegin(GL_POLYGON);

    glColor3f(1.0, 1.0, 0.85);
    glVertex2f(centerXEye2, centerYEye2);

    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.1416 / 180.0;

        float x = centerXEye2 + radiusEyes * cos(angle);
        float y = centerYEye2 + radiusEyes * sin(angle);

        glColor3f(0.75, 0.75, 0.65);
        glVertex2f(x, y);
    }

    glEnd();

    //Mouth
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(1.08, 0.37);
    glVertex2f(1.1, 0.36);
    glVertex2f(1.12, 0.39);
    glVertex2f(1.2, 0.39);
    glVertex2f(1.21, 0.36);
    glVertex2f(1.23, 0.36);
    glVertex2f(1.22, 0.4);
    glVertex2f(1.19, 0.42);
    glVertex2f(1.11, 0.42);
    glEnd();

    //body
    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.30f, 0.20f);
    glVertex2f(1.03, 0.1);
    glVertex2f(1.18, 0.02);
    glVertex2f(1.45, 0.02);
    glVertex2f(1.45, 0.31);
    glVertex2f(1.34, 0.37);
    glVertex2f(1.22, 0.31);
    glVertex2f(1.1, 0.31);
    glVertex2f(1.03, 0.35);
    glEnd();

    //left leg
    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.30f, 0.20f);
    glVertex2f(0.93, 0.05);
    glVertex2f(1.1, -0.02);
    glVertex2f(1.16, -0.06);
    glVertex2f(1.22, -0.05);
    glVertex2f(1.24, 0.02);
    glVertex2f(1.18, 0.02);
    glVertex2f(1.03, 0.1);
    glVertex2f(0.99, 0.1);
    glVertex2f(0.95, 0.08);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.30f, 0.20f);
    glVertex2f(0.92, -0.02);
    glVertex2f(0.97, -0.13);
    glVertex2f(1.12, -0.06);
    glVertex2f(1.1, -0.02);
    glVertex2f(0.93, 0.05);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.30f, 0.20f);
    glVertex2f(1.01, -0.2);
    //glVertex2f(0.94, -0.28);
    //glVertex2f(0.96, -0.35);
    //glVertex2f(1.2, -0.24);
    glVertex2f(1.2, -0.19);
    glVertex2f(1.12, -0.06);
    glVertex2f(0.97, -0.13);
    // glVertex2f(1.01, -0.2);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.30f, 0.20f);
    //glVertex2f(1.01, -0.2);
    //glVertex2f(0.94, -0.28);
    glVertex2f(0.96, -0.35);
    glVertex2f(1.2, -0.24);
    glVertex2f(1.2, -0.19);
    //glVertex2f(1.12, -0.06);
    //glVertex2f(0.97, -0.13);
    glVertex2f(1.01, -0.2);
    glVertex2f(0.94, -0.28);

    glEnd();

    //right leg
    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.30f, 0.20f);
    glVertex2f(1.22, -0.11);
    glVertex2f(1.43, -0.05);
    glVertex2f(1.45, 0.02);
    glVertex2f(1.24, 0.02);
    glVertex2f(1.22, -0.05);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.30f, 0.20f);
    glVertex2f(1.32, -0.19);
    glVertex2f(1.43, -0.05);
    glVertex2f(1.22, -0.11);
    glVertex2f(1.26, -0.16);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.30f, 0.20f);
    glVertex2f(1.43, -0.24);
    glVertex2f(1.58, -0.12);
    glVertex2f(1.54, -0.09);
    glVertex2f(1.43, -0.05);
    glVertex2f(1.32, -0.19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.30f, 0.20f);
    glVertex2f(1.44, -0.32);
    glVertex2f(1.48, -0.35);
    glVertex2f(1.54, -0.34);
    glVertex2f(1.56, -0.31);
    glVertex2f(1.58, -0.12);
    glVertex2f(1.43, -0.24);
    glEnd();

    glPopMatrix();



    //glMatrixMode(GL_MODELVIEW);
    //glTranslatef(0.0f, y, 0.0f);

    //glTranslatef(tx, ty, 0.0f);


    //Human figure
    //Head
    //hair

    if (humanVisible) {

        glMatrixMode(GL_MODELVIEW);
        glTranslatef(0.0f, y, 0.0f);

        glTranslatef(tx, ty, 0.0f);

        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(-4.88, -0.62);
        glVertex2f(-4.73, -0.63);
        glVertex2f(-4.63, -0.61);
        glVertex2f(-4.53, -0.52);
        glVertex2f(-4.63, -0.47);
        glVertex2f(-4.73, -0.44);
        glVertex2f(-4.93, -0.44);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(-5.04, -0.5);
        glVertex2f(-4.88, -0.62);
        glVertex2f(-4.93, -0.44);
        glVertex2f(-4.99, -0.46);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(-4.91, -0.74);
        glVertex2f(-4.9, -0.74);
        glVertex2f(-4.9, -0.61);
        glVertex2f(-5.04, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(-5.12, -0.68);
        glVertex2f(-5.1, -0.75);
        glVertex2f(-5.04, -0.82);
        glVertex2f(-4.94, -0.83);
        glVertex2f(-4.94, -0.81);
        glVertex2f(-4.91, -0.74);
        glVertex2f(-5.04, -0.5);
        glVertex2f(-5.08, -0.53);
        glVertex2f(-5.11, -0.57);
        glVertex2f(-5.12, -0.61);
        glEnd();

        //ear
        glBegin(GL_POLYGON);
        glColor3f(1, 0.68, 0.8);
        glVertex2f(-5.04, -0.75);
        glVertex2f(-5.02, -0.79);
        glVertex2f(-4.99, -0.81);
        glVertex2f(-4.94, -0.81);
        glVertex2f(-4.9, -0.74);
        glVertex2f(-4.91, -0.74);
        glVertex2f(-4.95, -0.7);
        glVertex2f(-5.0, -0.69);
        glVertex2f(-5.03, -0.71);
        glEnd();

        //face
        glBegin(GL_POLYGON);
        glColor3f(1, 0.68, 0.8);
        glVertex2f(-4.94, -0.83);
        glVertex2f(-4.87, -0.85);
        glVertex2f(-4.81, -0.86);
        glVertex2f(-4.73, -0.86);
        glVertex2f(-4.66, -0.83);
        glVertex2f(-4.62, -0.78);
        glVertex2f(-4.62, -0.71);
        glVertex2f(-4.63, -0.61);
        glVertex2f(-4.73, -0.63);
        glVertex2f(-4.88, -0.63);
        glVertex2f(-4.9, -0.61);
        glVertex2f(-4.9, -0.74);
        glVertex2f(-4.94, -0.81);
        glEnd();

        //neck
        glBegin(GL_POLYGON);
        glColor3f(1, 0.68, 0.8);
        glVertex2f(-4.93, -0.87);
        glVertex2f(-4.88, -0.91);
        glVertex2f(-4.83, -0.93);
        glVertex2f(-4.79, -0.92);
        glVertex2f(-4.76, -0.9);
        glVertex2f(-4.75, -0.86);
        glVertex2f(-4.81, -0.86);
        glVertex2f(-4.87, -0.85);
        glVertex2f(-4.93, -0.83);
        glEnd();

        //left hand
        glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-5.14, -0.95);
        glVertex2f(-5.06, -1.05);
        glVertex2f(-5.02, -1.03);
        glVertex2f(-4.97, -0.99);
        glVertex2f(-4.88, -0.91);
        glVertex2f(-4.93, -0.87);
        glVertex2f(-4.99, -0.87);
        glVertex2f(-5.05, -0.89);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(1.0, 0.68, 0.8);
        glVertex2f(-5.21, -1.06);
        glVertex2f(-5.12, -1.13);
        glVertex2f(-5.06, -1.05);
        glVertex2f(-5.14, -0.95);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(1.0, 0.68, 0.8);
        glVertex2f(-5.28, -1.14);
        glVertex2f(-5.25, -1.19);
        glVertex2f(-5.19, -1.23);
        glVertex2f(-5.14, -1.22);
        glVertex2f(-5.12, -1.19);
        glVertex2f(-5.12, -1.13);
        glVertex2f(-5.21, -1.06);
        glVertex2f(-5.24, -1.08);
        glVertex2f(-5.27, -1.11);
        glEnd();

        //body
        glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-5.03, -1.16);
        glVertex2f(-4.96, -1.18);
        glVertex2f(-4.85, -1.18);
        glVertex2f(-4.72, -1.17);
        glVertex2f(-4.71, -1.08);
        glVertex2f(-4.76, -0.9);
        glVertex2f(-4.79, -0.92);
        glVertex2f(-4.83, -0.93);
        glVertex2f(-4.88, -0.91);
        glVertex2f(-4.97, -0.99);
        glVertex2f(-5.02, -1.03);
        glEnd();

        //right hand
        glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(-4.71, -1.08);
        glVertex2f(-4.65, -1.08);
        glVertex2f(-4.64, -0.97);
        glVertex2f(-4.74, -0.93);
        glVertex2f(-4.76, -0.9);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(1.0, 0.68, 0.8);
        glVertex2f(-4.65, -1.08);
        glVertex2f(-4.46, -1.06);
        glVertex2f(-4.45, -1.03);
        glVertex2f(-4.46, -0.97);
        glVertex2f(-4.51, -0.94);
        glVertex2f(-4.56, -0.94);
        glVertex2f(-4.61, -0.98);
        glVertex2f(-4.64, -0.97);
        glEnd();

        //right leg
        glBegin(GL_POLYGON);
        glColor3f(0.20, 0.25, 1.0);
        glVertex2f(-5.02, -1.26);
        glVertex2f(-4.97, -1.3);
        glVertex2f(-4.89, -1.32);
        glVertex2f(-4.8, -1.32);
        glVertex2f(-4.72, -1.17);
        glVertex2f(-4.85, -1.18);
        glVertex2f(-4.96, -1.18);
        glVertex2f(-5.03, -1.16);
        glVertex2f(-5.03, -1.22);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.20, 0.25, 1.0);
        glVertex2f(-4.72, -1.42);
        glVertex2f(-4.58, -1.34);
        glVertex2f(-4.63, -1.23);
        glVertex2f(-4.72, -1.17);
        glVertex2f(-4.8, -1.32);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(-4.7, -1.49);
        glVertex2f(-4.67, -1.51);
        glVertex2f(-4.58, -1.48);
        glVertex2f(-4.48, -1.43);
        glVertex2f(-4.46, -1.38);
        glVertex2f(-4.49, -1.34);
        glVertex2f(-4.52, -1.32);
        glVertex2f(-4.58, -1.34);
        glVertex2f(-4.72, -1.42);
        glEnd();

        //left leg
        glBegin(GL_POLYGON);
        glColor3f(0.20, 0.25, 1.0);
        glVertex2f(-5.04, -1.31);
        glVertex2f(-4.96, -1.47);
        glVertex2f(-4.9, -1.39);
        glVertex2f(-4.89, -1.32);
        glVertex2f(-4.97, -1.3);
        glVertex2f(-5.02, -1.26);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.20, 0.25, 1.0);
        glVertex2f(-5.11, -1.45);
        glVertex2f(-5.01, -1.47);
        glVertex2f(-4.96, -1.47);
        glVertex2f(-5.04, -1.31);
        glVertex2f(-5.11, -1.3);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(-5.25, -1.5);
        glVertex2f(-5.21, -1.54);
        glVertex2f(-5.17, -1.54);
        glVertex2f(-5.12, -1.5);
        glVertex2f(-5.11, -1.3);
        glVertex2f(-5.25, -1.3);
        glEnd();

    }










    /*
     //human figure
     //head
     glBegin(GL_POLYGON);
     glColor3f(0.0, 0.0, 0.0);
     glVertex2f(-1.57, 0.87);
     glVertex2f(-1.39, 0.76);
     glVertex2f(-1.23, 0.76);
     glVertex2f(-1.15, 0.77);
     glVertex2f(-1.06, 0.86);
     glVertex2f(-1.25, 0.94);
     glVertex2f(-1.44, 0.94);
     glVertex2f(-1.53, 0.92);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.0, 0.0, 0.0);
     glVertex2f(-1.65, 0.8);
     glVertex2f(-1.5, 0.7);
     glVertex2f(-1.43, 0.65);
     glVertex2f(-1.43, 0.78);
     glVertex2f(-1.57, 0.87);
     glVertex2f(-1.63, 0.84);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(0.0, 0.0, 0.0);
     glVertex2f(-1.66, 0.76);
     glVertex2f(-1.66, 0.71);
     glVertex2f(-1.64, 0.65);
     glVertex2f(-1.6, 0.59);
     glVertex2f(-1.53, 0.55);
     glVertex2f(-1.47, 0.56);
     glVertex2f(-1.47, 0.58);
     glVertex2f(-1.51, 0.58);
     glVertex2f(-1.54, 0.59);
     glVertex2f(-1.57, 0.63);
     glVertex2f(-1.57, 0.67);
     glVertex2f(-1.54, 0.69);
     glVertex2f(-1.5, 0.7);
     glVertex2f(-1.65, 0.8);
     glEnd();

     // face
     glBegin(GL_POLYGON);
     glColor3f(1, 0.68, 0.8);
     glVertex2f(-1.57, 0.63);
     glVertex2f(-1.54, 0.59);
     glVertex2f(-1.51, 0.58);
     glVertex2f(-1.47, 0.58);
     glVertex2f(-1.47, 0.56);
     glVertex2f(-1.41, 0.52);
     glVertex2f(-1.31, 0.52);
     glVertex2f(-1.23, 0.53);
     glVertex2f(-1.17, 0.56);
     glVertex2f(-1.14, 0.61);
     glVertex2f(-1.15, 0.77);
     glVertex2f(-1.23, 0.76);
     glVertex2f(-1.39, 0.76);
     glVertex2f(-1.43, 0.78);
     glVertex2f(-1.43, 0.65);
     glVertex2f(-1.5, 0.7);
     glVertex2f(-1.54, 0.69);
     glVertex2f(-1.57, 0.67);
     glEnd();


     //neck
     glBegin(GL_POLYGON);
     glColor3f(1, 0.68, 0.8);
     glVertex2f(-1.46, 0.51);
     glVertex2f(-1.42, 0.47);
     glVertex2f(-1.35, 0.46);
     glVertex2f(-1.32, 0.47);
     glVertex2f(-1.29, 0.49);
     glVertex2f(-1.29, 0.52);
     glVertex2f(-1.31, 0.52);
     glVertex2f(-1.41, 0.52);
     glVertex2f(-1.47, 0.56);
     glVertex2f(-1.46, 0.53);
     glEnd();

     //body
     glBegin(GL_POLYGON);
     glColor3f(1, 1, 1);
     glVertex2f(-1.56, 0.23);
     glVertex2f(-1.5, 0.21);
     glVertex2f(-1.39, 0.21);
     glVertex2f(-1.25, 0.21);
     glVertex2f(-1.25, 0.31);
     glVertex2f(-1.25, 0.37);
     glVertex2f(-1.28, 0.47);
     glVertex2f(-1.29, 0.49);
     glVertex2f(-1.32, 0.47);
     glVertex2f(-1.35, 0.46);
     glVertex2f(-1.42, 0.47);
     glVertex2f(-1.56, 0.36);
     glEnd();

     //back hand

     glBegin(GL_POLYGON);
     glColor3f(1, 1, 1);
     glVertex2f(-1.69, 0.43);
     glVertex2f(-1.6, 0.33);
     glVertex2f(-1.42, 0.47);
     glVertex2f(-1.46, 0.51);
     glVertex2f(-1.46, 0.53);
     glVertex2f(-1.55, 0.52);
     glVertex2f(-1.63, 0.48);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(1, 0.68, 0.8);
     glVertex2f(-1.75, 0.32);
     glVertex2f(-1.66, 0.25);
     glVertex2f(-1.6, 0.33);
     glVertex2f(-1.69, 0.43);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(1, 0.68, 0.8);
     glVertex2f(-1.81, 0.25);
     glVertex2f(-1.82, 0.21);
     glVertex2f(-1.71, 0.14);
     glVertex2f(-1.65, 0.18);
     glVertex2f(-1.66, 0.25);
     glVertex2f(-1.75, 0.32);
     glVertex2f(-1.78, 0.29);
     glEnd();

     //front hand

     glBegin(GL_POLYGON);
     glColor3f(1, 1, 1);
     glVertex2f(-1.25, 0.37);
     glVertex2f(-1.25, 0.31);
     glVertex2f(-1.15, 0.31);
     glVertex2f(-1.15, 0.41);
     glVertex2f(-1.28, 0.47);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(1, 0.68, 0.8);
     glVertex2f(-1.15, 0.31);
     glVertex2f(-1.0, 0.31);
     glVertex2f(-0.98, 0.36);
     glVertex2f(-0.99, 0.42);
     glVertex2f(-1.06, 0.45);
     glVertex2f(-1.11, 0.43);
     glVertex2f(-1.15, 0.41);
     glEnd();

     */


glFlush();


    glutSwapBuffers();

}





























//Asma

void update0(int value) {

    if (j) {
        v -= 0.01f;   // gravity
        //y += v;       // vertical movement only
        moveY += v;

        //if (y <= 0.0f)
        if ( moveY <= 0.0f) { // landed
             moveY = 0.0f;
            v = 0.0f;
            j = 0;
        }
    }






    // Player position based on manX (character starts around x = -5.35)
    float playerX = manX + (-5.35f);
    float playerY = -0.65f;  // fixed ground level

    // === Right Portal only → move to Level 1 ===
    if (checkCollision(playerX, playerY, 5.35f, -0.55f, 0.6f))
    {
        if (level == 0)
        {
            level = 1;
            cout << "Level 1" << endl;
        }

        // Reset Asma's player state
        manX  = 0.0f;

        // Reset Tamal's player state (for when Level 1 starts fresh)
        moveX = 0.0f;
        moveY = 0.0f;
        y     = 0.0f;
        v     = 0.0f;
        j     = 0;
    }

   // glutPostRedisplay();
    glutTimerFunc(16, update0, 0);
}







//Tamal
void update1(int value) {

    if (j) {
        v -= 0.01f;   // gravity
        //y += v;       // vertical movement only
        moveY += v;

        //if (y <= 0.0f)
        if ( moveY <= 0.0f) { // landed
             moveY = 0.0f;
            v = 0.0f;
            j = 0;
        }
    }


//Tamal Coin
// Declare player position first
    float playerX = moveX - 3.0f;
    float playerY = moveY + y;


  //  float playerX = moveX + (-3.07f);
   // float playerY = moveY + (-0.10f);

// Usage in update()
if (checkCollision(playerX, playerY, -1.50f, -0.10f))
    {
        coinB3 = 0;
    }
if (checkCollision(playerX, playerY, -0.84f, -0.10f))
    {
        coinD3 = 0;
    }
if (checkCollision(playerX, playerY, -0.30f, -0.10f))
    {
        coinE3 = 0;
    }
if (checkCollision(playerX, playerY, 0.26f, -0.10f))
    {
        coinF3 = 0;
    }
if (checkCollision(playerX, playerY, 1.07f, -0.10f))
    {
        coinH3 = 0;
    }

if (checkCollision(playerX, playerY, 1.86f, -0.10f))
    {
        coinJ3 = 0;
    }
if (checkCollision(playerX, playerY, 3.28f, -0.15f))
    {
        coinB7 = 0;
    }
if (checkCollision(playerX, playerY, 3.93f, -0.14f))
    {


    coinC7 = 0;
    }



    // === Portals ===
    // Right portal → next level
    if (checkCollision(playerX, playerY, 5.2f, 0.20f, 0.8f))
    {
        if (level == 1)
        {
            level = 2;
            cout << "Level 2" << endl;
        }
        moveX = 0.0f;
        moveY = 0.0f;
        y     = 0.0f;
        v     = 0.0f;
        j     = 0;
    }

    // Left portal → go back
    if (checkCollision(playerX, playerY, -5.2f, 0.20f, 0.8f))
    {
        if (level == 1)
        {
            level = 0;
            cout << "Back to Level 0" << endl;
        }
        moveX = 0.0f;
        moveY = 0.0f;
        y     = 0.0f;
        v     = 0.0f;
        j     = 0;
        manX  = 0.0f;  // reset Asma's character too
    }


   // glutPostRedisplay();
    glutTimerFunc(16, update1, 0);
}




//Alvi

float checkGround(float x)
{

    if(x >= -6 && x <= -3.88)
        return -1.04f;


    if(x >= -4 && x <= -1.72)
        return -0.5f;

    if(x >= -1 && x <= 2.38)
        return -0.5f;

    if(x >= 2.6 && x <= 6.0)
        return -1.0f;

    return -100.0f;
}




void update2(int value)
{
    float playerX = - 3.6f + moveX;
    float playerFeetY = - 0.5f + moveY;

    float groundY = checkGround(playerX);

    if(!isJumping)
    {
        if(playerFeetY > groundY)
        {
            isJumping = 1;
            velocityY = 0.0f;
        }
    }

    if(isJumping)
    {
        velocityY = velocityY - 0.01f;

        moveY = moveY + velocityY;
        moveX = moveX + velocityX;


        playerFeetY = moveY - 0.5f;


        if(playerFeetY <= groundY)
        {
            moveY = groundY + 0.5f;
            velocityY = 0.0f;
            velocityX = 0.0f;
            isJumping = 0;
        }
    }


    float portal1X = -4.98;
    float portal1Y = -0.2;

    float portal2X = 4.87;
    float portal2Y = -0.2;


    float playerY =  - 0.2f + moveY;
    float distance;


    distance = sqrt(pow(playerX + 2.84, 2) + pow(playerY + 0.27, 2));
    if(distance < 0.3) coin10 = 0;

    distance = sqrt(pow(playerX + 2.28, 2) + pow(playerY + 0.26, 2));
    if(distance < 0.3) coin11 = 0;

    distance = sqrt(pow(playerX - 1.23, 2) + pow(playerY + 0.26, 2));
    if(distance < 0.3) coin14 = 0;

    distance = sqrt(pow(playerX - 0.64, 2) + pow(playerY + 0.26, 2));
    if(distance < 0.3) coin15 = 0;

    distance = sqrt(pow(playerX - 0.08, 2) + pow(playerY + 0.26, 2));
    if(distance < 0.3) coin16 = 0;

    distance = sqrt(pow(playerX - 3.28, 2) + pow(playerY + 0.77, 2));
    if(distance < 0.3) coin12 = 0;

    distance = sqrt(pow(playerX - 3.84, 2) + pow(playerY + 0.77, 2));
    if(distance < 0.3) coin13 = 0;


 // LEFT PORTAL -> LEVEL 1
distance = sqrt(pow(playerX - portal1X, 2) +
                pow(playerY - portal1Y, 2));

if(distance < 0.5)
{
    level = 1;

    moveX = 4.0f;
    moveY = 0.0f;

    playerVisible = 1;

    cout << "LEVEL 1" << endl;
}


// RIGHT PORTAL -> LEVEL 3
distance = sqrt(pow(playerX - portal2X, 2) +
                pow(playerY - portal2Y, 2));

if(distance < 0.5)
{
    level = 3;

    moveX = -4.0f;
    moveY = 0.0f;

    playerVisible = 1;

    cout << "LEVEL 3" << endl;
}



    float fireLeft = 1.72;
    float fireRight = 2.29;

    float fireBottom = -0.51;
    float fireTop = 0.0;

    float px = playerX;
    float py = playerY;

    if(px >= fireLeft && px <= fireRight &&
       py >= fireBottom && py <= fireTop)
    {
        playerVisible = 0;
    }
   // glutPostRedisplay();
   // glutTimerFunc(16, update2, 0);
}





//Shithil

float checkGround3(float x)
{
    // left most block
    if (x >= -6 && x <= -3.88) {
        return -1.55;
    }

    // left block
    if (x >= -4 && x <= -1.73) {
        return -0.74;
    }

    // middle block
    if (x >= -1.04 && x <= 2.52) {
        return -0.74;
    }

    // right block
    if (x >= 2.56 && x <= 3.88) {
        return -1.31;
    }


    if (x >= 3.97 && x <= 6.0) {
        return -1.54;
    }


    // No block
    return -6.0;
}


void update3(int value) {
    /*
    float playerBaseX = -3.0f;
    float playerBaseY = -4.0f;

    float playerX = tx + playerBaseX;
    float playerY = ty + y + playerBaseY;

    float groundY = checkGround(playerX);

        if (j) {
            v -= 0.01f;
            y += v;


            if (y <= 0.0f) {
                y = 0.0f;
                v = 0.0f;
                j = 0;
            }
        }



    if (j) {
        v -= 0.01f;
        y += v;
    }


    // playerY = ty + y;
    playerY = ty + y + playerBaseY;
    playerX = tx + playerBaseX;


    if (playerY <= groundY) {
        y = groundY - ty;
        v = 0.0f;
        j = 0;
    }
    */
    //float playerBaseX = -3.0f;
    //float playerBaseY = -4.0f;

    float playerX = tx - 4.8f;
    float playerY = ty + y - 1.0;
    float playerFeet = playerY - 1.5f;

    float groundY3 = checkGround3(playerX);

    if (j) {
        v -= 0.01f;
        y += v;
    }

    if (playerFeet <= groundY3 && v <= 0) {
        y = groundY3 - ty + 1.5f;
        v = 0.0f;
        j = 0;
    }


    static float speed = 0.02f;

    yz += speed;

    // Reverse direction at limits
    if (yz > 0.9f || yz < -0.5f) {
        speed = -speed;
    }

    //glutPostRedisplay();
    //glutTimerFunc(16, update, 0);



    //float playerX = tx - 3.0f;
    //float playerY = ty + y;

    //float groundY = checkGround(playerX);

    float zombieX = txz + 1.2f;
    float zombieY = yz + tyz + 0.3f;

    if (checkCollision(playerX, playerY, zombieX, zombieY, 0.7f)) {
        humanVisible = false;
    }

    if (checkCollision(playerX, playerY, -2.84, -0.47, 0.3f)) {
        humanVisible = false;
    }


    if (checkCollision(playerX, playerY, -3.42f, -0.48f)) {
        coin1 = false;
    }


    if (checkCollision(playerX, playerY, 1.94f, -0.48f)) {
        coin2 = false;
    }

    if (checkCollision(playerX, playerY, -2.3f, -0.48f)) {
        coin3 = false;
    }

    if (checkCollision(playerX, playerY, -0.55f, -0.48f)) {
        coin4 = false;
    }


    if (checkCollision(playerX, playerY, 0.03f, -0.48f)) {
        coin5 = false;
    }

    if (checkCollision(playerX, playerY, 0.6f, -0.48f)) {
        coin6 = false;
    }

    if (checkCollision(playerX, playerY, 1.17f, -0.48f)) {
        coin7 = false;
    }

    if (checkCollision(playerX, playerY, 3.24f, -1.08f)) {
        coin8 = false;
    }

    if (checkCollision(playerX, playerY, 3.78f, -1.08f)) {
        coin9 = false;
    }


    //glutPostRedisplay();
    glutTimerFunc(16, update3, 0);
}




//Asma

void keyboard0(unsigned char key, int x, int y){
    switch (key) {
        break;
        case 'a':
            manX -= 0.1f;
            break;
        case 'd':
            manX += 0.1f;
            break;
            case ' ':
            if (!j) { // jump
                j = 1;
                v = 0.25f;
            }
            break;
    }
    glutPostRedisplay();
}





//Tamal
void keyboard1(unsigned char key, int x, int y)
{
    switch(key)
    {
        case ' ':
            if (!j) { // jump
                j = 1;
                v = 0.25f;
            }
            break;

        case 'a':
            moveX -= 0.1f; // move left
            break;

        case 'd':
            moveX += 0.1f; // move right
            break;

        case 'r':
            rain = true;   // start rain
            break;

            case 's':
            rain = false;  // stop rain
            break;

        case 'x':
            exit(0);       // exit game
            break;


    }

    glutPostRedisplay();
}






//Alvi


void keyboard2(unsigned char key, int x, int y)
{
    if(key == 'a')
    {
        moveX -= 0.1f;
    }
    else if(key == 'd')
    {
        moveX += 0.1f;
    }
    else if(key == ' ')   // space for jump
    {
        if(!isJumping)
        {
            isJumping = 1;
            velocityY = 0.15f;
        }
    }

    else if(key == 'k')    // angular jump
    {
        if(!isJumping)
        {
            isJumping = 1;

            velocityY = 0.15f;
            velocityX = 0.05f;
        }
    }

    glutPostRedisplay();
}




//Shithil



void keyboard3(unsigned char key, int x, int yPos) {
    if (key == ' ') {
        if (!j) {
            j = 1;
            v = 0.25f;
        }
    }

    switch (key) {

    case 'w': ty += 0.1f; break;
    case 's': ty -= 0.1f; break;
    case 'a': tx -= 0.1f; break;
    case 'd': tx += 0.5f; break;

    }

    if (tx > 9.5f) {

        ty = -10.0f;

    }
    if (tx > 19.5f) {
        ty = -20.0f;
    }
}





void terminal() {

    cout << "LOST IN DIMENSIONS: JOURNEY BACK TO EARTH" << endl;
    cout << "Created by: Md. Tawfiqul Islam Tamal" << endl;
    cout << endl;
    cout << "CONTROLS:" << endl;
    cout << "  SPACE  -> Jump Straight Up" << endl;
    cout << "  r  -> Rain Start" << endl;//Tamal
    cout << "  s  -> Stop Rain" << endl;//Tamal
    cout << "  s  -> Move Down" << endl;//Shithil
    cout << "  a  -> Move Left" << endl;
    cout << "  d  -> Move Right" << endl;
    cout << "  X  -> Exit Game" << endl;
    cout << "  w  -> Move Up" << endl;//Shithil
    cout << "  k -> Angular jump" << endl;//Alvi

    cout << endl;
    cout << "Game Started. Begin your journey!" << endl;

}


void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    //glViewport(0, 0, 100, 100);
    glViewport(0, 0, 1200, 800);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6.0, 6.0, -4.0, 4.0);
    glMatrixMode(GL_MODELVIEW);



}

/*
void update(int value) {
    if (level == 0)
        update0(value);
    else if (level == 1)
        update1(value);
     else if (level == 2)
      update2(value);
     else if (level == 3)
        update3(value);
}


*/
void update(int value)
{
    if (level == 0)
    {
        update0(0);
    }
    else if (level == 1)
    {
        update1(0);
    }
    else if (level == 2)
    {
        update2(0);
    }
    else if (level == 3)
    {
        update3(0);
    }

    glutPostRedisplay();

    // ONLY ONE TIMER
    glutTimerFunc(16, update, 0);
}



/*

void keyboard(unsigned char key, int x, int y) {
    if (level == 0)
        keyboard0(key, x, y);
    else if (level == 1)
        keyboard1(key, x, y);
     else if (level == 2)
         keyboard2(key, x, y);
     else if (level == 3)
        keyboard3(key, x, y);
}

*/



void keyboard(unsigned char key, int x, int y)
{
    if (level == 0)
    {
        keyboard0(key, x, y);
    }
    else if (level == 1)
    {
        keyboard1(key, x, y);
    }
    else if (level == 2)
    {
        keyboard2(key, x, y);
    }
    else if (level == 3)
    {
        keyboard3(key, x, y);
    }

    glutPostRedisplay();
}












void display() {
    if (level == 0)
        display0();       // Level 0 (intro /               's screen)
    else if (level == 1)
        display1();        // Level 1 (Tamal's screen)
     else if (level == 2)
         display2();  // plug in when ready
     else if (level == 3)
        display3();
}












//Main Function
int main(int argc, char** argv) {
    terminal();
    glutInit(&argc, argv);


    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("LOST IN DIMENSIONS: JOURNEY BACK TO EARTH");

    init();
    glutDisplayFunc(display);


    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}

#include <iostream>
#include <math.h>
#include <stdlib.h>

#ifdef __linux__
#include <GL/glut.h>
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h> 
#endif

using namespace std;

namespace colors
{
    enum colorNames {
        BLACK=0, 
        RED=1, 
        GREEN=2, 
        BLUE=3, 
        CYAN=4, 
        YELLOW=5, 
        PINK=6, 
        WHITE=7
    };
}

GLfloat color[3] = {0, 0, 0};

// sets global color vector 
void colorMeSilly(colors::colorNames name){
    color[0] = color[1] = color[2] = 0;
    switch (name) {
        case colors::BLACK: break;
        case colors::RED: 
            color[0] = 1;
            break;
        case colors::GREEN:
            color[1] = 1;
            break;
        case colors::BLUE:
            color[2] = 1;
            break;
        case colors::YELLOW:
            color[0] = color[1] = 1;
            break; 
        case colors::CYAN:
            color[1] = color[2] = 1;
            break;
        case colors::PINK:
            color[0] = color[2] = 1;
            break;
        case colors::WHITE:
            color[0] = color[1] = color[2] = 1;
    }
    cout<<color[0]<<color[1]<<color[2]<<endl;
    glColor3fv(color);
}; 

float change_x=0; // 0 = left , 1 = right
float change_y=0; // 0 = bottom, 1 = top
int change_z=0; // 0 = near, 1 = far
int currentdir=0;

int currentpos[4][2] = {{45,45},{55,45},{55,55},{45,55}};

void keypressed(unsigned char key, int x, int y)
{
    switch(key) { 
        case 'w': 
            currentdir = 0;
            break;
        case 's': 
            currentdir = 1;
            break;
        case 'd': 
            currentdir = 2;
            break;
        case 'a': 
            currentdir = 3;
            break;
    }
    cout<<key<<endl;
}

// Draws 9 sided polygons in random locations using translate
// Polygon formula taken from  https://gist.github.com/kenpower/3782654 and modified because it drew one side less
void drawObstacles(int obstacleCount, double radius, colors::colorNames color) {
    // initialize random seed - otherwise random positions generated each time when display calls. 
    srand (33);
    // generates M sided polygon
    const int sides=9;
    // defining bounds for ortho
    const int xMin=0, xMax=100, yMin=0, yMax=100;

    for (int i=0; i<obstacleCount; i++){
        // defining bounds used to limit centers of polygon 
        const int xCenter = rand() % xMax + xMin; 
        const int yCenter = rand() % yMax + yMin;

        glBegin(GL_POLYGON);
        for(int i=0;i<=sides;i++){
            double angle=i*2*M_PI/sides;
            colorMeSilly(color); // using instead of glColor
            glVertex2d(xCenter+radius*cos(angle),yCenter+radius*sin(angle));	
        }
        glEnd();
    }

}
void drawcar()
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2iv(currentpos[0]); //Change all
        glVertex2iv(currentpos[1]); //Change
        glVertex2iv(currentpos[2]); //Change
        glVertex2iv(currentpos[3]); //Change
    glEnd();
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glOrtho(0.0,100.0,0.0,100.0,0.0,10.0);
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    switch(currentdir)
    {
        // up
        case 0: 
            change_y+=0.1;
            break;
        // down
        case 1:
            change_y-=0.1;
            break;
        // right
        case 2:
            change_x+=0.1;
            break;
        // left
        case 3:
            change_x-=0.1;
            break;
    }
    glTranslatef(change_x,change_y,0);
    drawcar();
    glPopMatrix();
    // obstacleCount, radius, color
    drawObstacles(7,3, colors::PINK);
    glFlush();
    glutSwapBuffers();
}

void moveFo()
{
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,700);
    glutCreateWindow("PAKO FOREVER!!");
    myinit();
    glutDisplayFunc(display);
    glutIdleFunc(moveFo);
    glEnable(GL_DEPTH_TEST); 
    glutKeyboardFunc(keypressed);
    glutMainLoop();
    return 0;
}
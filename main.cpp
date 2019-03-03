#include <iostream>

#ifdef __linux__
#include <GL/glut.h>
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h> 
#endif

using namespace std;

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
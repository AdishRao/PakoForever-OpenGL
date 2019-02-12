#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
using namespace std;

int change_x[2]={0}; // 0 = left , 1 = right
int change_y[2]={0}; // 0 = bottom, 1 = top
int change_z[2]={0}; // 0 = near, 1 = far

int currentpos[4][2] = {{25,55},{35,55},{35,65},{25,65}};

void moveCar(char key) { 
    if (key == 'D') {

    }

} 


void keypressed(unsigned char key, int x, int y)
{
    cout<<key<<endl;
    moveCar(key);
}

void drawcar()
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2d(25,55);
        glVertex2d(35,55);
        glVertex2d(35,65);
        glVertex2d(25,65);
    glEnd();
}

void myinit()
{
    glOrtho(0.0,100.0,100.0,0.0,0.0,10.0);
    //gluLookAt(2.0,2.0,2.0,10.0,10.0,10.0,2.0,2.0,2.0);
    glClearColor(1.0,1.0,1.0,1.0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    drawcar();
    cout<<"loopy"<<endl;
    //moveForwards();
    glFlush();
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
    glEnable(GL_DEPTH_TEST); 
    glutKeyboardFunc(keypressed);
    glutMainLoop();
    return 0;
}
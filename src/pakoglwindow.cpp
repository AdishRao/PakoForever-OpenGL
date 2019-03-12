#include "../include/pakoglwindow.h"

void PakoGLWindow::keypressed(unsigned char key, int x, int y)
{
    switch(key) { 
        case 'w': 
        case 's': 
        case 'd': 
        case 'a': 
                car.changeDirection(key);
                break;
        case 'q':
            viewer[0] ++; 
            break;
        case 'Q':
            viewer[0] --;
            break;
        case 'r':
            viewer[1] ++; 
            break;
        case 'R':
            viewer[1] --;
            break;
        case 'e':
            viewer[2] ++; 
            break;
        case 'E':
            viewer[2] --;
    }
    std::cout<<key<<std::endl;
}

void PakoGLWindow::specialKey(int key, int x, int y){ 
    switch (key)
    {
        case GLUT_KEY_UP:
        case GLUT_KEY_DOWN:
        case GLUT_KEY_LEFT:
        case GLUT_KEY_RIGHT: break;
    }
}

// Draws 9 sided polygons in random locations using translate
// Polygon formula taken from  https://gist.github.com/kenpower/3782654 and modified because it drew one side less
void PakoGLWindow::drawObstacles(int obstacleCount, double radius, colors::colorNames color) {
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

void PakoGLWindow::initialize()
{    
    glMatrixMode(GL_PROJECTION);
    glOrtho(0.0,100.0,0.0,100.0,-2.0,15.0);
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}


void PakoGLWindow::display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    car.moveForward();
    // obstacleCount, radius, color
    drawObstacles(7,3, colors::PINK);
    glFlush();
    glutSwapBuffers();
}

void PakoGLWindow::idle() { 
    glutPostRedisplay();
}

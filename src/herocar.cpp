#include "../include/herocar.h"

void HeroCar::drawCar()
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2iv(currentpos[0]); //Change all
        glVertex2iv(currentpos[1]); //Change
        glVertex2iv(currentpos[2]); //Change
        glVertex2iv(currentpos[3]); //Change
    glEnd();
}

void HeroCar::changeDirection(unsigned char key) { 
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
}

void HeroCar::moveForward()
{
    glPushMatrix();
    switch(currentdir)
    {
        // up
        case 0: 
            change_y+=0.01;
            break;
        // down
        case 1:
            change_y-=0.01;
            break;
        // right
        case 2:
            change_x+=0.01;
            break;
        // left
        case 3:
            change_x-=0.01;
            break;
    }
    glTranslatef(change_x,change_y,0);
    drawCar();
    glPopMatrix();
}

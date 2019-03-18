#include "../include/herocar.h"

void HeroCar::drawCar(int a,int b,int c,int d)
{
    glBegin(GL_POLYGON);
        glVertex3iv(currentpos[a]);
        glVertex3iv(currentpos[b]);
        glVertex3iv(currentpos[c]);
        glVertex3iv(currentpos[d]);
    glEnd();
}

void HeroCar::drawCarCall()
{
    colorMeSilly(colors::RED);
    drawCar(0,3,2,1);
    colorMeSilly(colors::CYAN);
    drawCar(2,3,7,6);
    colorMeSilly(colors::CYAN);
    drawCar(0,4,7,3);
    colorMeSilly(colors::WHITE);
    drawCar(1,2,6,5);
    colorMeSilly(colors::YELLOW);
    drawCar(4,5,6,7);
    colorMeSilly(colors::CYAN);
    drawCar(0,1,5,4);
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
    //glRotatef(15,0.0,1.0,0.0);
    //glRotatef(15,0.0,0.0,1.0);
    drawCarCall();
    glPopMatrix();
}

void HeroCar::drawCop(int a,int b,int c,int d)
{
    glBegin(GL_POLYGON);
        glVertex3iv(cop1pos[a]);
        glVertex3iv(cop1pos[b]);
        glVertex3iv(cop1pos[c]);
        glVertex3iv(cop1pos[d]);
    glEnd();
    //std::cout<<"hello"<<std::endl;

}

void HeroCar::drawCopCall()
{
    //std::cout<<"hello"<<std::endl;
    glPushMatrix();
    glLoadIdentity();
    colorMeSilly(colors::RED);
    drawCop(0,3,2,1);
    colorMeSilly(colors::RED);
    drawCop(2,3,7,6);
    colorMeSilly(colors::RED);
    drawCop(0,4,7,3);
    colorMeSilly(colors::RED);
    drawCop(1,2,6,5);
    colorMeSilly(colors::BLUE);
    drawCop(4,5,6,7);
    colorMeSilly(colors::RED);
    drawCop(0,1,5,4);
   glPopMatrix();
}
#include "../include/herocar.h"

int i = 0;

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
    if(currentdir==2)
    colorMeSilly(colors::WHITE);
    else
    colorMeSilly(colors::CYAN);
    drawCar(2,3,7,6);
    if(currentdir==1)
    colorMeSilly(colors::WHITE);
    else
    colorMeSilly(colors::CYAN);
    drawCar(0,4,7,3);
    
    if (currentdir==0)
    colorMeSilly(colors::WHITE);
    else 
    colorMeSilly(colors::CYAN);
    drawCar(1,2,6,5);

    colorMeSilly(colors::YELLOW);
    drawCar(4,5,6,7);

    if(currentdir == 3)
    colorMeSilly(colors::WHITE);
    else
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
    drawCarCall();
    glPopMatrix();
}

void HeroCar::calmovement(int pos[8][3])
{
    float heromidx = 30 + change_x;
    float heromidy = 30 + change_y;
    float copmidx = 55 + change_cop_x;
    float copmidy = 30 + change_cop_y;  
    if(heromidx>copmidx)
        change_cop_x+=1;
    else if (heromidx<copmidx)
        change_cop_x-=1;
    if (heromidy>copmidy)
        change_cop_y+=1;
    else if (heromidy<copmidy)
        change_cop_y-=1;
}

void HeroCar::drawCop(int a,int b,int c,int d)
{
    static int coppos_one[8][3] =  {{50,25,15},{50,35,15},{60,35,15},{60,25,15},{70,45,0},{70,55,0},{80,55,0},{80,45,0}};
    calmovement(coppos_one);
    glBegin(GL_POLYGON);
        glVertex3iv(coppos_one[a]);
        glVertex3iv(coppos_one[b]);
        glVertex3iv(coppos_one[c]);
        glVertex3iv(coppos_one[d]);
    glEnd();
}

void HeroCar::drawCopCall()
{   
    if(i==0)
    {
        glPushMatrix();
        glTranslatef(change_cop_x,change_cop_y,0);
        std::cout<<'x'<<change_cop_x<<std::endl;
        std::cout<<'y'<<change_cop_y<<std::endl;
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
        i=1;
    }
    else
    {
        glPushMatrix();
        glTranslatef(change_cop_x,change_cop_y,0);
        std::cout<<'x'<<change_cop_x<<std::endl;
        std::cout<<'y'<<change_cop_y<<std::endl;
        glLoadIdentity();
        colorMeSilly(colors::BLUE);
        drawCop(0,3,2,1);
        colorMeSilly(colors::BLUE);
        drawCop(2,3,7,6);
        colorMeSilly(colors::BLUE);
        drawCop(0,4,7,3);
        colorMeSilly(colors::BLUE);
        drawCop(1,2,6,5);
        colorMeSilly(colors::RED);
        drawCop(4,5,6,7);
        colorMeSilly(colors::BLUE);
        drawCop(0,1,5,4);
        glPopMatrix();
        i=0;   
    }
}
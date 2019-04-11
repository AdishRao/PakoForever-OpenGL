#include "../include/herocar.h"

int i = 0;
float heromidx = 60;
float heromidy = 60;
//COP 1

float change1_cop_x = 0;
float change1_cop_y = 0;
float copmid1x = 25;
float copmid1y = 100;

//COP 2
float change2_cop_x = 0;
float change2_cop_y = 0;
float copmid2x = 95;
float copmid2y = 10;

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
            change_y+=0.9;
            break;
        // down
        case 1:
            change_y-=0.9;
            break;
        // right
        case 2:
            change_x+=0.9;
            break;
        // left
        case 3:
            change_x-=0.9;
            break;
    }
    glTranslatef(change_x,change_y,0);
    drawCarCall();
    glPopMatrix();
}

void HeroCar::calmovement2(int pos[8][3])
{
    heromidx = 60 + change_x;
    heromidy = 60 + change_y;
    copmid2x = 95 + change2_cop_x;
    copmid2y = 10 + change2_cop_y;
    std::cout<<"hero "<<heromidx<<"  "<<heromidy<<std::endl;
    std::cout<<"Cop "<<copmid2x<<"  "<<copmid2y<<std::endl;
    if (i==0)
    {
        if(heromidx>copmid2x)
            change2_cop_x+=0.15;
        else if (heromidx<copmid2x)
            change2_cop_x-=0.15;
        if (heromidy>copmid2y)
            change2_cop_y+=0.15;
        else if (heromidy<copmid2y)
            change2_cop_y-=0.15;
    }
}

void HeroCar::drawCop2(int a,int b,int c,int d)
{
    static int coppos_two[8][3] =  {{90,05,15},{90,15,15},{100,15,15},{100,05,15},{110,25,0},{110,35,0},{120,35,0},{120,25,0}};
    calmovement2(coppos_two);
    glBegin(GL_POLYGON);
        glVertex3iv(coppos_two[a]);
        glVertex3iv(coppos_two[b]);
        glVertex3iv(coppos_two[c]);
        glVertex3iv(coppos_two[d]);
    glEnd();
}

void HeroCar::drawCopCall2()
{   
    if(i==0)
    {
        std::cout<<"x in if "<<change2_cop_x<<std::endl;
        std::cout<<"y in if "<<change2_cop_y<<std::endl;
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(change2_cop_x,change2_cop_y,0);
        colorMeSilly(colors::RED);
        drawCop2(0,3,2,1);
        colorMeSilly(colors::RED);
        drawCop2(2,3,7,6);
        colorMeSilly(colors::RED);
        drawCop2(0,4,7,3);
        colorMeSilly(colors::RED);
        drawCop2(1,2,6,5);
        colorMeSilly(colors::BLUE);
        drawCop2(4,5,6,7);
        colorMeSilly(colors::RED);
        drawCop2(0,1,5,4);
        glPopMatrix();
    }
    else
    {
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(change2_cop_x,change2_cop_y,0);
        std::cout<<"x in else "<<change2_cop_x<<std::endl;
        std::cout<<"y in else "<<change2_cop_y<<std::endl;
        colorMeSilly(colors::BLUE);
        drawCop2(0,3,2,1);
        colorMeSilly(colors::BLUE);
        drawCop2(2,3,7,6);
        colorMeSilly(colors::BLUE);
        drawCop2(0,4,7,3);
        colorMeSilly(colors::BLUE);
        drawCop2(1,2,6,5);
        colorMeSilly(colors::RED);
        drawCop2(4,5,6,7);
        colorMeSilly(colors::BLUE);
        drawCop2(0,1,5,4);
        glPopMatrix();
    }
}

void HeroCar::calmovement1(int pos[8][3])
{
    heromidx = 60 + change_x;
    heromidy = 60 + change_y;
    copmid1x = 25 + change1_cop_x;
    copmid1y = 100 + change1_cop_y;
    std::cout<<"hero "<<heromidx<<"  "<<heromidy<<std::endl;
    std::cout<<"Cop "<<copmid1x<<"  "<<copmid1y<<std::endl;
    if (i==0)
    {
        if(heromidx>copmid1x)
            change1_cop_x+=0.1;
        else if (heromidx<copmid1x)
            change1_cop_x-=0.1;
        if (heromidy>copmid1y)
            change1_cop_y+=0.1;
        else if (heromidy<copmid1y)
            change1_cop_y-=0.1;
    }
}

void HeroCar::drawCop1(int a,int b,int c,int d)
{
    static int coppos_one[8][3] =  {{20,95,15},{20,105,15},{30,105,15},{30,95,15},{40,115,0},{40,125,0},{50,125,0},{50,115,0}};
    calmovement1(coppos_one);
    glBegin(GL_POLYGON);
        glVertex3iv(coppos_one[a]);
        glVertex3iv(coppos_one[b]);
        glVertex3iv(coppos_one[c]);
        glVertex3iv(coppos_one[d]);
    glEnd();
}

void HeroCar::drawCopCall1()
{   
    if(i==0)
    {
        std::cout<<"x in if "<<change1_cop_x<<std::endl;
        std::cout<<"y in if "<<change1_cop_y<<std::endl;
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(change1_cop_x,change1_cop_y,0);
        colorMeSilly(colors::RED);
        drawCop1(0,3,2,1);
        colorMeSilly(colors::RED);
        drawCop1(2,3,7,6);
        colorMeSilly(colors::RED);
        drawCop1(0,4,7,3);
        colorMeSilly(colors::RED);
        drawCop1(1,2,6,5);
        colorMeSilly(colors::BLUE);
        drawCop1(4,5,6,7);
        colorMeSilly(colors::RED);
        drawCop1(0,1,5,4);
        glPopMatrix();
        i=1;
    }
    else
    {
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(change1_cop_x,change1_cop_y,0);
        std::cout<<"x in else "<<change1_cop_x<<std::endl;
        std::cout<<"y in else "<<change1_cop_y<<std::endl;
        colorMeSilly(colors::BLUE);
        drawCop1(0,3,2,1);
        colorMeSilly(colors::BLUE);
        drawCop1(2,3,7,6);
        colorMeSilly(colors::BLUE);
        drawCop1(0,4,7,3);
        colorMeSilly(colors::BLUE);
        drawCop1(1,2,6,5);
        colorMeSilly(colors::RED);
        drawCop1(4,5,6,7);
        colorMeSilly(colors::BLUE);
        drawCop1(0,1,5,4);
        glPopMatrix();
        i=0;   
    }
}
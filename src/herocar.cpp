#include "../include/herocar.h"

int i = 0;
float heromidx = 60;
float heromidy = 60;
static int coppos[10][8][3]={
    {{20,95,15},{20,105,15},{30,105,15},{30,95,15},{40,115,0},{40,125,0},{50,125,0},{50,115,0}}, 
    {{90,5,15},{90,15,15},{100,15,15},{100,5,15},{110,25,0},{110,35,0},{120,35,0},{120,25,0}},
    {{400,400,15},{400,410,15},{410,410,15},{410,400,15},{420,420,0},{420,430,0},{430,430,0},{430,420,0}},
    {{200,300,15},{200,310,15},{210,310,15},{210,300,15},{220,320,0},{220,330,0},{230,330,0},{230,320,0}},
    {{400,40,15},{400,50,15},{410,50,15},{410,40,15},{420,60,0},{420,70,0},{430,70,0},{430,60,0}},
    };
float change_cop[10][2] = {0};
float copmid[10][2]={{25,100},{95,10},{405,405},{205,305},{405,45}};
float initpos[10][2]={{25,100},{95,10},{405,405},{205,305},{405,45}};
float iamspeed[10]={0.02,0.02,0.02,0.05,0.05};

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

void HeroCar::calmovement(int pos[8][3],int carno)
{
    heromidx = 60 + change_x;
    heromidy = 60 + change_y;
    copmid[carno][0] = initpos[carno][0] + change_cop[carno][0];
    copmid[carno][1] = initpos[carno][1] + change_cop[carno][1];
    if (i==0)
    {
        if(heromidx>copmid[carno][0])
            change_cop[carno][0]+=iamspeed[carno];
        else if (heromidx<copmid[carno][0])
            change_cop[carno][0]-=iamspeed[carno];
        if (heromidy>copmid[carno][1])
            change_cop[carno][1]+=iamspeed[carno];
        else if (heromidy<copmid[carno][1])
            change_cop[carno][1]-=iamspeed[carno];
    }
}


void HeroCar::drawCop(int a,int b,int c,int d,int carno)
{
    calmovement(coppos[carno],carno);
    glBegin(GL_POLYGON);
        glVertex3iv(coppos[carno][a]);
        glVertex3iv(coppos[carno][b]);
        glVertex3iv(coppos[carno][c]);
        glVertex3iv(coppos[carno][d]);
    glEnd();
}


void HeroCar::drawCopCall(int carno)
{   
    if(i==0)
    {
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(change_cop[carno][0],change_cop[carno][1],0);
        colorMeSilly(colors::RED);
        drawCop(0,3,2,1,carno);
        colorMeSilly(colors::RED);
        drawCop(2,3,7,6,carno);
        colorMeSilly(colors::RED);
        drawCop(0,4,7,3,carno);
        colorMeSilly(colors::RED);
        drawCop(1,2,6,5,carno);
        colorMeSilly(colors::BLUE);
        drawCop(4,5,6,7,carno);
        colorMeSilly(colors::RED);
        drawCop(0,1,5,4,carno);
        glPopMatrix();
    }
    else
    {
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(change_cop[carno][0],change_cop[carno][1],0);
        colorMeSilly(colors::BLUE);
        drawCop(0,3,2,1,carno);
        colorMeSilly(colors::BLUE);
        drawCop(2,3,7,6,carno);
        colorMeSilly(colors::BLUE);
        drawCop(0,4,7,3,carno);
        colorMeSilly(colors::BLUE);
        drawCop(1,2,6,5,carno);
        colorMeSilly(colors::RED);
        drawCop(4,5,6,7,carno);
        colorMeSilly(colors::BLUE);
        drawCop(0,1,5,4,carno);
        glPopMatrix();
    }
}

void HeroCar::drawgod()
{
    i++;
    if(i>4) i=0;
    drawCopCall(0);
    drawCopCall(1);
    drawCopCall(2);
    drawCopCall(3);
    drawCopCall(4);
}

bool HeroCar::heroCollides() 
{
    const int THRESHOLD = 5;
    for (int carno=0; carno<5; carno++) {
        float dist = pow((pow(heromidx-copmid[carno][0],2) + pow(heromidy-copmid[carno][1],2)), 2);
        if (dist <= THRESHOLD)
            return true;
    }
    return false;
}

void HeroCar::resetPositions()
{ 
    // need to reset positions
}
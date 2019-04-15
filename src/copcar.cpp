#include "../include/copcar.h"

const int copBounds[10][8][3]={
    {{20,95,15},{20,105,15},{30,105,15},{30,95,15},{40,115,0},{40,125,0},{50,125,0},{50,115,0}}, 
    {{90,5,15},{90,15,15},{100,15,15},{100,5,15},{110,25,0},{110,35,0},{120,35,0},{120,25,0}},
    {{400,400,15},{400,410,15},{410,410,15},{410,400,15},{420,420,0},{420,430,0},{430,430,0},{430,420,0}},
    {{200,300,15},{200,310,15},{210,310,15},{210,300,15},{220,320,0},{220,330,0},{230,330,0},{230,320,0}},
    {{400,40,15},{400,50,15},{410,50,15},{410,40,15},{420,60,0},{420,70,0},{430,70,0},{430,60,0}},
};

const float copMid[10][2]={{25,100},{95,10},{405,405},{205,305},{405,45}};
const float copSpeed[10]={0.02,0.02,0.02,0.05,0.05};

CopCar::CopCar(int carno)
{
    this->carno = carno; 
    mid[0] = copMid[carno][0];
    mid[1] = copMid[carno][1];
    mid[2] = 0;
    colorMode = 0;
}

void CopCar::calMovement()
{
    mid[0] = copMid[carno][0] + change[0];
    mid[1] = copMid[carno][1] + change[1];
    if (colorMode==0)
    {
        if(destx>mid[0])
            change[0]+=copSpeed[carno];
        else if (destx<mid[0])
            change[0]-=copSpeed[carno];
        if (desty>mid[1])
            change[1]+=copSpeed[carno];
        else if (desty<mid[1])
            change[1]-=copSpeed[carno];
    }
}

void CopCar::drawCar(int a,int b,int c,int d)
{
    calMovement();
    glBegin(GL_POLYGON);
        glVertex3iv(copBounds[carno][a]);
        glVertex3iv(copBounds[carno][b]);
        glVertex3iv(copBounds[carno][c]);
        glVertex3iv(copBounds[carno][d]);
    glEnd();
}


void CopCar::drawCarCall(GLfloat destx, GLfloat desty)
{   
    this->destx = destx;
    this->desty = desty;

    colors::colorNames primary = (colorMode<4)?colors::RED:colors::BLUE;
    colors::colorNames secondary = (colorMode<4)?colors::BLUE:colors::RED;
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(change[0],change[1],0);
    setGlColor(primary);
    drawCar(0,3,2,1);
    setGlColor(primary);
    drawCar(2,3,7,6);
    setGlColor(primary);
    drawCar(0,4,7,3);
    setGlColor(primary);
    drawCar(1,2,6,5);
    setGlColor(secondary);
    drawCar(4,5,6,7);
    setGlColor(primary);
    drawCar(0,1,5,4);
    glPopMatrix();
}

void CopCar::changeColor() {
    colorMode = (colorMode + 1)%4;
}

void CopCar::resetPositions() { 
    change[0] = change[1] = change[2] = 0;
    calMovement();
}
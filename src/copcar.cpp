#include "../include/copcar.h"

const int copBounds[10][8][3]={
    {{20,95,15},{20,105,15},{30,105,15},{30,95,15},{40,115,0},{40,125,0},{50,125,0},{50,115,0}}, 
    {{90,5,15},{90,15,15},{100,15,15},{100,5,15},{110,25,0},{110,35,0},{120,35,0},{120,25,0}},
    {{400,400,15},{400,410,15},{410,410,15},{410,400,15},{420,420,0},{420,430,0},{430,430,0},{430,420,0}},
    {{200,300,15},{200,310,15},{210,310,15},{210,300,15},{220,320,0},{220,330,0},{230,330,0},{230,320,0}},
    {{400,40,15},{400,50,15},{410,50,15},{410,40,15},{420,60,0},{420,70,0},{430,70,0},{430,60,0}},
};

const float copMid[10][2]={{25+20,100+20},{95+20,10+20},{405+20,405+20},{205+20,305+20},{405+20,45+20}};
float copSpeed[10]={0.5,0.5,0.6,0.6,0.8};
float icopSpeed[10]={0.5,0.5,0.6,0.6,0.8};

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

void CopCar::drawCar()
{
    calMovement();
    glPushMatrix();
    glTranslatef( mid[0],mid[1],0);
    glRotatef(45,1,0,0);
    glutSolidTorus(3,9,30, 30);
    glPopMatrix();
}


void CopCar::drawCarCall(GLfloat destx, GLfloat desty)
{   
    this->destx = destx;
    this->desty = desty;
    if(copSpeed[0]<1.1)
        copSpeed[0]+=0.0003;
    if(copSpeed[1]<1)
        copSpeed[1]+=0.0001;
    if(copSpeed[2]<1)
        copSpeed[2]+=0.0002;
    if(copSpeed[3]<1)
        copSpeed[3]+=0.0005;
    if(copSpeed[4]<1)
        copSpeed[4]+=0.00033;

    colors::colorNames primary = (colorMode<9)?colors::RED:colors::BLUE;
    colors::colorNames secondary = (colorMode<9)?colors::BLUE:colors::RED;
    glPushMatrix();
    glLoadIdentity();
    setGlColor(primary);
    drawCar();
    glPopMatrix();
}

void CopCar::changeColor() {
    colorMode = (colorMode + 1)%11;
}

bool CopCar::collides(GLfloat **obstacles, GLfloat **trees, CopCar** cops, int obstacleCount, int treeCount, int copCount) 
{
    const int THRESHOLD = 15;
    const GLfloat midx = mid[0], midy = mid[1];
    for (int carno=0; carno<copCount; carno++) {
        if (carno == this->carno) continue;
        float dist = pow((pow(midx-cops[carno]->mid[0],2) + pow(midy-cops[carno]->mid[1],2)), 2);
        if (dist <= THRESHOLD)
            return true;
    }
    if (obstacles!=nullptr){
        for (int obno=0; obno<obstacleCount; obno++) {
            //std::cout<<obstacles[obno][0]<<"<->"<<midx<<" "<<obstacles[obno][1]<<"<->"<<midy<<std::endl;
            float dist = pow((pow(midx-obstacles[obno][0],2) + pow(midy-obstacles[obno][1],2)), 2);
            if (dist <= THRESHOLD+10)
                return true;
        }
        //std::cout<<"No obstacle collision";
    }
    if (trees!=nullptr) {
        for (int treeno=0; treeno<treeCount; treeno++) {
            float dist = pow((pow(midx-trees[treeno][0],2) + pow(midy-trees[treeno][1],2)), 2);
            if (dist <= THRESHOLD+10)
                return true;
        }
        //std::cout<<"No tree collision";
    }
    return false;
}


void CopCar::resetPositions(bool resetSpeed = false) { 
    change[0] = change[1] = change[2] = 0;
    if (resetSpeed) copSpeed[carno]=icopSpeed[carno];
    calMovement();
}
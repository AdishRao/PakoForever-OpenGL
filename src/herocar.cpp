#include "../include/herocar.h"

int i = 0;
const float HEROSPEED = 0.9;
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
    setGlColor(colors::RED);
    drawCar(0,3,2,1);
    if(currentdir==2)
    setGlColor(colors::WHITE);
    else
    setGlColor(colors::CYAN);
    drawCar(2,3,7,6);
    if(currentdir==1)
    setGlColor(colors::WHITE);
    else
    setGlColor(colors::CYAN);
    drawCar(0,4,7,3);
    
    if (currentdir==0)
    setGlColor(colors::WHITE);
    else 
    setGlColor(colors::CYAN);
    drawCar(1,2,6,5);

    setGlColor(colors::YELLOW);
    drawCar(4,5,6,7);

    if(currentdir == 3)
    setGlColor(colors::WHITE);
    else
    setGlColor(colors::CYAN);
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
    setGlColor(colors::WHITE);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2d(heromidx,heromidy);
    glEnd();
    glPushMatrix(); 
    switch(currentdir)
    {
        // up
        case 0: 
            change_y+=HEROSPEED;
            break;
        // down
        case 1:
            change_y-=HEROSPEED;
            break;
        // right
        case 2:
            change_x+=HEROSPEED;
            break;
        // left
        case 3:
            change_x-=HEROSPEED;
            break;
    }
    //std::cout<<"CHANGE"<<change_x<<" "<<change_y<<std::endl;
    heromidx = 80 + change_x;
    heromidy = 80 + change_y;
    glTranslatef(change_x,change_y,0);
    drawCarCall();
    glPopMatrix();
}

bool HeroCar::heroCollides(GLfloat **obstacles, GLfloat **trees, CopCar** cops, int obstacleCount, int treeCount, int copCount) 
{
    const int THRESHOLD = 5;
    for (int carno=0; carno<copCount; carno++) {
        float dist = pow((pow(heromidx-cops[carno]->mid[0],2) + pow(heromidy-cops[carno]->mid[1],2)), 2);
        if (dist <= THRESHOLD)
            return true;
    }
    if (obstacles!=nullptr){
        for (int obno=0; obno<obstacleCount; obno++) {
            //std::cout<<obstacles[obno][0]<<"<->"<<heromidx<<" "<<obstacles[obno][1]<<"<->"<<heromidy<<std::endl;
            float dist = pow((pow(heromidx-obstacles[obno][0],2) + pow(heromidy-obstacles[obno][1],2)), 2);
            if (dist <= THRESHOLD+10)
                return true;
        }
        //std::cout<<"No obstacle collision";
    }
    if (trees!=nullptr) {
        for (int treeno=0; treeno<treeCount; treeno++) {
            float dist = pow((pow(heromidx-trees[treeno][0],2) + pow(heromidy-trees[treeno][1],2)), 2);
            if (dist <= THRESHOLD+10)
                return true;
        }
        //std::cout<<"No tree collision";
    }
    return false;
}

void HeroCar::resetPositions()
{ 
    // need to reset positions
    change_x = 0;
    change_y = 0;
}
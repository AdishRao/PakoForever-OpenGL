#include "../include/herocar.h"

int i = 0;
const float HEROSPEED = 1.2;

void HeroCar::drawCarTor()
{
    glPushMatrix();
    glTranslatef(heromidx, heromidy, 0);
    glRotatef(45,1,0,0);
    glutSolidTorus(3,9,30, 30);
    glPopMatrix();
}

void HeroCar::drawCarCall()
{
    setGlColor(colors::CYAN);
    drawCarTor();
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
    heromidx = 80 + change_x;  // When you're changing this also change it in the reset posion function
    heromidy = 80 + change_y;
    //glTranslatef(change_x,change_y,0);
    drawCarCall();
    glPopMatrix();
}

bool HeroCar::heroCollides(GLfloat **obstacles, GLfloat **trees, CopCar** cops, int obstacleCount, int treeCount, int copCount) 
{
    const int THRESHOLD = 45;
    if ( heromidx < 0 || heromidx >= 500 || heromidy <0 || heromidy >= 500) { 
        return true;
    }
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
    heromidx =  heromidy = 0;
    change_x = 0;
    change_y = 0;
}
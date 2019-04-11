#ifndef HEROCAR_H
#define HEROCAR_H

#include "global.h"

class HeroCar { 
    private:                   //0              1           2       3           4           5       6       7
        int currentpos[8][3] = {{55,55,15},{55,65,15},{65,65,15},{65,55,15},{75,75,0},{75,85,0},{85,85,0},{85,75,0}};
        float change_x=0; // 0 = left , 1 = right
        float change_y=0; // 0 = bottom, 1 = top
        int change_z=0; // 0 = near, 1 = far
        int currentdir=0;
    public:
        void drawCarCall();
        void drawCar(int,int,int,int);
        void moveForward();
        void changeDirection(unsigned char);

        void drawCopCall1();
        void drawCop1(int,int,int,int);
        void calmovement1(int[8][3]);

        void drawCopCall2();
        void drawCop2(int,int,int,int);
        void calmovement2(int[8][3]);
};

#endif
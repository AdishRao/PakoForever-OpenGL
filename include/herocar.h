#ifndef HEROCAR_H
#define HEROCAR_H

#include "global.h"

class HeroCar { 
    private:                   //0              1           2       3           4           5       6       7
        int currentpos[8][3] = {{25,25,15},{25,35,15},{35,35,15},{35,25,15},{45,45,0},{45,55,0},{55,55,0},{55,45,0}};
        float change_x=0; // 0 = left , 1 = right
        float change_y=0; // 0 = bottom, 1 = top
        int change_z=0; // 0 = near, 1 = far
        int currentdir=0;
        float change_cop_x = 0;
        float change_cop_y = 0;
    public:
        void drawCarCall();
        void drawCar(int,int,int,int);
        void moveForward();
        void changeDirection(unsigned char);
        void drawCopCall();
        void drawCop(int,int,int,int);
        void calmovement(int[8][3]);
};

#endif
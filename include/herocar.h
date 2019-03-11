#ifndef HEROCAR_H
#define HEROCAR_H

#include "global.h"

class HeroCar { 
    private:
        int currentpos[4][2] = {{45,45},{55,45},{55,55},{45,55}};
        float change_x=0; // 0 = left , 1 = right
        float change_y=0; // 0 = bottom, 1 = top
        int change_z=0; // 0 = near, 1 = far
        int currentdir=0;
    public:
        void drawCar();
        void moveForward();
        void changeDirection(unsigned char);
};

#endif
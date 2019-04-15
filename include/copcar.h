#ifndef COPCAR_H
#define COPCAR_H

#include "global.h"

class CopCar { 
    private:
        GLfloat change[3]; // Change in coordinates [0:x, 1:y, 2:z]
    public:
        GLfloat mid[3]; // Middle of the car [0:x, 1:y, 2:z]
        int carno; // Used to index bounds and speed data 
        int colorMode; // either 0 or 1  
        GLfloat destx, desty; // Location to move the car to
        CopCar(int);
        void calMovement();
        void drawCar(int,int,int,int);
        void drawCarCall(GLfloat,GLfloat);
        void changeColor(); 
        void resetPositions();
};

#endif

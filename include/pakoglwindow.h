#ifndef PAKOGLWINDOW_H
#define PAKOGLWINDOW_H

#include "global.h"
#include "herocar.h"

class PakoGLWindow { 
    private:
        GLdouble viewer[3] = {50,50,20};
        HeroCar car;
        void drawObstacles(int, double, colors::colorNames);
    public:
        void initialize();
        void display();
        void idle();
        void keypressed(unsigned char, int, int);
        void specialKey(int, int, int);
        void myReshape(int,int);

};

#endif
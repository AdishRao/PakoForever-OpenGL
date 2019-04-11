#ifndef PAKOGLWINDOW_H
#define PAKOGLWINDOW_H

#include "global.h"
#include "herocar.h"

class PakoGLWindow { 
    private:
        GLdouble viewer[3] = {60,60,20};
        int currentScreen;
        HeroCar car;
        void drawObstacles(int, double, colors::colorNames);
    public:
        void initialize();
        void display();
        void idle();
        void keypressed(unsigned char, int, int);
        void specialKey(int, int, int);
        void myReshape(int,int);
        void startScreen();
};

#endif
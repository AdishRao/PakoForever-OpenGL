#ifndef PAKOGLWINDOW_H
#define PAKOGLWINDOW_H

#include "global.h"
#include "herocar.h"

class PakoGLWindow { 
    private:
        GLdouble viewer[3] = {0,0,0};
        int currentScreen;
        HeroCar car;
        void drawObstacles(int, double, colors::colorNames);
    public:
        void initialize();
        void display();
        void idle();
        void keypressed(unsigned char, int, int);
        void specialKey(int, int, int);
        void startScreen();
};

#endif
#ifndef PAKOGLWINDOW_H
#define PAKOGLWINDOW_H

#include "global.h"
#include "herocar.h"

class PakoGLWindow { 
    private:
        GLdouble viewer[3] = {60,60,20};
        enum screen{startgame, gamescreen, gameover} currentScreen;
        HeroCar car;
        void drawObstacles(int, double, colors::colorNames);
        void drawTree(int,colors::colorNames);
        void drawTime();
    public:
        void initialize();
        void display();
        void idle();
        void keypressed(unsigned char, int, int);
        void specialKey(int, int, int);
        void startScreen();
        void gameOverScreen();
};

#endif
#ifndef PAKOGLWINDOW_H
#define PAKOGLWINDOW_H

#include "global.h"
#include "herocar.h"

class PakoGLWindow { 
    private:
        GLdouble viewer[3] = {60,60,20};
        enum screen{startgame, gamescreen, gameover} currentScreen;
        HeroCar car;
        GLfloat **obstacles = nullptr, **trees =nullptr;
        int obstacleCount,treeCount;
        void drawObstacles(double, colors::colorNames);
        void drawTree(colors::colorNames);
        void drawTime();
        void freeMemory();
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
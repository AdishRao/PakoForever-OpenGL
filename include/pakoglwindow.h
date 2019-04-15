#ifndef PAKOGLWINDOW_H
#define PAKOGLWINDOW_H

#include "global.h"
#include "herocar.h"
#include "copcar.h"

class PakoGLWindow { 
    private:
        GLdouble viewer[3] = {60,60,20};
        enum screen{startgame, gamescreen, gameover} currentScreen;
        double time;
        HeroCar car;
        int copCount; 
        GLfloat **obstacles = nullptr, **trees =nullptr;
        CopCar **cops;
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
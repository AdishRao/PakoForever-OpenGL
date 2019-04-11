#ifndef GLOBAL_H
#define GLOBAL_H

#ifdef __linux__
#include <GL/glut.h>
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h> 
#endif

#include <iostream>
#include <math.h>
#include <string.h>

namespace colors
{
    enum colorNames {
        BLACK=0, 
        RED=1, 
        GREEN=2, 
        BLUE=3, 
        CYAN=4, 
        YELLOW=5, 
        PINK=6, 
        WHITE=7
    };
}

void colorMeSilly(colors::colorNames);

void glText(float x, float y, float r, float g, float b, void* font, std::string string);


#endif
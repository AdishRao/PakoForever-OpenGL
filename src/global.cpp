#include "../include/global.h"

GLfloat color[3] = {0, 0, 0};

// sets global color vector 
void colorMeSilly(colors::colorNames name){
    color[0] = color[1] = color[2] = 0;
    switch (name) {
        case colors::BLACK: break;
        case colors::RED: 
            color[0] = 1;
            break;
        case colors::GREEN:
            color[1] = 1;
            break;
        case colors::BLUE:
            color[2] = 1;
            break;
        case colors::YELLOW:
            color[0] = color[1] = 1;
            break; 
        case colors::CYAN:
            color[1] = color[2] = 1;
            break;
        case colors::PINK:
            color[0] = color[2] = 1;
            break;
        case colors::WHITE:
            color[0] = color[1] = color[2] = 1;
    }
    glColor3fv(color);
}; 

// prints text 
void glText(float x, float y, float r, float g, float b, void* font, std::string string)
{
  glColor3f( r, g, b );
  glRasterPos2f(x, y);
  int len, i;
  len = (int) string.length();
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}

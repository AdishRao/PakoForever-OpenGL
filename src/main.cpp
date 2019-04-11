#include "../include/global.h"
#include "../include/pakoglwindow.h"

PakoGLWindow window;

class Callbacks { 
    public:
        static void display() {  window.display(); }
        static void idle() {  window.idle(); }
        static void specialKey(int k, int x, int y) { window.specialKey(k,x,y); }
        static void keypressed(unsigned char k, int x, int y) { window.keypressed(k,x,y); }
        static void reshape(int x, int y) { window.myReshape(x,y); }
};

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,700);
    glutCreateWindow("PAKO FOREVER!");
    glEnable(GL_DEPTH_TEST); 
    window.initialize();
    glutDisplayFunc(Callbacks::display);
    glutIdleFunc(Callbacks::idle);
    glutSpecialFunc(Callbacks::specialKey);
    glutKeyboardFunc(Callbacks::keypressed);
    //glutReshapeFunc(Callbacks::reshape);
    glutMainLoop();
    return 0;
}
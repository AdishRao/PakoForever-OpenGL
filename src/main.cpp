#include "../include/global.h"
#include "../include/pakoglwindow.h"

PakoGLWindow window;

class Callbacks { 
    public:
        static void display() {  window.display(); }
        static void idle() {  window.idle(); }
        static void specialKey(int k, int x, int y) { window.specialKey(k,x,y); }
        static void keypressed(unsigned char k, int x, int y) { window.keypressed(k,x,y); }
};

void playSong(){ 
    system("afplay song.mp3");
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,700);
    glutCreateWindow("PAKO FOREVER!");
    glEnable(GL_DEPTH_TEST); 
    window.initialize();
    //std::thread th1(playSong);
    glutDisplayFunc(Callbacks::display);
    glutIdleFunc(Callbacks::idle);
    glutSpecialFunc(Callbacks::specialKey);
    glutKeyboardFunc(Callbacks::keypressed);
    glutMainLoop();
    return 0;
}
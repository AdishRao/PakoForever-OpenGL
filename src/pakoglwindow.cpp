#include "../include/pakoglwindow.h"

int flag = 1;
auto start = std::chrono::system_clock::now();

void PakoGLWindow::keypressed(unsigned char key, int x, int y)
{
    if (currentScreen==startgame | currentScreen==gameover) 
    { 
        currentScreen = gamescreen;
        return;
    } 
    switch(key) 
    { 
        case 'w': 
        case 's': 
        case 'd': 
        case 'a': 
                car.changeDirection(key);
                break;
        case 'q':
            viewer[0] ++; 
            break;
        case 'Q':
            viewer[0] --;
            break;
        case 'r':
            viewer[1] ++; 
            break;
        case 'R':
            viewer[1] --;
            break;
        case 'e':
            viewer[2] ++; 
            break;
        case 'E':
            viewer[2] --;
    }
    std::cout<<key<<std::endl;
}

void PakoGLWindow::specialKey(int key, int x, int y)
{ 
    switch (key)
    {
        case GLUT_KEY_UP:
        case GLUT_KEY_DOWN:
        case GLUT_KEY_LEFT:
        case GLUT_KEY_RIGHT: break;
    }
}

// Draws 9 sided polygons in random locations using translate
// Polygon formula taken from  https://gist.github.com/kenpower/3782654 and modified because it drew one side less
void PakoGLWindow::drawObstacles(double radius, colors::colorNames color) 
{
    // initialize random seed - otherwise random positions generated each time when display calls. 
    srand (33);
    // generates M sided polygon
    const int sides=9;
    // defining bounds for ortho
    const int xMin=0, xMax=500, yMin=0, yMax=500;
    
    obstacles = new GLfloat*[obstacleCount];   
    
    for (int i=0; i<obstacleCount; i++){
        // defining bounds used to limit centers of polygon 
        const int xCenter = rand() % xMax + xMin; 
        const int yCenter = rand() % yMax + yMin;
        
        obstacles[i] = new GLfloat[2];
        obstacles[i][0] = xCenter;
        obstacles[i][1] = yCenter;
        glPointSize(8);
        setGlColor(colors::YELLOW);
        glBegin(GL_POINTS);
        glVertex2f(xCenter,yCenter);
        glEnd();

        glBegin(GL_POLYGON);
        for(int i=0;i<=sides;i++)
        {
            double angle=i*2*M_PI/sides;
            setGlColor(color); // using instead of glColor
            glVertex2d(xCenter+radius*cos(angle),yCenter+radius*sin(angle));
            
        }
        glEnd();
    }
}

void PakoGLWindow::drawTree(colors::colorNames color) {
    // initialize random seed - otherwise random positions generated each time when display calls. 
    srand (30);
    // defining bounds for ortho
    const int xMin=0, xMax=500, yMin=0, yMax=500;
    trees = new GLfloat*[treeCount];

    for (int i=0; i<treeCount; i++){
        // defining bounds used to limit centers of polygon 
        const int xCenter = rand() % xMax + xMin; 
        const int yCenter = rand() % yMax + yMin;
        trees[i] = new GLfloat[2];
        trees[i][0] = xCenter;
        trees[i][1] = yCenter;
        glPushMatrix();
        glLoadIdentity();
        glTranslatef(xCenter,yCenter,0);
        glPointSize(10);
        setGlColor(colors::YELLOW);
        glBegin(GL_POINTS);
        glVertex2f(0,0);
        glEnd();
        setGlColor(color); // using instead of glColor
        glRotatef(-90,1,0,0);
        glutSolidCone(5,15,50,50);
        glPopMatrix();	
    }
}

void PakoGLWindow::drawTime()
{
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    auto str = std::to_string(elapsed_seconds.count()); 
    time = elapsed_seconds.count();
    std::string strin = "Time: "+str;
    glColor3f(1,1,1);
    glRasterPos2f(10, 480);
    int len, i;
    len = strin.length();
    for (i = 0; i < len; i++) 
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, strin[i]);
    }
}

void PakoGLWindow::initialize()
{
    currentScreen = startgame;
    obstacleCount = 20;
    treeCount = 10;
    copCount = 5;
    cops = new CopCar*[copCount];
    for (int i=0; i<copCount; i++) { 
        cops[i] = new CopCar(i);
        cops[i]->resetPositions();
    }

    glMatrixMode(GL_PROJECTION);
    glOrtho(0.0,500.0,0.0,500.0,-2.0,15.0);
    glMatrixMode(GL_MODELVIEW);
}

void PakoGLWindow::display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    switch (currentScreen) 
    {
        case startgame:
            startScreen();
            break; 
        case gamescreen:
                if ( car.heroCollides(obstacles,trees,cops,obstacleCount,treeCount,copCount) ) {
                    car.resetPositions();
                    for (int i=0; i<copCount; i++) { 
                        cops[i]->resetPositions();
                    }
                    currentScreen = gameover;
                    time = 0;
                    glutPostRedisplay();
                }
                else { 
                    car.moveForward();

                    for (int i=0; i<copCount; i++) { 
                        cops[i]->changeColor();
                        cops[i]->drawCarCall(car.heromidx, car.heromidy);
                    }
                    
                    // obstacleCount, radius, color
                    freeMemory();
                    drawObstacles(3, colors::BROWN);
                    drawTree(colors::GREEN);
                    drawTime();
                }
                break;
        case gameover:
            std::cout<<"gameover";
            gameOverScreen();
    }
    glFlush();
    glutSwapBuffers();
}

void PakoGLWindow::idle() { 
    if ( currentScreen == gamescreen ){
        glutPostRedisplay();
    }
}

void PakoGLWindow::startScreen()
{
    glClearColor(0,0,0,0);
    glText(200,250,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24, "Pako Forever!");
    glText(180,230,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24, "Press any key to continue");
}

void PakoGLWindow::gameOverScreen()
{

    glClearColor(0,0,0,0);
    glText(200,250,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24, "END GAME");
    glText(182,230,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24, "Your Score is "+std::to_string(time));
    glText(178,210,1,1,1,GLUT_BITMAP_TIMES_ROMAN_24, "Press any key to start again");
}

void PakoGLWindow::freeMemory()
{
    if (obstacles!=nullptr){
        for(int i=0; i<obstacleCount; i++) { 
            delete obstacles[i];
        }
        delete obstacles;
    }
    if (trees!=nullptr){
        for(int i=0; i<treeCount; i++) { 
            delete trees[i];
        }
        delete trees;
    }
    
}
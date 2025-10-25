#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isDay = true;
float cloudX = 0.0f;
float birdX = 0.0f;
float car1X = 0.0f;
float car2X = 0.5f;
float personY[3] = {0.18f, 0.19f, 0.185f}; // Start below road
float personSpeed[3] = {0.0008f, 0.0006f, 0.0007f}; // Individual speeds

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * i / num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawCar(float x, float y, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x+0.12f, y);
    glVertex2f(x+0.12f, y+0.05f);
    glVertex2f(x, y+0.05f);
    glEnd();

    glColor3f(0,0,0);
    drawCircle(x+0.03f, y-0.01f, 0.015f, 20);
    drawCircle(x+0.09f, y-0.01f, 0.015f, 20);
}

void drawPerson(float x, float y) {
    glColor3f(1.0f, 0.8f, 0.6f);
    drawCircle(x, y+0.02f, 0.01f, 20);

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(x, y+0.01f);
    glVertex2f(x, y-0.02f);
    glVertex2f(x-0.01f, y);
    glVertex2f(x+0.01f, y);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(x, y-0.02f);
    glVertex2f(x-0.01f, y-0.04f);
    glVertex2f(x, y-0.02f);
    glVertex2f(x+0.01f, y-0.04f);
    glEnd();
}

// Houses
void drawHouse(float x, float y, float w, float h,
               float bodyR, float bodyG, float bodyB,
               float roofR, float roofG, float roofB) {
    // Reduce house body height
    float newH = h * 0.6f; // decrease height to 60% of original

    // House body
    glColor3f(bodyR, bodyG, bodyB);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + newH);
    glVertex2f(x, y + newH);
    glEnd();

    // Smaller roof (triangle)
    glColor3f(roofR, roofG, roofB);
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.01f, y + newH);         // left corner
    glVertex2f(x + w / 2, y + newH + 0.05f); // top (roof height smaller)
    glVertex2f(x + w + 0.01f, y + newH);     // right corner
    glEnd();

    // Door
    glColor3f(0.4, 0.2, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(x + w * 0.35f, y);
    glVertex2f(x + w * 0.65f, y);
    glVertex2f(x + w * 0.65f, y + newH * 0.5f);
    glVertex2f(x + w * 0.35f, y + newH * 0.5f);
    glEnd();
}


// Modern City Buildings
void drawModernBuilding(float x, float y, float w, float h, float r, float g, float b) {
    glColor3f(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(x,y);
    glVertex2f(x+w,y);
    glVertex2f(x+w,y+h);
    glVertex2f(x,y+h);
    glEnd();

    // Windows
    glColor3f(1,1,0.8f);
    float winW = w/5;
    float winH = h/10;
    for(float i=y+h*0.05; i<y+h; i+=winH*2){
        for(float j=x+w*0.05; j<x+w; j+=winW*2){
            glBegin(GL_QUADS);
            glVertex2f(j,i);
            glVertex2f(j+winW,i);
            glVertex2f(j+winW,i+winH);
            glVertex2f(j,i+winH);
            glEnd();
        }
    }
}

// Tree
void drawTree(float x, float y) {
    glColor3f(0.36f,0.25f,0.2f);
    glBegin(GL_QUADS);
    glVertex2f(x-0.01f, y);
    glVertex2f(x+0.01f, y);
    glVertex2f(x+0.015f, y+0.12f);
    glVertex2f(x-0.015f, y+0.12f);
    glEnd();

    glColor3f(0.0f,0.5f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x-0.05f, y+0.12f);
    glVertex2f(x, y+0.25f);
    glVertex2f(x+0.05f, y+0.12f);

    glVertex2f(x-0.04f, y+0.17f);
    glVertex2f(x, y+0.27f);
    glVertex2f(x+0.04f, y+0.17f);

    glVertex2f(x-0.03f, y+0.21f);
    glVertex2f(x, y+0.31f);
    glVertex2f(x+0.03f, y+0.21f);
    glEnd();
}

// Birds
void drawBird(float x, float y) {
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x+0.015f, y+0.01f);
    glVertex2f(x+0.015f, y+0.01f);
    glVertex2f(x+0.03f, y);
    glEnd();
}

static void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Sky
    if(isDay) glColor3f(0.53f,0.81f,0.98f);
    else glColor3f(0.0f,0.1f,0.2f);
    glBegin(GL_QUADS);
    glVertex2f(0.0,1.0);
    glVertex2f(1.0,1.0);
    glVertex2f(1.0,0.0);
    glVertex2f(0.0,0.0);
    glEnd();

    // Ground
    glColor3f(0.0,0.6,0.0);
    glBegin(GL_QUADS);
    glVertex2f(0.0,0.0);
    glVertex2f(1.0,0.0);
    glVertex2f(1.0,0.3);
    glVertex2f(0.0,0.3);
    glEnd();

    // Road
    glColor3f(0.2f,0.2f,0.2f);
    glBegin(GL_QUADS);
    glVertex2f(0.0,0.22);
    glVertex2f(1.0,0.22);
    glVertex2f(1.0,0.28);
    glVertex2f(0.0,0.28);
    glEnd();

    // Road lines
    glColor3f(1,1,1);
    glLineWidth(2);
    glBegin(GL_LINES);
    for(float i=0;i<1.0;i+=0.08){
        glVertex2f(i,0.25);
        glVertex2f(i+0.04,0.25);
    }
    glEnd();

    // Sun/Moon
    if(isDay) glColor3f(1.0,1.0,0.0);
    else glColor3f(1.0,1.0,1.0);
    drawCircle(0.85,0.85,0.07,50);

    // Houses
    drawHouse(0.05,0.3,0.12,0.2,0.8,0.5,0.4,0.5,0.1,0.0);
    drawHouse(0.2,0.3,0.2,0.25,1.0,0.8,0.4,0.6,0.2,0.0);
    drawHouse(0.5,0.3,0.15,0.22,0.9,0.6,0.3,0.7,0.3,0.0);

    // Modern buildings
    drawModernBuilding(0.7,0.3,0.08,0.35,0.4,0.4,0.5);
    drawModernBuilding(0.82,0.3,0.05,0.25,0.5,0.5,0.6);

    // Tree
    drawTree(0.65,0.3);

    // Clouds
    if(isDay){
        glColor3f(1,1,1);
        drawCircle(0.2 + cloudX,0.85,0.04,30);
        drawCircle(0.25 + cloudX,0.88,0.04,30);
        drawCircle(0.3 + cloudX,0.85,0.04,30);
    }

    // Birds
    drawBird(0.4 + birdX,0.8);
    drawBird(0.5 + birdX,0.82);
    drawBird(0.6 + birdX,0.78);

    // Cars (on road)
    drawCar(car1X, 0.28f, 1, 0, 0);
    drawCar(car2X, 0.26f, 0, 0, 1);

    // Persons (crossing road)
    drawPerson(0.8, personY[0]);
    drawPerson(0.6, personY[1]);
    drawPerson(0.7, personY[2]);




    glFlush();
}

void update(int value) {
    // Clouds
    cloudX += 0.001;
    if(cloudX > 1.2) cloudX = -0.3;

    // Birds
    birdX += 0.002;
    if(birdX > 1.2) birdX = -0.4;

    // Cars
    car1X += 0.002;
    if(car1X > 1.0) car1X = -0.12;

    car2X += 0.003;
    if(car2X > 1.0) car2X = -0.12;

    // Persons (cross road)
    for(int i=0;i<3;i++){
        personY[i] += personSpeed[i];
        if(personY[i]>0.33f) personY[i]=0.18f;  // Reset after crossing
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void keyboard(unsigned char key, int x, int y){
    if(key=='t' || key=='T'){
        isDay = !isDay;
        glutPostRedisplay();
    }
}

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-10.0,10.0);
}

int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Village & Modern City with Crossing Pedestrians");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0,update,0);
    glutMainLoop();
    return 0;
}

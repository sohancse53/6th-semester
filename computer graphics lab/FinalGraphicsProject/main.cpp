#ifdef _WIN32
#include <windows.h>
#endif
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// --------------------- Scene state -------------------------
bool isDay = true;
float cloudX = 0.0f;
float cloud2X = -0.3f;
float birdX = 0.0f;
float car1X = 0.0f;
float car2X = 0.5f;

// ------------pedestrians: x,y positions and speeds--------------
float personX[5] = {0.58f, 0.62f, 0.66f, 0.70f, 0.74f};
float personY[5] = {0.18f, 0.16f, 0.185f, 0.17f, 0.19f};


// -------------Normalized car speeds-----------------------------
float car1Speed = 0.0012f;
float car2Speed = 0.0014f;

// ----------------------- objects -----------------------------------
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * (float)M_PI * (float)i / (float)num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

// ------------------ Clouds  --------------------
void drawCloud(float x, float y, float scale) {
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x - 0.05f , y, 0.035f * scale, 28);
    drawCircle(x - 0.02f , y + 0.02f * scale, 0.045f * scale, 28);
    drawCircle(x + 0.03f , y + 0.03f * scale, 0.05f * scale, 28);
    drawCircle(x + 0.07f , y + 0.015f * scale, 0.04f * scale, 28);
    drawCircle(x + 0.03f , y - 0.02f * scale, 0.035f * scale, 28);
    drawCircle(x - 0.03f , y - 0.02f * scale, 0.03f * scale, 28);
}

// -------------------- Sports Car ------------------------------
void drawSportsCar(float x, float y, float r, float g, float b) {
    // Body
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + 0.12f, y);
    glVertex2f(x + 0.11f, y + 0.03f);
    glVertex2f(x + 0.09f, y + 0.05f);
    glVertex2f(x + 0.03f, y + 0.05f);
    glVertex2f(x + 0.01f, y + 0.03f);
    glEnd();

    // ---------------Windshield accent--------------------------
    glColor3f(0.0f, 0.8f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(x + 0.02f, y + 0.03f);
    glVertex2f(x + 0.04f, y + 0.045f);
    glVertex2f(x + 0.08f, y + 0.045f);
    glVertex2f(x + 0.10f, y + 0.03f);
    glEnd();

    //-------------------- Wheels-------------------------------
    glColor3f(0, 0, 0);
    drawCircle(x + 0.03f, y - 0.01f, 0.015f, 20);
    drawCircle(x + 0.09f, y - 0.01f, 0.015f, 20);
}

// -------------------------Person -----------------------------
void drawPerson(float x, float y) {
    // Head
    glColor3f(1.0f, 0.85f, 0.7f);
    drawCircle(x, y + 0.02f, 0.01f, 20);

    // Body and limbs
    glColor3f(0.0f, 0.0f, 0.6f);
    glBegin(GL_LINES);
    glVertex2f(x, y + 0.01f); glVertex2f(x, y - 0.02f); // torso
    glVertex2f(x - 0.01f, y); glVertex2f(x + 0.01f, y); // arms
    glVertex2f(x, y - 0.02f); glVertex2f(x - 0.01f, y - 0.04f); // left leg
    glVertex2f(x, y - 0.02f); glVertex2f(x + 0.01f, y - 0.04f); // right leg
    glEnd();
}

// ---------- Kid (small person) ----------
void drawKid(float x, float y) {
    //head
    glColor3f(1.0f, 0.85f, 0.7f);
    drawCircle(x, y + 0.015f, 0.01f, 20);

    //body
    glColor3f(0.0f, 0.0f, 0.6f);
    glBegin(GL_LINES);
    glVertex2f(x, y + 0.01f); glVertex2f(x, y - 0.02f);
    glVertex2f(x - 0.01f, y); glVertex2f(x + 0.01f, y);
    glVertex2f(x, y - 0.02f); glVertex2f(x - 0.01f, y - 0.04f);
    glVertex2f(x, y - 0.02f); glVertex2f(x + 0.01f, y - 0.04f);
    glEnd();
}

// ---------- House ----------
void drawHouse(float x, float y, float w, float h,
               float bodyR, float bodyG, float bodyB,
               float roofR, float roofG, float roofB) {
    float newH = h * 0.6f;

    // Body
    glColor3f(bodyR, bodyG, bodyB);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + newH);
    glVertex2f(x, y + newH);
    glEnd();

    // Roof
    glColor3f(roofR, roofG, roofB);
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.01f, y + newH);
    glVertex2f(x + w / 2, y + newH + 0.05f);
    glVertex2f(x + w + 0.01f, y + newH);
    glEnd();

    // Door
    glColor3f(0.45f, 0.25f, 0.05f);
    glBegin(GL_QUADS);
    glVertex2f(x + w * 0.35f, y);
    glVertex2f(x + w * 0.65f, y);
    glVertex2f(x + w * 0.65f, y + newH * 0.5f);
    glVertex2f(x + w * 0.35f, y + newH * 0.5f);
    glEnd();
}

// ---------- Modern building ----------
void drawModernBuilding(float x, float y, float w, float h, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x, y + h);
    glEnd();

    // windows
    glColor3f(1, 1, 0.9f);
    float winW = w / 6.0f;
    float winH = h / 10.0f;
    for (float yy = y + h * 0.05f; yy < y + h - 0.001f; yy += winH * 2.0f) {
        for (float xx = x + w * 0.02f; xx < x + w - 0.001f; xx += winW * 2.0f) {
            glBegin(GL_QUADS);
            glVertex2f(xx, yy);
            glVertex2f(xx + winW, yy);
            glVertex2f(xx + winW, yy + winH);
            glVertex2f(xx, yy + winH);
            glEnd();
        }
    }
}

// ---------- Tree ----------
void drawTree(float x, float y) {
    // trunk
    glColor3f(0.36f, 0.25f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.01f, y);
    glVertex2f(x + 0.01f, y);
    glVertex2f(x + 0.015f, y + 0.12f);
    glVertex2f(x - 0.015f, y + 0.12f);
    glEnd();

    // foliage (3 tiers)
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.05f, y + 0.12f);
    glVertex2f(x, y + 0.25f);
    glVertex2f(x + 0.05f, y + 0.12f);

    glVertex2f(x - 0.04f, y + 0.17f);
    glVertex2f(x, y + 0.27f);
    glVertex2f(x + 0.04f, y + 0.17f);

    glVertex2f(x - 0.03f, y + 0.21f);
    glVertex2f(x, y + 0.31f);
    glVertex2f(x + 0.03f, y + 0.21f);
    glEnd();
}

// ---------- Bench ----------
void drawBench(float x, float y) {
    glColor3f(0.5f, 0.3f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 0.07f, y);
    glVertex2f(x + 0.07f, y + 0.015f);
    glVertex2f(x, y + 0.015f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x + 0.005f, y - 0.03f);
    glVertex2f(x + 0.015f, y - 0.03f);
    glVertex2f(x + 0.015f, y);
    glVertex2f(x + 0.005f, y);

    glVertex2f(x + 0.055f, y - 0.03f);
    glVertex2f(x + 0.065f, y - 0.03f);
    glVertex2f(x + 0.065f, y);
    glVertex2f(x + 0.055f, y);
    glEnd();
}

// ---------- Bush ----------
void drawBush(float x, float y) {
    glColor3f(0.0f, 0.45f, 0.0f);
    drawCircle(x, y, 0.03f, 20);
    drawCircle(x + 0.03f, y, 0.03f, 20);
    drawCircle(x - 0.03f, y, 0.03f, 20);
}



// ---------- Playground: nicer slide, swing, seesaw ----------
void drawSlideNicer(float x, float y) {
    // ladder
    glColor3f(0.45f, 0.25f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(x + 0.00f, y + 0.00f);
    glVertex2f(x + 0.02f, y + 0.00f);
    glVertex2f(x + 0.02f, y + 0.10f);
    glVertex2f(x + 0.00f, y + 0.10f);
    glEnd();

    // platform
    glColor3f(0.8f, 0.5f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(x + 0.02f, y + 0.09f);
    glVertex2f(x + 0.07f, y + 0.09f);
    glVertex2f(x + 0.07f, y + 0.11f);
    glVertex2f(x + 0.02f, y + 0.11f);
    glEnd();

    // curved slide surface (approximated by small quads)
    glColor3f(0.9f, 0.2f, 0.2f);
    float sx = x + 0.07f;
    float sy = y + 0.095f;
    for (int i = 0; i < 20; ++i) {
        float t = i / 20.0f;
        float nx = sx + t * 0.5f;
        float ny = sy - (0.02f + 0.12f * (t*t)); // curved drop
        glBegin(GL_QUADS);
        glVertex2f(nx, ny);
        glVertex2f(nx + 0.025f, ny);
        glVertex2f(nx + 0.025f, ny - 0.02f);
        glVertex2f(nx, ny - 0.02f);
        glEnd();
    }
}

// A-frame swing with chains and seat
void drawSwingNicer(float x, float y) {
    // A-frame legs
    glColor3f(0.45f, 0.25f, 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x + 0.00f, y + 0.00f);
    glVertex2f(x + 0.03f, y + 0.00f);
    glVertex2f(x + 0.015f, y + 0.15f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(x + 0.07f, y + 0.00f);
    glVertex2f(x + 0.10f, y + 0.00f);
    glVertex2f(x + 0.085f, y + 0.15f);
    glEnd();

    // top bar
    glColor3f(0.4f, 0.2f, 0.05f);
    glBegin(GL_QUADS);
    glVertex2f(x + 0.015f, y + 0.15f);
    glVertex2f(x + 0.085f, y + 0.15f);
    glVertex2f(x + 0.085f, y + 0.155f);
    glVertex2f(x + 0.015f, y + 0.155f);
    glEnd();

    // chains
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(x + 0.03f, y + 0.15f); glVertex2f(x + 0.03f, y + 0.06f);
    glVertex2f(x + 0.07f, y + 0.15f); glVertex2f(x + 0.07f, y + 0.06f);
    glEnd();

    // seat
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(x + 0.025f, y + 0.06f);
    glVertex2f(x + 0.075f, y + 0.06f);
    glVertex2f(x + 0.075f, y + 0.05f);
    glVertex2f(x + 0.025f, y + 0.05f);
    glEnd();
}

// seesaw with fulcrum and plank
void drawSeeSawNicer(float x, float y) {
    // fulcrum base
    glColor3f(0.35f, 0.2f, 0.08f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x + 0.0f, y + 0.0f);
    glVertex2f(x + 0.04f, y + 0.0f);
    glVertex2f(x + 0.02f, y + 0.05f);
    glEnd();

    // plank
    glColor3f(0.85f, 0.5f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.12f, y + 0.05f);
    glVertex2f(x + 0.16f, y + 0.05f);
    glVertex2f(x + 0.16f, y + 0.08f);
    glVertex2f(x - 0.12f, y + 0.08f);
    glEnd();

    // seats at ends
    glColor3f(0.6f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.11f, y + 0.08f);
    glVertex2f(x - 0.07f, y + 0.08f);
    glVertex2f(x - 0.07f, y + 0.09f);
    glVertex2f(x - 0.11f, y + 0.09f);

    glVertex2f(x + 0.12f, y + 0.08f);
    glVertex2f(x + 0.16f, y + 0.08f);
    glVertex2f(x + 0.16f, y + 0.09f);
    glVertex2f(x + 0.12f, y + 0.09f);
    glEnd();
}

// ---------- Bird (simple) ----------
void drawBird(float x, float y) {
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(x, y); glVertex2f(x + 0.015f, y + 0.01f);
    glVertex2f(x + 0.015f, y + 0.01f); glVertex2f(x + 0.03f, y);
    glEnd();
}

// ---------- DISPLAY ----------
static void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Sky
    if (isDay) {
        glColor3f(0.53f, 0.81f, 0.98f);
    }
    else {
        glColor3f(0.02f, 0.05f, 0.12f);
    }

    //sky
  glBegin(GL_QUADS);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glEnd();


    // Ground
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 0.3f);
    glVertex2f(0.0f, 0.3f);
    glEnd();

    // Road
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.22f);
    glVertex2f(1.0f, 0.22f);
    glVertex2f(1.0f, 0.28f);
    glVertex2f(0.0f, 0.28f);
    glEnd();

    // Road dashed lines
    glColor3f(1, 1, 1);
    glLineWidth(5);
    glBegin(GL_LINES);
    for (float i = 0.0f; i < 1.0f; i += 0.08f) {
        glVertex2f(i, 0.25f);
        glVertex2f(i + 0.04f, 0.25f);
    }
    glEnd();

    // Sun / Moon
    if (isDay) glColor3f(1.0f, 1.0f, 0.0f);
    else glColor3f(0.95f, 0.95f, 1.0f);
    drawCircle(0.85f, 0.85f, 0.07f, 50);

    // Houses and buildings
    drawHouse(0.05f, 0.3f, 0.12f, 0.2f, 0.8f, 0.5f, 0.4f, 0.5f, 0.1f, 0.0f);
    drawHouse(0.2f, 0.3f, 0.2f, 0.25f, 1.0f, 0.8f, 0.4f, 0.6f, 0.2f, 0.0f);
    drawHouse(0.5f, 0.3f, 0.15f, 0.22f, 0.9f, 0.6f, 0.3f, 0.7f, 0.3f, 0.0f);
    drawHouse(-0.09f, 0.3f, 0.12f, 0.2f, 0.8f, 0.5f, 0.4f, 0.5f, 0.1f, 0.0f);

    drawModernBuilding(0.7f, 0.3f, 0.08f, 0.35f, 0.4f, 0.4f, 0.5f);
    drawModernBuilding(0.82f, 0.3f, 0.05f, 0.25f, 0.5f, 0.5f, 0.6f);
    drawModernBuilding(0.41f, 0.3f, 0.08f, 0.35f, 0.4f, 0.4f, 0.5f);
    drawModernBuilding(0.9f, 0.3f, 0.05f, 0.25f, 0.5f, 0.5f, 0.6f);
    drawModernBuilding(0.99f, 0.3f, 0.08f, 0.35f, 0.4f, 0.4f, 0.5f);

    // Trees, bushes
   drawTree(0.65f, 0.3f);
    drawTree(0.9f, 0.3f);
    drawBush(0.70f, 0.05f);
    drawBush(0.90f, 0.05f);

    // Clouds ()
    if (isDay) {
        drawCloud(0.12f + cloudX, 0.82f, 1.0f);
        drawCloud(0.35f + cloudX * 0.8f, 0.88f, 0.9f);
        drawCloud(0.65f + cloud2X, 0.83f, 1.1f);
    } else {
        // faint clouds at night
        glColor3f(1, 1, 1);
        drawCloud(0.25f + cloudX, 0.82f, 0.7f);
        drawCloud(0.6f + cloud2X, 0.86f, 0.8f);
    }

    // Birds
    drawBird(0.4f + birdX, 0.8f);
    drawBird(0.5f + birdX * 0.9f, 0.79f);
    drawBird(0.6f + birdX * 0.8f, 0.78f);

    // Cars
    drawSportsCar(car1X, 0.28f, 1.0f, 0.0f, 0.0f);
    drawSportsCar(car2X, 0.26f, 0.0f, 0.0f, 1.0f);
     drawSportsCar(car2X+0.2, 0.26f, 0.0f, 0.0f, 1.0f);

    // Pedestrians (now they will cross the road vertically from bottom sidewalk -> top sidewalk)
    for (int i = 0; i < 5; ++i) {
        drawPerson(personX[i], personY[i]);
    }

    // Playground group (left) - using nicer designs
    drawSlideNicer(0.06f, 0.06f);
    drawSwingNicer(0.22f, 0.06f);
    drawSeeSawNicer(0.36f, 0.06f);

    drawKid(0.10f, 0.13f);
    drawKid(0.23f, 0.14f);
    drawKid(0.36f, 0.13f);

    // Sandbox
    glColor3f(0.9f, 0.8f, 0.6f);
    glBegin(GL_QUADS);
    glVertex2f(0.15f, 0.05f);
    glVertex2f(0.25f, 0.05f);
    glVertex2f(0.25f, 0.08f);
    glVertex2f(0.15f, 0.08f);
    glEnd();

    // Benches (right)
    drawBench(0.65f, 0.10f);
    drawBench(0.80f, 0.10f);

    glFlush();
}

// ----------ANIMATION ----------
void update(int value) {
    // Cloud movement
    cloudX += 0.0006f;
    if (cloudX > 1.4f) cloudX = -0.4f;

    cloud2X += 0.0009f;
    if (cloud2X > 1.4f) cloud2X = -0.6f;

    // Birds
    birdX += 0.0015f;
    if (birdX > 1.3f) birdX = -0.6f;







    // Cars slow when someone is on the road
    float car1Step = car1Speed;
    float car2Step = car2Speed;


    // Update cars
    car1X += car1Step;
    car2X += car2Step;

    if (car1X > 1.2f) car1X = -0.2f;
    if (car2X > 1.2f) car2X = -0.2f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// ---------- KEYBOARD Toggle----------
void keyboard(unsigned char key, int x, int y) {
    (void)x; (void)y;
    if (key == 't' || key == 'T') {
        isDay = !isDay;
        glutPostRedisplay();
    }
}

// ---------- INIT ----------
void init(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f);
}

// ---------- MAIN ----------
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Village & City with Park & Playground - Crosswalks & New Playground");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}

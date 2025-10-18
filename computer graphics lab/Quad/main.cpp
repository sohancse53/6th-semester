#include<windows.h>
#include <GL/glut.h>

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

        // Rectangle
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-0.8f, 0.2f, 0.0f);
        glVertex3f(-0.3f, 0.2f, 0.0f);
        glVertex3f(-0.3f, 0.6f, 0.0f);
        glVertex3f(-0.8f, 0.6f, 0.0f);

        // Parallelogram
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.1f, 0.2f, 0.0f);
        glVertex3f(0.6f, 0.2f, 0.0f);
        glVertex3f(0.5f, 0.6f, 0.0f);
        glVertex3f(0.0f, 0.6f, 0.0f);

        // Trapezium
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(-0.9f, -0.6f, 0.0f);
        glVertex3f(-0.3f, -0.6f, 0.0f);
        glVertex3f(-0.4f, -0.2f, 0.0f);
        glVertex3f(-0.8f, -0.2f, 0.0f);

        // Square
        glColor3f(0.5, 0.7, 0.9);
        glVertex3f(0.2f, -0.6f, 0.0f);
        glVertex3f(0.6f, -0.6f, 0.0f);
        glVertex3f(0.6f, -0.2f, 0.0f);
        glVertex3f(0.2f, -0.2f, 0.0f);

        // Rhombus
        glColor3f(0.8, 0.6, 0.4);
        glVertex3f(0.7f, -0.6f, 0.0f);
        glVertex3f(0.9f, -0.6f, 0.0f);
        glVertex3f(1.0f, -0.2f, 0.0f);
        glVertex3f(0.8f, -0.2f, 0.0f);

    glEnd();

    glFlush();
}

// Main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bigger Shapes in OpenGL");

    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

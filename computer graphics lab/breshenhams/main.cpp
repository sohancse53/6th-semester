#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // white color

    // Example points for the line
    int x1 = 100, y1 = 100, x2 = 400, y2 = 300;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p = 2 * dy - dx;

    int x = x1;
    int y = y1;

    glBegin(GL_POINTS); // start drawing pixels

    if (dx > dy)
    {
        // slope <= 1
        for (int i = 0; i <= dx; i++)
        {
            glVertex2f(x / 600.0, y / 600.0); // normalize to window size
            if (p < 0)
                p += 2 * dy;
            else
            {
                p += 2 * (dy - dx);
                y++;
            }
            x++;
        }
    }
    else
    {
        // slope > 1
        p = 2 * dx - dy;
        for (int i = 0; i <= dy; i++)
        {
            glVertex2f(x / 600.0, y / 600.0);
            if (p < 0)
                p += 2 * dx;
            else
            {
                p += 2 * (dx - dy);
                x++;
            }
            y++;
        }
    }

    glEnd();
    glFlush();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); // background black
    glColor3f(1.0, 1.0, 1.0);         // drawing color white
    glPointSize(5.0);                 // size of points
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1, 0, 1); // 2D coordinate system
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Drawing - GLUT Demo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

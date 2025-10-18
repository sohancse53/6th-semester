#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
/* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/


        glBegin(GL_QUADS); //Begin quadrilateral coordinates

        //Rectangle
        glColor3f (1.0, 0.0, 0.0);
        glVertex3f(0.1f, 0.6f, 0.0f);
        glVertex3f(0.3f, 0.6f, 0.0f);
        glVertex3f(0.3f, 0.7f, 0.0f);
        glVertex3f(0.1f, 0.7f, 0.0f);

        //Parallelogram
        glColor3f (0.0, 1.0, 0.0);
        glVertex3f(0.4f, 0.6f, 0.0f);
        glVertex3f(0.6f, 0.6f, 0.0f);
        glVertex3f(0.65f, 0.7f, 0.0f);
        glVertex3f(0.45f, 0.7f, 0.0f);

        //Trapezium
        glColor3f (0.0, 0.0, 1.0);
        glVertex3f(0.7f, 0.6f, 0.0f);
        glVertex3f(0.9f, 0.6f, 0.0f);
        glVertex3f(0.9f, 0.7f, 0.0f);
        glVertex3f(0.8f, 0.7f, 0.0f);

        //Square
        glColor3f (0.5, 0.7, 0.9);
        glVertex3f(0.3f, 0.4f, 0.0f);
        glVertex3f(0.4f, 0.4f, 0.0f);
        glVertex3f(0.4f, 0.5f, 0.0f);
        glVertex3f(0.3f, 0.5f, 0.0f);

        //Rhombus
        glColor3f (0.8, 0.6, 0.4);
        glVertex3f(0.6f, 0.4f, 0.0f);
        glVertex3f(0.7f, 0.4f, 0.0f);
        glVertex3f(0.76f, 0.48f, 0.0f);
        glVertex3f(0.66f, 0.48f, 0.0f);


        glEnd(); //End quadrilateral coordinates

/* don't wait!
* start processing buffered OpenGL routines
*/
glFlush ();
}
void init (void)
{
/* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -10.0, 10.0);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Quadrangle");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



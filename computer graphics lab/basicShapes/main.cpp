
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<bits/stdc++.h>
#include <stdlib.h>
#include<math.h>
using namespace std;


static void display(void)
{
        glClear(GL_COLOR_BUFFER_BIT);

/* ================================================================
draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/


  /*
    glBegin(GL_QUADS);
    glColor3f(0,1.0,0);
    glVertex3f(0.05f, 0.05f, 0.0f);
    glColor3f(1.0,0,0);
	glVertex3f(0.35f, 0.05f, 0.0f);
	glColor3f(0,0,1);
	glVertex3f(0.40f, 0.35f, 0.0f);
	glColor3f(1.0,1.0,0);
	glVertex3f(0.00f, 0.35f, 0.0f);
    glEnd();
  */

    //triangle
  /*
     glColor3f(0,0,1.0);
     glBegin(GL_TRIANGLES);
    glVertex2f(0.5,0.8); //A
    glVertex2f(0.2,0.3); //B
    glVertex2f(0.8,0.3); //C
     glEnd();
     ======================================================================
     */

 /*---------------------------------------------------------
  ghor
     glColor3f(1.0,0,0);
     glBegin(GL_LINES);
     glVertex2f(0.4,0.3); //A
      glVertex2f(0.8,0.3); //B

       glVertex2f(0.4,0.3); //A
        glVertex2f(0.4,0.5); //C

        glVertex2f(0.8,0.3); //B
        glVertex2f(0.8,0.5); //D


         glVertex2f(0.4,0.5); //C
          glVertex2f(0.8,0.5); //D

          glVertex2f(0.4,0.5); //C
          glVertex2f(0.6,0.7); //C

           glVertex2f(0.8,0.5); //C
          glVertex2f(0.6,0.7); //C

     glEnd();
------------------------------------------------------------
  */



  /*-----------------------------------------------------------------------------
  circle drawing with line_loop and circle fill with gl_polygon

  float cx=0,cy=0,r=0.7,segments = 100;
glBegin(GL_LINE_LOOP);
glColor3f(1,1,1);
for(int i=0;i<segments;i++){
    float theta = 2*3.1416* float(i) / segments;
    float x= r*cosf(theta);
    float y = r*sinf(theta);
    glVertex2f(cx+x,cy+y);
}
glEnd();



        float cx1 = 0,cy1=0,r1=0.5;
    int segments1 = 100;

    glBegin(GL_POLYGON);
     // glColor3f(0,0.5,0);
    for(int i=0;i<segments;i++){
        float theta = 2*3.14* float(i) / float(segments1);
        float x = r1 * cosf(theta);
         float y = r1 * sinf(theta);
           glColor3f(x+0.5,y+0.5,0.4);
         glVertex2f(cx1+x,cy1+y);
    }

    glEnd();
  -----------------------------------------------------------------------------
  */





  //-------------------dda line drawing algorithm---------------------

/*
float x1=2, x2=40, y1=5, y2=80;
float dx = x2-x1, dy= y2-y1;
int steps = max(abs(dx),abs(dy));
float xinc = dx/steps;
float yinc = dy/steps;

glColor3f(1.0, 0, 0);
glBegin(GL_POINTS);
float x=x1,y=y1;
for(int i= 0;i<=steps;i++){
    glVertex2f(x/100,y/100);
    x +=xinc;
    y += yinc;
}
glEnd();
*/


     glFlush();

}

void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-1.0, 1.0, -1.0, 1.0, -1, 1);
}




int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (600, 600);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Basic Shapes");
init ();
glutDisplayFunc(display);
glutMainLoop();

    return EXIT_SUCCESS;
}

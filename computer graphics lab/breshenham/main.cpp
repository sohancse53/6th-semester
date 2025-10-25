/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
 #include<windows.h>
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>



/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    int x1=2,y1=2,x2=8,y2=8;
  int dx = abs(x1-x2);
    int dy = abs(y2-y1);
    int x= x1;
    int y= y1;
    cout<<"plot: "<<x<<","<<y<<endl;
    //slope<=1
    if(dx>=dy){
        int p = ((2*dy)-dx);
        while(x!=x2){
            if(p<0){
                x= x+1;
                y = y;
                 cout<<"plot: "<<x<<","<<y<<endl;
                 p = p + (2*dy);
            }
            else{
                x= x+1;
                y= y+1;
                 cout<<"plot: "<<x<<","<<y<<endl;
                 p = p + (2*dy) - (2*dx);
            }
        }
    }
    else{
        int p = ((2*dx)- dy);
        while(y!=y2){
              if(p<0){
                x= x;
                y = y+1;
                 cout<<"plot: "<<x<<","<<y<<endl;
                 p = p + (2*dx);
            }
            else{
                x= x+1;
                y= y+1;
                 cout<<"plot: "<<x<<","<<y<<endl;
                 p = p + (2*dx) - (2*dy);
            }
        }
    }
}





/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);



    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);


    glutMainLoop();

    return EXIT_SUCCESS;
}

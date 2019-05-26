#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#define f(x) (exp(-fabs(x)) * cos(2 * M_PI * x))

const GLdouble screenWidth = 1280.0, screenHeiht = 960.0;
GLdouble A, B, C, D;

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, screenWidth, 0.0, screenHeiht);
    A = screenWidth /4.0;
    B = 0.0;
    C = D = screenHeiht / 2.0;
}

void myPlotter(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
        for (GLdouble x = 0; x < 4.0; x += 0.001)
        {
            glVertex2d(A * x + B, C * f(x) + D);
        }
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeiht);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("Plotter");
    glutDisplayFunc(myPlotter);
    myInit();
    glutMainLoop();
}
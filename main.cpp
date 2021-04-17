#include "GL/freeglut.h"
#include <cmath>

double coordX, coordY,
    b = 0.0,
    animStep = 0.0006,
    length = 0.3,
    lengthCoef = 1.5,
    inclineCoef = 0.6;
int branches = 3, depth = 6;

void Fractal(double x, double y, double a, double L, int n) {
    for(int i = 0; i < 2*branches; i += 2)
    {
        coordX = x + cos(a + i * b) * L;
        coordY = y + sin(a + i * b) * L;
        glVertex2d(x, y);
        glVertex2d(coordX, coordY);
        if(n > 0) {
            Fractal(coordX, coordY, a + (i - 1) * b, L / lengthCoef, n - 1);
        }
    }
}

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glColor3d(0.0, 1.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2d(0.0, -0.5);
    glVertex2d(0.0, 0.0);
    Fractal(0.0, 0.0, inclineCoef, length, depth);
    glEnd();

    if(b < 6.8) {
        b += animStep;
    }
    if (b >= 6.8) {
        b = 0;
    }

    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Tree Animation");
    glClearColor(0.0,0.0,0.0,0.0);
    glutIdleFunc(Draw);
    glutDisplayFunc(Draw);
    glutMainLoop();
}
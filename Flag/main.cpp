#include <GL/glut.h>
#include <cmath>

#define PI 3.14159265

void drawRectangle(float x, float y, float w, float h, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x, y + h);
    glEnd();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);


    glutInitWindowSize(1000, 600);
    glutCreateWindow("Cook Islands Flag - Full Screen");
    init();
    glutDisplayFunc(drawRectangle);
    glutMainLoop();
    return 0;
}


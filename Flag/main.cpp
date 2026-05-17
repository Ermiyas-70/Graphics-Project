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

void drawStar(float cx, float cy, float outerR, float innerR) {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= 10; i++) {
            float angle = PI / 2 + i * PI / 5;
            float radius = (i % 2 == 0) ? outerR : innerR;
            glVertex2f(cx + cos(angle) * radius, cy + sin(angle) * radius);
        }
    glEnd();
}

void draw_Background() {
    drawRectangle(-1.0, -0.75, 2.5, 1.5, 0.0, 0.13, 0.45);
}

void drawUnionJack() {
    drawRectangle(-1.0, 0.0, 1.0, 0.75, 0.0, 0.13, 0.45);
    glLineWidth(16);
    glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glVertex2f(-1.0, 0.75); glVertex2f(0.0, 0.0);
        glVertex2f(-1.0, 0.0); glVertex2f(0.0, 0.75);
    glEnd();
    glLineWidth(6);
    glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glVertex2f(-1.0, 0.75); glVertex2f(0.0, 0.0);
        glVertex2f(-1.0, 0.0); glVertex2f(0.0, 0.75);
    glEnd();
    drawRectangle(-1.0, 0.28, 1.0, 0.19, 1, 1, 1);
    drawRectangle(-0.595, 0.0, 0.19, 0.75, 1, 1, 1);
    drawRectangle(-1.0, 0.32, 1.0, 0.11, 1, 0, 0);
    drawRectangle(-0.555, 0.0, 0.11, 0.75, 1, 0, 0);
}

void drawStudent3_StarsRing() {

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
     draw_Background();
     drawUnionJack();
    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.5, -0.75, 0.75);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("Cook Islands Flag - Multi-Student Collaboration");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

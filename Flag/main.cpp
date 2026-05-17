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



    float leftGap = 0.15f;
    glBegin(GL_POLYGON);
        glVertex2f(-3.05f, -0.35f); glVertex2f(-2.03f-leftGap, -0.35f);
        glVertex2f(-1.81f-leftGap, -0.05f); glVertex2f(-3.27f, -0.05f);
    glEnd();

    glPushMatrix();
    glTranslatef(-1.45f, 0.05f, 0.0f);
    glScalef(0.68f, 0.68f, 1.0f);
    glColor3f(0.85f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
        glVertex2f(-0.75f, 0.18f); glVertex2f( 0.35f, 0.18f);
        glVertex2f( 0.55f, 0.62f); glVertex2f(-0.55f, 0.62f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.35f, 0.18f);
        for(int i = 0; i <= 100; i++) {
            float theta = (75.0f * i) / 100.0f;
            float rad = theta * PI / 180.0f;
            glVertex2f(0.35f + 0.42f * cos(rad), 0.18f + 0.44f * sin(rad));
        }
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.77f, 0.18f); glVertex2f(0.35f, 0.18f);
        glVertex2f(0.12f, -0.05f); glVertex2f(0.45f, -0.05f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.40f,  0.10f); glVertex2f( 0.05f,  0.10f);
        glVertex2f(-0.15f, -0.22f); glVertex2f(-0.61f, -0.22f);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.61f, -0.22f); glVertex2f(-0.15f, -0.22f);
        float centerX = -0.15f, centerY = -0.22f;
        float radiusX = 0.70f, radiusY = 0.45f;
        for(float i = 0; i >= -90; i -= 1) {
            float rad = i * PI / 180.0f;
            glVertex2f(centerX + cos(rad) * radiusX, centerY + sin(rad) * radiusY);
        }
        glVertex2f(-0.85f, -0.67f);
    glEnd();
    glPopMatrix();

    glColor3f(1.0f, 0.8f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-3.30f, -0.26f); glVertex2f(-1.98f, -0.26f);
        glVertex2f(-1.98f, -0.24f); glVertex2f(-3.30f, -0.24f);

        glVertex2f(-3.30f, -0.16f); glVertex2f(-1.98f, -0.16f);
        glVertex2f(-1.98f, -0.14f); glVertex2f(-3.30f, -0.14f);


        glVertex2f(-3.30f, -0.42f); glVertex2f( 2.30f, -0.42f);
        glVertex2f( 2.30f, -0.34f); glVertex2f(-3.30f, -0.34f);
    glEnd();

    void drawStudent3_StarsRing() {
    float centerX = 0.65; 
    float ringRadius = 0.45;
    for (int i = 0; i < 15; i++) {
        float theta = i * 2.0 * PI / 15.0;
        drawStar(centerX + ringRadius * cos(theta), ringRadius * sin(theta), 0.08, 0.035);
    }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    drawRectangle(-1.0, -0.75, 2.5, 1.5, 0.0, 0.13, 0.45);


    drawUnionJack();
    drawStudent3_StarsRing();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 500);
    glutCreateWindow("DHL Logo - Student 1 Baseline with Bottom Cut");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

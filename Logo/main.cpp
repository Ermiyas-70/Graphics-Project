#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265359f;

void drawBlock(float x, float y, float width, float height, float slant) {
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width + slant, y + height);
        glVertex2f(x + slant, y + height);
    glEnd();
}

void drawStudent1_D_Extension_AndLeftSlices() {
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
}

void drawStudent2_H(float hShiftX, float lStartX) {

    glColor3f(0.85f, 0.0f, 0.0f);
    drawBlock(-1.10f + hShiftX, -0.35f, 0.22f, 0.83f, 0.40f);
    drawBlock(-0.65f + hShiftX, -0.35f, 0.22f, 0.83f, 0.40f);
    drawBlock(-0.90f + hShiftX, 0.05f, 0.45f, 0.15f, 0.10f);
    drawBlock(-0.92f + hShiftX, -0.01f, 0.47f, 0.06f, 0.05f);


    glColor3f(1.0f, 0.8f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-1.15f + hShiftX,           -0.07f);
        glVertex2f(lStartX + 0.95f,            -0.07f);
        glVertex2f(lStartX + 0.95f,            -0.005f);
        glVertex2f(-1.15f + hShiftX,           -0.005f);
    glEnd();
}

void drawStudent3_L_Extension_AndRightSlices(float lStartX, float rightGap) {

}

void display() {
    glClearColor(1.0f, 0.8f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(0.55f, 0.0f, 0.0f);
    glColor3f(0.85f, 0.0f, 0.0f);

    float rightGap = 0.15f;
    float lStartX = 0.05f;
    float hShiftX = 0.10f;

    drawStudent1_D_Extension_AndLeftSlices();
    drawStudent2_H(hShiftX, lStartX);
    drawStudent3_L_Extension_AndRightSlices(lStartX, rightGap);

    glPopMatrix();
    glFlush();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.5, 2.5, -1.0, 1.0);
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

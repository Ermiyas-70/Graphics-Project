#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265359f;


float rotationAngle = 0.0f;
bool isSpinning = false;


void drawBlock(float x, float y, float width, float height, float slant) {
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width + slant, y + height);
        glVertex2f(x + slant, y + height);
    glEnd();
}
void student1_drawD() {
    glPushMatrix();
    glTranslatef(-1.45f, 0.05f, 0.0f);
    glScalef(0.68f, 0.68f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);


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
}
void student2_drawH(float hShiftX) {
    glColor3f(0.0f, 0.0f, 0.0f);


    drawBlock(-1.10f + hShiftX, -0.35f, 0.22f, 0.83f, 0.40f);

    drawBlock(-0.65f + hShiftX, -0.35f, 0.22f, 0.83f, 0.40f);

    drawBlock(-0.90f + hShiftX, 0.05f, 0.45f, 0.15f, 0.10f);
    drawBlock(-0.92f + hShiftX, -0.01f, 0.47f, 0.06f, 0.05f);
}

void student3_drawL(float lStartX, float rightGap) {
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
        glVertex2f(lStartX - 0.145f, -0.05f); glVertex2f(lStartX + 0.15f, -0.05f);
        glVertex2f(lStartX + 0.40f, 0.48f); glVertex2f(lStartX + 0.10f, 0.48f);
    glEnd();


    glBegin(GL_POLYGON);
        glVertex2f(lStartX, -0.35f); glVertex2f(lStartX + 0.60f, -0.35f);
        glVertex2f(lStartX + 0.90f, -0.05f); glVertex2f(lStartX, -0.05f);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(lStartX, -0.20f);
        for(int i = 0; i <= 50; i++) {
            float angle = PI/2.0f + (PI * i / 50.0f);
            glVertex2f(lStartX + 0.15f * cos(angle), -0.20f + 0.15f * sin(angle));
        }
    glEnd();


    glBegin(GL_POLYGON);
        glVertex2f(lStartX + 0.60f + rightGap, -0.35f); glVertex2f(2.20f, -0.35f);
        glVertex2f(1.98f, -0.05f); glVertex2f(lStartX + 0.90f + rightGap, -0.05f);
    glEnd();
}


void student3_applyNegativeSpaceMask(float lStartX, float hShiftX) {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

        glVertex2f(-3.30f, -0.26f); glVertex2f(-1.98f, -0.26f);
        glVertex2f(-1.98f, -0.24f); glVertex2f(-3.30f, -0.24f);

        glVertex2f(-3.30f, -0.16f); glVertex2f(-1.98f, -0.16f);
        glVertex2f(-1.98f, -0.14f); glVertex2f(-3.30f, -0.14f);

        glVertex2f(lStartX + 0.85f, -0.26f); glVertex2f(2.30f, -0.26f);
        glVertex2f(2.30f,           -0.24f); glVertex2f(lStartX + 0.85f, -0.24f);

        glVertex2f(lStartX + 0.85f, -0.16f); glVertex2f(2.30f, -0.16f);
        glVertex2f(2.30f,           -0.14f); glVertex2f(lStartX + 0.85f, -0.14f);


        glVertex2f(-1.15f + hShiftX,           -0.07f);
        glVertex2f(lStartX + 0.95f,            -0.07f);
        glVertex2f(lStartX + 0.95f,            -0.005f);
        glVertex2f(-1.15f + hShiftX,           -0.005f);
    glEnd();


    glBegin(GL_QUADS);
        glVertex2f(-3.30f, -0.42f); glVertex2f( 2.30f, -0.42f);
        glVertex2f( 2.30f, -0.34f); glVertex2f(-3.30f, -0.34f);
    glEnd();
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();


    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.55f, 0.0f, 0.0f);

    float leftGap = 0.15f;
    float rightGap = 0.15f;
    float lStartX = 0.05f;
    float hShiftX = 0.10f;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-3.05f, -0.35f); glVertex2f(-2.03f-leftGap, -0.35f);
        glVertex2f(-1.81f-leftGap, -0.05f); glVertex2f(-3.27f, -0.05f);
    glEnd();

    student1_drawD();
    student2_drawH(hShiftX);
    student3_drawL(lStartX, rightGap);


    student3_applyNegativeSpaceMask(lStartX, hShiftX);

    glPopMatrix();
    glutSwapBuffers();
}

void update(int value) {
    if (isSpinning) {
        rotationAngle += 2.0f;
        if (rotationAngle > 360.0f) rotationAngle -= 360.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(16, update, 0);
}

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        isSpinning = !isSpinning;
    }
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.5, 2.5, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 500);
    glutCreateWindow("DHL Logo");
    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouseClick);
    glutTimerFunc(25, update, 0);

    glutMainLoop();
    return 0;
}

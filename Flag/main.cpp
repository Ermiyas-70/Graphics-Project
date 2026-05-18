#include <GL/glut.h>
#include <cmath>

#define PI 3.14159265

float waveTime = 0.0f;

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
void timer(int value) {
    waveTime += 0.05f; 
    if (waveTime > 2 * PI) {
        waveTime -= 2 * PI;
    }
    glutPostRedisplay(); 
    glutTimerFunc(16, timer, 0); 
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    int numSlices = 100;
    float flagWidth = 2.5f;
    float sliceWidth = flagWidth / numSlices;

    for (int i = 0; i < numSlices; i++) {
        float xStart = -1.0f + i * sliceWidth;

        float yOffset = sin(xStart * 3.0f + waveTime) * 0.05f;

        glPushMatrix();
        glTranslatef(0.0f, yOffset, 0.0f); 

        glEnable(GL_SCISSOR_TEST);
        int screenXStart = static_cast<int>(((xStart - (-1.0f)) / 2.5f) * 1000);
        int screenSliceWidth = static_cast<int>((sliceWidth / 2.5f) * 1000) + 1;
        glScissor(screenXStart, 0, screenSliceWidth, 600);

    drawRectangle(-1.0, -0.75, 2.5, 1.5, 0.0, 0.13, 0.45);


    drawUnionJack();


    float centerX = 0.65;
    float ringRadius = 0.45;
    for (int j = 0; j < 15; j++) {
        float theta = j * 2.0 * PI / 15.0;
        drawStar(centerX + ringRadius * cos(theta), ringRadius * sin(theta), 0.08, 0.035);
    }

    glDisable(GL_SCISSOR_TEST);
    glPopMatrix();
}
   glutSwapBuffers();
}

void init() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    gluOrtho2D(-1.0, 1.5, -0.75, 0.75);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);


    glutInitWindowSize(1000, 600);
    glutCreateWindow("Cook Islands Flag - Full Screen");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}

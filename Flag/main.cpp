#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);

        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, 0.5);

    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(640, 480);

    glutCreateWindow("Test");

    glClearColor(1,1,1,1);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

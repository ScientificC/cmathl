#include <GL/glut.h>
#include <cml/easings.h>

using namespace std;

void
render_ease_elastic_in()
{
        glClearColor(0.0, 0.0, 0.0, 1.0); // clear background with black
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        double w = glutGet(GLUT_WINDOW_WIDTH);
        double h = glutGet(GLUT_WINDOW_HEIGHT);
        double ar = w / h;

        glOrtho(-75 * ar, 75 * ar, -100, 100, -1, 1);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glPointSize(5);
        glColor3f(1.0,0.0,0.0);

        glBegin(GL_POINTS);

        int i;

        for(i = 0; i < 100; i += 1)
        {
                float x = (float) i - 50;
                float y = (float) 100 * cml_ease_elastic_in((double) i / 100.0) - 15;
                glVertex2f(x,y);
        }

        glEnd();
        glutSwapBuffers();
}

int
main(int argc, char** argv)
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
        glutInitWindowSize(720, 480);
        glutCreateWindow("SineWave.cpp");
        glutDisplayFunc(render_ease_elastic_in);
        glutMainLoop();

        return 0;
}

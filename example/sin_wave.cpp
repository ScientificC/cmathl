#include <GL/glut.h>
#include <cml.hpp>

using namespace std;
using namespace cml;

void
render_sine_wave()
{
        glClearColor(0.0, 0.0, 0.0, 1.0); // clear background with black
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        double w = glutGet(GLUT_WINDOW_WIDTH);
        double h = glutGet(GLUT_WINDOW_HEIGHT);
        double ar = w / h;

        glOrtho(-360 * ar, 360 * ar, -120, 120, -1, 1);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glPointSize(2);
        glColor3f(1.0,0.0,0.0);

        glBegin(GL_POINTS);

        int i;

        for(i = -360; i < 360; i++)
        {
                float x = (float) i;
                float y = 100.0 * (float) sin(i * (M_TAU/360.0));
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
        glutDisplayFunc(render_sine_wave);
        glutMainLoop();

        return 0;
}

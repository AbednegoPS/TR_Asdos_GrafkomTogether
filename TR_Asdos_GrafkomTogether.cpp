#include<windows.h>
#include<gl/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void mouseMotion(int, int);
void ukuran(int, int);

int is_depth;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Grafkom Together");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void tampil(void)
{
    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glTranslatef(xmov, ymov, zmov);
    glPushMatrix();

    //Alas
    glBegin(GL_QUADS);
    glColor3f(0.36, 0.27, 0.1);
    glVertex3f(-150.0, -16, -130.0);
    glVertex3f(-150.0, -16, 87.0);
    glVertex3f(180.0, -16, 87.0);
    glVertex3f(180.0, -16, -130.0);
    glEnd();
    
    //Gedung Universitas
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-14.0, 5.0, 40.0);
    glVertex3f(-14.0, 45.0, 40.0);
    glVertex3f(14.0, 45.0, 40.0);
    glVertex3f(14.0, 5.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(14.0, 5.0, 0.0);
    glVertex3f(14.0, 45.0, 0.0);
    glVertex3f(14.0, 45.0, 40.0);
    glVertex3f(14.0, 5.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-14.0, 5.0, 0.0);
    glVertex3f(-14.0, 45.0, 0.0);
    glVertex3f(-14.0, 45.0, 40.0);
    glVertex3f(-14.0, 5.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-14.0, 45.0, 0.0);
    glVertex3f(14.0, 45.0, 0.0);
    glVertex3f(14.0, 45.0, 40.0);
    glVertex3f(-14.0, 45.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-14.0, 5.0, 0.0);
    glVertex3f(14.0, 5.0, 0.0);
    glVertex3f(14.0, 5.0, 40.0);
    glVertex3f(-14.0, 5.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-12.5, 45.0, 30.0);
    glVertex3f(-12.5, 55.0, 30.0);
    glVertex3f(12.5, 55.0, 30.0);
    glVertex3f(12.5, 45.0, 30.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(12.5, 45.0, 0.0);
    glVertex3f(12.5, 55.0, 0.0);
    glVertex3f(12.5, 55.0, 30.0);
    glVertex3f(12.5, 45.0, 30.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-12.5, 45.0, 0.0);
    glVertex3f(-12.5, 55.0, 0.0);
    glVertex3f(-12.5, 55.0, 30.0);
    glVertex3f(-12.5, 45.0, 30.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-12.5, 55.0, 0.0);
    glVertex3f(12.5, 55.0, 0.0);
    glVertex3f(12.5, 55.0, 30.0);
    glVertex3f(-12.5, 55.0, 30.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-60.0, -15.0, 0.0);
    glVertex3f(-12.5, -15.0, 0.0);
    glVertex3f(-12.5, 55.0, 0.0);
    glVertex3f(-60.0, 55.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.6, 0.0);
    glVertex3f(-60.1, 20.0, 0.1);
    glVertex3f(-35.0, 20.0, 0.1);
    glVertex3f(-35.0, 45.0, 0.1);
    glVertex3f(-60.1, 45.0, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.4, 0.0);
    glVertex3f(-60.1, 20.0, 0.0);
    glVertex3f(-60.1, 20.0, -20.0);
    glVertex3f(-60.1, 45.0, -20.0);
    glVertex3f(-60.1, 45.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(60.0, -15.0, 0.0);
    glVertex3f(12.5, -15.0, 0.0);
    glVertex3f(12.5, 55.0, 0.0);
    glVertex3f(60.0, 55.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.6, 0.0);
    glVertex3f(60.1, 20.0, 0.1);
    glVertex3f(35.0, 20.0, 0.1);
    glVertex3f(35.0, 45.0, 0.1);
    glVertex3f(60.1, 45.0, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.4, 0.0);
    glVertex3f(60.1, 20.0, 0.0);
    glVertex3f(60.1, 20.0, -20.0);
    glVertex3f(60.1, 45.0, -20.0);
    glVertex3f(60.1, 45.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(60.0, -15.0, -45.0);
    glVertex3f(60.0, -15.0, 0.0);
    glVertex3f(60.0, 55.0, 0.0);
    glVertex3f(60.0, 55.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(60.0, -15.0, -45.0);
    glVertex3f(-60.0, -15.0, -45.0);
    glVertex3f(-60.0, 55.0, -45.0);
    glVertex3f(60.0, 55.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(60.0, -15.0, 0.0);
    glVertex3f(-60.0, -15.0, 0.0);
    glVertex3f(-60.0, -15.0, -45.0);
    glVertex3f(60.0, -15.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(60.0, 55.0, -45.0);
    glVertex3f(60.0, 55.0, 0.0);
    glVertex3f(-60.0, 55.0, 0.0);
    glVertex3f(-60.0, 55.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60.0, -15.0, -45.0);
    glVertex3f(-60.0, -15.0, 0.0);
    glVertex3f(-60.0, 55.0, 0.0);
    glVertex3f(-60.0, 55.0, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-12.0, -15.0, 36.0);
    glVertex3f(-9.0, -15.0, 36.0);
    glVertex3f(-9.0, 5.0, 36.0);
    glVertex3f(-12.0, 5.0, 36.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-12.0, -15.0, 36.0);
    glVertex3f(-12.0, -15.0, 33.0);
    glVertex3f(-12.0, 5.0, 33.0);
    glVertex3f(-12.0, 5.0, 36.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-9.0, -15.0, 36.0);
    glVertex3f(-9.0, -15.0, 33.0);
    glVertex3f(-9.0, 5.0, 33.0);
    glVertex3f(-9.0, 5.0, 36.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-9.0, -15.0, 33.0);
    glVertex3f(-12.0, -15.0, 33.0);
    glVertex3f(-12.0, 5.0, 33.0);
    glVertex3f(-9.0, 5.0, 33.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-9.0, -15.0, 36.0);
    glVertex3f(-9.0, -15.0, 33.0);
    glVertex3f(-12.0, -15.0, 33.0);
    glVertex3f(-12.0, -15.0, 36.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-12.0, -15.0, 6.0);
    glVertex3f(-9.0, -15.0, 6.0);
    glVertex3f(-9.0, 5.0, 6.0);
    glVertex3f(-12.0, 5.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-12.0, -15.0, 6.0);
    glVertex3f(-12.0, -15.0, 3.0);
    glVertex3f(-12.0, 5.0, 3.0);
    glVertex3f(-12.0, 5.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-9.0, -15.0, 6.0);
    glVertex3f(-9.0, -15.0, 3.0);
    glVertex3f(-9.0, 5.0, 3.0);
    glVertex3f(-9.0, 5.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-9.0, -15.0, 3.0);
    glVertex3f(-12.0, -15.0, 3.0);
    glVertex3f(-12.0, 5.0, 3.0);
    glVertex3f(-9.0, 5.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-9.0, -15.0, 6.0);
    glVertex3f(-9.0, -15.0, 3.0);
    glVertex3f(-12.0, -15.0, 3.0);
    glVertex3f(-12.0, -15.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(12.0, -15.0, 36.0);
    glVertex3f(9.0, -15.0, 36.0);
    glVertex3f(9.0, 5.0, 36.0);
    glVertex3f(12.0, 5.0, 36.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(12.0, -15.0, 36.0);
    glVertex3f(12.0, -15.0, 33.0);
    glVertex3f(12.0, 5.0, 33.0);
    glVertex3f(12.0, 5.0, 36.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(9.0, -15.0, 36.0);
    glVertex3f(9.0, -15.0, 33.0);
    glVertex3f(9.0, 5.0, 33.0);
    glVertex3f(9.0, 5.0, 36.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(9.0, -15.0, 33.0);
    glVertex3f(12.0, -15.0, 33.0);
    glVertex3f(12.0, 5.0, 33.0);
    glVertex3f(9.0, 5.0, 33.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(9.0, -15.0, 36.0);
    glVertex3f(9.0, -15.0, 33.0);
    glVertex3f(12.0, -15.0, 33.0);
    glVertex3f(12.0, -15.0, 36.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(12.0, -15.0, 6.0);
    glVertex3f(9.0, -15.0, 6.0);
    glVertex3f(9.0, 5.0, 6.0);
    glVertex3f(12.0, 5.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(12.0, -15.0, 6.0);
    glVertex3f(12.0, -15.0, 3.0);
    glVertex3f(12.0, 5.0, 3.0);
    glVertex3f(12.0, 5.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(9.0, -15.0, 6.0);
    glVertex3f(9.0, -15.0, 3.0);
    glVertex3f(9.0, 5.0, 3.0);
    glVertex3f(9.0, 5.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(9.0, -15.0, 3.0);
    glVertex3f(12.0, -15.0, 3.0);
    glVertex3f(12.0, 5.0, 3.0);
    glVertex3f(9.0, 5.0, 3.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(9.0, -15.0, 6.0);
    glVertex3f(9.0, -15.0, 3.0);
    glVertex3f(12.0, -15.0, 3.0);
    glVertex3f(12.0, -15.0, 6.0);
    glEnd();

    //Meja
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.6, 0.4);
    glVertex3f(-15.0, -10.0, -20.0);
    glVertex3f(-5.0, -10.0, -20.0);
    glVertex3f(-5.0, -10, -10.0);
    glVertex3f(-15.0, -10.0, -10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.0, 0.0);
    glVertex3f(-15.0, -12.0, -20.0);
    glVertex3f(-5.0, -12.0, -20.0);
    glVertex3f(-5.0, -12, -10.0);
    glVertex3f(-15.0, -12.0, -10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.5, 0.0);
    glVertex3f(-15.0, -10.0, -10.0);
    glVertex3f(-5.0, -10.0, -10.0);
    glVertex3f(-5.0, -12.0, -10.0);
    glVertex3f(-15.0, -12.0, -10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5, 0.1, 0.0);
    glVertex3f(-15.0, -10.0, -20.0);
    glVertex3f(-5.0, -10.0, -20.0);
    glVertex3f(-5.0, -12.0, -20.0);
    glVertex3f(-15.0, -12.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.0);
    glVertex3f(-15.0, -10.0, -10.0);
    glVertex3f(-15.0, -10.0, -20.0);
    glVertex3f(-15.0, -12.0, -20.0);
    glVertex3f(-15.0, -12.0, -10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.3, 0.0);
    glVertex3f(-5.0, -10.0, -10.0);
    glVertex3f(-5.0, -10.0, -20.0);
    glVertex3f(-5.0, -12.0, -20.0);
    glVertex3f(-5.0, -12.0, -10.0);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-14.0, -12.0, -18.0);
    glVertex3f(-13.0, -12.0, -18.0);
    glVertex3f(-13.0, -14.9, -18.0);
    glVertex3f(-14.0, -14.9, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-13.0, -12.0, -18.0);
    glVertex3f(-13.0, -12.0, -19.0);
    glVertex3f(-13.0, -14.9, -19.0);
    glVertex3f(-13.0, -14.9, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-14.0, -12.0, -18.0);
    glVertex3f(-14.0, -12.0, -19.0);
    glVertex3f(-14.0, -14.9, -19.0);
    glVertex3f(-14.0, -14.9, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-14.0, -12.0, -19.0);
    glVertex3f(-13.0, -12.0, -19.0);
    glVertex3f(-13.0, -14.9, -19.0);
    glVertex3f(-14.0, -14.9, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-14.0, -14.9, -18.0);
    glVertex3f(-13.0, -14.9, -18.0);
    glVertex3f(-13.0, -14.9, -19.0);
    glVertex3f(-14.0, -14.9, -19.0);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-14.0, -12.0, -11.0);
    glVertex3f(-13.0, -12.0, -11.0);
    glVertex3f(-13.0, -14.9, -11.0);
    glVertex3f(-14.0, -14.9, -11.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-13.0, -12.0, -11.0);
    glVertex3f(-13.0, -12.0, -12.0);
    glVertex3f(-13.0, -14.9, -12.0);
    glVertex3f(-13.0, -14.9, -11.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-14.0, -12.0, -11.0);
    glVertex3f(-14.0, -12.0, -12.0);
    glVertex3f(-14.0, -14.9, -12.0);
    glVertex3f(-14.0, -14.9, -11.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-14.0, -12.0, -12.0);
    glVertex3f(-13.0, -12.0, -12.0);
    glVertex3f(-13.0, -14.9, -12.0);
    glVertex3f(-14.0, -14.9, -12.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-14.0, -14.9, -11.0);
    glVertex3f(-13.0, -14.9, -11.0);
    glVertex3f(-13.0, -14.9, -12.0);
    glVertex3f(-14.0, -14.9, -12.0);
    glEnd();
    

    
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-6.0, -12.0, -18.0);
    glVertex3f(-7.0, -12.0, -18.0);
    glVertex3f(-7.0, -14.9, -18.0);
    glVertex3f(-6.0, -14.9, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-6.0, -12.0, -18.0);
    glVertex3f(-6.0, -12.0, -19.0);
    glVertex3f(-6.0, -14.9, -19.0);
    glVertex3f(-6.0, -14.9, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-7.0, -12.0, -18.0);
    glVertex3f(-7.0, -12.0, -19.0);
    glVertex3f(-7.0, -14.9, -19.0);
    glVertex3f(-7.0, -14.9, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-7.0, -12.0, -19.0);
    glVertex3f(-6.0, -12.0, -19.0);
    glVertex3f(-6.0, -14.9, -19.0);
    glVertex3f(-7.0, -14.9, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-7.0, -14.9, -18.0);
    glVertex3f(-6.0, -14.9, -18.0);
    glVertex3f(-6.0, -14.9, -19.0);
    glVertex3f(-7.0, -14.9, -19.0);
    glEnd();
    
    

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-7.0, -12.0, -11.0);
    glVertex3f(-6.0, -12.0, -11.0);
    glVertex3f(-6.0, -14.9, -11.0);
    glVertex3f(-7.0, -14.9, -11.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-6.0, -12.0, -11.0);
    glVertex3f(-6.0, -12.0, -12.0);
    glVertex3f(-6.0, -14.9, -12.0);
    glVertex3f(-6.0, -14.9, -11.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-7.0, -12.0, -11.0);
    glVertex3f(-7.0, -12.0, -12.0);
    glVertex3f(-7.0, -14.9, -12.0);
    glVertex3f(-7.0, -14.9, -11.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-7.0, -12.0, -12.0);
    glVertex3f(-6.0, -12.0, -12.0);
    glVertex3f(-6.0, -14.9, -12.0);
    glVertex3f(-7.0, -14.9, -12.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-7.0, -14.9, -11.0);
    glVertex3f(-6.0, -14.9, -11.0);
    glVertex3f(-6.0, -14.9, -12.0);
    glVertex3f(-7.0, -14.9, -12.0);
    glEnd();

    //Pot
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(45.0, -10.0, -30.0);
    glVertex3f(50.0, -10.0, -30.0);
    glVertex3f(50.0, -14.9, -30.0);
    glVertex3f(45.0, -14.9, -30.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(50.0, -10.0, -30.0);
    glVertex3f(50.0, -10.0, -35.0);
    glVertex3f(50.0, -14.9, -35.0);
    glVertex3f(50.0, -14.9, -30.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(45.0, -10.0, -30.0);
    glVertex3f(45.0, -10.0, -35.0);
    glVertex3f(45.0, -14.9, -35.0);
    glVertex3f(45.0, -14.9, -30.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(45.0, -10.0, -35.0);
    glVertex3f(50.0, -10.0, -35.0);
    glVertex3f(50.0, -14.9, -35.0);
    glVertex3f(45.0, -14.9, -35.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(45.0, -14.9, -30.0);
    glVertex3f(50.0, -14.9, -30.0);
    glVertex3f(50.0, -14.9, -35.0);
    glVertex3f(45.0, -14.9, -35.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3, 0.1, 0.0);
    glVertex3f(44.9, -10.5, -30.0);
    glVertex3f(49.9, -10.5, -30.0);
    glVertex3f(49.9, -10.5, -35.0);
    glVertex3f(44.9, -10.5, -35.0);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void idle() {
    if (!mouseDown) {
        xrot += 0.3f;
        yrot += 0.4f;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        zmov += 3.0;
        break;
    case 'd':
    case 'D':
        xmov += 3.0;
        break;
    case 's':
    case 'S':
        zmov -= 3.0;
        break;
    case 'a':
    case 'A':
        xmov -= 3.0;
        break;
    case '1':
        ymov += 3.0;
        break;
    case '2':
        ymov -= 3.0;
        break;
    case '3':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -300.0);
    glMatrixMode(GL_MODELVIEW);
}

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
float zrot = 0.0f;
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
    glRotatef(zrot, 0.0f, 0.0f, 1.0f);

    glTranslatef(xmov, ymov, zmov);
    glPushMatrix();
    
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
    
    glBegin(GL_QUADS);
    glColor3f(0.62, 0.86, 0.99);
    glVertex3f(57, 23.0, 0.2);
    glVertex3f(38.0, 23.0, 0.2);
    glVertex3f(38.0, 42.0, 0.2);
    glVertex3f(57, 42.0, 0.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.62, 0.86, 0.99);
    glVertex3f(-57, 23.0, 0.2);
    glVertex3f(-38.0, 23.0, 0.2);
    glVertex3f(-38.0, 42.0, 0.2);
    glVertex3f(-57, 42.0, 0.2);
    glEnd();
    
    //Jalan
    glBegin(GL_QUADS);
    glColor3f(0.14, 0.14, 0.14);
    glVertex3f(-100.0, -15, 33.0);
    glVertex3f(-100.0, -15, 5.0);
    glVertex3f(70.0, -15, 5.0);
    glVertex3f(70.0, -15, 33.0);
    glEnd();
    //garis jalan depan
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-100.0, -14, 20.0);
    glVertex3f(-100.0, -14, 17.0);
    glVertex3f(-80.0, -14, 17.0);
    glVertex3f(-80.0, -14, 20.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-50.0, -14, 20.0);
    glVertex3f(-50.0, -14, 17.0);
    glVertex3f(-30.0, -14, 17.0);
    glVertex3f(-30.0, -14, 20.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(0.0, -14, 20.0);
    glVertex3f(0.0, -14, 17.0);
    glVertex3f(20.0, -14, 17.0);
    glVertex3f(20.0, -14, 20.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(50.0, -14, 20.0);
    glVertex3f(50.0, -14, 17.0);
    glVertex3f(70.0, -14, 17.0);
    glVertex3f(70.0, -14, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.14, 0.14, 0.14);
    glVertex3f(-100.0, -15, -90.0);
    glVertex3f(-123.0, -15, -90.0);
    glVertex3f(-123.0, -15, 33.0);
    glVertex3f(-100.0, -15, 33.0);
    glEnd();
    //garis jalan kiri
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-112.5, -14, -20.0);
    glVertex3f(-112.5, -14, 0.0);
    glVertex3f(-110.0, -14, 0.0);
    glVertex3f(-110.0, -14, -20.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-112.5, -14, -70.0);
    glVertex3f(-112.5, -14, -50.0);
    glVertex3f(-110.0, -14, -50.0);
    glVertex3f(-110.0, -14, -70.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.14, 0.14, 0.14);
    glVertex3f(-100.0, -15, -90.0);
    glVertex3f(125.0, -15, -90.0);
    glVertex3f(125.0, -15, -65.0);
    glVertex3f(-100.0, -15, -65.0);
    glEnd();
    //garis jalan belakang
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-100.0, -14, -78.0);
    glVertex3f(-100.0, -14, -75.0);
    glVertex3f(-80.0, -14, -75.0);
    glVertex3f(-80.0, -14, -78.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(-50.0, -14, -78.0);
    glVertex3f(-50.0, -14, -75.0);
    glVertex3f(-30.0, -14, -75.0);
    glVertex3f(-30.0, -14, -78.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(0.0, -14, -78.0);
    glVertex3f(0.0, -14, -75.0);
    glVertex3f(20.0, -14, -75.0);
    glVertex3f(20.0, -14, -78.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(50.0, -14, -78.0);
    glVertex3f(50.0, -14, -75.0);
    glVertex3f(70.0, -14, -75.0);
    glVertex3f(70.0, -14, -78.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(100.0, -14, -78.0);
    glVertex3f(100.0, -14, -75.0);
    glVertex3f(120.0, -14, -75.0);
    glVertex3f(120.0, -14, -78.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.14, 0.14, 0.14);
    glVertex3f(70.0, -15, 5.0);
    glVertex3f(95.0, -15, 5.0);
    glVertex3f(95.0, -15, 60.0);
    glVertex3f(70.0, -15, 60.0);
    glEnd();
    //garis jalan depan maju
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(82.0, -14, 35.0);
    glVertex3f(85.0, -14, 35.0);
    glVertex3f(85.0, -14, 55.0);
    glVertex3f(82.0, -14, 55.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.14, 0.14, 0.14);
    glVertex3f(125.0, -15, 60.0);
    glVertex3f(70.0, -15, 60.0);
    glVertex3f(70.0, -15, 87.0);
    glVertex3f(125.0, -15, 87.0);
    glEnd();
    //garis jalan depan kiri
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(100.0, -14, 72.0);
    glVertex3f(120.0, -14, 72.0);
    glVertex3f(120.0, -14, 75.0);
    glVertex3f(100.0, -14, 75.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.14, 0.14, 0.14);
    glVertex3f(125.0, -15, 87.0);
    glVertex3f(150.0, -15, 87.0);
    glVertex3f(150.0, -15, -90.0);
    glVertex3f(125.0, -15, -90.0);
    glEnd();
    //garis jalan kanan
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(135.0, -14, 40.0);
    glVertex3f(138.0, -14, 40.0);
    glVertex3f(138.0, -14, 15.0);
    glVertex3f(135.0, -14, 15.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex3f(135.0, -14, -20.0);
    glVertex3f(138.0, -14, -20.0);
    glVertex3f(138.0, -14, -45.0);
    glVertex3f(135.0, -14, -45.0);
    glEnd();
    
    //Pohon
    glBegin(GL_QUADS);
    glColor3f(0.54, 0.27, 0.074);
    glVertex3f(-90.0, -15, -50.0);
    glVertex3f(-95.0, -15, -50.0);
    glVertex3f(-95.0, -15, -45.0);
    glVertex3f(-90.0, -15, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.54, 0.27, 0.074);
    glVertex3f(-90.0, 25, -50.0);
    glVertex3f(-95.0, 25, -50.0);
    glVertex3f(-95.0, 25, -45.0);
    glVertex3f(-90.0, 25, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.54, 0.27, 0.074);
    glVertex3f(-90.0, -15, -50.0);
    glVertex3f(-90.0, 25, -50.0);
    glVertex3f(-90.0, 25, -45.0);
    glVertex3f(-90.0, -15, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.54, 0.27, 0.074);
    glVertex3f(-95.0, -15, -50.0);
    glVertex3f(-95.0, 25, -50.0);
    glVertex3f(-95.0, 25, -45.0);
    glVertex3f(-95.0, -15, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.54, 0.27, 0.074);
    glVertex3f(-90.0, -15, -50.0);
    glVertex3f(-95.0, -15, -50.0);
    glVertex3f(-95.0, 25, -45.0);
    glVertex3f(-90.0, 25, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.54, 0.27, 0.074);
    glVertex3f(-90.0, -15, -50.0);
    glVertex3f(-95.0, -15, -50.0);
    glVertex3f(-95.0, 25, -50.0);
    glVertex3f(-90.0, 25, -50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.8, 0.19);
    glVertex3f(-100.0, 15, -60.0);
    glVertex3f(-85.0, 15, -60.0);
    glVertex3f(-85.0, 15, -35.0);
    glVertex3f(-100.0, 15, -35.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.8, 0.19);
    glVertex3f(-85.0, 15, -35.0);
    glVertex3f(-85.0, 15, -60.0);
    glVertex3f(-92.5, 30, -45.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.8, 0.19);
    glVertex3f(-100.0, 15, -35.0);
    glVertex3f(-100.0, 15, -60.0);
    glVertex3f(-92.5, 30, -45.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.8, 0.19);
    glVertex3f(-100.0, 15, -35.0);
    glVertex3f(-85.0, 15, -35.0);
    glVertex3f(-92.5, 30, -45.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.8, 0.19);
    glVertex3f(-100.0, 15, -60.0);
    glVertex3f(-85.0, 15, -60.0);
    glVertex3f(-92.5, 30, -45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.8, 0.19);
    glVertex3f(-100.0, 25, -60.0);
    glVertex3f(-85.0, 25, -60.0);
    glVertex3f(-85.0, 25, -35.0);
    glVertex3f(-100.0, 25, -35.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.8, 0.19);
    glVertex3f(-85.0, 25, -35.0);
    glVertex3f(-85.0, 25, -60.0);
    glVertex3f(-92.5, 45, -45.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.8, 0.19);
    glVertex3f(-100.0, 25, -35.0);
    glVertex3f(-100.0, 25, -60.0);
    glVertex3f(-92.5, 45, -45.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.8, 0.19);
    glVertex3f(-100.0, 25, -35.0);
    glVertex3f(-85.0, 25, -35.0);
    glVertex3f(-92.5, 45, -45.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.8, 0.19);
    glVertex3f(-100.0, 25, -60.0);
    glVertex3f(-85.0, 25, -60.0);
    glVertex3f(-92.5, 45, -45.0);
    glEnd();
    
    //jendela depan
    glBegin(GL_QUADS);
    glColor3f(0.90, 0.96, 1.00);
    glVertex3f(-10.0, 35.0, 40.1);
    glVertex3f(-10.0, 40.0, 40.1);
    glVertex3f(10.0, 40.0, 40.1);
    glVertex3f(10.0, 35.0, 40.1);
    glEnd();
    //jendela depan
    glBegin(GL_QUADS);
    glColor3f(0.90, 0.96, 1.00);
    glVertex3f(-10.0, 27.0, 40.1);
    glVertex3f(-10.0, 32.0, 40.1);
    glVertex3f(10.0, 32.0, 40.1);
    glVertex3f(10.0, 27.0, 40.1);
    glEnd();
    //jendela depan
    glBegin(GL_QUADS);
    glColor3f(0.90, 0.96, 1.00);
    glVertex3f(-10.0, 19.0, 40.1);
    glVertex3f(-10.0, 24.0, 40.1);
    glVertex3f(10.0, 24.0, 40.1);
    glVertex3f(10.0, 19.0, 40.1);
    glEnd();
    //jendela depan
    glBegin(GL_QUADS);
    glColor3f(0.90, 0.96, 1.00);
    glVertex3f(-10.0, 11.0, 40.1);
    glVertex3f(-10.0, 16.0, 40.1);
    glVertex3f(10.0, 16.0, 40.1);
    glVertex3f(10.0, 11.0, 40.1);
    glEnd();
    
    //Jendela Samping Kanan Kiri
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.3, 0.003);
    glVertex3f(14.1, 8.0, 3.0);
    glVertex3f(14.1, 41.0, 3.0);
    glVertex3f(14.1, 41.0, 37.0);
    glVertex3f(14.1, 8.0, 37.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.3, 0.003);
    glVertex3f(-14.1, 8.0, 3.0);
    glVertex3f(-14.1, 41.0, 3.0);
    glVertex3f(-14.1, 41.0, 37.0);
    glVertex3f(-14.1, 8.0, 37.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-14.2, 15.0, 37.0);
    glVertex3f(-14.2, 15.0, 3.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-14.2, 18.0, 37.0);
    glVertex3f(-14.2, 18.0, 3.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-14.2, 30.0, 37.0);
    glVertex3f(-14.2, 30.0, 3.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-14.2, 33.0, 37.0);
    glVertex3f(-14.2, 33.0, 3.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(14.2, 15.0, 37.0);
    glVertex3f(14.2, 15.0, 3.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(14.2, 18.0, 37.0);
    glVertex3f(14.2, 18.0, 3.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(14.2, 30.0, 37.0);
    glVertex3f(14.2, 30.0, 3.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(14.2, 33.0, 37.0);
    glVertex3f(14.2, 33.0, 3.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(14.2, 8.0, 10.0);
    glVertex3f(14.2, 41.0, 10.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-14.2, 8.0, 10.0);
    glVertex3f(-14.2, 41.0, 10.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(14.2, 8.0, 20.0);
    glVertex3f(14.2, 41.0, 20.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-14.2, 8.0, 20.0);
    glVertex3f(-14.2, 41.0, 20.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(14.2, 8.0, 30.0);
    glVertex3f(14.2, 41.0, 30.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-14.2, 8.0, 30.0);
    glVertex3f(-14.2, 41.0, 30.0);
    glEnd();
    
    //Perpotongan Garis Jendela
    float xa = 44, ya = 42, xb = 44, yb = 23, xc = 38, yc = 36, xd = 57, yd = 36;
    float mab = (yb - ya) / (xb - xa);
    float cab = ya - mab * xa;
    float mcd = (yd - yc) / (xd - xc);
    float ccd = yc - mcd * xc;

    float x = (ccd - cab) / (mab - mcd);
    float y = mab * x + cab;
    float z = 0.3;

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(xa, ya, z); 
    glVertex3f(xb, yb, z);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(xc, yc, z); 
    glVertex3f(xd, yd, z);
    glEnd();
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(x, y, z);
    glEnd();
    glFlush();

    float xa1 = 44, ya1 = 42, xb1 = 44, yb1 = 23, xc1 = 38, yc1 = 30, xd1 = 57, yd1 = 30;
    float ma1b1 = (yb1 - ya1) / (xb1 - xa1);
    float ca1b1 = ya1 - ma1b1 * xa1;
    float mc1d1 = (yd1 - yc1) / (xd1 - xc1);
    float cc1d1 = yc1 - mc1d1 * xc1;

    float x1 = (cc1d1 - ca1b1) / (ma1b1 - mc1d1);
    float y1 = ma1b1 * x1 + ca1b1;
    float z1 = 0.3;

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(xa1, ya1, z1);
    glVertex3f(xb1, yb1, z1);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(xc1, yc1, z1);
    glVertex3f(xd1, yd1, z1);
    glEnd();
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(x1, y1, z1);
    glEnd();
    glFlush();

    float xa2 = 50, ya2 = 42, xb2 = 50, yb2 = 23, xc2 = 38, yc2 = 30, xd2 = 57, yd2 = 30;
    float ma2b2 = (yb2 - ya2) / (xb2 - xa2);
    float ca2b2 = ya2 - ma2b2 * xa2;
    float mc2d2 = (yd2 - yc2) / (xd2 - xc2);
    float cc2d2 = yc2 - mc2d2 * xc2;

    float x2 = (cc2d2 - ca2b2) / (ma2b2 - mc2d2);
    float y2 = ma2b2 * x2 + ca2b2;
    float z2 = 0.3;

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(xa2, ya2, z2);
    glVertex3f(xb2, yb2, z2);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(xc2, yc2, z2);
    glVertex3f(xd2, yd2, z2);
    glEnd();
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(x2, y2, z2);
    glEnd();
    glFlush();

    float xa3 = -44, ya3 = 42, xb3 = -44, yb3 = 23, xc3 = -38, yc3 = 36, xd3 = -57, yd3 = 36;
    float ma3b3 = (yb3 - ya3) / (xb3 - xa3);
    float ca3b3 = ya3 - ma3b3 * xa3;
    float mc3d3 = (yd3 - yc3) / (xd3 - xc3);
    float cc3d3 = yc3 - mc3d3 * xc3;

    float x3 = (cc3d3 - ca3b3) / (ma3b3 - mc3d3);
    float y3 = ma3b3 * x3 + ca3b3;
    float z3 = 0.3;

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(xa3, ya3, z3);
    glVertex3f(xb3, yb3, z3);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(xc3, yc3, z3);
    glVertex3f(xd3, yd3, z3);
    glEnd();
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(x3, y3, z3);
    glEnd();
    glFlush();

    float xa4 = -44, ya4 = 42, xb4 = -44, yb4 = 23, xc4 = -38, yc4 = 30, xd4 = -57, yd4 = 30;
    float ma4b4 = (yb4 - ya4) / (xb4 - xa4);
    float ca4b4 = ya4 - ma4b4 * xa4;
    float mc4d4 = (yd4 - yc4) / (xd4 - xc4);
    float cc4d4 = yc4 - mc4d4 * xc4;

    float x4 = (cc4d4 - ca4b4) / (ma4b4 - mc4d4);
    float y4 = ma4b4 * x4 + ca4b4;
    float z4 = 0.3;

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(xa4, ya4, z4);
    glVertex3f(xb4, yb4, z4);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(xc4, yc4, z4);
    glVertex3f(xd4, yd4, z4);
    glEnd();
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(x4, y4, z4);
    glEnd();
    glFlush();

    float xa5 = -50, ya5 = 42, xb5 = -50, yb5 = 23, xc5 = -38, yc5 = 30, xd5 = -57, yd5 = 30;
    float ma5b5 = (yb5 - ya5) / (xb5 - xa5);
    float ca5b5 = ya5 - ma5b5 * xa5;
    float mc5d5 = (yd5 - yc5) / (xd5 - xc5);
    float cc5d5 = yc5 - mc5d5 * xc5;

    float x5 = (cc5d5 - ca5b5) / (ma5b5 - mc5d5);
    float y5 = ma5b5 * x5 + ca5b5;
    float z5 = 0.3;

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(xa5, ya5, z5);
    glVertex3f(xb5, yb5, z5);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(xc5, yc5, z5);
    glVertex3f(xd5, yd5, z5);
    glEnd();
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(x5, y5, z5);
    glEnd();
    glFlush();

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
    
    //TV
    for (int i = 0; i < 2; i++) {
        glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        glVertex3f(20.0, 35.0, -44.0 + i * 3);
        glVertex3f(40.0, 35.0, -44.0 + i * 3);
        glVertex3f(40.0, 20.0, -44.0 + i * 3);
        glVertex3f(20.0, 20.0, -44.0 + i * 3);
        glEnd();
    }
    for (int i = 0; i < 2; i++) {
        glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        glVertex3f(40.0 + i * -20, 35.0, -41.0);
        glVertex3f(40.0 + i * -20, 35.0, -44.0);
        glVertex3f(40.0 + i * -20, 20.0, -44.0);
        glVertex3f(40.0 + i * -20, 20.0, -41.0);
        glEnd();
    }
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(20.0, 20, -44.0);
    glVertex3f(20.0, 20, -41.0);
    glVertex3f(40.0, 20, -41.0);
    glVertex3f(40.0, 20, -44.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(20.0, 35, -44.0);
    glVertex3f(20.0, 35, -41.0);
    glVertex3f(40.0, 35, -41.0);
    glVertex3f(40.0, 35, -44.0);
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
    
    //kursi
    //Dudukan
    //Depan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.3, 0.0);
    glVertex3f(-10.0, -10.0, -20.8);
    glVertex3f(-7.2, -10.0, -20.8);
    glVertex3f(-7.2, -9.6, -20.8);
    glVertex3f(-10.0, -9.6, -20.8);
    glEnd();
    //Kanan
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(-7.2, -10.0, -24.4);
    glVertex3f(-7.2, -9.6, -24.4);
    glVertex3f(-7.2, -9.6, -20.8);
    glVertex3f(-7.2, -10.0, -20.8);
    glEnd();
    //Belakang
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.1, 0.0);
    glVertex3f(-10.0, -10.0, -24.4);
    glVertex3f(-10.0, -9.6, -24.4);
    glVertex3f(-7.2, -9.6, -24.4);
    glVertex3f(-7.2, -10.0, -24.4);
    glEnd();
    //Kiri
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(-10.0, -10.0, -24.4);
    glVertex3f(-10.0, -10.0, -20.8);
    glVertex3f(-10.0, -9.6, -20.8);
    glVertex3f(-10.0, -9.6, -24.4);
    glEnd();
    //Atas
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.4, 0.0);
    glVertex3f(-7.2, -9.6, -20.8);
    glVertex3f(-10.0, -9.6, -20.8);
    glVertex3f(-10.0, -9.6, -24.4);
    glVertex3f(-7.2, -9.6, -24.4);
    glEnd();
    //Bawah
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.0, 0.0);
    glVertex3f(-7.2, -10.0, -20.8);
    glVertex3f(-10.0, -10.0, -20.8);
    glVertex3f(-10.0, -10.0, -24.4);
    glVertex3f(-7.2, -10.0, -24.4);
    glEnd();
    //Kaki kanan kursi depan
    //Depan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.3, 0.0);
    glVertex3f(-7.8, -10.0, -21.2);
    glVertex3f(-7.4, -10.0, -21.2);
    glVertex3f(-7.4, -14.9, -21.2);
    glVertex3f(-7.8, -14.9, -21.2);
    glEnd();
    //Belakang
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.1, 0.0);
    glVertex3f(-7.8, -10.0, -21.6);
    glVertex3f(-7.4, -10.0, -21.6);
    glVertex3f(-7.4, -14.9, -21.6);
    glVertex3f(-7.8, -14.9, -21.6);
    glEnd();
    //Kanan
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(-7.4, -10.0, -21.6);
    glVertex3f(-7.4, -10.0, -21.2);
    glVertex3f(-7.4, -14.9, -21.2);
    glVertex3f(-7.4, -14.9, -21.6);
    glEnd();
    //Kiri
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(-7.8, -10.0, -21.6);
    glVertex3f(-7.8, -10.0, -21.2);
    glVertex3f(-7.8, -14.9, -21.2);
    glVertex3f(-7.8, -14.9, -21.6);
    glEnd();
    //Kaki kanan kursi belakang
    //Depan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.3, 0.0);
    glVertex3f(-7.8, -10.0, -23.6);
    glVertex3f(-7.4, -10.0, -23.6);
    glVertex3f(-7.4, -14.9, -23.6);
    glVertex3f(-7.8, -14.9, -23.6);
    glEnd();
    //Belakang
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.1, 0.0);
    glVertex3f(-7.8, -10.0, -24.0);
    glVertex3f(-7.4, -10.0, -24.0);
    glVertex3f(-7.4, -14.9, -24.0);
    glVertex3f(-7.8, -14.9, -24.0);
    glEnd();
    //Kanan
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(-7.4, -10.0, -24.0);
    glVertex3f(-7.4, -10.0, -23.6);
    glVertex3f(-7.4, -14.9, -23.6);
    glVertex3f(-7.4, -14.9, -24.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(-7.8, -10.0, -24.0);
    glVertex3f(-7.8, -10.0, -23.6);
    glVertex3f(-7.8, -14.9, -23.6);
    glVertex3f(-7.8, -14.9, -24.0);
    glEnd();
    //Kaki kiri kursi depan
    //Depan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.3, 0.0);
    glVertex3f(-9.8, -10.0, -21.2);
    glVertex3f(-9.4, -10.0, -21.2);
    glVertex3f(-9.4, -14.9, -21.2);
    glVertex3f(-9.8, -14.9, -21.2);
    glEnd();
    //Belakang
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.1, 0.0);
    glVertex3f(-9.8, -10.0, -21.6);
    glVertex3f(-9.4, -10.0, -21.6);
    glVertex3f(-9.4, -14.9, -21.6);
    glVertex3f(-9.8, -14.9, -21.6);
    glEnd();
    //Kanan
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(-9.4, -10.0, -21.6);
    glVertex3f(-9.4, -10.0, -21.2);
    glVertex3f(-9.4, -14.9, -21.2);
    glVertex3f(-9.4, -14.9, -21.6);
    glEnd();
    //Kiri
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(-9.8, -10.0, -21.6);
    glVertex3f(-9.8, -10.0, -21.2);
    glVertex3f(-9.8, -14.9, -21.2);
    glVertex3f(-9.8, -14.9, -21.6);
    glEnd();
    //Kaki kiri kursi belakang
    //Depan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.3, 0.0);
    glVertex3f(-9.8, -10.0, -23.6);
    glVertex3f(-9.4, -10.0, -23.6);
    glVertex3f(-9.4, -14.9, -23.6);
    glVertex3f(-9.8, -14.9, -23.6);
    glEnd();
    //Belakang
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.1, 0.0);
    glVertex3f(-9.8, -10.0, -24.0);
    glVertex3f(-9.4, -10.0, -24.0);
    glVertex3f(-9.4, -14.9, -24.0);
    glVertex3f(-9.8, -14.9, -24.0);
    glEnd();
    //Kanan
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(-9.4, -10.0, -24.0);
    glVertex3f(-9.4, -10.0, -23.6);
    glVertex3f(-9.4, -14.9, -23.6);
    glVertex3f(-9.4, -14.9, -24.0);
    glEnd();
    //Kiri
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(-9.8, -10.0, -24.0);
    glVertex3f(-9.8, -10.0, -23.6);
    glVertex3f(-9.8, -14.9, -23.6);
    glVertex3f(-9.8, -14.9, -24.0);
    glEnd();
    //Sandaran punggung
    //Depan
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.3, 0.0);
    glVertex3f(-9.8, -9.6, -24.2);
    glVertex3f(-7.4, -9.6, -24.2);
    glVertex3f(-7.4, -6.3, -24.2);
    glVertex3f(-9.8, -6.3, -24.2);
    glEnd();
    //Belakang
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.1, 0.0);
    glVertex3f(-9.8, -9.6, -24.4);
    glVertex3f(-7.4, -9.6, -24.4);
    glVertex3f(-7.4, -6.3, -24.4);
    glVertex3f(-9.8, -6.3, -24.4);
    glEnd();
    //Kiri
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(-9.8, -9.6, -24.4);
    glVertex3f(-9.8, -6.3, -24.4);
    glVertex3f(-9.8, -6.3, -24.2);
    glVertex3f(-9.8, -9.6, -24.2);
    glEnd();
    //Kanan
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(-7.4, -9.6, -24.4);
    glVertex3f(-7.4, -6.3, -24.4);
    glVertex3f(-7.4, -6.3, -24.2);
    glVertex3f(-7.4, -9.6, -24.2);
    glEnd();
    //Atas
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.4, 0.0);
    glVertex3f(-9.8, -6.3, -24.4);
    glVertex3f(-9.8, -6.3, -24.2);
    glVertex3f(-7.4, -6.3, -24.2);
    glVertex3f(-7.4, -6.3, -24.4);
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
    case 't':
    case 'T':
        xrot += 3.0;
        break;
    case 'g':
    case 'G':
        xrot -= 3.0;
        break;
    case 'y':
    case 'Y':
        yrot += 3.0;
        break;
    case 'h':
    case 'H':
        yrot -= 3.0;
        break;
    case 'u':
    case 'U':
        zrot += 3.0;
        break;
    case 'j':
    case 'J':
        zrot -= 3.0;
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

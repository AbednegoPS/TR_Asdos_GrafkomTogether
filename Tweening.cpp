#include <windows.h>
#include <stdio.h>
#include <gl/gl.h>
#include <gl/glut.h>

int berjalan = 0;

bool upup = true;

void UniversitasCiputraSurabaya(){


glBegin(GL_LINE_LOOP);//U

glVertex2f(-295,0);

glVertex2f(-295,50);

glVertex2f(-305,50);

glVertex2f(-305,10);

glVertex2f(-325,10);

glVertex2f(-325,50);

glVertex2f(-335,50);

glVertex2f(-335,0);

glVertex2f(-295,0);

glEnd();



glBegin(GL_LINE_LOOP);//N

glVertex2f(-270,0);

glVertex2f(-270,50);

glVertex2f(-260,50);

glVertex2f(-220,20);

glVertex2f(-220,50);

glVertex2f(-210,50);

glVertex2f(-210,0);

glVertex2f(-220,0);

glVertex2f(-260,35);

glVertex2f(-260,0);

glEnd();


glBegin(GL_LINE_LOOP);//I

glVertex2f(-190,0);

glVertex2f(-190,50);//1

glVertex2f(-180,50);

glVertex2f(-180,0);

glEnd();


glBegin(GL_LINE_LOOP);//V

glVertex2f(-160,0);

glVertex2f(-140,0);

glVertex2f(-100,50);

glVertex2f(-130,50);

glVertex2f(-140,25);

glVertex2f(-150,50);

glVertex2f(-170,50);

glVertex2f(-160,0);

glEnd();


glBegin(GL_LINE_LOOP);//C

glVertex2f(55,0);

glVertex2f(55,50);

glVertex2f(95,50);

glVertex2f(75,30);

glVertex2f(95,0);

glVertex2f(85,5);

glVertex2f(95,0);

glVertex2f(55,0);

glVertex2f(55,0);

glEnd();


glBegin(GL_LINE_LOOP);//I

glVertex2f(130,0);

glVertex2f(130,50);

glVertex2f(120,50);

glVertex2f(120,0);

glEnd();


glBegin(GL_LINE_LOOP);//P

glVertex2f(200,0);

glVertex2f(200,50);

glVertex2f(240,50);

glVertex2f(240,40);

glVertex2f(250,30);

glVertex2f(210,30);

glVertex2f(240,30);

glVertex2f(240,20);

glVertex2f(210,20);

glVertex2f(210,0);

glEnd();


glBegin(GL_LINE_LOOP);//U

glVertex2f(250,0);

glVertex2f(250,50);

glVertex2f(260,50);

glVertex2f(260,10);

glVertex2f(280,10);

glVertex2f(280,50);

glVertex2f(290,50);

glVertex2f(290,0);

glVertex2f(250,0);

glEnd();


glBegin(GL_LINE_LOOP);//A

glVertex2f(345,0);

glVertex2f(345,50);

glVertex2f(305,50);

glVertex2f(305,0);

glVertex2f(315,0);

glVertex2f(315,15);

glVertex2f(335,15);

glVertex2f(335,0);

glEnd();

glBegin(GL_LINE_LOOP);

glVertex2f(335,25);

glVertex2f(315,25);

glVertex2f(315,40);

glVertex2f(335,40);

glEnd();




}


void display(void){

glClear(GL_COLOR_BUFFER_BIT);

glPushMatrix();

glTranslatef(berjalan,0,0);

UniversitasCiputraSurabaya();

glLineWidth(3);

glColor3f(0.0,0.0,1.0);

glFlush();

glPopMatrix();

glutSwapBuffers();

}



void kecepatan(int t)

{

if (upup){

berjalan +=10;

}

else{

berjalan-=10;

}



if (berjalan>200){

upup=true;

}

else if(berjalan<-200)

{

upup=true;

}



glutPostRedisplay();

glutTimerFunc(205,kecepatan,0);

}



int main(int argc, char **argv){

glutInit(&argc, argv);

glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

glutInitWindowPosition(200,20);

glutInitWindowSize(1020,720);

glutCreateWindow("Universitas Ciputra Surabaya");

glClearColor(1.0,1.0,1.0,1.0);

gluOrtho2D(-320.,500.,-240.0,240.0);

glutDisplayFunc(display);

glutIdleFunc(display);

glutTimerFunc(1,kecepatan,0);

glutMainLoop();

return 0;

}

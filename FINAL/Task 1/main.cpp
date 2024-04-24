#include <windows.h>
#include <gl/glut.h>
#include<iostream>
using namespace std;


void circle() {
 glColor3f(1.0, 0.0, 0.0);
 glPointSize(2.0);
 float r = 100;
 float x = 0, y = r;
 float z = 0;
 float p = 1 - r;
 glBegin(GL_POINTS);
 while (x != y)
 {
  x++;
  if (p < 0) {
   p += 2 * (x + 1) + 1;
  }
  else {
   y--;
   p += 2 * (x + 1) + 1 - 2 * (y - 1);
  }
  glVertex3i(x, y,0);
  glVertex3i(-x, y,0);
  glVertex3i(x, -y,0);
  glVertex3i(-x, -y,0);

  glVertex3i(y, x,0);
  glVertex3i(-y, x,0);
  glVertex3i(y, -x,0);
  glVertex3i(-y, -x,0);

 }
 glEnd();
 glFlush();
}
int main(int argc, char ** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Circle");

 //glClearColor(1.0, 1.0, 1.0, 1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 gluOrtho2D(-250, 250, -250, 250);
 glMatrixMode(GL_PROJECTION);
 glViewport(0, 0, 500, 500);

 glutDisplayFunc(circle);
 glutMainLoop();
 return 0;
}

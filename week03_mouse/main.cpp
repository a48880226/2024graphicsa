#include <GL/glut.h>
#include <stdio.h>
void mouse(int button,int state,int x,int y){
    //printf("Hello Mouse!\n");
    //printf("%d %d %d %d\n",button,state,x,y);
    if(state==GLUT_DOWN) printf("glVertext(%d-150)/150.0,-(%d-150)/150.0\n",x,y);
}
void display(){
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc,char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03_mouse");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}

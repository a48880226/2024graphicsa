#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename){
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * handA = NULL;
GLMmodel * handB = NULL;
GLMmodel * upperA = NULL;
GLMmodel * lowerA = NULL;
GLMmodel * body = NULL;
void drawBody(void)
{
    if (!body) {
	body = glmReadOBJ("data/body.obj");
	if (!body) exit(0);
	glmUnitize(body);
	glmFacetNormals(body);
	glmVertexNormals(body, 90.0);
    }

    glmDraw(body, GLM_SMOOTH | GLM_TEXTURE);
}

void drawUpperA(void){
    if (!upperA) {
	upperA = glmReadOBJ("data/upperA.obj");
	if (!upperA) exit(0);
	glmUnitize(upperA);
	glmFacetNormals(upperA);
	glmVertexNormals(upperA, 90.0);
    }

    glmDraw(upperA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawLowerA(void){
    if (!lowerA) {
	lowerA = glmReadOBJ("data/lowerA.obj");
	if (!lowerA) exit(0);
	glmUnitize(lowerA);
	glmFacetNormals(lowerA);
	glmVertexNormals(lowerA, 90.0);
    }

    glmDraw(lowerA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawmodel(void){
    if (!pmodel) {
	pmodel = glmReadOBJ("data/Gundam.obj");
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH | GLM_TEXTURE);
}
void drawhandA(void){
    if (!handA) {
	handA = glmReadOBJ("data/handA.obj");
	if (!handA) exit(0);
	glmUnitize(handA);
	glmFacetNormals(handA);
	glmVertexNormals(handA, 90.0);
    }

    glmDraw(handA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawhandB(void){
    if (!handB) {
	handB = glmReadOBJ("data/handA.obj");
	if (!handB) exit(0);
	glmUnitize(handB);
	glmFacetNormals(handB);
	glmVertexNormals(handB, 90.0);
    }

    glmDraw(handB, GLM_SMOOTH | GLM_TEXTURE);
}
void myBody(){
    glPushMatrix();
        glColor3f(1,0,0);
        glutSolidCube(0.6);
    glPopMatrix();
}
//float angle = 0,da=1;
float angle[20]={};
int angleID=0;
int oldX=0,oldY=0;
#include <stdio.h>
FILE * fin=NULL;
FILE * fout=NULL;
void motion(int x,int y){
    angle[angleID]+=y-oldY;
    oldX=x;
    oldY=y;
    glutPostRedisplay();
    if(fout==NULL) fout=fopen("angle.txt","w+");
    for(int i=0;i<20;i++){
        printf("%.1f ",angle[i]);
        fprintf(fout,"%.1f ",angle[i]);
    }
    printf("\n");
    fprintf(fout,"\n");
}
void mouse(int button,int state,int x,int y){
    oldX=x;
    oldY=y;
}
void keyboard(unsigned char key,int x,int y){
    if(key=='r'){
        if(fin==NULL) fin=fopen("angle.txt","r");
        for(int i=0;i<20;i++){
            fscanf(fin,"%f",&angle[i]);
        }
        glutPostRedisplay();
    }
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);
    glPushMatrix();
        glRotatef(angle[0],0,1,0);
        drawBody();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1,1,1);
        glPushMatrix();
            glTranslatef(-0.1,0,0);
            glRotatef(angle[1],0,0,1);
            glRotatef(angle[2],1,0,0);
            glTranslatef(0,-0.07,0);
            drawUpperA();
            glPushMatrix();
                glTranslatef(-0.02,-0.09,0);
                glRotatef(angle[3],1,0,0);
                glTranslatef(0,-0.21,0);
                drawLowerA();
            glPopMatrix();
        glPopMatrix();
        glutSwapBuffers();
}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
int main(int argc, char*argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week13-2");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    myTexture("data/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glutMainLoop();
}

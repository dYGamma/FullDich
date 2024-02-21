#include <stdarg.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glut.h>

void init(void) {
	glClearColor(0.3, 0.3, 0.3, 1.0);
	glShadeModel(GL_SMOOTH);

	static float lmodelTwoside[] = { GL_TRUE };
	static float lmodelOneside[] = { GL_FALSE };
	static float position[] = { 1.0, 1.0, 1.0, 1.0 };
	static float frontMatShininess[] = { 1.0 };
	static float backMatShininess[] = { 0.0 };

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glMaterialfv(GL_FRONT, GL_SHININESS, frontMatShininess);
	glMaterialfv(GL_BACK, GL_SHININESS, backMatShininess);

	glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE, lmodelTwoside);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glEnable(GL_LIGHTING);//включаем расчет освещения
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.3, 0.5);
	glVertex3f(0.3, -0.3, -0.3);
	glVertex3f(0.3, 0.3, -0.3);
	glVertex3f(-0.3, 0.3, -0.3);
	glVertex3f(-0.3, -0.3, -0.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 1.0, 1.0);//front
	glVertex3f(0.3, -0.3, 0.3);
	glVertex3f(0.3, 0.3, 0.3);
	glVertex3f(-0.3, 0.3, 0.3);
	glVertex3f(-0.3, -0.3, 0.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);//front
	glVertex3f(0.3, -0.3, -0.3);
	glVertex3f(0.3, 0.3, -0.3);
	glVertex3f(0.3, 0.3, 0.3);
	glVertex3f(0.3, -0.3, 0.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-0.3, -0.3, 0.3);
	glVertex3f(-0.3, 0.3, 0.3);
	glVertex3f(-0.3, 0.3, -0.3);
	glVertex3f(-0.3, -0.3, -0.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.5);//front
	glVertex3f(0.3, 0.3, 0.3);
	glVertex3f(0.3, 0.3, -0.3);
	glVertex3f(-0.3, 0.3, -0.3);
	glVertex3f(-0.3, 0.3, 0.3);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.3, -0.3, -0.3);
	glVertex3f(0.3, -0.3, 0.3);
	glVertex3f(-0.3, -0.3, 0.3);
	glVertex3f(-0.3, -0.3, -0.3);
	glEnd();

	glPushMatrix();
	glColor3d(1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 1.0);
	glutSolidSphere(0.25, 30, 40);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslatef(1.0, 0.0, 1.0);
	glutSolidSphere(0.25, 30, 40);
	glPopMatrix();

	glPushMatrix();
	glColor3d(0.0, 1.0, 0.0);
	glTranslatef(0.0, 1.0, 1.0);
	glutSolidSphere(0.25, 30, 40);
	glPopMatrix();


	glutSwapBuffers();//смена буферов
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, (double)w / (double)h, 2.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		2.0f, 2.0f, 2.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	);
}


int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(720, 480);
	glutCreateWindow("Лабораторная работа");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}

#include <stdarg.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glut.h>

void init(void) {
	glClearColor(0.3, 0.3, 0.3, 1.0);//очистка экрана в цвет
	glShadeModel(GL_SMOOTH);//интерполяция цветов, режим сглаживания

	static float lmodelTwoside[] = { GL_TRUE };
	static float lmodelOneside[] = { GL_FALSE };
	static float position[] = { 1.0, 1.0, 1.0, 1.0 };
	static float frontMatShininess[] = { 1.0 };
	static float backMatShininess[] = { 0.0 };

	glEnable(GL_DEPTH_TEST);//включаем тест глубины
	glDepthFunc(GL_LEQUAL);//фрагмент проходит тест, если его значение глубины меньше либо равно хранимому в буфере
	glLightfv(GL_LIGHT0, GL_POSITION, position);//указываем параметры света, //источник//парметры источника
	glMaterialfv(GL_FRONT, GL_SHININESS, frontMatShininess);//зеркальное отражение
	glMaterialfv(GL_BACK, GL_SHININESS, backMatShininess);

	glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE, lmodelTwoside);//параметры модели освещения (двустороннее)
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//очистка буфера от старых значений
	glEnable(GL_COLOR_MATERIAL);//управление свойством материала
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glEnable(GL_LIGHTING);//включаем расчет освещения
	glEnable(GL_LIGHT0);// разблокировка источника света
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
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//окно просмотра
	glMatrixMode(GL_PROJECTION);//применить последующие матричные операции к стеку проекционных матриц
	glLoadIdentity();//установить текущую матрицу в качестве единичной матрицы
	gluPerspective(50.0, (double)w / (double)h, 2.0, 100.0);// установить текущее видимое пространство в пространство перспективной проекции
	glMatrixMode(GL_MODELVIEW);//применить последующие операции матрицы к стеку матрицы представления модели.
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
	glutInitWindowSize(1280, 640);
	glutCreateWindow("Лабораторная работа");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}

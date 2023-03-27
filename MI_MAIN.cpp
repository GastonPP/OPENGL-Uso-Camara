#include <iostream>
#include <GL/glut.h>
#include "DEFINES.h"
#include "Class_Camara.h"
#include "Controles.h"
#include "Movimiento Camara.h"


/*
	EJEMPLO DE USO DE LA CAMARA CON "glFrustum" y "gluLookAt".

	Excelente ejemplo donde se muestra el uso de la camara y tambien
	el uso del teclado y mouse.
*/

// TIMER : 16MS PARA 60fpss
void Timer(int x) {
	glutPostRedisplay();
	glutTimerFunc(16, Timer, 1);
}

static void display(void) {

	Coor3d Rot_, Trasl_, Ang_;

	// Limpiamos 
	glClear(GL_COLOR_BUFFER_BIT);

	// MODO MATRIZ (GL_MODELVIEW)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// CAMARA
	Camara.Movimiento_Camara();

	Rot_ = Camara.Get_Rotacion();
	Trasl_ = Camara.Get_Traslacion();
	Ang_ = Camara.Get_Angulos();

	gluLookAt(Trasl_.X_, Trasl_.Y_, Trasl_.Z_,
			  Rot_.X_, Rot_.Y_, Rot_.Z_,
			  0.0, 1.0, 0.0);

	dibujo2();

	


	glutSwapBuffers();

}

// VER QUE AL REDIMENSIONAR NO SE DISTORSIONA.
static void reshape(int w, int h) {

	// PONEMOS EL MODO DE MATRIZ EN PROJECCION
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// INDICAMOS LO QUE SE VA A MOSTRAR CON LA
	// CAMARA (CON PROJECCION)
	glFrustum(-2.0, 2.0, -2.0, 2.0, 1.0, 100.0);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(500, 100);
	glutCreateWindow(argv[0]);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(4.0f);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMotionFunc(Mouse_func);
	glutMouseFunc(Mouse_Buttons);
	glutKeyboardFunc(Keyboard_Down);
	glutKeyboardUpFunc(Keyboard_Up);
	glutSpecialFunc(Keyboard_Special_Down);
	glutSpecialUpFunc(Keyboard_Special_Up);

	Timer(1);

	glutMainLoop();

	return 0;
}
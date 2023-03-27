#pragma once


void dibujo() {

	static double angulo;

	angulo += 1.0;

	glPushMatrix();
		glTranslated(0.0, 0.0, 0.0);				// Dentro de una matriz todo es acumulable. Osea si me
		glColor3f(1.0f, 1.0f, 1.0f);				// traslado por el eje X 2 posiciones, luego todo lo
		glutWireCube(3);							// que se haga sera a partir de ese punto. Osea, despues
													// del traslado, la posicion X=2 ahora es el punto (0,0,0)
		glTranslated(-6.0, 0.0, 0.0);				// Notar que primero dibujamos el cubo en (0,0,0), luego
		glColor3f(1.0f, 0.0f, 0.0f);				// nos trasladamos (-6,0,0) y dibujamos otro cubo. Ahora esta
		glutWireCube(3);							// posicion ahora es la (0,0,0). Si queremos dibujar el
													// otro cubo en donde antes era (6,0,0) tenemos que movernos
													// a (12,0,0).
		glRotated(angulo*2, 0, 0, 1);
		glTranslated(12.0, 0.0, 0.0);				
		glColor3f(0.0f, 0.0f, 1.0f);
		glutWireCube(3);
	glPopMatrix();

	glRotated(angulo, 0, 0, 1);
	glTranslated(12.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 1.0f);
	glutWireCube(3);
}

void dibujo2() {

	double Cantidad = 10.0;
	double Separacion = 10.0;
	double Indice = Cantidad * Separacion;

	for (double x = 0; x < Indice; x += Separacion) {
		for (double y = 0; y < Indice; y += Separacion) {
			for (double z = 0; z < Indice; z += Separacion) {
				glPushMatrix();
					glTranslated(x, y, z);
					glColor3f(0.01f*x, 0.01f*y, 0.01f*z);
					glutWireCube(3);
				glPopMatrix();
			}
		}
	}
}


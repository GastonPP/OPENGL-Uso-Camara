#pragma once

// Las siguientes funciones son un muy buen ejemplo del uso del 
// teclado y el mouse. Notar el uso de las Estructuras del Teclado
// y el Mouse y como las funciones guardan los valores necesarios.


// MOUSE (MOVIMIENTO)
// Guardamos constantemente las coordenadas del mouse en el
// objeto "Mouse_" del tipo STRUCT_MOUSE
void Mouse_func(int x, int y) {
	Mouse_.POS_X = x;
	Mouse_.POS_Y = y;
}


// MOUSE (BOTONES)
// Cuando el click izquierdo esta presionado, guardamos el valor
// "true" en la variable "Mouse_" del tipo STRUCT_MOUSE
// Lo mismo con el click Derecho.
void Mouse_Buttons(int botton, int state, int x, int y) {

	switch (botton) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) { Mouse_.MOUSE_IZQ = true; }
		else { Mouse_.MOUSE_IZQ = false; }
		break;

	case GLUT_MIDDLE_BUTTON:
		// nada
		break;

	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) { Mouse_.MOUSE_DER = true; }
		else { Mouse_.MOUSE_DER = false; }
		break;
	}
}


// TECLAS APRETADAS (DOWN)
// Cuando las teclas estan presionadas, guardamos el valor true en 
// la teclas correspondientes. (con la 'r' reseteamos la posicion
// de la camara). Para ello usamos el vector "Teclado_"
void Keyboard_Down(unsigned char Tecla_, int x, int y) {

	switch (Tecla_) {
		case 'w':
			Teclado_[KEY_W] = true;
			break;

		case 's':
			Teclado_[KEY_S] = true;
			break;

		case 'a':
			Teclado_[KEY_A] = true;
			break;

		case 'd':
			Teclado_[KEY_D] = true;
			break;

		case 'e':
			Teclado_[KEY_E] = true;
			break;

		case 'q':
			Teclado_[KEY_Q] = true;
			break;

		case 'h':
			Teclado_[KEY_H] = true;
			break;

		case 'y':
			Teclado_[KEY_Y] = true;
			break;

		case 'g':
			Teclado_[KEY_G] = true;
			break;

		case 'j':
			Teclado_[KEY_J] = true;
			break;

		case 'r':
			Camara.Reset();
			break;
	}
}


// TECLAS LEVANTADAS (UP)
// Cuando las teclas se dejan de presionar, se guarda el
// valor "false" en la tecla correspondiente. Para ello
// usamos el vector "Teclado_"
void Keyboard_Up(unsigned char Tecla_, int x, int y) {
	
	switch (Tecla_) {
		case 'w':
			Teclado_[KEY_W] = false;
			break;

		case 's':
			Teclado_[KEY_S] = false;
			break;

		case 'a':
			Teclado_[KEY_A] = false;
			break;

		case 'd':
			Teclado_[KEY_D] = false;
			break;

		case 'e':
			Teclado_[KEY_E] = false;
			break;

		case 'q':
			Teclado_[KEY_Q] = false;
			break;

		case 'h':
			Teclado_[KEY_H] = false;
			break;

		case 'y':
			Teclado_[KEY_Y] = false;
			break;

		case 'g':
			Teclado_[KEY_G] = false;
			break;

		case 'j':
			Teclado_[KEY_J] = false;
			break;
	}
}


// TECLAS ESPECIALES APRETADAS (DOWN)
void Keyboard_Special_Down(int Key_, int x, int y) {

	switch (Key_) {
		case GLUT_KEY_UP:
			Teclado_[KEY_UP] = true;
			break;

		case GLUT_KEY_DOWN:
			Teclado_[KEY_DOWN] = true;
			break;

		case GLUT_KEY_LEFT:
			Teclado_[KEY_LEFT] = true;
			break;

		case GLUT_KEY_RIGHT:
			Teclado_[KEY_RIGHT] = true;
			break;
	}
}


// TECLAS ESPECIALES LEVANTADAS (UP)
void Keyboard_Special_Up(int Key_, int x, int y) {

	switch (Key_) {
	case GLUT_KEY_UP:
		Teclado_[KEY_UP] = false;
		break;

	case GLUT_KEY_DOWN:
		Teclado_[KEY_DOWN] = false;
		break;

	case GLUT_KEY_LEFT:
		Teclado_[KEY_LEFT] = false;
		break;

	case GLUT_KEY_RIGHT:
		Teclado_[KEY_RIGHT] = false;
		break;
	}
}
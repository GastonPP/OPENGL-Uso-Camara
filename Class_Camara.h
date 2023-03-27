#pragma once

const double VARIACION_ROTACION = 1.0;
const double VARIACION_TRASLACION = 0.2;

// La idea de esta clase es que basandose en la posicion
// de la camara, en radio definido del objetivo y el angulo
// de los planos XZ e YZ, nos calcule el objetivo de la
// camara. De manera que podamos movernos con la camara de
// la misma manera que en los juegos de primera persona.
class CLS_CAMARA {
	private:
		// Estado de los angulos X°, Y°, Z°
		STRUCT_ROTACION		ANG_ROTACION;

		// Estado posiciones de rotacion y traslacion
		STRUCT_ROTACION		ROTACION;
		STRUCT_TRASLACION	TRASLACION;

	private:
		void Movimiento(DIR_MOVIMIENTO);
		void Rotacion();
		void Traslacion(DIR_MOVIMIENTO);

	public:
		void Movimiento_Camara();
		void Reset();

		Coor3d Get_Rotacion();
		Coor3d Get_Traslacion();
		Coor3d Get_Angulos();

		// CONSTRUCTOR
		CLS_CAMARA();
} Camara;


// CONSTRUCTOR
CLS_CAMARA::CLS_CAMARA()  {
	ROTACION.X_ = 1.0;
	ROTACION.Y_ = 0.0;
	ROTACION.Z_ = 0.0;

	ANG_ROTACION.X_ = 0.0;
	ANG_ROTACION.Y_ = 0.0;
	ANG_ROTACION.Z_ = 0.0;

	TRASLACION.X_ = 0.0;
	TRASLACION.Y_ = 0.0;
	TRASLACION.Z_ = 0.0;
}


// RESET
void CLS_CAMARA::Reset() {
	ANG_ROTACION.X_ = 0.0;
	ANG_ROTACION.Y_ = 0.0;
	ANG_ROTACION.Z_ = 0.0;

	TRASLACION.X_ = 0.0;
	TRASLACION.Y_ = 0.0;
	TRASLACION.Z_ = 0.0;

	ROTACION.X_ = 1.0;
	ROTACION.Y_ = 0.0;
	ROTACION.Z_ = 0.0;
}


// Movimiento. Angulo de Camara, Rotacion y Traslacion
void CLS_CAMARA::Movimiento(DIR_MOVIMIENTO Mov) {

	switch (Mov) {

			// MOVIMIENTO DE LA ROTACION DE CAMARA
		case DERECHA:
			ANG_ROTACION.Y_ += VARIACION_ROTACION;
			break;

		case IZQUIERDA:
			ANG_ROTACION.Y_ -= VARIACION_ROTACION;
			break;

		case ARRIBA:
			if (ANG_ROTACION.X_ < 90.0)
				ANG_ROTACION.X_ += VARIACION_ROTACION;
			break;

		case ABAJO:
			if (ANG_ROTACION.X_ > -90.0)
				ANG_ROTACION.X_ -= VARIACION_ROTACION;
			break;
	}

	// Limitamos la ANG_ROTACION a 360°
	// ANG_ROTACION.X_ = Lim_Ang(ANG_ROTACION.X_);		lo limitamos de -90 a 90 (no da la vuelta)
	ANG_ROTACION.Y_ = Lim_Ang(ANG_ROTACION.Y_);
	ANG_ROTACION.Z_ = Lim_Ang(ANG_ROTACION.Z_);

	Rotacion();
	Traslacion(Mov);
}


// APLICAR ROTACION
void CLS_CAMARA::Rotacion() {

	// PLANO X, Y
	ROTACION.X_ = TRASLACION.X_ + cos_(ANG_ROTACION.Y_) * cos_(ANG_ROTACION.X_);
	ROTACION.Z_ = TRASLACION.Z_ + sin_(ANG_ROTACION.Y_) * cos_(ANG_ROTACION.X_);

	// ALTURA, EJE Y
	ROTACION.Y_ = TRASLACION.Y_ + sin_(ANG_ROTACION.X_);
}


// APLICAR TRASLACION
void CLS_CAMARA::Traslacion(DIR_MOVIMIENTO Mov) {

	switch (Mov) {

		case ADELANTE:
			TRASLACION.X_ += cos_(ANG_ROTACION.Y_) * VARIACION_TRASLACION * cos_(ANG_ROTACION.X_);
			TRASLACION.Z_ += sin_(ANG_ROTACION.Y_) * VARIACION_TRASLACION * cos_(ANG_ROTACION.X_);

			TRASLACION.Y_ += sin_(ANG_ROTACION.X_) * VARIACION_TRASLACION;
			break;

		case ATRAS:
			TRASLACION.X_ -= cos_(ANG_ROTACION.Y_) * VARIACION_TRASLACION * cos_(ANG_ROTACION.X_);
			TRASLACION.Z_ -= sin_(ANG_ROTACION.Y_) * VARIACION_TRASLACION * cos_(ANG_ROTACION.X_);

			TRASLACION.Y_ -= sin_(ANG_ROTACION.X_) * VARIACION_TRASLACION;
			break;

		// Nos trasladamos solo en el palo X, Z no afecta ni el angulo X° ni la trasl en Y
		case HOR_IZQUIERDA:
			TRASLACION.X_ += cos_(ANG_ROTACION.Y_ - 90.0) * VARIACION_TRASLACION;
			TRASLACION.Z_ += sin_(ANG_ROTACION.Y_ - 90.0) * VARIACION_TRASLACION;
			break;

		case HOR_DERECHA:
			TRASLACION.X_ += cos_(ANG_ROTACION.Y_ + 90.0) * VARIACION_TRASLACION;
			TRASLACION.Z_ += sin_(ANG_ROTACION.Y_ + 90.0) * VARIACION_TRASLACION;
			break;

	}
}


// Leer Posiciones de Rotacion
Coor3d CLS_CAMARA::Get_Rotacion() {
	Coor3d Temp;

	Temp.X_ = ROTACION.X_;
	Temp.Y_ = ROTACION.Y_;
	Temp.Z_ = ROTACION.Z_;

	return Temp;
}

// Leer Posiciones de Traslacion
Coor3d CLS_CAMARA::Get_Traslacion() {
	Coor3d Temp;

	Temp.X_ = TRASLACION.X_;
	Temp.Y_ = TRASLACION.Y_;
	Temp.Z_ = TRASLACION.Z_;

	return Temp;
}

// Leer valores de los Angulos
Coor3d CLS_CAMARA::Get_Angulos() {
	Coor3d Temp;

	Temp.X_ = ANG_ROTACION.X_;
	Temp.Y_ = ANG_ROTACION.Y_;
	Temp.Z_ = ANG_ROTACION.Z_;

	return Temp;
}


// MOVIMIENTOS DE LA CAMARA
// Con esta funcion recuperamos los estados del
// teclado y mouse y realizamos las acciones
// correspondientes.
void  CLS_CAMARA::Movimiento_Camara() {

	// EJE X: Cuando queremos girar de izquierda a derecha (eje X)
	// en realidad giramos sobre el eje Y
	if (Teclado_[KEY_A]) {
		Movimiento(IZQUIERDA);
	}

	if (Teclado_[KEY_D]) {
		Movimiento(DERECHA);
	}

	// EJE Y: Cuando giramos de arriba a abajo (eje Y)
	// en realidad giramos sobre el eje X
	if (Teclado_[KEY_W]) {
		Movimiento(ARRIBA);
	}

	if (Teclado_[KEY_S]) {
		Movimiento(ABAJO);
	}

	// EJE Z: Cuando vamos hacia adelante y hacia atras.
	// nos movemos por el eje Z
	if (Teclado_[KEY_UP]) {
		Movimiento(ADELANTE);
	}

	if (Teclado_[KEY_DOWN]) {
		Movimiento(ATRAS);
	}

	// EJE X: HORIZONTAL
	if (Teclado_[KEY_LEFT]) {
		Movimiento(HOR_IZQUIERDA);
	}

	if (Teclado_[KEY_RIGHT]) {
		Movimiento(HOR_DERECHA);
	}
}







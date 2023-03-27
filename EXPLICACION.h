#pragma once

/*
	INTENTO DE RESUMEN DE LOS CALCULOS DE CAMARA

	Lo primero es enteder como calculamos los movimientos de la camara en el eje X y Z, osea en el plano
	cuando miramos para la izquierda o a la derecha (sobre el propio eje).

	- ROTACION DE CAMARA (EJES X y Z)
	---------------------------------
	El problema se da al tener que ingresar un punto en X y en Z, que vaya dibujando un circulo.
	Para eso usamos la funcion del Sin y Cos. Si tomamos un circulo de radio 1 (nos da igual el 
	radio, pero para el movimiento circular, que el radio sea 1 nos arregla muchos problemas), y
	entonces indicando el Angulo (0 a 360) podemos saber la posicion en X y Z muy facil de la 
	siguiente forma:

			si el angulo es 145° -->	X = cos(145)
										Z = sin(145)

			IMPORTANTE, el angulo en este caso corresponde al EJE Y.
										
										X = cos(Y°)
										Z = sin(Y°)

	y con ese simple calculo ya tenemos las coordenadas que necesitamos. Dependiendo de como se
	esten ingresando los angulos o de como se los tome en cuenta, puede que haya que invertir
	el Sin por el Cos y viceversa, pero solo es cuenstion de ir probando, no hay muchas
	combinaciones posibles.

	El mismo razonamiento se da para el movimiento de Arriba y Abajo (sobr el eje) osea sobre los
	eje Y,Z. En este caso el angulo sera el que formen con X.
										
										Y = cos(X°)
										Z = sin(X°)

	- TRASLACION DE LA CAMARA (EJES X y Z)
	--------------------------------------
	ahora bien, para movernos por los eje X y Z basta con indicar una posicion en X y otra en Z,
	o bien ir sumando o restando una cierta cantidad de "Variacion" a las posiciones actuales.
	Ejemplo, estamos en (10,5) y me muevo +1 sobre X, entonces queda (11,5) y nos trasladaremos
	a esa posicion. Pero el inconvieniente es que siempre nos movemos sobre el eje X o sobre el
	Z de forma recta, y si por ejemplo, rotamos la camara, "adelante" seguira siendo "adelante"
	y nos moveremos en en esa direccion por mas que la camara mire en otra direccion.
	La idea es que "adelante" o "atras" sea en relacion a la rotacion de la camara. Si la camara
	mira en un direccion, que "adelante" sea esa direccion, y "atras" lo contrario. Entonces ya
	podemos concluir que ese movimiento sera una convinacion entre X y Z y que dependera del
	angulo (Y°), del que depende el angulo de rotacion de la camara sobre si misma. El
	razonamiento es el siguiente.

				SI angulo Y° = 0° (eje +X) ---> posicion sera (X, 0)				si tomamos X+ como 0°
				SI angulo Y° = 90° (eje +Z) ---> posicion sera (0, Z)
				SI angulo Y° = 180° (eje -X) ---> posicion sera (-X, 0)
				SI angulo Y° = 270° (eje -Z) ---> posicion sera (0, -Z)

	El resto de los angulo dara como resultado una convinacion entre X e Z, pero con valores de 
	X y Z, que aumentaran y disminuiran de forma opuesta, es decir, que si X aumenta, Z disminuira.
	Es el mismo razonamiento que la rotacion de la camara, para formar un circulo. Entonces podemos
	mediante el angulo, dar valores a X y Z de la forma que necesitamos:
					
				Cos(90) = 0		y	Sen(90) = 1
				Cos(180) = -1	y	Sen(180) = 0
				Cos(270) = 0	y	Sen(270) = -1
				Cos(0) = 1		y	Sen(0) = 0 
				
				nosotros necesitamos que en 0 grados "Z" sea cero -->
						
						X = Cos(Y°) * Variacion			("variacion", la cantidad que nos movemos cada vez)
						Z = Sin(Y°) * Variacion

	entonces para trasladarnos por el plano X, Z usaremos el calculo de arriba. De ahora en mas adelante
	siempre sera adelante de la camara.
	Ahora mediante este simple razonamiento tambien podemos solucionar el movimiento lateral, osea cuando
	nos movemos a la izquierda o derecha, pero manteniendo la camara hacia el frente, osea a 90° del
	movimiento. En este caso nosotros no rotamos la camara, mantiene el mismo angulo, pero lo que hacemos
	si queresmos movernos para la izquierda es restar 90° y a la derecha sumar 90° al angulo de Y° y
	entonces nos moveremos de forma lateral:
						
					Izquierda
						X = Cos(Y° - 90) * Variacion			
						Z = Sin(Y° - 90) * Variacion

					Derecha
						X = Cos(Y° + 90) * Variacion
						Z = Sin(Y° + 90) * Variacion

	MOVIMIENTO EN 3 DIMENSIONES (3D)
	--------------------------------
	El movimiento en 3 dimensiones es algo tal vez un poco mas dificil de explicar, pero los calculos para
	poder llevarlos a cabo terminan siendo mucho mas simples de lo que cuesta entender.
	Intentemos razonar lo siguiente: Tomando en cuenta lo anterior dicho, en 2 dimensiones calcular un
	punto o coordenada al redordor de un centro, osea hacer un circulo al rededor de la posicion actual
	se consigue con el Seno y Coseno. Con eso calculamos cualquier punto de un circulo de radio 1, y si
	necesimos calcular un punto con un radio mas que 1, solo multiplicamos el valor de X y Z por la cantidad
	que nos queremos desplazar, como en los ejemplos de arriba. Ahora bien una vez que tenemos el punto en
	2 dimnesiones, como calculamos la altura?? el eje Y?? Si nos ponemos a pensar, calcular la posicion
	al rededor de un punto, es formar una esfera al rededor. Osea que la altura en Y no sera cualquiera,
	esta comprendida en el radio de la esfera, lo mismo que X y Z. Entonces teniendo en cuenta el proceso
	de como calculamos X y Z, que mientras uno aumenta el otro decrece, el mismo razonamiento se aplica
	para el eje Y, solo que teniendo en cuenta los otros 2 ejes. Meintras Y crezca, tanto X como Z iran
	decreciendo. Ahroa hay que tener en cuenta y no olvidarse, que X y Z dependen del angulo de Y, osea
	del angulo que forma el plano X, Z con el eje Y. Entonces de que depende Y? bueno del angulo que 
	forme el eje X con el plano Y, Z o el angulo que forme el eje Z con el plano X, Y. Tomaremos el 
	angulo de X°. Lo siguiente es enteder que si el angulo de X° es 0 o 180, Y valdra cero, entonces
					
					X° = 0	 --> Y = 0
					X° = 90  --> Y = 1
					X° = 180 --> Y = 0
					X° = 270 --> Y = -1

	de manera que mientras el angulo X° sea 90 o 270, mas crecera Y, y menos X y Z. Y lo contrarios si el
	angulo X° es 0 o 180 entonces:
					
					sin(0) = 0
					sin(90) = 1
					sin(180) = 0
					sin(270) = -1

	entonces Y sera sin(X°) y X y Z dependeran del valor de Y de la siguiente forma:

							X = Cos(Y°) * Variacion * Cos(X°)				Coseno, opuesto de Seno
							Z = Sin(Y°) * Variacion * Cos(X°)				mientras Y avanza X, Z
							Y = Sin(X°) * Variacion							disminuyen, y al revez.

	con esto, ya podemos calcular cualquier posicion de la esfera al rededor de un punto, con solo indicar
	el angulo de X° e Y°. Solo hay que recordar que el angulo de X° es el que forma el plano de Y, Z con X
	y el angulo de Y° es el angulo que forma el plano X, Z con Y.

	En este programa de OpenGL de ejemplo, use una clase donde tengo una variable de tipo "struct" donde 
	almaceno el angulo de X° Y° y Z°. EL angulo de Z° no lo uso, mientras que el angulo de X° e Y° los voy
	aumentando con las teclas. 'w' y 's' aumentan y disminuyen el angulo de X° y las teclas 'a' y 'd' el
	angulo de Y°. Con esto giro la camara en su propio eje, y luego con las flechas adelante y atras se
	traslada por el mapa, usando los angulos del giro de la camara para calcular donde moverse.



*/
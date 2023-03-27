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
	mira en un direccion, que adelante sea esa direccion, y atras lo contrario. Entonces ya
	podemos concluir que ese movimiento sera una convinacion entre X y Z y que dependera del
	angulo (Y°). El razonamiento es el siguiente.

				SI angulo Y° = 0° (eje +X) ---> posicion sera (X, 0) 
				SI angulo Y° = 90° (eje +Z) ---> posicion sera (0, Z)
				SI angulo Y° = 180° (eje -X) ---> posicion sera (-X, 0)
				SI angulo Y° = 270° (eje -Z) ---> posicion sera (0, -Z)

	El resto de los angulo dara como resultado una convinacion entre X e Z, pero con valores de 
	X e Z, que aumentaran y disminuiran de forma opuesta, es decir, que si X aumenta, Z disminuira.
	Es el mismo razonamiento que la rotacion de la camara, para formar un circulo. Entonces podemos
	mediante el angulo, dar valores a X y Z de la forma que necesitamos:
					
				Cos(90) = 0 y Sen(90) = 1
				Cos(180) = -1 y Sen(180) = 0
				Cos(270) = 0 y Sen(0270) = -1
				Cos(0) = 1 y Sen(0) = 0 
				
				nosotros necesitamos que en 0 grados "Z" sea cero -->
						
						X = Cos(Y°) * Variacion			(variacion, la cantidad que nos movemos cada vez)
						Z = Sin(Y°) * Variacion

	entonces para trasladarnos por el plano X, Z usaremos el calculo de arriba. De ahora en mas adelante
	siempre sera adelante de la camara.
	Ahora mediante un simple razonamiento tambien podemos solucionar el movimiento lateral, osea cuando
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













*/
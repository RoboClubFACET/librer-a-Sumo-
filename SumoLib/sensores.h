#ifndef SENSORES_H
#define SENSORES_H

///Clase para el sensor HC-SR04
/**
* La clase que define el funcionamiento del sensor ultrasonido HC-SR04. Permite
* configurar los dos pins del sensor y retornar la distancia medida.
*/
class Ultrasonido {
	public:

    /// Contructor
    /**
    * @param trig es el pin adonde esta conectado el tigger del HC-SR04.
    * @param echo es el pin adonde esta conectado el echo del HC-SR04.
    */
		Ultrasonido(int trig, int echo);

    /// Retornar la distancia medida por el HC-SR04 en cm.
    /**
    * @return La distancia en cm.
    */
		long retornarDistancia();

	private:
		int trig_;       /**< El pin adonde esta conectado el trigger. */
    int echo_;       /**< El pin adonde esta conectado el echo. */
		long duration_;  /**< El tiempo de vuelo de la señal ultrasonica. */
    long distance_;  /**< La distancia al primer objecto detectado en cm. */
};

///Clase para el sensor TCRT5000
/**
* La clase que define el funcionamiento del sensor infrarrojo TCRT5000. Permite
* configurar los dos pins del sensor y el modo de funcionamiento
* (analogico/digtal).
*/
class Infrarrojo {
	public:

    /// Contructor
    /**
    * @param trig es el pin adonde esta conectado el tigger del HC-SR04.
    * @param echo es el pin adonde esta conectado el echo del HC-SR04.
    */
		Infrarrojo(int pin, int modo);

    /// Retornar la intensidad de reflejo del TCRT5000.
    /**
    * @return En modo digital retorna un 0 o 1 dependiendo de la intensidad de
    * reflejo. En modo analogico retorna la intensidad de reflejo en 0 y 1024.
    */
		//int (*lectura)();

	private:

    /// Retornar la intensidad de reflejo del TCRT5000 entre 0 y 1.
    /**
    * @return Si la intensidad de reflejo es lo suficiente, retorna 1.
    */
		int lecturaDigital();

    /// Retornar la intensidad de reflejo del TCRT5000 entre 0 y 1024.
    /**
    * @return La intensiada de reflejo en un valor entre 0 (sin reflejo) y 1024
    * (maximo relfejo).
    */
		int lecturaAnagolica();

    int pin_;
		int lecturaSensor_; /**< Intensidad de reflejo medida por el sensor. */
};

#endif

#ifndef MOTOR_H
#define MOTOR_H
//Motor con pwm

///Clase para motor DC generico
/**
* La clase que define el funcionamiento de un motor DC generico de 6-12v.
* Permite configurar los dos pins de direccionamiento y la velocidad.
*/
class Motor {
	public:

    /// Contructor
    /**
    * @param pin_positivo es el pin positivo para direccionamiento.
    * @param pin_negativo es el pin negativo para direccionamiento.
    * @param pin_pwm es el pin del PWM para controlar la velocidad del motor.
    * Valores validos son entre 0 y 255.
    */
		Motor(int pin_positivo, int pin_negativo, int pin_pwm);

    /// Girar el motor en modo avanzar.
    /**
    * @param La velocidad del motor. Valores validos son entre 0 y 255.
    */
    void avanzar(int pwm);

    /// Girar el motor en modo retroceder.
    /**
    * @param La velocidad del motor. Valores validos son entre 0 y 255.
    */
    void retroceder(int pwm);

    /// Dejar el motor en punto muerto.
    void puntoMuerto(int pwm);

    /// Detener el motor bruscamente.
    void detener();

	private:
		int pin_positivo_; /*< El pin positivo de direccionamiento. */
        int pin_negativo_; /*< El pin negativo de direccionamiento. */
        int pin_pwm_;      /*< El pin del PWM. */
};

#endif

#include "Arduino.h"
#include "motor.h"

Motor::Motor(int pin_positivo, int pin_negativo, int pin_pwm)
{
  // Los pines de direccionamiento son salidas
	pinMode(pin_positivo, OUTPUT);
	pinMode(pin_negativo, OUTPUT);

  // Guardar la informacion de pins para futuro uso.
	pin_positivo_ = pin_positivo;
	pin_negativo_ = pin_negativo;
	pin_pwm_ = pin_pwm;

  // Asegurar que el motor empieze detenido.
	digitalWrite(pin_positivo_, LOW);
	digitalWrite(pin_negativo_, LOW);
	analogWrite(pin_pwm_, 0);
}

void Motor::avanzar(int pwm)
{

  //
	digitalWrite(pin_positivo_, HIGH);
	digitalWrite(pin_negativo_, LOW);

  // Seleccionar la velocidad.
	analogWrite(pin_pwm_, pwm);
}

void Motor::retroceder(int pwm)
{

  // Direccionar el motor para avanzar.
	digitalWrite(pin_positivo_, LOW);
	digitalWrite(pin_negativo_, HIGH);

  // Seleccionar la velocidad.
	analogWrite(pin_pwm_, pwm);
}

void Motor::puntoMuerto(int pwm)
{

}

void Motor::detener()
{
  // Direccionar el motor para detener bruscamente.
	digitalWrite(pin_positivo_, LOW);
	digitalWrite(pin_negativo_, LOW);

  // Seleccionar la velocidad.
	analogWrite(pin_pwm_, 0);
}

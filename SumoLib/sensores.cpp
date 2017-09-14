#include "Arduino.h"
#include "sensores.h"

/*
* HC-SR04
*/
Ultrasonido::Ultrasonido(int trig, int echo)
{
  // El trigger es salida.
  pinMode(trig, OUTPUT);

  // El echo es entrada.
	pinMode(echo, INPUT);

  // Guardar valores para futuro uso.
  trig_ = trig;
	echo_ = echo;
}

long Ultrasonido::retornarDistancia()
{
  // Activar el trigger.
  digitalWrite(trig_, LOW);
	delayMicroseconds(2);
  digitalWrite(trig_, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig_, LOW);

  // Leer tiempo de vuelo y convertirlo a centimetros
	duration_ = pulseIn(echo_, HIGH);
	distance_ = duration_ * 0.034 / 2;	//Centimetros
	return (distance_);
}

/*
* TCRT5000
*/
Infrarrojo::Infrarrojo(int pin, int modo)
{
  // El pin del sensor es una entrada.
  pinMode(pin, INPUT);
  /*
	if(modo){
    // Modo 1
		lectura = &Tcrt5000::lecturaDigital;
	}else{
    // Modo 0
		lectura = &Tcrt5000::lecturaAnagolica;
	}
  */

  // Guardar valor para futuro uso.
  pin_ = pin;
}

int Infrarrojo::lecturaDigital()
{
  return digitalRead(pin_);
}

int Infrarrojo::lecturaAnagolica()
{
  return analogRead(pin_);
}

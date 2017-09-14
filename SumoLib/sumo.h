#ifndef SUMO_h
#define SUMO_h

#include "sensores.h"
#include "motor.h"

typedef struct {
	int pinMotorIzqPos;
	int pinMotorIzqNeg;
	int pinPwmIzq;
	int pinMotorDerPos;
	int pinMotorDerNeg;
	int pinPwmDer;
	int pinIr1;
	int pinIr2;
	int pinUltraTrig1;
	int pinUltraEcho1;
	int pinUltraTrig2;
	int pinUltraEcho2;
	int pinBtnActivar;
	int pinBtnModo;
} SumoConfig;

///Clase para el robot sumo.
/**
* La clase que define el funcionamiento del robot sumo. El robot contiene dos
* sensores infrarojo, dos sensores ultrasonido y dos motores independientes
* (robot mobil con motores diferencial).
*/
class Sumo {
public:

	/// Contructor
	/**
	* @param config es una estructura que define todos los pins de entrada/salida
	* para los sensores y motores.
	*/
	Sumo(SumoConfig config);

	/// Retornar la distancia medida por el HC-SR04 en cm.
	/**
	* @return La distancia en cm.
	*/
	void avanzar(int pwm);
	void retroceder(int pwm);
	void girarSobreEje(int pwm, int direccion);
	void doblar(int pwm, int direccion);
	void detener();
	bool leerInfrarrojo(int sensorIr);
	long leerUltrasonido(int sensorUltra);

private:
	int pinBtnActivar;
	int pinBtnModo;
	Motor izq;
	Motor der;
	Infrarrojo ir1;
	Infrarrojo ir2;
	Ultrasonido ultra1;
	Ultrasonido ultra2;

};

#endif

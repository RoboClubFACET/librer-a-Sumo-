#ifndef SumoLib_h
#define SumoLib_h
#include "Arduino.h"

//led
class Led
{
	public:
		Led(int pin);
		
		void Blink();
		
		void Blink(int miliSegundos);
		
		void Encender();
		
		void Apagar();
	private:
		int _pin;
		char _tipoLectura;
};

//Sensor Ultra ultrasonido HC-SR04
class SensorHC
{
	public: 
		SensorHC(int trig, int echo);

		long RetornarDistancia();

	private:
		int _trig, _echo;
		long _duration, _distance;

};

//Sensor infrarrojo TCRT5000
class SensorTCRT{
	public:
		SensorTCRT(int pin, char tipoLectura);
		
		int SobreNegro();
	
	private:
		int _lecturaSensor;
};

//Motor con pwm

class Motor{
	public:
		Motor(int pin_positivo, int pin_negativo, int pin_pwm);
		
		void Apagar();
		
		void Encender();
		
		void Encender(int pwm);
		
	private:
		int _pin_positivo, _pin_negativo, _pin_pwm;
};


#endif

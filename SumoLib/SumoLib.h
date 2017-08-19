#ifndef SumoLib_h
#define SumoLib_h
#include "Arduino.h"

//led
class Led
{
	public:
		Led(int pin);
		
		void blink();
		
		void blink(int miliSegundos);
		
		void encender();
		
		void apagar();
	private:
		int _pin;
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
		SensorTCRT(int pin, int modo);

		int (*lectura)();
	
	private:
		int lecturaDigital();
		int lecturaAnagolica();
		int _lecturaSensor;
};

//Motor con pwm

class Motor{
	public:
		Motor(int pin_positivo, int pin_negativo);
		
		void detener();
		
		void retroceder(int pwm);
		
		void avanzar(int pwm);

		void frenar(int pwm);
		
	private:
		int _pin_positivo, _pin_negativo, _pin_pwm;
};

typedef struct{
	int motorIzqPos;
	int motorIzqNeg;
	int motorDerPos;
	int motorDerNeg;
	int pinIr1;
	int pinIr2;
	int pinUltraTrig1;
	int pinUltraEcho1;
	int pinUltraTrig2;
	int pinUltraEcho2;
	int pinBtnActivar;
	int pinBtnModo;
}SumoConfig;

class Sumo{
public:
	Sumo(SumoConfig _config);
	void avanzar(int pwm);
	void retroceder(int pwm);
	void girarSobreEje(int pwm);
	void doblar(int pwm);
	void detener();
	void frenar(int pwm);
	bool leerInfrarrojo(int sensorIr);
	long int leerUltrasonido(int sensorUltra);

private:
	int pinBtnActivar;
	int pinBtnModo;
	Motor izq;
	Motor der;
	SensorTCRT ir1;
	SensorTCRT ir2;
	SensorHC ultra1;
	SensorHC ultra2;

};


#endif

//uhhh que loco nuevas cosas
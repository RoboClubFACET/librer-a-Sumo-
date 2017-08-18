#include "Arduino.h"
#include "SumoLib.h"

//Led
Led::Led(int pin)
{
	pinMode(pin, OUTPUT);
	_pin = pin;
}
//Led Parpadeo --CONTIENE UN DELAY
void Led::Blink(){
	digitalWrite(_pin,HIGH);
	delay(500);
	digitalWrite(_pin,LOW);
	delay(500);
}
//Led Parpadeo sobrecarga(miliSegundos) --CONTIENE UN DELAY
void Led::Blink(int miliSegundos)
{
	digitalWrite(_pin,HIGH);
	delay(miliSegundos);
	digitalWrite(_pin,LOW);
	delay(miliSegundos);
}
//Led Encender
void Led::Encender()
{
	digitalWrite(_pin,HIGH);
}
//Led Apagar
void Led::Apagar()
{
	digitalWrite(_pin,LOW);
}

//Sensor Ultra ultrasonido HC-SR04
SensorHC::SensorHC(int trig, int echo)
{
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
	_trig = trig;
	_echo = echo;
}
//Ultra Sonido RetornarDistancia
long SensorHC::RetornarDistancia()
{
	digitalWrite(_trig, LOW); 
	delayMicroseconds(2);
  	digitalWrite(_trig, HIGH); 
	delayMicroseconds(10);
	digitalWrite(_trig, LOW);
	_duration = pulseIn(_echo, HIGH); 
	_distance= _duration*0.034/2;	//Centimetros
	return (_distance);
}

//Sensor infrarrojo TCRT5000
SensorTCRT::SensorTCRT(int pin, char tipoLectura)
{	
	pinMode(pin, INPUT);
	if(tipoLectura == 'A'){
		_lecturaSensor = analogRead(pin);
	}else if(tipoLectura == 'D'){
		_lecturaSensor = digitalRead(pin);
	}
}
//Sensor Infrarrojo SobreNegro (Retorna 1 si esta sobre negro, de lo contrario 0)
int SobreNegro(){
	/*if(_lecturaSensor > 750){
		return 1;
	}else{
		return 0;
	}*/
}
//Motor con pwm
Motor::Motor(int pin_positivo, int pin_negativo, int pin_pwm){
	pinMode(pin_positivo, OUTPUT);
	pinMode(pin_negativo, OUTPUT);
	_pin_positivo = pin_positivo;
	_pin_negativo = pin_negativo;
	_pin_pwm = pin_pwm;
	digitalWrite(_pin_positivo, LOW);
	digitalWrite(_pin_negativo, LOW);
	analogWrite(_pin_pwm, 0);
}
//Motor Apagar
void Motor::Apagar(){
	digitalWrite(_pin_positivo, LOW);
	digitalWrite(_pin_negativo, LOW);
	analogWrite(_pin_pwm, 0);
}
//Motor Encender
void Motor::Encender(){
	digitalWrite(_pin_positivo, HIGH);
	digitalWrite(_pin_negativo, LOW);
	analogWrite(_pin_pwm, 150);
}
//Motor Encender Sobrecarga(pwm)
void Motor::Encender(int pwm){
	digitalWrite(_pin_positivo, HIGH);
	digitalWrite(_pin_negativo, LOW);
	analogWrite(_pin_pwm, pwm);
}

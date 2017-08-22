#include "Arduino.h"
#include "SumoLib.h"

//Led
Led::Led(int pin)
{
	pinMode(pin, OUTPUT);
	_pin = pin;
}

void Led::blink(){
	digitalWrite(_pin,HIGH);
	delay(500);
	digitalWrite(_pin,LOW);
	delay(500);
}

void Led::blink(int miliSegundos)
{
	digitalWrite(_pin,HIGH);
	delay(miliSegundos);
	digitalWrite(_pin,LOW);
	delay(miliSegundos);
}

void Led::encender()
{
	digitalWrite(_pin,HIGH);
}

void Led::apagar()
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
SensorTCRT::SensorTCRT(int pin, int modo)
{
	pinMode(pin, INPUT);
	if(modo){
		lectura = &lecturaDigital;
	}else{
		lectura = &lecturaAnagolica;
	}
}
int lecturaDigital()
{

}
int lecturaAnagolica(){

}

//Motor con pwm
Motor::Motor(int pin_positivo, int pin_negativo, int pin_pwm)
{
	pinMode(pin_positivo, OUTPUT);
	pinMode(pin_negativo, OUTPUT);
	_pin_positivo = pin_positivo;
	_pin_negativo = pin_negativo;
	_pin_pwm = pin_pwm;
	digitalWrite(_pin_positivo, LOW);
	digitalWrite(_pin_negativo, LOW);
	analogWrite(_pin_pwm, 0);
}

void Motor::detener()
{
	digitalWrite(_pin_positivo, LOW);
	digitalWrite(_pin_negativo, LOW);
	analogWrite(_pin_pwm, 0);
}

void Motor::retroceder(int pwm)
{
	digitalWrite(_pin_positivo, LOW);
	digitalWrite(_pin_negativo, HIGH);
	analogWrite(_pin_pwm, pwm);
}

void Motor::avanzar(int pwm)
{
	digitalWrite(_pin_positivo, HIGH);
	digitalWrite(_pin_negativo, LOW);
	analogWrite(_pin_pwm, pwm);
}

void Motor::frenar(int pwm)
{

}

void Sumo::Sumo(SumoConfig _config) : izq(_config.motorIzqPos, _config.motorIzqNeg, _config.pinPwmIzq),
                                      der(_config.motorDerPos, _config.motorDerNeg, _config.pinPwmDer),
                                      ir1(_config.pinIr1, 0),
                                      ir2(_config.pinIr2, 0),
                                      ultra1(_config.pinUltraTrig1, _config.pinUltraEcho1),
                                      ultra2(_config.pinUltraTrig2, _config.pinUltraEcho2)
{
	this->pinBtnActivar = _config.pinBtnActivar;
	this->pinBtnModo = _config.pinBtnModo;
}

void Sumo::avanzar(int pwm)
{
	izq.avanzar(pwm);
	der.avanzar(pwm);
}

void Sumo::retroceder(int pwm)
{
	izq.retroceder(pwm);
	der.retroceder(pwm);
}

void Sumo::girarSobreEje(int pwm)
{

}

void Sumo::doblar(int pwm)
{

}

void Sumo::detener()
{
	izq.detener();
	der.detener();
}

void Sumo::frenar(int pwm)
{
	izq.frenar(pwm);
	der.frenar(pwm);
}

bool Sumo::leerInfrarrojo(int sensorIr)
{

}

float Sumo::leerUltrasonido(int sensorUltra)
{

}

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

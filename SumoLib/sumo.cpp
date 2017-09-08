#include "Arduino.h"
#include "Sumo.h"

Sumo::Sumo(SumoConfig config) : izq(config.pinMotorIzqPos, config.pinMotorIzqNeg, config.pinPwmIzq),
                                      der(config.pinMotorDerPos, config.pinMotorDerNeg, config.pinPwmDer),
                                      ir1(config.pinIr1, 0),
                                      ir2(config.pinIr2, 0),
                                      ultra1(config.pinUltraTrig1, config.pinUltraEcho1),
                                      ultra2(config.pinUltraTrig2, config.pinUltraEcho2)
{
	this->pinBtnActivar = config.pinBtnActivar;
	this->pinBtnModo = config.pinBtnModo;
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

bool Sumo::leerInfrarrojo(int sensorIr)
{

}

float Sumo::leerUltrasonido(int sensorUltra)
{

}

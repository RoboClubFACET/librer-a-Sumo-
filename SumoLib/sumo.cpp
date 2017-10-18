#include "Arduino.h"
#include "Sumo.h"

Sumo::Sumo()
{
	pinBtnActivar = 0;
	pinBtnModo = 0;
}

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

void Sumo::init(SumoConfig config)
{
	izq.init(config.pinMotorIzqPos, config.pinMotorIzqNeg, config.pinPwmIzq);
	der.init(config.pinMotorDerPos, config.pinMotorDerNeg, config.pinPwmDer);
	ultra1.init(config.pinUltraTrig1, config.pinUltraEcho1);
	ultra2.init(config.pinUltraTrig2, config.pinUltraEcho2);
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

void Sumo::girarSobreEje(int pwm, int direccion)
{	
	if(direccion){
		// gira hacia la izquierda
		izq.retroceder(pwm);
		der.avanzar(pwm);
	}else{
		// gira hacia la derecha
		izq.avanzar(pwm);
		der.retroceder(pwm);
	}
}

void Sumo::doblar(int pwm, int direccion)
{
	if(direccion){
		// dobla hacia la izquierda
		izq.avanzar(pwm-50);
		der.avanzar(pwm);
	}else{
		// dobla hacia la derecha
		izq.avanzar(pwm);
		der.avanzar(pwm-50);
	}
}

void Sumo::detener()
{
	izq.detener();
	der.detener();
}

bool Sumo::leerInfrarrojo(int sensorIr)
{

}

long Sumo::leerUltrasonido(int sensorUltra)
{
	if(sensorUltra == 1){
		// retorna lectura de ultra1
		return ultra1.retornarDistancia();
	}else if(sensorUltra == 2){
		// retorna lectura de ultra2
		return ultra2.retornarDistancia();
	}
}

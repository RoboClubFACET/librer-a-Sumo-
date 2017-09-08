#include "Arduino.h"
#include "led.h"


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

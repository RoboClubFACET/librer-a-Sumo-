#ifndef LED_h
#define LED_h


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


#endif
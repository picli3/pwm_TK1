/* sprintf example */
#include <stdio.h>
#include <stdlib.h> //Librería necesaria para la función system().
#include <unistd.h>

class pwm
{
public:
	pwm();
	~pwm();
	void begin();
	void start(int );
	void stop();
	void restart();
private:
	char _buffer[50];
	int _iterator;
};
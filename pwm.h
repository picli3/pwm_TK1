/* sprintf example */
#include <stdio.h>
#include <stdlib.h> //Librería necesaria para la función system().
#include <unistd.h>

class pwm
{
public:
	pwm();
	~pwm();
	void begin(char );
	void start(char,int );
	void stop();
	void restart();
private:
	char _buffer[10];
	int _iterator;
};
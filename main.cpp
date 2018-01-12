
#include "pwm.h"

int main(int argc, char const *argv[])
{

	int value;
	char * pEnd;
	value = strtol(argv[1],&pEnd,10);
	pwm iluminacion;

	iluminacion.begin((char)argv[2]);
	iluminacion.start(value);
	


	return 0;
}

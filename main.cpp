
#include "pwm.h"

int main(int argc, char const *argv[])
{

	int value;
	char * pEnd;
	value = strtol(argv[1],&pEnd,10);
	pwm iluminacion;
	iluminacion.begin();
	iluminacion.start(value);
	return 0;
}

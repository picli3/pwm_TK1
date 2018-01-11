
#include "pwm.h"

int main(int argc, char const *argv[])
{

	/*int value;
	char * pEnd;
	value = strtol(argv[1],&pEnd,10);
	pwm iluminacion;
	iluminacion.begin();
	iluminacion.start(value);*/
	
FILE *f1;

/* Apertura del fichero original, para lectura en binario*/
f1 = fopen ("/sys/class/pwm/pwmchip0/unexport", "r");
if (f1==NULL)
{
   perror("No se puede abrir fichero.dat");
   return -1;
}


	return 0;
}

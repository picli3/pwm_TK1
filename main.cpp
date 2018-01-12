
#include "pwm.h"



int main(int argc, char **argv)
{


	
	int value;
	char * pEnd;
	value = strtol(argv[1],&pEnd,10);
	pwm iluminacion;
	printf("%d\n",value);
	//printf("%c\n",argv[2][0] );

	iluminacion.begin(argv[2][0]);
	iluminacion.start(value);
	


	return 0;
}

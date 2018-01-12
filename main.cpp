#include "pwm.h"

int main(int argc, char **argv)
{
	int value;
	char * pEnd;
	value = strtol(argv[1],&pEnd,10);
	
	printf("%d\n",value);
	printf("%d %c\n",value,argv[2][0] );
	pwm iluminacion;
	iluminacion.begin(argv[2][0]);
	
	iluminacion.start(argv[2][0],value);
	
	if (argv[3][0]=='p')
	{
		iluminacion.stop(argv[2][0]);
	}

	return 0;
}

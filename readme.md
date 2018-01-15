# Control de PWM con Apalis TK1

## Descripcion
una pequeña clase que controla el PWM de procesador apalis TK1 con las posibilidades de control habilitacion y desabilitacion de cada uno de sus PWM's.

La clase funciona de forma muy sensilla e intiutiva, debe ejecutarse como **root** para que pueda funcionar.

## Uso

~~~ 
#include "pwm.h"

int main(int argc, char **argv)
{
	int value;
	char * pEnd;
	value = strtol(argv[1],&pEnd,10);
	
	pwm iluminacion;
	iluminacion.begin(argv[2][0]);
	
	iluminacion.start(argv[2][0],value);
	
	if (argv[3][0]=='p')
	{
		iluminacion.stop(argv[2][0]);
	}

	return 0;
}
~~~

## ejecucion

### Inicia el pwm 1 con Ducty_cicle de 10%
~~~
./pwm 1 1
~~~
### Detiene el pwm 1
~~~
./pwm 1 1 p
~~~

### Autor:
[Maykol Rey](https://twitter.com/reymaykol)
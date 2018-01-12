#include "pwm.h"

pwm::pwm(){
	_buffer[10]=0;
	_iterator=0;
}
pwm::~pwm(){}

//Inicializa el PWM con 1s de periodo
void pwm::begin(char index){

	_buffer[10]=0;
  	sprintf(_buffer,"echo %c > /sys/class/pwm/pwmchip0/unexport \n",index);
	system(_buffer);
	sleep(1);
	sprintf(_buffer,"echo %c > /sys/class/pwm/pwmchip0/export \n",index);
	system(_buffer);

	sprintf(_buffer,"echo 1000000 > /sys/class/pwm/pwmchip0/pwm%c/period \n",index);
	system(_buffer);

	sprintf(_buffer,"echo 0 > /sys/class/pwm/pwmchip0/pwm%c/duty_cycle \n",index);
	system(_buffer);

	sprintf(_buffer,"echo 1 > /sys/class/pwm/pwmchip0/pwm%c/enable \n",index);
	system(_buffer);
}

//dicar a que led se le cambiara el ciclo de trabajo
void pwm::start(char index,int i){
	    i=100000*i;
  		sprintf(_buffer,"echo %d > /sys/class/pwm/pwmchip0/pwm%c/duty_cycle \n",i,index);
		system(_buffer);
}
// Apaga el led al cual se le indique
void pwm::stop(char index){

	sprintf(_buffer,"echo 0 > /sys/class/pwm/pwmchip0/pwm%c/enable \n",index);
	system(_buffer);
}

//estaura los valores de fabrica
void pwm::restart(){
	system("echo 1 > /sys/class/pwm/pwmchip0/unexport \n");
}
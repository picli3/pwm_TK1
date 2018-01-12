#include "pwm.h"

pwm::pwm(){
	_buffer[4]=0;
	_iterator=0;
}
pwm::~pwm(){}

void pwm::begin(char index){

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

void pwm::start(char index,int i){
	    i+=100000;

  		sprintf(_buffer,"echo %d > /sys/class/pwm/pwmchip0/pwm%c/duty_cycle \n",i,index);
		system(_buffer);
}

void pwm::stop(){
	system("echo 0 > /sys/class/pwm/pwmchip0/pwm1/enable \n");
}

void pwm::restart(){
	system("echo 1 > /sys/class/pwm/pwmchip0/unexport \n");
}
#include "pwm.h"

pwm::pwm(){
	_buffer[50]=0;
	_iterator=0;
}
pwm::~pwm(){}

void pwm::begin(){

	system("echo 1 > /sys/class/pwm/pwmchip0/unexport \n");
 	system("echo 1 > /sys/class/pwm/pwmchip0/export \n");
	system("echo 1000000 > /sys/class/pwm/pwmchip0/pwm1/period \n");
	system("echo 0 > /sys/class/pwm/pwmchip0/pwm1/duty_cycle \n");
	system("echo 1 > /sys/class/pwm/pwmchip0/pwm1/enable \n");

}

void pwm::start(int i){
	    i+=100000;
  		sprintf(_buffer,"echo %d > /sys/class/pwm/pwmchip0/pwm1/duty_cycle \n",i);
		system(_buffer);
}

void pwm::stop(){
	system("echo 0 > /sys/class/pwm/pwmchip0/pwm1/enable \n");
}

void pwm::restart(){
	system("echo 1 > /sys/class/pwm/pwmchip0/unexport \n");
}
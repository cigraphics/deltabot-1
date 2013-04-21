#include <wiringPi.h>
#include <stdio.h>
#include <cstdlib>

#define SERVO_1_PIN 1
#define SERVO_2_PIN 2
#define SERVO_3_PIN 7

#define MASA_LUCRU 22

#define SERVO_1_MIN_DEG 235
#define SERVO_2_MIN_DEG 229
#define SERVO_3_MIN_DEG 240

#define MASA_LUCRU 22

#define SERVO_1_MAX_DEG (SERVO_1_MIN_DEG - MASA_LUCRU) 
#define SERVO_2_MAX_DEG (SERVO_2_MIN_DEG - MASA_LUCRU)
#define SERVO_3_MAX_DEG (SERVO_3_MIN_DEG - MASA_LUCRU)

void servo_write(int servo_pin, int deg) { // 0 - 180 deg
  char exec[255] = {0};
	sprintf(exec, "echo %d=%d > /dev/servoblaster", servo_pin, deg);
	system(exec);
	
}

int main() {
	printf("starting \n");
	
	servo_write(SERVO_1_PIN, SERVO_1_MIN_DEG);
	servo_write(SERVO_2_PIN, SERVO_2_MIN_DEG);
	servo_write(SERVO_3_PIN, SERVO_3_MIN_DEG);
	
	delay(500);
	
	servo_write(SERVO_1_PIN, SERVO_1_MAX_DEG);
	servo_write(SERVO_2_PIN, SERVO_2_MAX_DEG);
	servo_write(SERVO_3_PIN, SERVO_3_MAX_DEG);
	
	delay(500);
	
	servo_write(SERVO_1_PIN, SERVO_1_MIN_DEG);
	servo_write(SERVO_2_PIN, SERVO_2_MIN_DEG);
	servo_write(SERVO_3_PIN, SERVO_3_MIN_DEG);
	
	servo_write(SERVO_1_PIN, 0);
	servo_write(SERVO_2_PIN, 0);
	servo_write(SERVO_3_PIN, 0);

}

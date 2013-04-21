#include <wiringPi.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <fstream>

#define SERVO_1_PIN 1
#define SERVO_2_PIN 2
#define SERVO_3_PIN 7

#define SERVO_1_MIN_DEG 235
#define SERVO_2_MIN_DEG 229
#define SERVO_3_MIN_DEG 240

#define MASA_LUCRU 60

#define SERVO_1_MAX_DEG (SERVO_1_MIN_DEG - MASA_LUCRU) 
#define SERVO_2_MAX_DEG (SERVO_2_MIN_DEG - MASA_LUCRU)
#define SERVO_3_MAX_DEG (SERVO_3_MIN_DEG - MASA_LUCRU)

int servo_max_deg[4];
int servo_min_deg[4];

int servo_deg[8];

using namespace std;

void servo_write(int servo_pin, int deg) { // 0 - 180 deg
  int new_deg = deg == 0 ? 0 : servo_min_deg[servo_pin] - deg;
	printf("Attempt: Servo %d > deg: %d \n", servo_pin, new_deg);
	if (new_deg >= servo_max_deg[servo_pin] && new_deg <= servo_min_deg[servo_pin]) {
		char exec[255] = {0};
		sprintf(exec, "echo %d=%d > /dev/servoblaster", servo_pin, new_deg);
		printf("echo %d=%d > /dev/servoblaster\n", servo_pin, new_deg);
		system(exec);
		servo_deg[servo_pin] = deg;
	}
}

void resetPos() {
	servo_write(SERVO_1_PIN, 1);
	servo_write(SERVO_2_PIN, 1);
	servo_write(SERVO_3_PIN, 1);
}

int main(int argc, char *argv[]) {
	servo_deg[1] = 0;
	servo_deg[2] = 0;
	servo_deg[7] = 0;
	
	servo_max_deg[1] = (SERVO_1_MIN_DEG - MASA_LUCRU);
	servo_max_deg[2] = (SERVO_2_MIN_DEG - MASA_LUCRU);
	servo_max_deg[7] = (SERVO_3_MIN_DEG - MASA_LUCRU);
	
	servo_min_deg[1] = SERVO_1_MIN_DEG;
	servo_min_deg[2] = SERVO_2_MIN_DEG;
	servo_min_deg[7] = SERVO_3_MIN_DEG;

	int deget1[3];
	int deget2[3];
	int deget3[3];
	int deget4[3];
	int deget5[3];
	
	deget1[0] = 42;
	deget1[1] = 9;
	deget1[2] = 42;
	
	deget2[0] = 13;
	deget2[1] = 5;
	deget2[2] = 28;
	
	deget3[0] = 18;
	deget3[1] = 22;
	deget3[2] = 29;
	
	deget4[0] = 20;
	deget4[1] = 34;
	deget4[2] = 32;
	
	deget5[0] = 34;
	deget5[1] = 34;
	deget5[2] = 17;
	int i = 0;
	int speed = 750;
	while ( i < 3 ) {
	
	servo_write(SERVO_1_PIN, deget1[0]);
	servo_write(SERVO_2_PIN, deget1[1]);
	servo_write(SERVO_3_PIN, deget1[2]);
	
	delay(speed);
	resetPos();
	speed -= 50;
	delay(speed);
	
	servo_write(SERVO_1_PIN, deget2[0]);
	servo_write(SERVO_2_PIN, deget2[1]);
	servo_write(SERVO_3_PIN, deget2[2]);
	
	delay(speed);
	resetPos();
	speed -= 50;
	delay(speed);
	
	servo_write(SERVO_1_PIN, deget3[0]);
	servo_write(SERVO_2_PIN, deget3[1]);
	servo_write(SERVO_3_PIN, deget3[2]);
	
	delay(speed);
	resetPos();
	speed -= 50;
	delay(speed);
	
	servo_write(SERVO_1_PIN, deget4[0]);
	servo_write(SERVO_2_PIN, deget4[1]);
	servo_write(SERVO_3_PIN, deget4[2]);
	
	delay(speed);
	resetPos();
	speed -= 50;
	delay(speed);
	
	servo_write(SERVO_1_PIN, deget5[0]);
	servo_write(SERVO_2_PIN, deget5[1]);
	servo_write(SERVO_3_PIN, deget5[2]);
	
	delay(speed);
	resetPos();
	speed -= 50;
	delay(1000);
	
	++i;
	}
}

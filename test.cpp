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

int a1[19];
int a2[19];
int a3[19];

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

int main(int argc, char *argv[]) {

	// test
	a1[0] = 21;
	a1[1] = 22;
	a1[2] = 23;
	a1[3] = 23;
	a1[4] = 25;
	a1[5] = 26;
	a1[6] = 27;
	a1[7] = 28;
	a1[8] = 29;
	a1[9] = 30;
	a1[10] = 31;
	a1[11] = 32;
	a1[12] = 33;
	a1[13] = 34;
	a1[14] = 35;
	a1[15] = 36;
	a1[16] = 37;
	a1[17] = 38;
	
	a2[0] = 0;
	a2[1] = 0;
	a2[2] = 0;
	a2[3] = 0;
	a2[4] = 0;
	a2[5] = 0;
	a2[6] = 0;
	a2[7] = 0;
	a2[8] = 1;
	a2[9] = 1;
	a2[10] = 1;
	a2[11] = 1;
	a2[12] = 1;
	a2[13] = 1;
	a2[14] = 1;
	a2[15] = 1;
	a2[16] = 2;
	a2[17] = 2;

		
	a3[0] = 28;
	a3[1] = 28;
	a3[2] = 28;
	a3[3] = 28;
	a3[4] = 27;
	a3[5] = 27;
	a3[6] = 27;
	a3[7] = 27;
	a3[8] = 26;
	a3[9] = 26;
	a3[10] = 26;
	a3[11] = 26;
	a3[12] = 25;
	a3[13] = 25;
	a3[14] = 25;
	a3[15] = 25;
	a3[16] = 24;
	a3[17] = 24;
	
	// test 

	servo_deg[1] = 0;
	servo_deg[2] = 0;
	servo_deg[7] = 0;
	
	servo_max_deg[1] = (SERVO_1_MIN_DEG - MASA_LUCRU);
	servo_max_deg[2] = (SERVO_2_MIN_DEG - MASA_LUCRU);
	servo_max_deg[7] = (SERVO_3_MIN_DEG - MASA_LUCRU);
	
	servo_min_deg[1] = SERVO_1_MIN_DEG;
	servo_min_deg[2] = SERVO_2_MIN_DEG;
	servo_min_deg[7] = SERVO_3_MIN_DEG;
	
	/*
	servo_write(SERVO_1_PIN, 28);
	servo_write(SERVO_2_PIN, 15);
	servo_write(SERVO_3_PIN, 21);
	delay(500);*/
	/*
	for (int i = 0; i <= 17; i++) {
		delay(500);
		if (i != 3) {
			a2[i]+= 15;
			printf("pas: %d > S1= %d > S2= %d > S3=%d \n", i, a3[i]-10, a2[i]-10, a1[i]-10);
			servo_write(SERVO_1_PIN, a3[i]-4);
			servo_write(SERVO_2_PIN, a2[i]-4);
			servo_write(SERVO_3_PIN, a1[i]-4);
		}
	}*/
	/*
	delay(500);
	servo_write(SERVO_1_PIN, 10);
	servo_write(SERVO_2_PIN, 10);
	servo_write(SERVO_3_PIN, 10);
	
	delay(500);
	servo_write(SERVO_1_PIN, 24);
	servo_write(SERVO_2_PIN, 17);
	servo_write(SERVO_3_PIN, 38);*/
	
	servo_write(SERVO_1_PIN, atoi(argv[1]));
	servo_write(SERVO_2_PIN, atoi(argv[2]));
	servo_write(SERVO_3_PIN, atoi(argv[3]));
	
}

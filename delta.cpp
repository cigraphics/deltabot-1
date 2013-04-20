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
	
	/*
	ofstream myfile;
	myfile.open ("servo_1_deg.txt");
	
	printf("New session: \n");
	myfile << "New session: \n";
	
	for (int i = 0; i <= 45; i++){
		servo_write(SERVO_1_PIN, i);
		myfile << "Servo_1 is at position: " << servo_deg[SERVO_1_PIN] << ".\n";
	}
	
	myfile.close();*/
	
	
	/*servo_write(SERVO_1_PIN, 22);
	servo_write(SERVO_3_PIN, 22);
	servo_write(SERVO_2_PIN, 22);
	*/
	
	/*
	while(1) {
		for (int i = 10; i <= 24; i++) {
			servo_write(SERVO_1_PIN, 24);
			servo_write(SERVO_1_PIN, 0);
			
			servo_write(SERVO_2_PIN, i);
			servo_write(SERVO_3_PIN, i);
		}
		
		delay(500);
		
		for (int i = 24; i >= 0; i--) {
			servo_write(SERVO_1_PIN, i);
			servo_write(SERVO_2_PIN, i);
			servo_write(SERVO_3_PIN, i);
		}
		
		delay(500);
	}*/
	
	
	// centru	
	/*
	servo_write(SERVO_1_PIN, 23);
	servo_write(SERVO_2_PIN, 23);
	servo_write(SERVO_3_PIN, 23);*/
	
	
	//delay(5000);
	
	// colt dreapta
	servo_write(SERVO_1_PIN, atoi(argv[1]));
	servo_write(SERVO_2_PIN, atoi(argv[2]));
	servo_write(SERVO_3_PIN, atoi(argv[3]));
	
}

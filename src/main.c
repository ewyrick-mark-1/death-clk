#include <stdio.h>
#include <lgpio.h>

//grab the current time from linux kernal
#include <time.h>

//for sleep
#include <unistd.h>

//defined in .env:
//DEATH_DAY


int main() {
	
	//check that .env vars are configured
	#ifndef DEATH_DAY
		fprintf(stderr, "DEATH_DAY variable not set");
		return 0;
	#endif

	

	for(int i = 0; i < 15; i++){
	
		time_t raw_time = time(NULL);
		
		time_t time_left = (long long int)DEATH_DAY - raw_time;	
		printf("You have %lld seconds left.\n", time_left);
		//sleep 1s
		sleep(1);
	}
	
	return 1;
}

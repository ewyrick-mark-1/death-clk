#include <stdio.h>
#include <lgpio.h>

//grab the current time from linux kernal
#include <time.h>
//for sleep
#include <unistd.h>
int main() {

	for(int i = 0; i < 15; i++){
	
		time_t raw_time = time(NULL);
	
		printf("the time is: %s", ctime(&raw_time));
		//sleep 1s
		sleep(1);
	}
	
return 1;
}

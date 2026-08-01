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

	struct tm *time_detailed; //struct to carry time info
	
	const char *weekdays[] = {
		"SUN",
		"MON",
		"TUE",
		"WED",
		"THU",
		"FRI",
		"SAT"
	};

	//"\033[H"  - ANSI code to put cursor top left
	//"\033[2J" - ANSI code to wipe terminal screen
	
       	printf("\033[2J");

	for(int i = 0; i < 65; i++){
		
		printf("\033[H");

		time_t raw_time = time(NULL);
		
		time_detailed = localtime(&raw_time);
		
		int hour = time_detailed->tm_hour;
		int min = time_detailed->tm_min;
		int month = time_detailed->tm_mon + 1;
		int mday = time_detailed->tm_mday;
		int year = (time_detailed->tm_year + 1900) % 100 ; 
		//^returns time since 1900, so I have to add 1900. Only want the last two digits so mod 100.
		
		//int sec = time_detailed->tm_sec;
		int wday = time_detailed->tm_wday; //weekday 0-6
		
		char *am_or_pm = (hour > 12) ? "PM" : "AM";

		time_t time_left = (long long int)DEATH_DAY - raw_time;
		printf("┌──────────────────┐\n");	
		printf("| %-6s%10lld |\n", weekdays[wday], time_left);
		printf("| %02d/%02d/%02d %02d:%02d%2s |\n", month, mday, year, hour%12, min, am_or_pm);
		printf("└──────────────────┘\n");
		//sleep 1s
		sleep(1);
	}
	
	return 1;
}

/* How Timer calls a callback function in C
I would like to implement a scheduler. 

The scheduler would be assigned multiple jobs and will configure the time interval when the job/callback function should called... 

I could say, Callback-function_1 should be called after 20 secs and callback-function_2 should be called after 30 secs like that.... 

we can assume, from the start time, after 20 secs the first callback-function would be called... 

How all these callback functions are put into a queue (the one which is going to be called soon has to be first...) and how they have been called ? How the timer invokes those callback-functions ? How do we pass an arguments to the callback-functions in this case...? */

#include "timer_callback.h"

void event_handler(unsigned int latency, unsigned int eventID)
{
	time_t start_time = time();
	size_t timer_cnt;
	
	while (time() - start_time < latency)
	{
		time_t diff = latency - (time() - start_time);
		printf("Time remaining: %u secs\n", diff);
	}
	
	timer_cnt = sizeof(timer_callbacks)/sizeof(void *);
	
	if(eventID < timer_cnt)
	{
		timer_callbacks[eventID];
	}
}

void timer_10_secs(unsigned int duration)
{
	printf("Ran first timer for %u seconds.\n", duration);
}

void timer_20_secs(unsigned int duration)
{
	printf("Ran second timer for %u seconds.\n", duration);
}

void timer_30_secs(unsigned int duration)
{
	printf("Ran third timer for %u seconds.\n", duration);
}

void (*timer_callbacks[3])() = {timer_10_secs, timer_20_secs, timer_30_secs};

void register_callbacks_to_eventID(unsigned int latency)
{
	switch(latency)
	{
		case 10:
			event_handler(10, 0);
			break;
			
		case 20:
			event_handler(20, 1);
			break;
			
		case 30:
			event_handler(30, 2);
			break;
			
		default:
			break;
	}
}

int main()
{
	register_callbacks_to_eventID(10);
	register_callbacks_to_eventID(20);
	register_callbacks_to_eventID(30);
	
	return SUCCESS;
}


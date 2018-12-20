/* How Timer calls a callback function in C
I would like to implement a scheduler. 

The scheduler would be assigned multiple jobs and will configure the time interval when the job/callback function should called... 

I could say, Callback-function_1 should be called after 20 secs and callback-function_2 should be called after 30 secs like that.... 

we can assume, from the start time, after 20 secs the first callback-function would be called... 

How all these callback functions are put into a queue (the one which is going to be called soon has to be first...) and how they have been called ? How the timer invokes those callback-functions ? How do we pass an arguments to the callback-functions in this case...? */

#ifndef __TIMER_CALLBACK__
#define __TIMER_CALLBACK__

#include <stdio.h>
#include <cstdlib>
#include <time.h>

#include "error_codes.h"

void event_handler(unsigned int);
void timer_10_secs();
void timer_20_secs();
void timer_30_secs();
void register_callbacks(unsigned int, void (**)());

#endif
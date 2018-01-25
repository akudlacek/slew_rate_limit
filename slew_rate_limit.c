/*
 * slew_rate_limit.c
 *
 *  Created on: Sep 30, 2016
 *      Author: akudlacek
 */


#include "slew_rate_limit.h"


/******************************************************************************
 * Limits slew rate of input based on time since last call, last value, up rate
 * and down rate
 * 
 * reset sets the current input to the last so ramping can jump to new input
 * 
 * output slew_rate_limit_f(input, dt, up_rate_lim, dn_rate_lim, reset)
 * 
 * https://www.mathworks.com/help/simulink/slref/ratelimiter.html
 ******************************************************************************/
float slew_rate_limit_f(float input, float dt, float up_rate_lim, float dn_rate_lim, char reset)
{
	static float last_output;
	float err;
	float rate;
	float output;

	if(reset == 1) last_output = input;

	err = input - last_output;

	rate = err / dt;

	//up rate limit
	if((rate > up_rate_lim) && (up_rate_lim != 0))
	{
		output = dt * up_rate_lim + last_output;
	}
	//down rate limit
	else if((rate < dn_rate_lim) && (dn_rate_lim != 0))
	{
		output = dt * dn_rate_lim + last_output;
	}
	//within limits
	else
	{
		output = input;
	}

	last_output = output;

	return output;
}

/******************************************************************************
 * Limits slew rate of input based on time since last call, last value, up rate
 * and down rate
 * 
 * reset sets the current input to the last so ramping can jump to new input
 * 
 * output slew_rate_limit(input, dt, up_rate_lim, dn_rate_lim, reset)
 * 
 * https://www.mathworks.com/help/simulink/slref/ratelimiter.html
 ******************************************************************************/
long slew_rate_limit_l(long input, long dt, long up_rate_lim, long dn_rate_lim, char reset)
{
	static long last_output;
	long err;
	long rate;
	long output;

	if(reset == 1) last_output = input;

	err = input - last_output;

	rate = err / dt;

	//up rate limit
	if((rate > up_rate_lim) && (up_rate_lim != 0))
	{
		output = dt * up_rate_lim + last_output;
	}
	//down rate limit
	else if((rate < dn_rate_lim) && (dn_rate_lim != 0))
	{
		output = dt * dn_rate_lim + last_output;
	}
	//within limits
	else
	{
		output = input;
	}

	last_output = output;

	return output;
}

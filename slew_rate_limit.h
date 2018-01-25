/*
 * slew_rate_limit.h
 *
 *  Created on: Sep 30, 2016
 *      Author: akudlacek
 */

#ifndef SLEW_RATE_LIMIT_H_
#define SLEW_RATE_LIMIT_H_

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

/******************************************************************************
 * Global Prototypes
 ******************************************************************************/
float slew_rate_limit_f(float input, float dt, float up_rate_lim, float dn_rate_lim, char reset);
long slew_rate_limit_l(long input, long dt, long up_rate_lim, long dn_rate_lim, char reset);

#endif /* SLEW_RATE_LIMIT_H_ */

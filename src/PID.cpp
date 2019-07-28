#include "PID.h"
#include <iostream>
#include <string>
#include <math.h>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
	/**
	* TODO: Initialize PID coefficients (and errors, if needed)
	*/
	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;
	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
	prev_cte = 0.0;
	 
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
	
	i_error = i_error + cte;
	d_error = cte - prev_cte;
	p_error = Kp * cte;
	prev_cte = cte;
	
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
	
	double total_error = -p_error - Kd * d_error - Ki * i_error;
  return total_error;
}
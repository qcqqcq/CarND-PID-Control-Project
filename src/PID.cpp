#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

  /*
  * Coefficients
  */ 
  Kp_ = Kp;
  Ki_ = Ki;
  Kd_ = Kd;

  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;

  prev_cte = 0.0;

  total_sq_cte = 0;
  total_n = 0;

}

void PID::UpdateError(double cte) {


  cout << p_error << endl;

  p_error = cte;

  i_error = i_error + cte;

  d_error = cte - prev_cte;
  prev_cte = cte;

  
  if(total_n > 200){
    total_sq_cte = total_sq_cte + cte*cte;
  }
  total_n ++;

  cout << "Number Steps: " << total_n << endl;
  cout << "MSE: " << total_sq_cte/(total_n-200) << endl;

}

double PID::TotalError() {
  double steer_value = -Kp_*p_error - Ki_*i_error - Kd_*d_error;

  //cout << p_error << endl;
  //cout << i_error << endl;
  //cout << d_error << endl;

  if(steer_value < -1){
    steer_value = -1;
  }else if(steer_value > 1){
    steer_value = 1;
  };

  return steer_value;
}



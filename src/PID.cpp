#include "PID.h"


PID::PID()
{
  this->p_error = 0.0;
  this->i_error = 0.0;
  this->d_error = 0.0;
  this->last_cte = 0.0;
  this->cost = 0.0;
}


PID::~PID(){}


void PID::Init(double Kp_, double Ki_, double Kd_)
{
  this->Kp = Kp_;
  this->Ki = Ki_;
  this->Kd = Kd_;
}

void PID::UpdateError(double cte) {
  this->p_error = cte; 
  this->i_error += cte;
  this->d_error = cte - last_cte;
  this->last_cte = cte;
  this->cost += cte;
}

double PID::TotalError() {
  return this->Kp*this->p_error + this->Ki*this->i_error + this->Kd*this->d_error;
}

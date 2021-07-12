#ifndef PID_H
#define PID_H


class PID {
 public:
  PID();
  virtual ~PID();
  void Init(double Kp_, double Ki_, double Kd_);
  void UpdateError(double cte);
  double TotalError();
  double cost;

 private:
  double p_error;
  double i_error;
  double d_error;
  double Kp;
  double Ki;
  double Kd;
  double last_cte;
};


#endif  // PID_H
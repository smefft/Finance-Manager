//Sandra Effert
//CoLab 03C
//Retirement header file

#ifndef RETIREMENT_H
#define RETIREMENT_H

class Retirement {
 public:
  Retirement() {
    currentAge=0; retiredAge=0;
    currentSaved=0.0; monthlyContribution=0.0; annualReturn=0.0;
    };  //Default Constructor
  void estimateDriver();
  double estimateEarnings(int, int, double, double, double);

 private:
  int currentAge;
  int retiredAge;
  double currentSaved;
  double monthlyContribution;
  double annualReturn;

};
#endif

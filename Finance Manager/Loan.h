//Sandra Effert
//CoLab 03C
//Loan Payment header file

#ifndef LOAN_H
#define LOAN_H

class Loan {
 public:
  Loan() {
    principal=0.0;
    interest_rate = 0.0;
    monthly_payment = 0.0;
  }; //Default constructor
  void paymentDriver();
  int paymentMonths(double, double, double);

 private:
  double principal;
  double interest_rate;
  double monthly_payment;
};

#endif

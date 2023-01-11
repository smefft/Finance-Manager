//Sandra Effert
//CoLab 03C
//Retirement Implementation File

#include "Retirement.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Estimate Driver to populate private variables of class
void Retirement::estimateDriver() {
  
  cout<<"Estimate Savings at Retirement"<<endl;
  cout<<"Disclaimer: This is only a rough estimate!"<<endl<<endl;

  //get current age
  cout<<"        Enter your current age in years: ";
  cin>>currentAge;
  while (currentAge <= 0) {
    cout<<"        Age cannot be 0 or less."<<endl;
    cout<<"        Re-enter your age in years: ";
    cin>>currentAge;
  }

  //get retirement age
  cout<<"        Enter your target retirement age: ";
  cin>>retiredAge;
  while (retiredAge <= 0) {
    cout<<"        Your target age cannot be less than or equal to zero."<<endl;
    cout<<"        Re-enter your target age in years: ";
    cin>>retiredAge;
  }
  while (retiredAge <= currentAge) {
    cout<<"        Your target age cannot be less than or equal your current age."<<endl;
    cout<<"        Re-enter your target age in years: ";
    cin>>retiredAge;
  }

  //get current savings
  cout<<"        How much have you saved towards retirement?: $";
  cin>>currentSaved;
  while (currentSaved <0) {
    cout<<"        Your savings cannot be negative."<<endl;
    cout<<"        Re-enter your savings: $";
    cin>>currentSaved;
  }

  //get monthly contribution
  cout<<"        Enter your monthly contribution to retirement: $";
  cin>>monthlyContribution;
  while (monthlyContribution <= 0) {
    cout<<"        Your monthly contribution cannot be less than or equal to zero."<<endl;
    cout<<"        Re-enter your monthly contribution: $";
    cin>>monthlyContribution;
  }

  //get annual return
  cout<<"        Enter the estimated annual return on investment (in percent): ";
  cin>>annualReturn;
  while (annualReturn < 0) {
    cout<<"        Your rate cannot be less than zero."<<endl;
    cout<<"        Re-enter your rate (in percent): ";
    cin>>annualReturn;
  }

  cout<<'.'<<endl;
  cout<<'.'<<endl;
  cout<<"...calculating"<<endl<<endl;

  //call function to calculate retirement earnings
  estimateEarnings(currentAge, retiredAge, currentSaved, monthlyContribution, annualReturn);

  cout<<endl;

  //prompt for another estimate
  char yn;
  do {
    cout<<"Calculate another estimate? (y/n): ";
    cin>>yn;
    while (yn!='y' && yn!='Y' && yn!='n' && yn!='N') {
      cout<<"Invalid Input! Please choose again."<<endl;
      cout<<"Calculate another estimate? (y/n): ";
      cin>>yn;
    }
  }
  while (yn!='n' && yn !='N');
  cout<<endl;
}

double Retirement::estimateEarnings(int currentAge, int retiredAge, double currentSaved, double monthlyContribution, double annualReturn) {
  //calculate how many years until retirement
  int timeInYears = retiredAge-currentAge;
  
  //convert return from percent to decimal
  annualReturn /= 100;
  double annualIncrease = pow((1+annualReturn/12.0),(12.0*timeInYears));

  //Calculate final retirement savings
  double retirementEarnings = currentSaved * annualIncrease + (monthlyContribution * (annualIncrease - 1)) / (annualReturn/12.0);
  cout<<"Estimated Retirement Savings: $"<<fixed<<setprecision(2)<<retirementEarnings<<endl;

  //calculate growth
  double retirementGrowth = retirementEarnings - currentSaved - (monthlyContribution*timeInYears*12);
  cout<<"Estimated Retirement Growth: $"<<fixed<<setprecision(2)<<retirementGrowth<<endl;
  
  return retirementEarnings;
}

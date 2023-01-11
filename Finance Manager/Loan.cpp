//Sandra Effert
//CoLab 03C
//Loan Implementation File

#include "Loan.h"
#include <iostream>
#include <cmath>

using namespace std;

void Loan::paymentDriver() {
  char userInput;
  do {
    cout<<"Loan Payment Calculator"<<endl<<endl;

    //User input for principal amount
    cout<<"Enter the principal amount: $";
    cin>>principal;

    //User input for APY
    cout<<"Enter the annual interest rate (in percent): ";
    cin>>interest_rate;

    //User input for Monthly Payment
    cout<<"Enter the monthly payment: $";
    cin>>monthly_payment;

    //calculate time to pay off loan
    Loan::paymentMonths(principal, interest_rate, monthly_payment);

    //prompt for another loan
    cout<<"Calculate another loan payoff? (y/n): ";
    cin>>userInput;
    while (userInput != 'y' && userInput!= 'Y' && userInput != 'n' && userInput != 'N') {
       cout<<"Invalid Input! Please choose again."<<endl;
       cout<<"Calculate another loan payoff? (y/n): ";
       cin>>userInput;
     }
   }
   while (userInput != 'n' && userInput != 'N');
   cout<<endl;
}

//Calculate how long to pay off loan
int Loan::paymentMonths(double principal, double interest_rate, double monthly_payment) {
    cout<<"\nCalculating...\n";

    
    //Calculate months (x) it will take to pay down debt
    float months = (log(monthly_payment) - log(monthly_payment - (interest_rate/1200.0) * principal)) / (log((interest_rate / 1200.0) + 1.0));

    //Print how many months and years it will take to pay off the loan
    cout<<"\n"<<round(months)<<" months"<<" (" << round((round(months)/12)*10) / 10<<" years) are needed to pay your loan off.\n";

    
    //Calculate how much faster the loan would be paid off with a higher monthly payment
    float new_monthly_payment = monthly_payment + 15;
    float new_months = (log(new_monthly_payment) - log(new_monthly_payment - (interest_rate/1200.0) * principal)) / (log((interest_rate / 1200.0) + 1.0));

    cout<<"\nDid you know if you paid an additional $15 per month, you would pay off your loan "<<round(months)-round(new_months)<<" months earlier?\n\n";
  
    return round(months);
}

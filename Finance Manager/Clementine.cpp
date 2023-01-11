//Sandra Effert
//1071 Lab 03C
//Clementine driver

//TODO separate old labs into classes

#include <iostream>
#include "Register.h"
#include "Loan.h"
#include "Retirement.h"

using namespace std;

void runMenuSystem();

int main() {
  cout<<"Starting Clementine Financial Bank"<<endl;
  runMenuSystem(); 
  return 0;
}


//Run the Menu
void runMenuSystem() {
  char userChoice;
  do {
    cout<<"******* Welcome to Clementine Financial *********"<<endl;
    cout<<"\nMenu:"<< endl;
    cout<<"        [E] Estimate how much money at retirement"<<endl;
    cout<<"        [L] Loan payoff calculator"<<endl;
    cout<<"        [R] Run transaction classifier"<<endl;
    cout<<"        [Q] Quit program"<<endl<<endl;
    cout<<" Enter your choice and press enter: ";
  
    cin>>userChoice;
    char Choices[] = {'q', 'Q', 'e', 'E', 'l', 'L', 'r', 'R'};
    char choice;
    for (int i=0; i<8; i++) {
      if (Choices[i] == userChoice) {
	choice = Choices[i];
    }
      else {}
    }
  
    if (userChoice == choice && userChoice != 'q' && userChoice != 'Q') {
      switch(userChoice) {
      case 'E': case 'e': {                  //Estimate retirement
	Retirement userEstimate;         
	userEstimate.estimateDriver();
	break;}      
      case 'L': case 'l': {                  //Estimate retirement
	Loan loanPayoff;                           
	loanPayoff.paymentDriver();
	break;}    
      case 'R': case 'r': {                  //Transaction Classifier
	Register userTransactions;
	userTransactions.processTransaction();
	break;}
      default: {cout<<"The provided choice was invalid! Please select again."<<endl<<endl; break;}
      }
    }
    else if (userChoice != 'q' && userChoice != 'Q') {
      cout<<"\nThe provided choice was invalid! Please select again.\n"<<endl;
    }
  }
  while (userChoice != 'q' && userChoice != 'Q');

} //end menu


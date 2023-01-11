//Sandra Effert
//CPSC 1071 Lab 03C
//Register Implementation File

#include "Register.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream> //used for opening files
#include <iomanip> 

//Function header for converting to enumerated type
Register::Transactions convert(string);


//FUNCTION Driver for getfile, readfromfile, printfile; Returns true if successful
bool Register::processTransaction() {
  char yn;        //yes or no to continue
  do {
    setFileName(getFileName());
    while (readFromFile()==false) { // while (!readFromFile())
      setFileName(getFileName());
    }
    printFile();
  
    cout<<"Would you like to process another transaction register? (y/n): ";
    cin>>yn;
    if (yn != 'y' && yn !='Y' && yn != 'n' && yn != 'N') {  //tolower(yn)- only works for char
      cout<<"Invalid Input! Please choose again."<<endl;
      cout<<"Would you like to process another transaction register? (y/n): ";
      cin>>yn;
    }
  }
  while (yn != 'n' && yn != 'N');
  cout<<endl;
  return true;
} 


//FUNCTION User inputs file name; returns name of file as string  
string Register::getFileName() {
  string inputFile;
  cout<<"        Please enter the filename: ";
  cin>>inputFile;
  return inputFile;
}


//FUNCTION Set file used by class to user's
void Register::setFileName(string inputFile) {
  filename = inputFile;
}


//FUNCTION Open and read from the file. Returns true if successful, false is not.
bool Register::readFromFile() {
  cout<<"        Opening the file <"<<filename<<">"<<endl;
  
  ifstream transactionFile;
  string transaction;
  double userAmount;
  
  transactionFile.open(filename);
  count=0;

  if (transactionFile) {                       //Check for successful open
    while (transactionFile >> transaction) {   //iterate until eof
      int i = count % 4;  //declare int i outside of loop so it doesn't keep declaring

      //Sort values into their respective vectors
      switch (i) {
      case 0: date.push_back(transaction); break;                                  //Date
      case 1: type.push_back(convert(transaction));break;                          //Type
      case 2: location.push_back(transaction); break;                              //Location
      case 3: userAmount = stod(transaction); amount.push_back(userAmount); break; //Amount	
      default: break;
      } 
      count++;
    }
    transactionFile.close();
    return true;
  }
  
  else {                                     //if open was unsuccessful
    cout<<"Error opening file. Please retry."<<endl;
    return false;
  } 
}


//FUNCTION to convert string to custom type Transactions
Register::Transactions convert(string transaction) {
  Register::Transactions transactionType;
  char typeIdentifier = transaction.front();

  //Use first letter to identify transaction type
  switch (typeIdentifier) {
  case 'R': transactionType = Register::RESTAURANT; break;
  case 'M': transactionType = Register::MERCHANDISE; break;
  case 'U': transactionType = Register::UTILITY; break;
  case 'C': transactionType = Register::COFFEESHOP; break;
  case 'A': transactionType = Register::AUTOMOTIVE; break;
  case 'D': transactionType = Register::DEPOSIT; break;
  case 'O': transactionType = Register::OTHER; break;
  default: cout<<"Invalid."<<endl; break;
  }

  return transactionType;
}


//FUNCTION Format transactions and print them
void Register::printFile() {
  
  cout<<"Printing Transaction Ledger\n"<<endl;
  string transactionType;
  for (int i=0; i<(count/4); i++) {

    //Turn enumerated type back into string
    switch (type[i]) {
    case 0: transactionType = "Restaurant"; break;
    case 1: transactionType = "Merchandise"; break;
    case 2: transactionType = "Utility"; break;
    case 3: transactionType = "Coffeeshop"; break;
    case 4: transactionType = "Automotive"; break;
    case 5: transactionType = "Deposit"; break;
    case 6: transactionType = "Other"; break;				  
    default: transactionType = "Something else"; break;
    }
    //Print out table of transactions
    cout<<setw(10)<<date[i]<<" |";
    cout<<setw(15)<<location[i]<<" |";
    cout<<setw(10)<<fixed<<setprecision(2)<<amount[i]<<" |";
    cout<<setw(20)<<transactionType<<endl<<endl;
  }
}



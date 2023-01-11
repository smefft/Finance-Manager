//Sandra Effert
//CPSC 1071 Lab 03C
//Register class to initialize all functions and variables

#ifndef REGISTER_H
#define REGISTER_H
#include <string>
#include <vector>
#include <fstream> //used for files

using namespace std;

class Register {
 public:
  Register() {filename = ""; count =0;};  //Default Constructor
  enum Transactions {RESTAURANT, MERCHANDISE, UTILITY, COFFEESHOP, AUTOMOTIVE, DEPOSIT, OTHER};
  string getFileName();
  void setFileName(string);
  bool processTransaction();
  bool readFromFile();
  void printFile();

 private:
  string filename;
  int count;
  vector<string>  date;
  vector<double>  amount;
  vector<string> location;
  vector<Transactions> type;

};





#endif

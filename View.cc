/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Banking System                */
/*  Author:   Christine Laurendeau                 */
/*  Date:     08-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "View.h"
using namespace std;

void View::mainMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   BANKING SYSTEM MAIN MENU\n\n";
  cout<< "          1. Admin menu \n\n";
  cout<< "          2. Customer menu \n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 2) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}

void View::adminMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   BANKING SYSTEM ADMIN MENU\n\n";
  cout<< "          1. Add account \n\n";
  cout<< "          2. Print accounts \n\n";
  cout<< "          3. Print Transactions \n\n";
  cout<< "          4. Print Customers \n\n"; 
  cout<< "          5. Remove Account \n\n"; 
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 5) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}

void View::custMenu(int& choice)
{
  string str;

  choice = -1;

  cout<< "\n\n\n                   BANKING SYSTEM CUSTOMER MENU\n\n";
  cout<< "          1. Check balance \n\n";
  cout<< "          2. Deposit \n\n";  
  cout<< "          3. Withdrawal \n\n";
  cout<< "          0. Exit\n\n";

  while (choice < 0 || choice > 3) {
    cout << "Enter your selection:  ";
    choice = readInt();
  }
}

void View::printAccounts(Bank& bank)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.

  string str;
  bank.getAccounts()->toString(str);
  cout << str;
  
}


void View::printTransactions(string transactions)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.
  
  cout << transactions;
  
}


void View::printCustomers(Bank& bank){

	cout << endl << "Customers: " << endl;
	for(int i = 0; i<bank.getCustomers()->getSize(); i++){
	
		Customer* cust = bank.getCustomers()->get(i);
		
		cout << cust->getId();
		cout << "  " + cust->getName();
		cout << endl;
		
	}
}


void View::printBalance(float id)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.
  
  stringstream ss;
   // ss << setw(8) << fixed << setprecision(2) << b;
    
   // cin.get(); 
    cout << endl << "Your balance is $" << ss.str();
    cout << id;
    pauseN();
}

void View::printError(string err)
{
  cout << endl << err;
  cin.get();
}

void View::readCustId(int& id)
{
  string str;

  cout << "Customer id: ";
  getline(cin, str);
  stringstream ss(str);
  ss >> id;
}

void View::readAcctType(AcctType& acctType)
{
  string str;
  int    num;

  cout << "Account type [1 for chequing, 2 for savings]: ";
  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  if (num == 1)
    acctType = CHEQUING;
  else if (num == 2)
    acctType = SAVINGS;
  else
    acctType = GENERAL;
}

int View::readInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}



int View::readAcctNum()
{
  string str;
  int    num;
  cout << endl << "Please enter a account number" << endl;
  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

float View::readAmountNum()
{
  string str;
  float    num;
  cout << endl << "Please enter an amount" << endl;
  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}




void View::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

//PauseN, used to automatically exit out of checkBalance.

void View::pauseN()
{
  string str;

  cout << endl;
  getline(cin, str);
}



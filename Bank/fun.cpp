#include "fun.h"

#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

Bank::Bank() : balance(0) {}

/* Function to make sure input stream remains functioning */
void clearCin() {
  // Clear error flag
  std::cin.clear();
  // Throw away the rest of the line
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/* Only accepts digits to be returned. */
int getDigit() {
  int answer;
  // While condition will loop IF cin returns true (true = failed to getninput)
  // To simplify: Cin is saved to var and loop won't run if everything is ok.
  while (!(std::cin >> answer)) {
    clearCin();
    std::cout << "Error! Enter new number: ";
  }
  return answer;
}

// Set login password with the parameter and prompt for it
// 'Chances' limits the password attempts
bool login(int pinNumber, int chances) {
  int password = 0;

  for (int i = 1; i <= chances; ++i) {
    cout << "Enter your password: ";
    cin >> password;
    if (password == pinNumber) {
      return true;
    }
    cout << "Wrong! "
         << "You have " << chances - i << " tries left." << endl;
  }
  return false;
}
// Main switch menu
int getUserOption() {
  cout << "Main menu:" << endl;
  cout << "	1 - View my balance" << endl;
  cout << "	2 - Withdraw cash" << endl;
  cout << "	3 - Deposit funds" << endl;
  cout << "	4 - Exit" << endl;
  cout << "Enter a choice: " << endl;
  return getDigit();
}
// Display current balance on file
void Bank::viewBalance() {
  readFileBalance();
  cout << "You have: " << balance << " kr" << endl;
}
// Read current balance from file save to 'balance'.
void Bank::readFileBalance() {
  ifstream read("saldo.txt", ios::in);
  read >> balance;
  read.close();
}
// Update balance on file
void Bank::saveFileBalance() {
  ofstream save("saldo.txt", ios::out | ios::trunc);
  save << balance;
  save.close();
}

// Prompt to add funds to file
void Bank::depositFunds() {
  cout << "Enter amount to deposit: ";
  balance += getDigit();
  saveFileBalance();
}

// Withdraws cash based on saved values on file
void Bank::withdrawCash() {
  readFileBalance();
  // Get requested amount to withdraw
  int valueToWithdraw = 0;
  cout << "Withdrawal amount: " << endl;
  valueToWithdraw = getDigit();
  // If the withdrawal exceeds balance. Don't update balance
  if (valueToWithdraw > balance) {
    cout << "Not enough balance. You have " << balance << "kr left." << endl;
    // Else save new balance to file
  } else {
    balance -= valueToWithdraw;
    saveFileBalance();
  }
}



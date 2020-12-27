#ifndef FUN_H
#define FUN_H

class Bank {
 public:
  Bank();
  void withdrawCash();     // Withdraws cash based on saved values on file
  void viewBalance();      // Display current balance on file
  void depositFunds();     // Prompt to add funds to file
  void readFileBalance();  // Read current balance from file save to 'balance'
  void saveFileBalance();  // Update balance on file
 private:
  double balance;
};

/* Requests a pinNumber from user based on set validation chances */
bool login(int pinNumber, int chances);
/* Only accepts digits to be returned. */
int getDigit();
/* Function to make sure input stream remains functioning */
void clearCin();
/* Main menu choices */
int getUserOption();

#endif  // FUN_H
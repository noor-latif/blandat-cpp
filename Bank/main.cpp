/* Author: Noor Latif
 * Description: Banking app that saves and reads balance from file.
 * Date: 2020-12-13
 */
#include <iostream>
#include "fun.h"

int main() {
  int exit = false;
  Bank bank;
  if (login(1234, 3)) { // Enter the menu if login function returns true
    do {
      switch (getUserOption()) {
        case 1:
          bank.viewBalance();
          break;
        case 2:
          bank.withdrawCash();
          break;
        case 3:
          bank.depositFunds();
          break;
        case 4:
          exit = true;
          break;
        default:
          std::cout << "Invalid option! Try again.\n";
          clearCin(); 
          break;
      }
    } while (exit == false);
  }
  std::cout << "Program will now exit\n";
  return 0;
}
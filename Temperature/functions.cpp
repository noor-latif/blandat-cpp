#include "functions.h"
#include <iostream>
#include <limits>

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
    std::cout << "inte ett heltal, försök igen: ";
  }
  return answer;
}
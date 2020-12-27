#include "pet.h"

#include <algorithm>  // std::any_of
#include <cctype>     // std::isalpha
#include <iostream>

/* Function to make sure input stream remains functioning */
void clearCin() {
  // Clear error flag
  cin.clear();
  // Throw away the rest of the line
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/* Constructor with message (overloaded) */
Pet::Pet(string welcome) : name(" "), age(0), isFemale(false) {
  cout << endl << welcome << endl << endl;
}
/* Constructor without message (overloaded) */
Pet::Pet() : name(" "), age(0), isFemale(false) {}

/* Only accepts digits to be returned. */
int Pet::getAge() {
  // While condition will loop IF cin returns true (true = failed to getninput)
  // To simplify: Cin is saved to age and loop won't run if everything is ok.
  while (!(cin >> age)) {
    clearCin();
    cout << "inte en siffra, försök igen: ";
  }
  return age;
}

/* Only accepts letters from user. Otherwise re-prompts. */
string Pet::getName() {
  while (true) {
    cin >> name;
    // Checks if name is NOT a letter OR cin failed.
    // any_of() takes 3 parameters. (1)beginning of string. (2)end of string.
    // (3)predicate (predikat) or other bool functions.
    if (!std::any_of(name.begin(), name.end(), ::isalpha) || cin.fail()) {
      cout << "inte ett namn, försök igen: ";
      clearCin();
      continue;  // Restart while loop
    } else {
      return name;
    }
  }
}

/* Checks if answer corresponds to female (j/n) */
void Pet::getGender() {
  while (true) {
    clearCin();
    char answer;
    cin >> answer;
    switch (answer) {
      case 'j':
      case 'J':  // catching upper- & lowercase answers.
        isFemale = 1;
        clearCin();
        return;  // return breaks out of the while loop
      case 'n':
      case 'N':
        isFemale = 0;
        clearCin();
        return;  // return breaks out of the while loop
      default:
        cout << "inte ett giltigt svar, försök igen: \n";
        continue;  // Restart loop
    }
  }
}

void Pet::printAll() {
  cout << "\n++++++++++++++++++++++++++++\n";
  cout << "Namn: " << name << " Ålder: " << age << endl;
  if (isFemale)  // to specify the write output
    cout << name << " är en snäll flicka\n";
  else {
    cout << name << " är en snäll pojke\n";
  }
  cout << "++++++++++++++++++++++++++++\n";
}

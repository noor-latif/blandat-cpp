#include "functions.h"

#include <iostream>
#include <limits>  // std::numeric_limits

/* Function to make sure input stream remains functioning */
void clearCin() {
  // Clear error flag
  cin.clear();
  // Throw away the rest of the line
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Initiate private variables
Test::Test()
    : answer(0), counter(0), a(0), b(0), wrong(0), correct(0), result(0) {}

/* Only accepts digits to be returned. */
int getDigit() {
  int answer;
  // While condition will loop IF cin returns true (true = failed to getninput)
  // To simplify: Cin is saved to age and loop won't run if everything is ok.
  while (!(cin >> answer)) {
    clearCin();
    cout << "inte en siffra, försök igen: ";
  }
  return answer;
}

// Prompts user to continue or stop program.
bool repeatProgram(string prompt) {
  while (true) {
    char repeat;
    clearCin();
    cout << prompt << "\n";
    cin >> repeat;
    switch (repeat) {
      case 'j':
      case 'J':  // catch lower or uppercase y
        clearCin();
        return true;
      case 'n':
      case 'N':
        clearCin();
        return false;
      default:
        cout << "Undefined choice. Please try again...\n";
        continue;
    }
  }
  return false;
}

// The parameter 'symbol' takes the operator to calculate with.
// The parameter 'difficulty' defines largest number to use in test
// The parameter 'limit' defines the amount of test questions
// If 'test' parameter is true: Don't give second chances on wrong answers.
int Test::math(char symbol, const int difficulty, int limit, const bool test) {
  int randomMath = 0, i;
  int doOnce = 1;
  int randomCounter = true;

  /* For loop runs once and each if-case repeats according to limit parameter.
   * if the '?' symbol is received, the logic is switched; meaning:
   * For loop runs according to limit parameter and each if-case runs once to
   * allow symbol calculation reset (to randomize every try) */
  for (i = -1; i < randomCounter - 1; i++) {
    // Randomize math choice logic if '?' is received and keep random active
    // when randomMath is actively used.
    if (symbol == '?' || randomMath > 0) {
      randomMath = rand() % 3 + 1;  // (1 == +) (2 == -) (3 == *)
      counter = 0;  // Set for-case counter to 0 so we can run each if-case once
      while (doOnce) {          // Swap values to set up random function.
        randomCounter = limit;  // limit random questions to 'limit'
        limit = 1;  // Limit switch case to 1 to randomize each case every time
        doOnce = 0;
      }
    }
    if (symbol == '+' || randomMath == 1) {
      for (counter = 0; counter < limit; counter++) {
        a = rand() % difficulty + 1;
        b = rand() % difficulty + 1;
        while (true) {
          cout << a << " + " << b << " = ";
          answer = getDigit();
          if (a + b == answer) {
            cout << "Correct!\n";
            ++correct;
            answer = 0;
            break;
          } else {
            ++wrong;
            answer = 0;
            if (test) {
              cout << "Incorrect!\n";
              break;
            }
            cout << "Incorrect!\n";
            continue;
          }
        }
      }
    } else if (symbol == '-' || randomMath == 2) {
      for (counter = 0; counter < limit; counter++) {
        a = rand() % difficulty + 1;
        b = rand() % difficulty + 1;
        while (true) {
          cout << a << " - " << b << " = ";
          answer = getDigit();
          if (a - b == answer) {
            cout << "Correct!\n";
            ++correct;
            answer = 0;
            break;
          } else {
            ++wrong;
            answer = 0;
            if (test) {
              cout << "Incorrect!\n";
              break;
            }
            cout << "Incorrect!\n";
            continue;
          }
        }
      }
    } else if (symbol == '*' || randomMath == 3) {
      for (counter = 0; counter < limit; counter++) {
        a = rand() % difficulty + 1;
        b = rand() % difficulty + 1;
        while (true) {
          cout << a << " * " << b << " = ";
          answer = getDigit();
          if (a * b == answer) {
            cout << "Correct!\n";
            ++correct;
            answer = 0;
            break;
          } else {
            ++wrong;
            answer = 0;
            if (test) {
              cout << "Incorrect!\n";
              break;
            }
            cout << "Incorrect!\n";
            continue;
          }
        }
      }
    }
  }
  return 0;
}

int Test::getCorrect() { return correct; }
int Test::getWrong() { return wrong; }

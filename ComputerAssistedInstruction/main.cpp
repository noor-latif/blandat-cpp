/*
Author: Noor Latif
Description: A math testing program.
Date created: 2020-12-13
*/
const int _difficulty = 20;  // Numbers used in test varies between 0 and 20
const int _practice = 4;
const int _test = 10;

#include <stdlib.h>  // exit, EXIT_FAILURE

#include <ctime>
#include <iostream>

#include "functions.h"
using namespace std;

int main() {
  // Declare and intiate variables
  char mathType = ' ';
  int mathMethod;
  int mathChoice;
  float testLimit;
  float slutresultat;
  bool isTest;
  // Seed the RNG once, at the start of the program
  srand((unsigned int)time(NULL));
  // Create Test object
  Test test;
  do {
    /*
     ** Let user choose excercise, test or to exit.
     */
    cout << "\nVälkommen!\n\n"
         << "Anpassa ditt test:\n";
    cout << "1. Kör en övningsgenomgång.\n"
         << "2. Gör ett test.\n"
         << "3. Avsluta programmet.\n";
    cout << "Ange ditt val: ";
    mathChoice = getDigit();
    // Switch menu
    switch (mathChoice) {
      case 1:
        isTest = 0;
        testLimit = _practice;
        break;
      case 2:
        isTest = 1;
        testLimit = _test;
        break;
      case 3:
        cout << "\nDu valde att avsluta.\nHoppas programmet kom till nytta.\n";
        exit(EXIT_SUCCESS);
      default:
        cout << "Okänd inmatning, försök igen.\n";
        continue;
    }

    /*
     ** Let user choose calculus type or random.
     */
    cout << "\nVälj räkningsmetod!\n";
    cout << "1. Addition(+)\n"
         << "2. Subtraktion(-)\n"
         << "3. Multiplikation(*)\n"
         << "4. Blandat (+)(-)(*)\n"
         << "5. Avsluta programmet.\n";
    cout << "Ange ditt val: ";
    mathMethod = getDigit();
    cout << endl;
    // Switch menu
    switch (mathMethod) {
      case 1:
        mathType = '+';
        break;
      case 2:
        mathType = '-';
        break;
      case 3:
        mathType = '*';
        break;
      case 4:
        mathType = '?';
        break;
      case 5:
        cout << "\nDu valde att avsluta.\nHoppas programmet kom till nytta.\n";
        exit(EXIT_SUCCESS);
      default:
        cout << "Okänd inmatning, försök igen.\n";
        continue;
    }
    test.math(mathType, _difficulty, testLimit, isTest);
    cout << "Antal fel: " << test.getWrong() << endl;
    cout << "Antal rätt: " << test.getCorrect() << endl;
    if (isTest) {
      slutresultat = test.getCorrect() / testLimit * 100.0f;
      cout << "Du fick " << slutresultat << "% rätt\n\n";
    }
  } while (repeatProgram("Kör igen? (j/n)"));
}

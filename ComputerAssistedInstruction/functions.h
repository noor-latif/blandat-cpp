#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>

using namespace std;

void clearCin();
bool repeatProgram(string);
int getDigit();

class Test {
 public:
  Test();
  int math(char, int, int, bool);
  int getWrong();
  int getCorrect();
  friend int getDigit();  // Best-friends-forever-function
 private:
  int answer, counter, a, b, wrong, correct;
  double result;
};

#endif  // FUNCTIONS_H

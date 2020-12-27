#ifndef PET_H
#define PET_H
#include <string>

using namespace std;

void clearCin();

class Pet {
 public:
  Pet(std::string);
  Pet();
  std::string getName();
  int getAge();
  void getGender();
  void printAll();

 private:
  string name;
  int age;
  bool isFemale;
};

#endif  // PET_H

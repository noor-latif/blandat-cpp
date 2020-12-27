#include <iostream>

#include "pet.h"

int main() {
  /* Upon object construction, display welcome message */
  Pet pet("Välkommen!");

  /* Save name to private variable */
  cout << "Namn? ";
  string petName = pet.getName();

  /* Save age to private variable */
  cout << "Ålder " << petName << "? ";
  pet.getAge();

  /* Gender check saved to private variable */
  cout << "Är ditt djur en hona (j/n)?\n";
  pet.getGender();

  /* Print everything contained in pet object*/
  pet.printAll();

  std::cout << "\nPress enter to exit!";
  std::cin.ignore();
  return 0;
}

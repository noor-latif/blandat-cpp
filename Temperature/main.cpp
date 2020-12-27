/* Author: Noor Latif
 * Description: Save sensors to list. Sort and categorise values. Save to file
 * Date: 2020-12-13
 */

#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>

#include "functions.h"
using namespace std;

int main() {
  // Declare and initiate variables to categorise with
  int under0, mellan0_10, mellan11_20, mellan21_30, over30;
  under0 = mellan0_10 = mellan11_20 = mellan21_30 = over30 = 0;

  // Create a list of 6 sensors and initiate them
  list<Sensor> listOfSensors = {
      Sensor(0, "Våning 1", "Toalett"),
      Sensor(0, "Våning 1", "Sovrum"),
      Sensor(0, "Våning 2", "Vard.rum"),
      Sensor(0, "Våning 2", "Hall"),
      Sensor(0, "Våning 3", "Stuga"),
      Sensor(0, "Våning -99", "Jordens Kärna"),
  };

  // Grab sensor values from user
  cout << "Mata in temperaturen för sensorerna." << endl;
  for (Sensor &sensor : listOfSensors) {
    cout << "°C för " << sensor.room << ": ";
    sensor.tempValue = getDigit();
  }

  // Sort the sensor values and increase counter for each category.
  for (Sensor &sensor : listOfSensors) {
    if (sensor.tempValue < 0) {
      under0++;
    } else if (sensor.tempValue <= 10) {
      mellan0_10++;
    } else if (sensor.tempValue <= 20) {
      mellan11_20++;
    } else if (sensor.tempValue <= 30) {
      mellan21_30++;
    } else if (sensor.tempValue >= 30) {
      over30++;
    }
  }

  // Sort the whole list according to temperature values
  listOfSensors.sort();

  // Save all information we gathered to file
  ofstream output("sensorDatabase.txt", ios::out | ios::trunc);
  output << " ===========================================" << endl;
  output << "| " << setw(13) << "Rum"
         << " |" << setw(12) << "Våning"
         << " |" << setw(13) << "Temperatur"
         << " |" << endl;
  output << " ===========================================" << endl;
  for (Sensor &sensor : listOfSensors) {
    output << "| " << setw(13) << sensor.room << " |" << setw(12)
           << sensor.floor << " |" << setw(13) << sensor.tempValue << " |"
           << endl;
  }
  output << " ===========================================" << endl;

  output << under0 << " sensor har registrerat värden under 0 grader\n"
         << mellan0_10 << " sensor har registrerat värden mellan 0-10 grader\n"
         << mellan11_20 << " sensor har registrerat värden under 11-20 grader\n"
         << mellan21_30 << " sensor har registrerat värden under 21-30 grader\n"
         << over30 << " sensor har registrerat värden över 30 grader\n";
  output.close();

  // Then display the text content to user
  string line;
  ifstream input("sensorDatabase.txt");
  if (input.is_open()) {
    while (getline(input, line)) {
      cout << line << endl;
    }
    input.close();
  }

  return 0;
}

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>

// Create struct to hold 3 categories: temp, floor, room.
struct Sensor {
  int tempValue;
  std::string floor;
  std::string room;
  Sensor(int temperature, std::string floorLevel, std::string roomLocation)
      : tempValue(temperature), floor(floorLevel), room(roomLocation) {}
  // Function that compares struct object to itself
  // to enable sort function according to temperature
  bool operator<(const Sensor &sensorLocation) const {
    return tempValue < sensorLocation.tempValue;
  }
};

// cin but with error-handling.
int getDigit();

#endif  // FUNCTIONS_H
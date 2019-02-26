
// Setup for GPIO controls


/* Accessing GPIO from Linux terminal

Ensure login as root
$ sudo -i

Export the pins to be used to the file /sys/class/gpio/export
# echo "4" > /sys/class/gpio/export
# echo "17" > /sys/class/gpio/export

Set pin 4 as output and pin 17 as input
# echo "out" > /sys/class/gpio/gpio4/direction
# echo "in" > /sys/class/gpio/gpio17/direction

Set high and low values to pin 4
# echo "1" > /sys/class/gpio/gpio4/value
# echo "0" > /sys/class/gpio/gpio4/value

Read the value of the the input pin 17
# cat /sys/class/gpio/gpio17/value

Unexport the pins when finished
# echo "4" > /sys/class/gpio/unexport
# echo "17" > /sys/class/gpio/unexport

*/

#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "GPIOClass.h" // Header file with constructor, saved locally

using namespace std;

GPIOClass::GPIOClass()
{
  this->gpionum = "4"; // GPIO4 is default
}

GPIOClass::GPIOClass(string gnum)
{
  this->gpionum = gnum; // Instantiate GPIOClass object for GPIO pin number `gnum`
}

int GPIOClass::export_gpio()
{
  string export_str = "/sys/class/gpio/export";
  std::ofstream exportgpio;
  try {
    exportgpio.open(export_str.c_str()); // Open "export" file. Convert C++ string to C string. Required for all Linux pathnames
    exportgpio << this->gpionum; // write GPIO number to export
  } catch (const ofstream::failure& e) {
    cout << " OPERATION FAILED: Unable to export GPIO" << this->gpionum << " ." << endl;
    return -1;
  }
  exportgpio.close(); // close export file
  return 0;
}

int GPIOClass::unexport_gpio()
{
  string unexport_str = "/sys/class/gpio/unexport";
  std::ofstream unexportgpio;
  try {
    unexportgpio.open(unexport_str.c_str()); // Open "unexport" file
    unexportgpio << this->gpionum; // write GPIO number to unexport
  } catch (const ofstream::failure& e) {
    cout << " OPERATION FAILED: Unable to unexport GPIO" << this->gpionum << " ." << endl;
    return -1;
  }
  unexportgpio.close(); // close unexport file
  return 0;
}

int GPIOClass::setdir_gpio(string dir)
{
  string setdir_str = "/sys/class/gpio/gpio" + this->gpionum + "/direction";
  std::ofstream setdirgpio;
  try {
    setdirgpio.open(setdir_str.c_str()); // open direction file for gpio
    setdirgpio << dir; //write direction to direction file
  } catch (const ofstream::failure& e) {
    cout << "OPERATION FAILED: Unable to set direction GPIO" << this->gpionum << " ." << endl;
    return -1;
  }
  setdirgpio.close();
  return 0;
}

int GPIOClass::setval_gpio(string val)
{
  string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";
  std::ofstream setvalgpio;
  try {
    setvalgpio.open(setval_str.c_str()); // open value file for gpio
    setvalgpio << val;
  } catch (const ofstream::failure& e) {
    cout << " OPERATION FAILED: Unable to set the value of GPIO" << this->gpionum << " ." << endl;
    return -1;
  }
  setvalgpio.close();
  return 0;
}

int GPIOClass::getval_gpio(string& val)
{
  string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";
  std::ifstream getvalgpio;
  try {
    getvalgpio.open(getval_str.c_str()); // open value file for gpio
    getvalgpio >> val; // read the gpio value
    if (val != "0"){
      val = "1";
    } else {
      val = "0";
    }
  } catch (const ifstream::failure& e) {
    cout << " OPERATION FAILED: Unable to get the value of GPIO" << this->gpionum << " ." << endl;
    return -1;
  }

  getvalgpio.close(); // close the value file
  return 0;
}

string GPIOClass::get_gpionum(){
  return this->gpionum;
}

#include <iostream>
#include <windows.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>

#include "GPIO_Control.cpp"

using namespace std;

int main (void) {
  string inputstate;
  GPIOClass* gpio4 = new GPIOClass("4"); // create new GPIO object to be attached to GPIO4
  GPIOClass* gpio17 = new GPIOClass("17"); // create new GPIO object to be attached to GPIO17

  gpio4->export_gpio(); // export GPIO4
  gpio17->export_gpio(); // expoert GPIO17
  cout << " GPIO pins exported" << endl;

  gpio17->setdir_gpio("in"); // GPIO17 set to input
  gpio4->setdir_gpio("out"); // GPIO4 set to output
  cout << " GPIO pin directions set" << endl;

  while (1) {
    Sleep(500); // wait for 0.5 seconds
    gpio17->getval_gpio(inputstate); // read state of GPIO17 input pin
    cout << "Current input pin state: " << inputstate << endl;
    if (inputstate == "0") {
      cout << "input pin state is definitely 'Pressed'. Turning LED ON" << endl;
      gpio4->setval_gpio("1"); // turn LED ON

      cout << " Waiting until pin is unpressed..." << endl;
      while (inputstate == "0") {
        gpio17->getval_gpio(inputstate);
      };
      cout << "pin is unpressed" << endl;
    } else {
      cout << "input pin state is definitely 'UnPressed'. That was just noise." << endl;
    }
    gpio4->setval_gpio("0");
  }
  cout << "Exiting..." << endl;
  return 0;
}

#include <iostream>
using namespace std;

// main() is where program execution begins.
// Statments are grouped with braces to form blocks.
int main() {
  cout << "Hello World"; //prints Hello World

  //must declare functions and variables within scope
  int check_size_of();

  check_size_of();

  return 0;
}

/* Forms of statements in C++.
End of line character isn't compiled, all statements end with `;`
x = y;
y = y + 1;
add(x, y);

Can also be written as:

x = y;y = y + 1;add(x, y);
*/

//Check the size of built-in types.
int check_size_of() {
  //`endl` denotes a newline character.
  cout << "Size of char : " << sizeof(char) << endl;
  cout << "Size of int : " << sizeof(int) << endl;
  cout << "Size of short int : " << sizeof(short int) << endl;
  cout << "Size of long int : " << sizeof(long int) << endl;
  cout << "Size of float : " << sizeof(float) << endl;
  cout << "Size of double : " << sizeof(double) << endl;
  cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

  return 0;
}

//Create a new type using typedef
int create_new_type() {
  //typedef type newname;
  typedef int feet;
  feet distance;
  distance = 1;

  return distance;
}

//Create a set of optional types for an identifier
void enumerate() {
  //enum enum-name {list of names } var-list;
  enum color {red, green, blue} c;
  c = blue;
}

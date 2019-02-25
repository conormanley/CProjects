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

/* Forms of statements.
End of line character isn't compiled, all statements end with `;`
x = y;
y = y + 1;
add(x, y);
*/

//Check the size of a variable.
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

#include <iostream>
#include <string>
#include <sstream>
#include "functions.h"
using std::cin, std::cout, std::endl, std::string, std::istringstream;

int main() {
  // prompt user input
  cout << "1 or 2 or 3" << endl;
  int user = 0;
  cin >> user;
  if (user == 1){
    cout << "Number" << endl;
    int j = 0;
    cin >> j;
  }
  
  //TODO: create a command-line interface for calculator GUI

  return 0;
}
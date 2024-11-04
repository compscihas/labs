#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;
int num1 = 0;
int num2 = 0;
int main() {
	// TODO(student): print prompt for input
	cout << "put in range" << endl;
	cin >> num1 >> num2;
	if (!bool(is_valid_range(num1, num2))){
		cout << "invalid" << endl;
	}
	//else{

	//}
	// TODO(student): read the numbers from standard input

	// TODO(student): validate input (and reprompt on invalid input)

	// TODO(student): compute and display solution
	
	return 0;
}
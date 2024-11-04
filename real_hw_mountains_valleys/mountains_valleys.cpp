#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;
int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	bool valid = true;
	// TODO(student): print prompt for input
	cout << "Enter numbers 10 <= a <= b < 10000: " ;
	// TODO(student): read the numbers from standard input
	cin >> a >> b >> c >> d >> e >> f;
	// TODO(student): validate input (and reprompt on invalid input)
	valid = is_valid_range(a,b);
	if (valid == false){
		cout << "Invalid Input" << endl;
		if (c != 0){
			is_valid_range(c,d);
			cout << "Enter numbers 10 <= a <= b < 10000: " ;
			count_valid_mv_numbers(c,d);
			/*if (e != 0){
				is_valid_range(e,f);
				cout << "Enter numbers 10 <= a <= b < 10000: " ;
				count_valid_mv_numbers(e,f);
			}*/
		}
	}
	else{
	// TODO(student): compute and display solution
		count_valid_mv_numbers(a,b);
		if (c != 0){
			is_valid_range(c,d);
			count_valid_mv_numbers(c,d);
		}
		if (e != 0){
			is_valid_range(e,f);
			count_valid_mv_numbers(e,f);
		}
	}

	return 0;
}
#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if((a<b)&& (a>=10) && (a < 10000) && (b>=10) && (b<10000)){
		return true;
	}
	else{
		return false;
	}
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	int length = 0;
	int savedNumber = number;
	int digit = 0;
	int peak = 0;
	int compare = 0;
	while (number != 0){
		number = number /10;
		length++;
	}
	int savedLength = length;
	for(int i = 0; i<length;i++){
		digit = number % 10;
		if (i == 0){
			compare = digit;
		}
		else if(i == 1){
			if(digit > compare){
				peak = 0;
			}
			else if(compare > digit){
				peak = 1;
			}
			else{
				return 'N';
			}
			compare = digit;
		}
		else{
			if(digit > compare){
				peak++;
			}
			else if(compare > digit){
				peak--;				}
			else{
				return 'N';
			}
			}
	}
	if((length%2 == 1) && (peak == 0)){
		

	}
	return 'N';
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
}
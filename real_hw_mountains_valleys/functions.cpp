#include <iostream>
#include "functions.h"

using std::cout, std::endl;
bool is_valid_range(int a, int b) {
	if ((10 <= a) && (a <= b) && (b < 10000)){
		return true;
	}
	else{
		return false;
	}
}
int lengthOfNum(int number){
	int i = 0;
	/*if ((number > 0) && (number < 10)){
		return 1;
	}
	else if ((number > 9) && (number < 100)){
		return 2;}
	else if ((number > 99) && (number < 1000)){
		return 3;}
	else if ((number > 999) && (number < 10000)){
		return 4;}
	else{
		return 0;}*/
	while (number != 0){
		number /= 10;
		i++;
	}
	return i;
}
char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	//int option = 0;
	int digit = 0;
	int d1 = 0;
	int d2 = 0;
	int dx = 0;
	int dy = 0;
	int lengthQ = 0;
	int numLength = 0;
	int savedNumber = number;
	int longNumber = 0;
	int up = 0;
	int saved = 0;
	while (number != 0){
		numLength = lengthOfNum(number);
		digit = number % 10;
		number = number / 10;
		if (numLength == 1){
			d1 = digit;
		}
		else if (numLength == 2){
			d2 = digit;
		}
	}
	if (lengthOfNum(savedNumber) == 2){
		if (d1 > d2){
			return 'V';
		}
		else if (d2 > d1){
			return 'M';
		}
		else{
			return 'N';
		}	
	}
/*else if(lengthOfNum(savedNumber) == 3){
	if ((d2 > d1) && (d2 > d3)){
		return 'M';
	}
	else if ((d1 > d2) && (d3 > d2)){
		return 'V';
	}
	else{
		return 'N';
	}
}
else if(lengthOfNum(savedNumber) == 4){
	if((d1 < d2) && (d2 > d3) && (d3 < d4)){
		return 'M';
	}
	else if ((d1 > d2) && (d2 < d3) && (d3 > d4)){
		return 'V';
	}
	else{
		return 'N';
	}
}*/
	else{
		lengthQ = lengthOfNum(savedNumber);
		longNumber = savedNumber;
		while (savedNumber != 0){
			dx = savedNumber % 10;//get rem
			if (lengthOfNum(savedNumber) == lengthQ){
				dy = dx;
			}
			else if (lengthOfNum(savedNumber) == (lengthQ -1)){ //checks to see if this is the first instance of going up or going down to set precedent
				if (dx>dy){ 
					up = 1;}
				else if (dy>dx){
					up = -1;}
				else{
					return 'N';}
				saved = up;
				dy = dx;
			}
			else{
				if (dy > dx){
					up -= 1;
					if (up == 0 || up == saved){
						dy = dx;}
					else{
						return 'N';
					}
				}
				else if(dy < dx){
					up += 1;
					if (up == 0 || up == saved){
						dy = dx;}
					else{
						return 'N';
					}
				}
				else{
					return 'N';
				}
			}
			savedNumber /= 10; //change after to chcek first if
		}
		if ((lengthQ % 2) == 1){
			if (up == 0){
				dx = longNumber % 10;
				longNumber /= 10;
				dy = longNumber % 10;
				if (dx > dy){
					return 'V';
				}
				else if (dy > dx){
					return 'M';
				}
			}
			else{
				return 'N';
			}
		}
		else if((lengthQ % 2) == 0){
			if ((up == saved) && (saved == 1)){
				return 'V';
			}
			else if((up == saved) && (saved == -1)){
				return 'M';
			}	
			else{
				return 'N';
			}
		}
		return 'N';
	}
}

	// return 'V' if number has \/\/ pattern, and return 'N' otherwise

void count_valid_mv_numbers(int a, int b){
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	char checker = 0;
	int mCount = 0;
	int vCount = 0;
	int r1 = a; //for output statement
	while (a <= b){
		checker = classify_mv_range_type(a);
		if (checker == 'M'){
			mCount += 1;
		}		
		else if (checker == 'V'){
			vCount += 1;
		}
		a++;
	}
	cout << "There are " << mCount << " mountain ranges and " << vCount << " valley ranges between " << r1 << " and " << b << "." << endl;
}


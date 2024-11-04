#include <iostream>
#include <iomanip>
#include <cstring>
#include "parallel_tracks.h"

using std::cin, std::cout, std::endl;
//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
int ssize = SIZE;
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
  //TODO
	for (int i = 0; i < ssize; i++){
		ary[i] = 0.0;
		//cout << ary[i] << endl;
  }

}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
  //TODO
	for(int i = 0; i < ssize; i++){
		ary[i] = 0;
		//cout << ary[i] << endl;
  }
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(char ary[][STRING_SIZE])
// making sure all values within the array are set to "N/A";
{
	//TODO
	for(int i = 0; i < ssize; i++){
		strcpy(ary[i], "N/A");
		strcpy(ary[i], "N/A");
		//cout << ary[i] << endl;
		//cout << ary[i] << endl;
	}
}

//-------------------------------------------------------
// Name: trim
// PreCondition:  the cstring
// PostCondition: whitespace has been removed from beginning and end of string
//---------------------------------------------------------
void trim(char str[STRING_SIZE]) {
	// TODO
	int start = 0; //indexing to track start
	int end = strlen(str)-1; //indexing to track end
	//cout << str<< endl;
	while (isspace(str[start]) && (start < end)) {
        start++;
    }

    // Trimming end whitespace
    while (isspace(str[end]) && (end > start)) {
        end--;
    }

    // moving characters up with removal of whitespace
    int length = end - start ;
	if (length != 0){
		length += 1;
	}
    //memmove(str, str + start, length);
	for(int i=0; i<length; i++){
		str[i] = str[i+start];
	}
    str[length] = '\0';
	//cout << str;
	/*int white = 0;
	//cout << str<< endl;
	char last[STRING_SIZE] = " ";
	for(int i=0; i<STRING_SIZE; i++){
		if ((isspace(str[i]))){
			if((isspace(str[i+1])) && (!isspace(last[0]))){
				str[i-white] = str[i];
				//cout << 'y' << endl;
			}
			else{
				white++;
				//cout << 'x' << endl;
			}
			last[0] = str[i];
		}
		else{
			last[0] = str[i];
			str[i-white] = str[i];
			//cout << "z" << endl;
		}
	}
	cout << str;*/
}

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_runner_data(double timeArray[], char countryArray[][STRING_SIZE], 
		unsigned int numberArray[], char lastnameArray[][STRING_SIZE]) 
{
  //TOD
	/*double time = 0.0;
	char countryS[STRING_SIZE] = "";
	unsigned int number = 0;
	char name[STRING_SIZE] = "";*/
	for (int i=0; i<ssize; i++){
		/*cin >> time >> countryS >> number;
		cin.getline(name[i])*/
		int useless = 0;
		cin >> timeArray[i] >> countryArray[i] >> numberArray[i];
		cin.getline(lastnameArray[i], STRING_SIZE);
		trim(lastnameArray[i]);
		if (timeArray[i] <= 0){
			return false;
		}
		if (strlen(countryArray[i]) != 3){
			return false;
		}
		for (int j=0; j<3; j++){
			if (!isupper(countryArray[i][j])){
				return false;
			}
		}
		if (numberArray[i] > 99){
			return false;
		}
		//cout << timeArray[i] << endl;
		if (strlen(lastnameArray[i])<1){
			return false;
		}
		for(unsigned int j = 0; j < strlen(lastnameArray[i]); j++){
			if ((isalpha(lastnameArray[i][j])) || isspace(lastnameArray[i][j])){
				useless += 1;
			}
			else{
				return false;
			}
		}
	}
	//for (int i = 0; i < SIZE; i++){
		//cout << "--" << timeArray[i] << " " << countryArray[i] << " " << numberArray[i] << " " << lastnameArray[i] << endl;
	//}
	return true; // set so it will compile
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{

	double newtimeArray[SIZE];
	prep_double_array(newtimeArray);
	for (int i = 0; i < ssize ; i++){
		newtimeArray[i] = timeArray[i];
	}
	for (int i = 0; i < ssize; ++i){
		for(int j = i + 1; j<ssize; ++j){
			if (newtimeArray[j] < newtimeArray[i]){
				double temp = newtimeArray[i];
				newtimeArray[i] = newtimeArray[j];
				newtimeArray[j] = temp;
			}
		}
	}
	for (int i = 0; i <ssize; ++i){
		for(int j = 0; j < ssize; ++j){
			if(timeArray[i] == newtimeArray[j]){
				rankArray[i] = j + 1 ;
				break;
			}
		}
	}
	/*for (int i = 0; i < SIZE; i++){
		cout << rankArray[i] << endl;
	}*/
	/*double var = 0;
	int count = 1;
	for (unsigned int i = 0; i < SIZE; ++i){
		var = timeArray[i];
		for(unsigned int j = 0;j < SIZE; ++j){
			if (var > timeArray[j])
			{
				++count;
			}
		}
		rankArray[i] = count;
		count = 1;
	}
	for (int i = 0; i < SIZE; i++){
		cout << rankArray[i] << endl;
	}*/
}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const char countryArray[][STRING_SIZE],
		const char lastnameArray[][STRING_SIZE], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}
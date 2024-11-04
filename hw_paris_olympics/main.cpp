/******************************************************************************

File: main.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section: 
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track 
event with 9 lanes. The code will sort the order, then display the results

Updates
Author: J. Michael Moore & Paul Taele
Author: J. Michael Moore

Input information format
<Time (double)> <Abbreviated Country (String)> <Uniform number (int)> <Lastname (String)>
32.7 USA 12 Moore
36.5 RUS 35 Polsley
45.8 ENG 73 Teale
52.34 CHN 14 Nemec
76.45 ITY 23 Lupoli     

*******************************************************************************/

#include <iostream>
#include <cstring>
#include "parallel_tracks.h"

using std::cin; using std::cout; using std::endl;
int main()
{
    //use file
    //std::ifstream inputFile("good_data04.txt");
    // TODO: create arrays needed
	double setTime[SIZE];
    char setCountry[SIZE][STRING_SIZE];
    unsigned int setJersey[SIZE];
    char setLastName[SIZE][STRING_SIZE];
    unsigned int rank[SIZE];
    // TOTO: prep all arrays
	prep_double_array(setTime);
    prep_string_array(setCountry);
    prep_unsigned_int_array(setJersey);
    prep_string_array(setLastName);
    prep_unsigned_int_array(rank);
    //trim(example);
    if(get_runner_data(setTime, setCountry, setJersey, setLastName)){
        get_ranking(setTime, rank);
        print_results(setTime,setCountry, setLastName, rank);
    }
    else{
        cout << "Bad Input";
    }
    // TODO: load the runner's data into the array

    // if unable to load runner data
    //   1) output "Bad input" to standard out
    //   2) exit program by returning 1
    
    // TODO: determine ranking, notice the rank array receives the results
    // TODO: Output results

    // this is not required in C++ but many people still explitly add it
    return 0; 
}


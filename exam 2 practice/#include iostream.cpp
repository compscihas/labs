#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"
#include <string>

using std::cout, std::endl, std::string, std::ifstream, std::ofstream;
double pathLength(double** distance, int n, int* path, int m){
    new double temp[n][n];

}
void avgMatrix (double** inArray, int rows, int columns, double ** outArray){
    double temp[rows][columns];
    double total = 0;
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++ ){
            if (i > 0) && (i < rows - 1){
                total += inArray[i-1][j]
            }
            temp[i][j] = 
        }
    }
}
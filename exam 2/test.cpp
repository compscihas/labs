#include <iostream>
using std::cin;
using std::cout;
using std::endl;

char** rotateImage(char** art, unsigned int width, unsigned int height) {
  // Write your solution here
  // We will not grade any code outside of this function
  // Code must handle arrays of any dimensions,
  //   not just the simple example we hard coded
  if((height == 0) || (width == 0)){
    return art;
  }
    char temp[99][99];
  for(unsigned int i = 0; i < height; i++){
        for(unsigned int j = 0; j < width; j++){
            temp[j][height - i - 1] = art[i][j]; //transfer values to new array while rotating
        }
  }
  for(unsigned int i = 0; i < width; i++){
        for(unsigned int j = 0; j < height; j++){
            art[i][j] = temp[i][j];
        }
  }
  int transfer = width;
  width = height;
  height = transfer;
  // ran out of time but would then dynamically allocate the array to a new array with a modified width and height based on the new values
  //would then return the new array


  return art; // update to correct result
}

void deleteImage(char**& art, unsigned int height) {
  // not required for exam, but writing would stop a memory leak
  delete [] art;
  //for loop here to set every value to null ptr
    art = nullptr
}

char** loadSimple(unsigned int& width, unsigned int& height) {
  /* This is a bad, non-scalable way to build an array
  
      <->
      [+]
      
  */
  
  width = 3;
  height = 2;
  char** ary = new char*[2];
  ary[0] = new char[3];
  ary[0][0] = '<';
  ary[0][1] = '-';
  ary[0][2] = '>';
  ary[1] = new char[3];
  ary[1][0] = '[';
  ary[1][1] = '+';
  ary[1][2] = ']';
  return ary;
}

void printImage(char const* const* art, unsigned int width, unsigned int height) {
    for (unsigned int row = 0; row < height; ++row) {
        for (unsigned int col = 0; col < width; ++col) {
            cout << art[row][col];
        }
        cout << endl;
    }
}

int main() {
    unsigned int width = 0;
    unsigned int height = 0;
     
    char** art = loadSimple(width, height);

    printImage(art, width, height);
    cout << endl;
    
    art = rotateImage(art, width, height);
    printImage(art, width, height);

    deleteImage(art, height);
}

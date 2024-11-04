#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"
#include <string>

using std::cout, std::endl, std::string, std::ifstream, std::ofstream;

void initializeImage(Pixel image[][MAX_HEIGHT]) {
  // iterate through columns
  for (unsigned int col = 0; col < MAX_WIDTH; col++) {
    // iterate through rows
    for (unsigned int row = 0; row < MAX_HEIGHT; row++) {
      // initialize pixel
      image[col][row] = {0, 0, 0};
    }
  }
}

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int& height) {
  // TODO: implement (part 1)
    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open "+ filename);//if file does not open
    }

    string type;
    file >> type;
    if (type != "P3" && type != "p3") {
        throw std::runtime_error("Invalid type "+ type);
    }

    file >> width >> height;
    if (width <= 0 || height <= 0 || width > MAX_WIDTH || height > MAX_HEIGHT) {
        throw std::runtime_error("Invalid dimensions");
    }

    int maxVal;
    file >> maxVal;
    if (maxVal != 255) {
        throw std::runtime_error("Invalid max value");
    }

    unsigned int pixelCount = 0;
    for (unsigned int i = 0; i < height; ++i) { //goes through the 2 dimensional array assigning values.
        for (unsigned int j = 0; j < width; ++j) {
            int r, g, b;
            if (!(file >> r >> g >> b)) {
                throw std::runtime_error("Invalid color value");
            }
            if (r < 0 || r >= 256 || g < 0 || g >= 256 || b < 0 || b >= 256) {
                throw std::runtime_error("Invalid color value");
            }
            image[j][i] = {static_cast<unsigned char>(r), static_cast<unsigned char>(g), static_cast<unsigned char>(b)};
            pixelCount++;
        }
    }

    if (file >> type) {  // Check if there's any additional data in the file
        throw std::runtime_error("Too many values");
    }

    if (pixelCount != width * height) {
        throw std::runtime_error("Invalid color value");
    }
}

void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height) {
  // TODO: implement (part 1)
  ofstream file;
  file.open(filename);
  if(!file.is_open()){
    throw std::runtime_error("Failed to open " + filename);
  }
  file << "P3" << endl;
  file << width << " " << height << endl;
  file << "255" << endl;
  for(unsigned int i = 0; i < height; ++i){
    for(unsigned int j = 0; j < width; ++j){
      file <<static_cast<int>(image[j][i].r) << " ";
      file <<static_cast<int>(image[j][i].g) << " ";
      file <<static_cast<int>(image[j][i].b) << " ";
    }
    file << endl;
  }


}
unsigned int colorDif(Pixel a, Pixel d) {
    return (a.r - d.r) * (a.r - d.r) +
           (a.g - d.g) * (a.g - d.g) +
           (a.b - d.b) * (a.b - d.b);
}
unsigned int energy(Pixel image[][MAX_HEIGHT], unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
  // TODO: implement (part 1)
    Pixel left = image[(x == 0 ? width - 1 : x - 1)][y];
    Pixel right = image[(x == width - 1 ? 0 : x + 1)][y];
    Pixel up = image[x][(y == 0 ? height - 1 : y - 1)];
    Pixel down = image[x][(y == height - 1 ? 0 : y + 1)];

    // Calculate the energy
    unsigned int deltaX2 = colorDif(left, right);
    unsigned int deltaY2 = colorDif(up, down);

    // Return the total energy as the sum of squared differences
    return deltaX2 + deltaY2;
}

// uncomment functions as you implement them (part 2)

unsigned int loadVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_col, unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)

  int totalEnergy = 0;
  unsigned int right = 99999999;
  unsigned int center = 99999999;
  unsigned int left = 99999999;

  for (unsigned int row = 0; row < height; ++row){
    if (row == 0){
      totalEnergy += energy(image, start_col, row, width, height);
    }
    else{
      right = 99999999;
      center = 99999999;
      left = 99999999;
      if (start_col > 0){
        right = energy(image, start_col - 1, row, width, height);
      }
      center = energy(image, start_col, row, width, height);
      if (start_col < width - 1){
        left = energy(image, start_col + 1, row, width, height);
      }
      if((center <= right) && (center <= left)){
        totalEnergy += center;
      }
      else if((left <= center) && (left <= right)){
        totalEnergy += left;
        start_col++;
      }
      else if ((right <= left) && (right <= center)){
        totalEnergy += right;
        start_col--;
      }
    } 
    seam[row] = start_col;
  }

 return totalEnergy;
}

unsigned int loadHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_row, unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
  unsigned int totalEnergy = 0;
  unsigned int temp = 0;
  unsigned int tempRow = 0;
  for(unsigned int col = 0; col < width; col++){
    if(col == 0){
      totalEnergy += energy(image, col, start_row, width, height);
    }
    else{
      temp = energy(image, col, start_row, width, height);
      tempRow = start_row;
      if (start_row > 0){
        if(energy(image, col, start_row - 1, width, height) < temp){
          temp = energy(image, col, start_row - 1, width, height);
          tempRow = start_row - 1;
        }
      }
      if(start_row < height - 1){
        if(energy(image, col, start_row + 1, width, height) < temp){
          temp = energy(image, col, start_row + 1, width, height);
          tempRow = start_row + 1;
        }
      }
      totalEnergy += temp;
      start_row = tempRow;
    }  
    seam[col] = start_row;
  }
  return totalEnergy;
}

void findMinVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
  int currentLowest = 0;
  int temp = 0;
  int check = 0;
  for(unsigned int i = 0; i < width; ++i){
    if(i == 0){
      currentLowest = loadVerticalSeam(image, i, width, height, seam);
      check = i;
    }
    else{
      temp = loadVerticalSeam(image, i, width, height, seam);
      if (temp < currentLowest){
        currentLowest = temp;
        check = i;
      }
    }
  }
  currentLowest = loadVerticalSeam(image, check, width, height, seam);
}

void findMinHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
  int currentLowest = 0;
  int temp = 0;
  int check = 0;
  for (unsigned int i = 0; i < height; i++){
    if(i == 0){
      currentLowest = loadHorizontalSeam(image, i, width, height, seam);
      check = i;
    }
    else{
      temp = loadHorizontalSeam(image, i, width, height, seam);
      if (temp < currentLowest){
        currentLowest = temp;
        check = i;
      }
    }
  }
  currentLowest = loadHorizontalSeam(image, check, width, height, seam);
}

void removeVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int height, unsigned int verticalSeam[]) {
//   // TODO: implement (part 2)
  int temp = 0;
  for (unsigned int i = 0; i < height; ++i){
    temp = verticalSeam[i];
    for(unsigned int j = temp; j < width - 1; j++){
      image[j][i] = image[j+1][i];
    }
  }
  width--;
}

void removeHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int& height, unsigned int horizontalSeam[]) {
//   // TODO: implement (part 2)
  int temp = 0;
  for(unsigned int i = 0; i < width; ++i){
    temp = horizontalSeam[i];
    for(unsigned int j = temp; j < height - 1; j++){
      image[i][j] = image[i][j+1];
    }
  }
  height--;
}

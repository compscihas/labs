#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
  // returns the length of the string including zero (0)
  int len = 0;
  while (str[len] != '\0')
  {
    ++len;
  }
  return len;
}

unsigned int find(char str[], char character) {
  int i = 0;
  int count = 0;
  while (str[i] != '\0')
  {
    if (str[i] == character){
      return i;
    }
    else {
      count++;
      i++;
    }
    }
    return count;
  }


  // returns 
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found


bool equalStr(char str1[], char str2[]) {
  int l1 = length(str1);
  int l2 = length(str2);
  if(l1 == l2){
    return true;
  }
  else {
    return false;
  }
  }
  // returns true if they are equal and false if they are not

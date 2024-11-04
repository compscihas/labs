#include <iostream>
#include "functions.h"
#include <stdexcept>
#include <string>
#include <limits>
using std::cout, std::cin, std::endl;

int Largest(int a, int b, int c) {
  int d = a;
  if (b > d) {
    d = b;
  }
  if (c > d) {
    d = c;
  }
  return d;
}

bool SumIsEven(int a, int b) {
  int c = a + b;
  if (c < 0){
    c *= -1;
  }
  if(c%2 == 1){
    return false;
  }
  else{
    return true;
  }
}

int BoxesNeeded(int apples) {
  int box = 1 + (apples/20);
  if (apples <= 0){
    return 0;
  }
  else{
    if(apples % 20 == 0){
      box -= 1;
    }
    return box;
  }
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
  double ACor = A_correct;
  double BCor = B_correct;
  double aTot = A_total;
  double bTot = B_total;
  double aGrade = ACor/aTot;
  double bGrade = BCor/bTot;
  if(ACor < 0 || aTot <= 0 || BCor < 0 || bTot <= 0 || ACor > aTot || BCor > bTot){
    throw std::invalid_argument("Invalid");
  }
  if(aGrade > bGrade){
    return true;
    }
  else if(aGrade <= bGrade){
    return false;
  }
  else{
    return false;
  }
}

bool GoodDinner(int pizzas, bool is_weekend) {
  if (pizzas >= 10 && pizzas <= 20) {
    return true;
  }
  if (is_weekend && pizzas > 10) {
    return true;
  }
  else{
    return false;
  }
}

int SumBetween(int low, int high) {
  int value = 0;
  if(low > high){
    throw std::invalid_argument("invalid");
  } //invalid arg pretty straight forward
  if((low < 0) && (high > 0)){
    if (((low+1) * -1) > (high - 1)){//accounts for abs(min) being > max
      high *= -1;//gets rid of instances where it would add up to 0
      high--;
    }
    else if(((low+1) * -1) < (high-1)){
      low *= -1;
      low++;
    }
    else{
      value = 0;
      return value;
    }
  }
  for (int n = low; n <= high; ++n) {
    if((value>0) && (n > 0)){
      int newMax = INT32_MAX - n;
      if((value > newMax)){
        throw std::overflow_error("max too big");
      }
    }
    if ((value < 0) && (n < 0)){
      int newMin = INT32_MIN - n;
      if ((value < newMin)){
        throw std::overflow_error("min too small");
      }
    }
    value += n;
    if (low == INT32_MAX){
      return value;
    }
  }
  return value;
}

int Product(int a, int b) {
  if(a == 0 || b == 0){
    return 0; //handles anything with 0 easily
  }
  if (a > 0 && b > 0) {
    if (a > INT32_MAX / b) {
      throw std::overflow_error("overflow");
      }
    } 
  else if (a < 0 && b < 0) {
    if (a < INT32_MAX / b) {
      throw std::overflow_error("overflow");
    }
  } 
  else if (a > 0 && b < 0) {
    if (b < INT32_MIN / a) {
      throw std::overflow_error("overflow");
    }
   } 
  else if (a < 0 && b > 0) {
    if (a < INT32_MIN / b) {
      throw std::overflow_error("overflow");
    }
  }

  return a * b;
}



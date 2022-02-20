/*
 * Name        : Charles Clarke
 * Description : Assigment #1
 * Sources     : FILL IN
 */
#include "assignment_1.h"
// Write Function Definitions Here (What goes below main)
bool CheckAlphabetic(const string & my_string) {
  if (my_string.length() == 0) {
    return false;
  }
  for (unsigned int i = 0; i < my_string.length(); i++) {
    if (!(((my_string.at(i) >= 'a') && (my_string.at(i) <= 'z')) ||
    ((my_string.at(i) >= 'A') && (my_string.at(i) <= 'Z')))) {
      return false;
    }
  }
  return true;
}
bool FitIntToLoop(int & my_int, int range[]) {
  if (range[0] > range[1]) {
    return false;
  } else {
    unsigned int total_range = range[1] - range[0] + 1;
    if (my_int > range[1]) {
      while (my_int > range[1]) {
        my_int -= total_range;
      }
    } else {
      while (my_int < range[0]) {
        my_int += total_range;
      }
    }
    return true;
  }
}
bool EncryptString(string & my_string, int shift_amount) {
  int my_range[2];
  int pre_loop_value;
  if (CheckAlphabetic(my_string)) {
    for (unsigned int i = 0; i < my_string.length(); i++) {
      if (my_string.at(i) >= 'a' && my_string.at(i) <= 'z') {
        my_range[0] = 'a';
        my_range[1] = 'z';
      } else {
        my_range[0] = 'A';
        my_range[1] = 'Z';
      }
      pre_loop_value = my_string.at(i) + shift_amount;
      FitIntToLoop(pre_loop_value, my_range);
      my_string.at(i) = pre_loop_value;
    }
    return true;
  } else {
    return false;
  }
}
bool DecryptString(string & my_string, int shift_amount) {
  shift_amount = -shift_amount;
  return EncryptString(my_string, shift_amount);
}
double ComputeAverage(double my_array[], unsigned int size_of_array) {
  double total = 0;
  for (unsigned int i = 0; i < size_of_array; i++) {
    total += my_array[i];
  }
  return total / size_of_array;
}
double FindMinValue(double my_array[], unsigned int size_of_array) {
  double min_value = my_array[0];
  for (unsigned int i = 1; i < size_of_array; i++) {
    if (my_array[i] < min_value) {
      min_value = my_array[i];
    }
  }
  return min_value;
}
double FindMaxValue(double my_array[], unsigned int size_of_array) {
  double max_value = my_array[0];
  for (unsigned int i = 1; i < size_of_array; i++) {
    if (my_array[i] > max_value) {
      max_value = my_array[i];
    }
  }
  return max_value;
}

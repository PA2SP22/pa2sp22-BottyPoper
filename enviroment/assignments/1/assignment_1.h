/*
 * Name        : assignment 1 head
 * Author      : charles Clarke
 * Description : FILL IN
 * Sources     : FILL IN
 */

#ifndef ASSIGNMENT_1_H
#define ASSIGNMENT_1_H

// Add any includes and using statements Here
#include <iostream>

#include <string>

using std::cout;
using std::string;
// Declare Function Prototypes Here (What goes above main)
/*
This function will check to make sure all characters in a given string 
are alphabetic. It returns true if the string is all alphabetic, 
otherwise it returns false. An empty string should also return false. 
 */
bool CheckAlphabetic(const string & my_string);
/*
This function is used to keep an integer value in a loop, meaning if 
you have a range of 1-5 and you add 2 to a value of 3 you would loop 
back to 1. Think like Pacman going off the map in one direction and 
coming in the other.
 */
bool FitIntToLoop(int & my_int, int range[]);
/*
This function will perform a Caesar Cipher shift 
(http://en.wikipedia.org/wiki/Caesar_cipher). If the string contains 
any non-alpha characters do not perform the encryption and return 
false. Otherwise perform the encryption and return true. 
 */
bool EncryptString(string & my_string, int shift_amount);
/*
This function decrypts a Caesar Cipher shift. If the string contains 
any non-alpha characters do not perform the decryption and return 
false. Otherwise perform the encryption and return true.
 */
bool DecryptString(string & my_string, int shift_amount);
/*
This function will compute the mean average of the values in the 
array. The array will always be at least of size 1.
 */
double ComputeAverage(double my_array[], unsigned int size_of_array);
/*
This function will find and return the smallest value in an array. The 
array will always be at least of size 1. 
 */
double FindMinValue(double my_array[], unsigned int size_of_array);
/*
This function will find and return the largest value in an array. The 
array will always be at least of size 1.
 */
double FindMaxValue(double my_array[], unsigned int size_of_array);
#endif /* ASSIGNMENT_1_H */

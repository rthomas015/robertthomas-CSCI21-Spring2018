/*
 * Name        : lab_4.h
 * Author      : Luke Sathrum
 * Description : Header File for Lab #4. DO NOT ALTER!
 */

#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ios_base;

// Function Prototypes (DO NOT ALTER)
string MakeString(string label, double value, char separator);
char StringToChar(string value);
int StringToInt(string value);
double StringToDouble(string value);
bool StringToBool(string value);

#endif

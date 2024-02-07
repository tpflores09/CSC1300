/* File name: perfect/lab6
   author: Tania Perdomo Flores
   Date: 10-20-2022
   Purpose: Create a program to list the perfect squares between two numbers supplied in a text file
   */
// only function prototypes

#ifndef PERFECT_H
#define PERFECT_H

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

void findPerfect (int lower, int upper, string filename);
bool isPerfect (long long x);

#endif
/* Author: Tania Perdomo Flores
   Date: 11-6-2022*/
// only function prototypes

#ifndef TEPERDOMOF42_PROG3_H
#define TEPERDOMOF42_PROG3_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

void getProfit(double profit[]);
double getTotal(double profit[]);
double getMax(double profit[], int size, string &maxMonth, string month[]);
double getMin(double profit, int size, string &minMonth, string month[]);
void getQuarterly(double quarterly[], double profit[]);
void printResults(double total, double quartely [], double maxProfit, double minProfit, double average, string maxMonth, string minMonth);
#endif 
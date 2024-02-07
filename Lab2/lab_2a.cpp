/* 
    Title: Purple - lab_2a.cpp 
    Author: Tania Perdomo Flores
    Date: 9-15-2022
    Purpose: Find the area of a triangle with user inputs.

*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int base;
int height;
double area;

int main ()
{
    cout << "Program to find the area of a triangle: " << endl;
    cout << "What is the base of the triangle?: ";
    cin >> base;
    cout << "What is the height of the triangle?: ";
    cin >> height;

    area = (base * height) / 2.0;
    cout << "The area of triangle is calculated to be: " << area << endl;


    return 0;
}
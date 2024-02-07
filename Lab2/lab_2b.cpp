/* 
    Title: Purple - lab_2b.cpp 
    Author: Tania Perdomo Flores
    Date: 9-15-2022
    Purpose: Find the percentage grade of the user by averaging test grades.

*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int firstTest;
int secondTest;
int thirdTest;
int total;
int percentage;
string studentName;

int main ()
{
    cout << "Enter the first student's name: ";
    getline(cin,studentName);
    cout << "Enter " << studentName << "'s first test grade: ";
    cin >> firstTest;
    cout << "Enter " << studentName << "'s second test grade: ";
    cin >> secondTest;
    cout << "Enter " << studentName << "'s third test grade: ";
    cin >> thirdTest;
    cout << endl;

    total = firstTest + secondTest + thirdTest;
    cout << studentName << " has a total of " << total << endl;
    percentage = (firstTest + secondTest + thirdTest) / 3;
    cout << studentName << " has a percentage of " << percentage << " %" << endl;
    cout << endl;

    cout << "Enter the second student's name: ";
    cin.ignore();
    getline(cin,studentName);
    cout << "Enter " << studentName << "'s first test grade: ";
    cin >> firstTest;
    cout << "Enter " << studentName << "'s second test grade: ";
    cin >> secondTest;
    cout << "Enter " << studentName << "'s third test grade: ";
    cin >> thirdTest;
    cout << endl;

    total = firstTest + secondTest + thirdTest;
    cout << studentName << " has a total of " << total << endl;
    percentage = (firstTest + secondTest + thirdTest) / 3;
    cout << studentName << " has a percentage of " << percentage << " %" << endl;
    cout << endl;

    cout << "Enter the third student's name: ";
    cin.ignore();
    getline(cin,studentName);
    cout << "Enter " << studentName << "'s first test grade: ";
    cin >> firstTest;
    cout << "Enter " << studentName << "'s second test grade: ";
    cin >> secondTest;
    cout << "Enter " << studentName << "'s third test grade: ";
    cin >> thirdTest;
    cout << endl;

    total = firstTest + secondTest + thirdTest;
    cout << studentName << " has a total of " << total << endl;
    percentage = (firstTest + secondTest + thirdTest) / 3;
    cout << studentName << " has a percentage of " << percentage << " %" << endl;
    cout << endl;
    return 0;
}
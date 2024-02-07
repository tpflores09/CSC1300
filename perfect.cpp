/* File name: perfect/lab6
   author: Tania Perdomo Flores
   Date: 10-20-2022
   Purpose: Create a program to list the perfect squares between two numbers supplied in a text file
   */
// all functions and libraries

#include "perfect.h"
#include <iostream>


void findPerfect (int lower, int upper, string filename);

int main()
{
    ofstream outfile;
    outfile.open ("perfect.txt");
    outfile << "Below are the perfect numbers between 1 and 20: " << endl;
    for (int i = lower; i <= upper; i++){
        if (isPerfect(i)){
            outfile << i << endl;
        }
    }
    outfile.close();
}

bool isPerfect(long long x){
    if (x>=0){
        long long y = sqrt(x);
        return (y * y == x);
    }

    return (false);
}
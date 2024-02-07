/* File name: perfect/lab6
   author: Tania Perdomo Flores
   Date: 10-20-2022
   Purpose: Create a program to list the perfect squares between two numbers supplied in a text file
   */
// only main function

#include "perfect.h"

int main()
{
    ifstream infile;
    string filename;
    int lower;
    int upper;
    infile.open("range.txt");
    cout << "What is the name of the file that you want the perfect square numbers to be printed to? ";
    cin >> filename;

    if (!infile){
        cout << "File not found..." << endl;
        cout << "Ending program." << endl;
        return 0;
    }

    infile >> lower;
    infile >> upper;
    infile.close();
    findPerfect (lower, upper, filename);
    cout << "Perfect Square numbers from " << lower << " to " << upper << "have been printed to " << filename << "." << endl;
    
    return 0;

}

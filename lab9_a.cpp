/* Author: Tania Perdomo FLores
   Date: 11/17/22
   Purpose: Write a program that will determine how many turkey necks should be saved
   based on the number of rednecks in a neighborhood*/


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void enterData(int *rednecks, int houses);
int findMax(int *maxRednecks, int houses);
int findTotal(int *rednecks, int houses);

int main (){
    int *rednecks;
    int houses;
    int total;
    int turkeys = (total*2);
    int maxRednecks;
    int maxHouses;

    cout << "How many houses are in your neighborhood?: ";
    cin >> houses;
    
    rednecks = new int[houses];
    
    enterData(rednecks, houses);
    maxRednecks = findMax(rednecks, houses);
    total = findTotal(rednecks, houses);
    
    cout << "There are " << total << " rednecks like cousin Eddie in the neighboorhood and so " << total * 2 << " turkey necks should be saved." << endl;
    cout << "The house with the most rednecks is house " << houses << " with " << maxRednecks << " rednecks." << endl;
    cout << endl;
    
    delete [] rednecks;
    
    cout << "If that thing had " << maxRednecks << " lives, she just spent 'em all." << endl;

    return 0;
}
void enterData(int *rednecks, int houses){
    cout << "Enter the number of rednecks for each house: " << endl;
    for (int i = 0; i < houses; i++){
        cout << "House " << i + 1 << ":";
        cin >> rednecks [i];
    }
}
int findMax(int *rednecks, int houses){
    int maxRednecks = 0;
    for (int i = 0; i < houses; i++){
        if (maxRednecks < *(rednecks + i)){
            maxRednecks = *(rednecks + i);
        }
    } 
    return maxRednecks;
}
int findTotal (int *rednecks, int houses){
    int total = 0;
    for (int i = 0; i < houses; i++){
        total += rednecks[i];
    }
    return total;
}

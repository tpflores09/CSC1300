/* Author: Tania Perdomo Flores
    Date: 11/27/2022
    Purpose: write a program for a Magical Creatures zookeeper to keep track of the creatures cared for by the zoo.  
    Information about each creature will be kept and manipulated in this program. 
    At the start of the program, the user can specify the maximum capacity of the zoo.  
    The user should then be able to load magical creature information from any file he or she chooses, 
    add creatures manually, delete a creature, print creature information to either a file or to the screen, or 
    print a cost analysis of each creature and the total cost to house and take care of these creatures. */
// function prototypes

#ifndef TEPERDOMOF42_PROG4_H
#define TEPERDOMOF42_PROG4_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

struct Cost {
    double hours;
    double cost;
    double food;
    double supplies;
};
struct Creatures{
    string creature;
    string description;
    double length;
    double height;
    string origin;
    bool danger;
    Cost cost;
};

int enterCreatures(int, int, Creatures*);
int deleteCreatures(int, Creatures*);
bool moveArrayElement(string, int , Creatures*);
void printCreatures(int, Creatures*);
void printStatistics(int, Creatures*);
void saveCreaturesToFile(int, Creatures*);

#endif
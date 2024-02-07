/************************************************************************
 *                                                                       *
 *     Title: Program 1 Assignment - Coral Reefs                         *
 *     File Name: teperdomof42_prog1.cpp                                 *
 *     Author: Tania Perdomo Flores                                      *
 *     Date: 9-14-2022                                                   *
 *     Description: This program will measure the growth rate of coral   *
 *     reefs, destruction rate of the Earth’s Coral Reefs and also       *
 *     measure the available Coral Fish & Mollusks for human consumption.*
 *                                                                       *
 ************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;
 
int main()
{
    /*variable definitions*/
    double coralReefDestructionRate;
    int startingYear = 2022;
    double growthRateMmYr;
    growthRateMmYr = 45.0;
    double growthRateInc;
    double animalPopulation;
    animalPopulation = 500000000;
    double animalDestructionRate;

	
    cout << "                      <<" << endl;
    cout << "                     <<<<" << endl;
    cout << "<<<                 <<<<<" << endl;
    cout << "<<<<               <<<<<<<" << endl;
    cout << "<<<<<<<<        <<<<<<<<<<<<<<" << endl;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< " << endl;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<O<<<<<" << endl;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "<<<<<<<<            <<<<<<<<  " << endl;
    cout << "<<<<<                  <<<<<< " << endl;
    cout << "<<<                      <<<< " << endl;  //output multiple lines to display a fish, this is a coral reef shark.
    
    cout << "\nCoral reefs contain fish and mollusks that feed around 500 million people each year. However, because of the rising seawater temperature due to climate change, ocean acidity level, and destructive fishing methods, the number of animals available for human consumption is decreasing." << endl;
   
    cout << "\nThe average growth rate for coral under favorable conditions (high light exposure, consistent temperature, moderate wave action), is 45 mm a year. However, there is now a destruction rate due to pollution and over-population." << endl; //output the description of the program to the screen
	
    cout << "\nDestruction rates estimate between .01 mm/year and 9.0 mm/year." << endl;
    cout << "What is the destruction rate of the coral? " << endl;
    cout << "(Between .01 and 9.0): ";
    cin >> coralReefDestructionRate;  //ask user for destruction rate of coral and input into a variable
    
    cout << "\nYear    Growth (mm/year)   Growth (in/year)   Fish and Mollusks" << endl; //print out header row
    cout << endl;
	cout << "                                                500,000,000.00   " << endl; //print out beginning mollusk/fish population under the Fish & Mullosks column
    cout << endl;
    while (animalPopulation > 0)
    {
        growthRateMmYr = growthRateMmYr - coralReefDestructionRate; //calculate growth rate in milimeters, 45.0 mm/yr
       
        cout << startingYear; //output the year
        
        cout << setw(16) << fixed << setprecision(2) << growthRateMmYr; //output growth rate in milimeters
    
		growthRateInc = growthRateMmYr * .0393700787; //calculate growth rate in inches, 1mm =.0393700787 inch
		
        cout << setw(18) << fixed << setprecision(2) << growthRateInc; //output growth rate in inches

        animalDestructionRate = coralReefDestructionRate / growthRateMmYr * animalPopulation; //calculate animal destruction rate

        animalPopulation = animalPopulation - animalDestructionRate; //calculate animal population
        cout << setw(24) << fixed << setprecision(2) << animalPopulation << endl; //output animal population
 
        startingYear = startingYear + 1; //add 1 to the current year (increment year)
        cout << endl;
    }	
    
    cout << "\nThere will not be enough fish or mollusks left in the coral reefs to feed anyone in year " << startingYear << " and the Coral Reefs will only be growing by a rate of " << growthRateInc << " inches per year by this date." << endl; /*output the results*/
    return 0;

}
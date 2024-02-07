/*
	Filename:  lab9_b.cpp
	Author: April Crockett, modified by Tania Perdomo Flores!!!
	Date: 11/17/2022
	Purpose: practice with structures, pointers, and dynamic memory allocation
*/
#include <iostream>
using namespace std;

//structure declarations
struct Child
{
	string name;
	int age;
	int numOffences; //multiply number of offences by 4 to get percent naughty.  max number of offences is 25	
	double naughty; //percent the child is naughty
	string *offenceDescArr;//array with description of child's offence
};

//function prototypes
void enterData(string elfName, Child *arr, int size);
void printResults(Child* arr, int size);

int main()
{
	//variable definitions
	int numChildren;
	Child* childArray;
	string elfName;
	
	//begin program
	cout << "\nHello cute elf!  What is your name? ";
	getline(cin, elfName);
	
	cout << elfName << " Elf, how many children are on Santa's list? ";
	cin >> numChildren; //this will be the size of our Child array!
	
	//validate user input to make sure number of children is 1 or more
	while(numChildren < 0)
	{
		cout << "\nThe number of children must be greater than zero.\n";
		cout << elfName << " Elf, how many children are on Santa's list? ";
		cin >> numChildren;
	}
	
	cin.ignore();
	
	//dynamically allocate Child array based on number of children
	childArray = new Child[numChildren];
	
	//get data from user to fill in array elements
	enterData(elfName, childArray, numChildren);
	
	//print the results
	printResults(childArray, numChildren);
	
	//release dynamically allocated arrays
	for(int i=0; i<numChildren; i++)
	{
		delete [] childArray[i].offenceDescArr;
	}
	delete [] childArray;
	
	return 0;
}

/*
	Function: 	enterData
	Parameters: name of the elf (a string), array of Child structure 
				elements and the size of this array
	Returns: 	none
	Purpose:  	Allow the user to enter in all the details about each child
				including child name, age, # offences, description of those offences, 
				and calculate the child's naughtiness percentage.  Store
				this information into each Child element of the array.
*/
void enterData(string elfName, Child* arr, int size)
{
	string line(50, '-');
	
	cout << line;
	cout << endl << elfName << " Elf, enter in the child data.\n";
	
	for(int i=0; i<size; i++)
	{
		cout << "\n******CHILD " << i+1 << ":\n";
		cout << "NAME: ";
		getline(cin, arr[i].name);
		
		cout << "AGE: ";
		cin >> arr[i].age;
		//validate child's age
		while(arr[i].age < 0 || arr[i].age > 17)
		{
			cout << "The person must be a child between 0 to 17.\n";
			cout << "AGE: ";
			cin >> arr[i].age;
		}
		
		cout << "# OFFENSES: ";
		cin >> arr[i].numOffences;
		//validate number of offences
		while(arr[i].numOffences < 0 || arr[i].numOffences > 25)
		{
			cout << "There is just no way a child could be "
					"that monsterous.\nNumber of offences must be "
					"between 0 and 25.\n";
			cout << "# OFFENSES: ";
			cin >> arr[i].numOffences;
		}
		
		//calculate % naughty by multiplying # offences by 4
		arr[i].naughty = arr[i].numOffences * 4;
		cin.ignore();
		
		//dynamically allocate string array
		arr[i].offenceDescArr = new string[arr[i].numOffences];
		
		//allow user to enter in individual offense description(s)
		cout << "\nWhat all has " << arr[i].name << " done wrong?\n";
		
		for(int j=0; j<arr[i].numOffences; j++)
		{
			cout << "\tOffence # " << j+1 << " - ";
			getline(cin, arr[i].offenceDescArr[j]); //read into string array
		}	
	}
	cout << line;
}

/*
	Function: 	printResults
	Arguments:  array of Child structure elements and the size of this array
	Returns: 	none
	Purpose:  	Find the child that had the most offences in the array and then
				print the details about the child.
*/
void printResults(Child* arr, int size)
{
	//which child has the most offences?
	int maxIndex = 0;
	for(int i=1; i<size; i++)
	{
		if(arr[i].numOffences > arr[maxIndex].numOffences)
			maxIndex = i;
	}
	
	cout << "\n\nNAUGHTIEST CHILD IN WORLD:\n\n";
	cout << arr[maxIndex].name << ", a " << arr[maxIndex].age;
	cout << "-year-old child, is " << arr[maxIndex].naughty << "% naughty ";
	cout << "having " << arr[maxIndex].numOffences << " offences as follows:\n";
	
	for(int j=0; j < arr[maxIndex].numOffences; j++)
	{
		cout << "\t" << j+1 << ". " << arr[maxIndex].offenceDescArr[j] << endl;
	}	
}




/* Author: Tania Perdomo Flores
    Date: 11/27/2022
    Purpose: write a program for a Magical Creatures zookeeper to keep track of the creatures cared for by the zoo.  
    Information about each creature will be kept and manipulated in this program. 
    At the start of the program, the user can specify the maximum capacity of the zoo.  
    The user should then be able to load magical creature information from any file he or she chooses, 
    add creatures manually, delete a creature, print creature information to either a file or to the screen, or 
    print a cost analysis of each creature and the total cost to house and take care of these creatures. */
// contains main function

#include "teperdomof42_prog4.h"

int main (){
    int choice;
    int currCreatures = 0;
    int capacity;
    Creatures *creaturesArray;

    cout << "What is the capacity of your magical creature zoo?: ";
    cin >> capacity;
    creaturesArray = new Creatures[capacity];

    do {
        cout << "What would you like to do?" << endl;
        cout << "1. Enter some Magical Creatures." << endl;
        cout << "2. Delete a Magical Creature." << endl;
        cout << "3. List/Print Creatures." << endl;
        cout << "4. Print Creature Costs." << endl;
        cout << "5. End Program." << endl;
        cout << "Choice: ";
        cin >> choice;
        while (choice < 1 || choice > 5){
            cout << "Invalid choice. Choose 1 through 5." << endl;
            cout << "Choice: ";
            cin >> choice;
        }
        switch (choice){
            case 1: 
            currCreatures = enterCreatures(capacity, currCreatures, creaturesArray);
            cout << endl;
            break;
            case 2:
            if (currCreatures == 0){
                cout << "There are no creatures in the zoo." << endl;
                cout << endl;
            }else {
                currCreatures = deleteCreatures(currCreatures, creaturesArray);
                cout << endl;
            }
            break;
            case 3:
            if (currCreatures == 0){
                cout << "There are no creatures in the zoo." << endl;
                cout << endl;
            }else {
                printCreatures(currCreatures, creaturesArray);
                cout << endl;
            }
            break;
            case 4: 
            if (currCreatures == 0){
                cout << "There are no creatures in the zoo." << endl;
                cout << endl;
            }else {
                printStatistics(currCreatures, creaturesArray);
                cout << endl;
            }
            break;
            case 5:
            if(currCreatures == 0)
            {
                cout << "no more creatures in this zoo.\n";
                cout << "Bye";
            }
            else
            {
                saveCreaturesToFile(currCreatures, creaturesArray);
            }
        }
    } while (choice != 5);
    delete []creaturesArray;
    return 0;
} 
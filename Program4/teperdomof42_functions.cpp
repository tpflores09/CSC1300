/* Author: Tania Perdomo Flores
    Date: 11/27/2022
    Purpose: write a program for a Magical Creatures zookeeper to keep track of the creatures cared for by the zoo.  
    Information about each creature will be kept and manipulated in this program. 
    At the start of the program, the user can specify the maximum capacity of the zoo.  
    The user should then be able to load magical creature information from any file he or she chooses, 
    add creatures manually, delete a creature, print creature information to either a file or to the screen, or 
    print a cost analysis of each creature and the total cost to house and take care of these creatures. */
// all other functions

#include "teperdomof42_prog4.h"

int enterCreatures(int capacity, int currCreatures, Creatures* creaturesArray){
    int choice;
    string data;
    char danger = 'Y';
    char again = 'Y';
    string filename;
    fstream file;

    do 
    {
        cout << endl;
        cout << "What do you want to do? " << endl;
        cout << "1. Load my creatures from a file." << endl;
        cout << "2. Enter one creature manually." << endl;
        cout << "Choose 1 or 2." << endl;
        cout << "Choice: ";
        cin >> choice;

        while (choice < 0 || choice > 2)
        {
            cout << "Your choice was invalid. Choose a number 1 through 2." << endl;
            cout << "Choice: ";
            cin >> choice;
        }
        switch (choice)
        {
            case 1:
            cout << "What is the name of the file with your list of creatures? (ex. filename.txt)" << endl;
            cout << "Filename: ";
            cin >> filename;
            file.open(filename);
            if (file.is_open()){
                for (int i = currCreatures; i < capacity; i++){
                    getline (file, creaturesArray[i].creature, '#');
                    getline (file, creaturesArray[i].description, '#');
                    getline (file, data, '#');
                    creaturesArray[i].length = stod(data);
                    getline (file, data, '#');
                    creaturesArray[i].height = stod (data);
                    getline (file, creaturesArray[i].origin, '#');
                    getline (file, data, '#');
                    creaturesArray[i].danger = stod (data);
                    getline (file, data, '#');
                    creaturesArray[i].cost.hours = stod (data);
                    getline (file, data, '#');
                    creaturesArray[i].cost.cost = stod (data);
                    getline (file, data, '#');
                    creaturesArray[i].cost.food = stod (data);
                    getline (file, data, '#');
                    creaturesArray[i].cost.supplies = stod (data);
                    getline (file, data, '#');
                    if (creaturesArray[i].creature == ""){
                        break;
                    }
                }
                cout << endl;
                cout << "All creatures from " << filename << " have been added to the program. " << endl;
            } else {
                cout << filename << " does not exist or is corrupt. Sorry, cannot load creatures." << endl;
            }
            file.close();
            break;
            case 2:
            do
            {
                if ((capacity = currCreatures)){
                    cout << "You are now at maximum capacity of " << currCreatures << " in your zoo. " << endl;
                    break;
                }
                cout << endl;
                cout << "Name: ";
                cin.ignore();
                getline (cin, creaturesArray[currCreatures].creature);
                cout << "Description: ";
                getline (cin, creaturesArray[currCreatures].description);
                cout << "Average length (in feet): ";
                cin >> creaturesArray[currCreatures].length;
                cout << "Average height: ";
                cin >> creaturesArray[currCreatures].height;
                cout << "Location/Origin: ";
                cin.ignore();
                getline (cin, creaturesArray[currCreatures].origin);
                cout << "Is it a dangerous creature? (Y or N): ";
                cin >> danger;
                if (danger == 'Y'){
                    creaturesArray[currCreatures].danger = true;
                } else if (danger == 'N'){
                    creaturesArray[currCreatures].danger = false;
                }
                cout << "How many hours do you spend caring for " << creaturesArray[currCreatures].creature << "?" << endl;
                cout << "Hours: ";
                cin >> creaturesArray[currCreatures].cost.hours;
                cin.ignore();
                cout << endl;
                cout << "What is the cost per hour for caring for " << creaturesArray[currCreatures].creature << "?" << endl;
                cout << "Cost per hour: ";
                cin >> creaturesArray[currCreatures].cost.cost;
                cin.ignore();
                cout << "\nHow much money do you spend on food for the " << creaturesArray[currCreatures].creature << "?" << endl;
                cout << "Food Cost: ";
                cin >> creaturesArray[currCreatures].cost.food;
                cin.ignore();
                cout << "How much money do you spend on food/supplies for " << creaturesArray[currCreatures].creature << "?" << endl;
                cout << "Supplies cost: ";
                cin >> creaturesArray[currCreatures].cost.supplies;
                cin.ignore();
                cout << endl;
                cout << "The " << creaturesArray[currCreatures].creature << " has been added. " << endl;
                cout << endl;
                cout << "Want to add more creatures? (Y or N): ";
                cin >> again;
                cin.ignore();

                currCreatures++;
            }while (again != 'N');
                break;
        } 

    } while (choice != 2);
    return currCreatures;
}
int deleteCreatures(int currCreatures, Creatures* creaturesArray){
    string data;
    cout << "The following is a list of all the creatures you take care of: " << endl;
    for (int i = 0; i < currCreatures; i++){
        cout << creaturesArray[i].creature << endl;
    }
    cout << endl;
    cout << "What creature do you wish to remove?: " << endl;
    cout << "Creature: ";
    cin.ignore();
    getline(cin, data);

    if (moveArrayElement(data, currCreatures, creaturesArray)){
        currCreatures--;
        cout << "You have removed " << data << "." << endl;
    }
    return currCreatures;
}
bool moveArrayElement(string data, int currCreatures, Creatures* creaturesArray){
    for (int j = 0; j < currCreatures; j++){
        if (creaturesArray[j].creature == data){
            for (int k = j; k < currCreatures; k++){
                creaturesArray[k] = creaturesArray[k+1];
            }
            return true;
        }
    }
    return false;
}
void printCreatures(int currCreatures, Creatures* creaturesArray){
    string filename;

    for (int i = 0; i < currCreatures; i++){
        cout << " ---------------------------------------- " << endl;
        cout << "Creature: " << (i+1) << endl;
        cout << "Name: " << creaturesArray[i].creature << endl;
        cout << "Description: " << creaturesArray[i].description << endl;
        cout << "Dangerous: ";
        if (creaturesArray[i].danger == true){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        cout << fixed;
        cout << endl;
        cout << "Hours to care for Creature: " << creaturesArray[i].cost.hours << endl;
        cout << "Cost per hour for taking care of Creature: " << creaturesArray[i].cost.cost << endl;
        cout << "Cost to feed creature: $" << creaturesArray[i].cost.food << endl;
        cout << "Supplies cost: $" << creaturesArray[i].cost.supplies << endl;
    }
}
void printStatistics (int currCreatures, Creatures* creaturesArray){
    float cost = 0;
    float totalCost = 0;
    
    cout << "Cost of each vehicle: " << endl;
    cout << setw(20) << left << "Vehicle" << setw(16) << right << "Cost" << endl;

    for (int i = 0; i < currCreatures; i++){
        cout << fixed;
        cout << setprecision(2);
        cost = (creaturesArray[i].cost.hours + creaturesArray[i].cost.cost + creaturesArray[i].cost.food + creaturesArray[i].cost.supplies);
        cout << setw(20) << left << creaturesArray[i].creature << "$ " << setw(15) << right << cost << endl;
        totalCost += cost;
    }
    cout << "Total Cost: " << "$" << setw(15) << totalCost << endl;
    cout << endl;
    cout << endl;
}
void saveCreaturesToFile(int currCreatures, Creatures* creaturesArray){
    char choice;
    
    ofstream outfile;
    string filename;
    
    cout << "Would you like to save your creature list to a file? (Y or N)";
    cin >> choice;

    cout << "What is the name of the file you want to save your creatures to? ";
    getline (cin, filename);
    outfile.open(filename);
    if (outfile.is_open()){
        for (int i = 0; i < currCreatures; i++){
            outfile << creaturesArray[i].creature;
            outfile << "#";
            outfile << creaturesArray[i].description;
            outfile << "#";
            outfile << creaturesArray[i].danger;
            outfile << "#";
            outfile << creaturesArray[i].cost.cost;
            outfile << "#";
            outfile << creaturesArray[i].cost.food;
            outfile << "#";
            outfile << creaturesArray[i].cost.hours;
            outfile << "#";
            outfile << creaturesArray[i].cost.supplies;
            outfile << "#";
        }
        cout << "Creatures were successfully saved to the " << filename << endl;
    } else {
        cout << "File does not exist." << endl;
    }
}
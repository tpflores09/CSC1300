#include <iostream>
#include <string>

using namespace std;
double findHighest (doubbke)

int main (){
    const int SIZE = 3;
    string names [SIZE];
    double price [SIZE];
    int findHighest([]);
    int index;
    int findLowest([]);


    cout << "Tell me 10 useful things and their price: " << endl;
    
    for (int i=0; i < SIZE; i++){
        cout << "USEFUL THING " << i+1 << ": ";
        getline(cin, names[i]);
        cout << "PRIZE FOR THING " << i+1 << ": ";
        cin >> price[i];
        cout << endl;
        cin.ignore();
    }

    cout << "Your list of useful items include: " << endl;

    for (int i=0; i < SIZE; i++){
        cout << names[i] << ", $" << price[i] << endl;

    }
    
    int highIndex = findHighest(price);
    int lowIndex = findLowest(price);
    double avg = findAverage(price);
    cout << "Results: ";
    cout << "Highest Price: " << name[highIndex] << " with price " << price[highIndex] << endl;
    cout << "Lowest Price: " << name [lowIndex] << " with price " << price [lowIndex] << endl;
    cout << "Average: $" << avg;
    cout << highIndex;
    
    return 0;

}

int findHighest(double price []){
    int index; 

    for (int i=1; i < SIZE: i++){
        if (price[i] > price [index]){
            index = [i];
        }
    }
    return index;
} 
int findLowest(double price []){
    int index; 

    for (int i=1; i < SIZE: i++){
        if (price[i] > price [index]){
            index = [i];
        }
    }
    return index;
} 
double findAverage(double price[]){
    double total = 0.0;
    for (int i=0; i< SIZE; i++){
        total += price[i];
    }
    return total/SIZE
}
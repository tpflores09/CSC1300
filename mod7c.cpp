#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

bool luckyGuess(int);
void getUserData(string, string, int);


int main () {
    
    srand(time(0));
    string name;
    string food;
    int favNum;

    getUserData(name, food, favNum);


    if (luckyGuess(favNum)){
        favNum = true;
        cout << name << " you will get a lifetime supply of " << food << "!" << endl;
    } else {
      cout <<"Sorry, no food" << endl;
    }
    

    return 0;

}
void getUserData(string& name, string& food, int& num){
    cout << "Name?: ";
    getline(cin,name);
    cout << "Favorite food: ";
    getline(cin, food);
    cout << "Favorite number: ";
    cin >> num;
}

bool luckyGuess(int num){
    bool guess;

    int randNum = rand()%100+1;
    
    if(num >= (randNum-25) && num <= (randNum+25)){
        guess = true;
    }
    else {
        guess = false;
    }
    return luckyGuess;
}
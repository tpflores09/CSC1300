#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
    string name2 = "Friend";
    char name1[30] = "Tania";

    cout << "name1: " << name1 << endl;
    cout << "name2: " << name2 << endl;

    cout << "What is your full name?: ";
    cin.getline (name1, 30);

    cout << "What is your friend's full name?: ";
    getline (cin, name2);
    
    cout << "name1: " << name1 << endl;
    cout << "name2: " << name2 << endl;

    strcpy(name1, "SCOUT");
    name2 = "JACK";
    for (int i = 0; i < strlen(name1); i++){
        cout << name1[i] << "*";
    }
    cout << endl;

    for (int i = 0; i < 4; i++){
        cout << name2[i] << "*";
    }


    return 0;
}
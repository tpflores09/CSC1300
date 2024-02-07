#include <iostream>
#include <string>
using namespace std;

const int SIZE = 3;

struct Phone {
    string phoneType;
    string color;
    double capacity;
};

void addPhone (Phone *);
void printArray (Phone *);

int main () 
{
    Phone *phones;
    phones = new Phone [SIZE];
    addPhone(phones);
    printArray(phones);
    delete [] phones;


    return 0;
}

void addPhone (Phone *phone){
    for (int i = 0; i < SIZE; i++){
        cout << "PHONE " << i + 1 << endl;
        cout << "Phone Type: ";
        getline (cin, phone[i].phoneType);
        cout << "Phone color: ";
        getline (cin, phone[i].color);
        cout << "Phone Capacity: ";
        cin >> phone[i].capacity;
        cin.ignore();
    }
}

void printArray(Phone *phone){
    for (int i = 0; i < SIZE; i++){
        cout << "Phone: " << phone[i].phoneType << endl;
        cout << "Color: " << phone[i].color << endl;
        cout << "Capacity: " << phone[i].capacity << endl;
    }

}

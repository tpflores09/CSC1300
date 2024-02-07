/* Tania Perdomo Flores 
   Lab5.cpp */


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () 
{
    ofstream outfile;
    const double SPAG = 20.00;
    const double CHEES = 15.00;
    const double SAL = 10.00;
    string name;
    int numCustomers;
    int customerNum;
    int i;
    int choice;
    double amount;
    int num;
    double total;
    cout << fixed << setprecision(2);

    outfile.open("restaurant.txt");
    outfile << fixed << setprecision (2);

    cout << "How many customers are ordering?: ";
    cin >> numCustomers;
    while (numCustomers <= 0){
    cout << "The number of customers must be greater than zero." << endl;
    cout << "How many customers are ordering?: ";
    cin >> numCustomers;
    }
    for (i = 1; i <= numCustomers; i++){
        amount = 0.00;
        cout << "Customer number " << i << " , what is your name?: ";
        cin.ignore();
        getline(cin,name);
        cout << name << " ,welcome to The Phantom Carriage Restaurant!" << endl; 
    
        do {
            cout << name << ", choose one of the following options: " << endl;
            cout << "1 - Spaghetti" << endl;
            cout << "2 - Cheesecake" << endl;
            cout << "3 - Salad" << endl;
            cout << "4 - Done ordering" << endl;
            cout << "CHOICE: " << choice << endl;
            cin >> choice;
            cout << endl;
            while (choice <= 0 || choice >= 5){
                cout << "Oops. That is not a valid choice. Choose 1-4";
                cout << "Choice: " << choice;
                cin >> choice;
            }
            switch (choice) {
                case 1 : choice = 1;
                    cout << "How many spaghetti dinners do you want to order?: ";
                    cin >> num;
                    cout << endl;
                    amount = amount + (num * SPAG);
                    cout << num << " spaghetti dinners were added and the total for the customer is now $ " << amount << endl; 
                    break;
                case 2 : choice = 2;
                    cout << "How many cheesecake dinners do you want to order?: ";
                    cin >> num;
                    amount = amount + (num * CHEES);
                    cout << num << " cheesecake dinners were added and the total for the customer is now $ " << amount << endl;
                    break;
                case 3 : choice = 3;
                    cout << "How many salad dinners do you want to order?: ";
                    cin >> num;
                    cout << endl;
                    amount = amount + (num * SAL);
                    cout << num << " salad dinners were added and the total for the customer is now $ " << amount << endl; 
                    break;
                case 4: choice = 4;
                    cout << name << " total for your order is $" << amount << endl;
                    outfile << name << " , total for your order is $" << amount << endl;
                    break;
            }

        } while (choice != 4);
            total = total + amount;
    }
    cout << "-----------------------------------------------------" << endl;
    cout << "The total received from all customers is $" << total;
    outfile << "---------------------------------------------------" << endl;
    outfile << "The total received from all customers is $" << total;
    outfile.close();

     return 0;
        
}

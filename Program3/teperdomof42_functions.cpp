/* Author: Tania Perdomo Flores
   Date: 11-6-2022*/
// contains all other functions
#include "teperdomof42_prog3.h"

void getProfit (double profit[]){
    for (i = 0; i < 12; i++){
        cout << "Welcome to Flourish and Blotts Bookstore!" << endl;
        cout << "Enter the profit for month" << i + 1 << ":";
        cin >> profit[i];
        while (profit [i]< 0){
            cout << "You must enter a profit greater than zero" << endl;
            cout << "Enter the profit for month" << i + 1 << ":";
            cin >> profit[i];
        }
    }
}
double getTotal(double profit[]){
    double total = 0.00;
    for (int i = 0; i < 12; i++){
        total += profit[i];
    }
    return total;
}
double getMax(double profit[], int size, string &maxMonth, string month[]){
    double maxProfit = profit [0];
    maxMonth = month[0];
    for (int months = 0; months < 12; months++){
        if (profit [months] > maxProfit){
            maxMonth = month [months];
            maxProfit = profit [months];
        }
    }
    return maxProfit;
}
double getMin(double profit, int size, string &minMonth, string month[]){
    double minProfit = profit [0];
    minMonth = month[0];
    for (int months = 0; months < 12; months++){
        if (profit[months] < minProfit){
            minMonth = month[months];
            minProfit = profit[months];
        }
    }
    return minProfit;
}
void getQuarterly(double quarterly[], double profit[]){
    for (int i = 0; i < 4; i++){
        quarterly[i] = 0.00;
    }
    for (int i = 0; i < 3; i++){
        quarterly[0] += profit[i];
    }
    for (int i = 3; i < 6; i++){
        quarterly[1] += profit[i];
    }
    for (int i = 6; i < 9; i++){
        quarterly[2] += profit[i];
    }
    for (int i = 9; i < 12; i++){
        quarterly[3] += profit[i];
    }
}
void printResults(double total, double quartely [], double maxProfit, double minProfit, double average, string maxMonth, string minMonth){
    char filename[100];
    cout << "What is the anme of the file you wish to print to?: ";
    cin >> filename;
    string file = filename;
    ofstream outfile;
    outfile.open(file);
    if (!outfile){
        cout << "File not found..." << endl;
        cout << "Ending program." << endl;
        return 0;
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "     TOTAL PROFITS FOR YEAR:        $" << total << endl;
    average = total / 12.0;
    cout << "      YEARLY AVERAGE PROFIT:        $" << average << endl;
    cout << "  MONTH WITH LARGEST PROFIT:         " << maxMonth << " totaling $" << getMax << endl;
    cout << " MONTH WITH SMALLEST PROFIT:         " << minMonth << " totaling $" << getMin << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "               QUARTERLY  PROFITS" << endl;
    cout << "       January - March         $" << quarterly[0] << endl;
    cout << "          April - June         $" << quarterly[1] << endl;
    cout << "      July - September         $" << quarterly[2] << endl;
    cout << "    October - December         $" << quarterly[3] << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    
    
    outfile << "--------------------------------------------------------------------------" << endl;
    outfile << "--------------------------------------------------------------------------" << endl;
    outfile << "     TOTAL PROFITS FOR YEAR:        $" << total << endl;
    average = total / 12.0;
    outfile << "      YEARLY AVERAGE PROFIT:        $" << average << endl;
    outfile << "  MONTH WITH LARGEST PROFIT:         " << maxMonth << " totaling $" << getMax << endl;
    outfile << " MONTH WITH SMALLEST PROFIT:         " << minMonth << " totaling $" << getMin << endl;
    outfile << "--------------------------------------------------------------------------------" << endl;
    outfile << endl;
    outfile << "               QUARTERLY  PROFITS" << endl;
    outfile << "       January - March         $" << quarterly[0] << endl;
    outfile << "          April - June         $" << quarterly[1] << endl;
    outfile << "      July - September         $" << quarterly[2] << endl;
    outfile << "    October - December         $" << quarterly[3] << endl;
    outfile << "--------------------------------------------------------------------------------" << endl;
    outfile << "--------------------------------------------------------------------------------" << endl;

    outfile.close();
}

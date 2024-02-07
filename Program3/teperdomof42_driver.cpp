/* Author: Tania Perdomo Flores
   Date: 11-6-2022
   Purpose: Foruli Flourish and Balbus Blotts owns a popular bookstore on Diagon Alley called Flourish & Blotts Bookstore.  
   They would like to know how the store profited last year.  They want to know the total profits, average profit per month, 
   the most profitable month, the least profitable month, and also the quarterly profits.  
   They would like their results to be printed to the screen, but also to a text file that they get to name themselves. */

// contains main function

#include "teperdomof42_prog3.h"

int main (){
    char response;
    ofstream outfile;
    int size = 12;
    string maxMonth;
    string minMonth;
    string month[size] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    double profit[size];
    double total;
    double maxProfit;
    double minProfit;
    double quarterly[4];
    double total;
    double average;
    cout << fixed << setprecision(2);

    do{
        getProfit (profit);
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        total = getTotal (profit);
        maxProfit = getMax(profit, size, maxMonth, month);
        minProfit = getMin(profit, size, maxMonth, month);
        cout << "--------------------------------------------------------------------------" << endl;
        getQuarterly(quarterly, profit);
        printResults(total, quarterly, maxProfit, minProfit, average, maxMonth, minMonth);
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "Would you like to run the program again? (Y/N): ";
        cin >> response;
        cout << endl;
    } while (response == "Y" || response == "y");
}





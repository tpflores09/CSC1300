#include <iostream> 
using namespace std;

int main(){
    double x  = 7.25;
    double * intptr = &x;
    cout << "The value of num is " << *intptr;

    return 0;
}
#include <iostream>
using namespace std;

int main(){
    int x, y, add=0;
    int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    string day[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    cin >> x >> y;

    for(int i=0; i<x-1; i++){
        add += month_days[i];
    }
    
    add += y;

    cout << day[(add-1)%7] <<"\n";

    return 0;
}
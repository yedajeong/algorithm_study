#include <iostream>
using namespace std;

int main(){
    string A, B, C, D;

    cin >> A >> B >> C >> D;

    unsigned long long AB = stoull(A+B); // string to unsigned long long
    unsigned long long CD = stoull(C+D);

    cout << AB+CD << "\n";

    return 0;
}

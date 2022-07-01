#include <iostream>
#include <string>
using namespace std;

int main(){
    int T, split;
    string input;

    cin >> T;

    for (int i=0; i<T; i++){
        cin >> input;
        split = input.find(',');
        int A = stoi(input.substr(0, split));
        int B = stoi(input.substr(split+1));
        cout << A+B << endl;
    }

    return 0;
}

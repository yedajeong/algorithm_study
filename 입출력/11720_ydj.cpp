#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, result=0;
    string input;

    cin >> N;
    cin >> input;
    
    for(int i=0; i<N; i++)
        result += stoi(input.substr(i, 1));

    cout << result << endl;

    return 0;
}
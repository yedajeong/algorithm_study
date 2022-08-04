#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int B, exp=0;
    string N;
    long long result = 0;

    cin >> N >> B;

    for (int i=N.size()-1; i>=0; i--){
        if (N[i] >= 'A' && N[i] <= 'Z'){//A~Z
            result += (int(N[i]) - 55) * pow(B, exp); // A=10, B=11, ..., Z=35
        } 
        else
            result += (int(N[i]) - 48) * pow(B, exp);

        exp++;    
    }

    cout << result << "\n";

    return 0;
}

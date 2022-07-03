#include <iostream>
using namespace std;

int main(){
    int count[1000];
    int n;
    cin >> n;

    count[1] = 1%10007; //2x1
    count[2] = 3%10007; //2x2

    for (int i=3; i<=n; i++){
        count[i] = (count[i-1] + 2*count[i-2])%10007;
    }
    
    cout << count[n] << "\n";

    return 0;
}
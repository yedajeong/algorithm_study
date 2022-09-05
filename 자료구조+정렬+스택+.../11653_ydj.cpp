#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N;

    cin >> N;

    int div = 2;
    
    for(int i=2; i<=N; i++){
        while(N%i == 0){
            cout << i << "\n";
            N /= i;
        }
    }

    return 0;
}

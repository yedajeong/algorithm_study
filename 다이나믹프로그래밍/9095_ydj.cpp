#include <iostream>
using namespace std;

int main(){
    int T, n;
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> n;
        int count[1000] = {0};
        count[1] = 1; //1
        count[2] = 2; //1+1, 2
        count[3] = 4; //1+1+1, 1+2, 2+1, 3

        for(int j=4; j<=n; j++)
            count[j] = count[j-1] + count[j-2] + count[j-3];

        cout << count[n] <<"\n";
    }

    return 0;
}
#include <iostream>
using namespace std;

int main(){
    int N, min, max;

    cin >> N;

    int input[N];

    for (int i=0; i<N; i++)
        cin >> input[i];

    min = input[0];
    max = input[0];

    for (int i=1; i<N; i++){
        if (input[i] < min)
            min = input[i];
        
        if (input[i] > max)
            max = input[i];
    }

    cout << min << " " << max << "\n";

    return 0;
}
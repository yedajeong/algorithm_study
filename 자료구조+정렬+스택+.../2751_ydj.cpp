#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;

    cin >> N;

    short arr[10001] = {0};
    short item;
    for (int i=1; i<=N; i++){
        cin >> item;
        arr[item] += 1;
    }

    for (int i=1; i<=10000; i++){
        while(arr[i] > 0){
            cout << i << '\n';
            arr[i]--;
        }
    }

    return 0;
}

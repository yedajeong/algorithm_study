#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    // 시간초과 방지
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
     
    int N;

    cin >> N;

    int arr[10001] = {0};
    int item;
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

#include <iostream>
#include <algorithm>
using namespace std;

// 4: 4->3->1 / 4->2->1 3번
// 5: 5->4->2->1 4번
// 6: 6->3->1 / 6->2->1 3번
// 7: 7->6->3->1 / 7->6->2->1 4번
// 8: 8->4->2->1 /  8->4->3->1 4번

int main(){
    int X;
    cin >> X;

    int count[1000000];
    count[1] = 0;

    for (int i=2; i<=X; i++){ // 1부터 X까지 배열 값 채워넣기

        count[i] = 1 + count[i-1]; // 1 빼기
        
        // 1 뺀 거랑 2 or 3으로 나눈 것 중에서 연산 횟수 더 작은 값으로 update 
        if(i%2 == 0) // 2로 나눠 떨어짐
            count[i] = min(count[i], count[i/2]+1);

        if(i%3 == 0) // 3으로 나눠 떨어짐
            count[i] = min(count[i], count[i/3]+1);
    }

    cout << count[X] << "\n";

    return 0;
}
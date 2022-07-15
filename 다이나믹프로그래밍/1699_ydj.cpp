#include <iostream>
using namespace std;

int main(){
    int N;
    int dp[100001];

    cin >> N;

    dp[0] = 0;
    dp[1] = 1; //1
    dp[2] = 2; //1, 1
    dp[3] = 3; //1, 1, 1
    
    for (int i=4; i<=N; i++){
        int j=2;
        dp[i] = i; // 초기값: 1^2을 i번 더해서 표현
        while(i-j*j >= 0){
            // (i - j^2) + j^2 = dp[i-j^2]+1
            dp[i] = min(dp[i], dp[i-j*j]+1);
            j++;
        }
    }

    // for (int i=1; i<=N; i++){
    //     cout << dp[i] << endl;
    // }
    cout << dp[N] << "\n";

    return 0;

}
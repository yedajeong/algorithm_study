#include <iostream>
using namespace std;

int main(){
    int N;
    int dp[31]={0};

    cin >> N;

    // N이 홀수면 경우의 수 0
    if (N%2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    dp[2] = 3;
    dp[0] = 1; //곱하기 계산 위함

    for (int i=4; i<=N; i+=2){
        dp[i] = dp[i-2] * dp[2];
        for (int j=0; j<=i-4; j+=2)
            dp[i] += dp[j]*2; // |=..=| 이 위 혹은 아래에 ㅡ..ㅡ 
    }
        

    cout << dp[N] << "\n";

    return 0;
}
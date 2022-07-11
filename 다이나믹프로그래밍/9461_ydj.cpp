#include <iostream>
using namespace std;

int main(){
    int T, N;
    long dp[101];

    dp[1] = 1;
    dp[2] = dp[1];
    dp[3] = dp[1];
    dp[4] = dp[2]+dp[3];
    dp[5] = dp[4];
    
    cin >> T;

    for (int i=0; i<T; i++){
        cin >> N;

        for (int i=6; i<=N; i++)
            dp[i] = dp[i-1] + dp[i-5];

        cout << dp[N] << "\n";
    }

    return 0;
}
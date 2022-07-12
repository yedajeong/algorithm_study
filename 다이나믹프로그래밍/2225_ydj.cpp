#include <iostream>
using namespace std;

int main(){
    int N, K, MOD=1000000000;
    long long dp[201][201] = {{0}}; //dp[n][k] -> 숫자 n을 k개 숫자의 합으로 표현

    cin >> N >> K;
    
    //dp[N][4] = dp[N][3]+dp[N-1][3]+...+dp[1][3]+dp[0][3] --> 000+N = N도 포함되니까

    // k=1: 어떤 수 n을 1개의 숫자의 합으로 나타내는 경우의 수 = 1가지
    for(int n=0; n<=N; n++)
        dp[n][1] = 1;                           

    for(int k=2; k<=K; k++){
        for(int n=0; n<=N; n++){
            for(int i=0; i<=n; i++)
                dp[n][k] += dp[i][k-1] % MOD;
        }
    }

    cout << dp[N][K];

    return 0;
}
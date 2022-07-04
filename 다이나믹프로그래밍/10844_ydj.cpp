#include <iostream>
#define mod 1000000000
using namespace std;

int main(){
    int N;
    long dp[101][10]; //끝자리에 0~9까지의 수가 오는 경우의 수
    // [n][0]: 뒤에 1만 올 수 있음
    // [n][9]: 뒤에 8만 올 수 있음
    // [n][1~8]: 뒤에 2가지씩올 수 있음
    cin >> N;

    dp[1][0] = 0;
    for(int i=1; i<10; i++)
        dp[1][i] = 1;
    
    for (int i=2; i<=N; i++){
        dp[i][0] = dp[i-1][1] % mod;
        dp[i][9] = dp[i-1][8] % mod;

        for (int j=1; j<9; j++)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;

    }

    long result = 0;
    for (int i=0; i<10; i++)
        result += dp[N][i];

    cout << result % mod << "\n";

    return 0;
}
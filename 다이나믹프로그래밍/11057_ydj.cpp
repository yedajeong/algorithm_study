#include <iostream>
#define mod 10007
using namespace std;

int main(){
    int N;
    long dp[1001][10] = {{0}};

    cin >> N;

    for (int i=0; i<10; i++)
        dp[1][i] = 1;
    
    for (int i=2; i<=N; i++){
        for (int j=0; j<10; j++){
            for (int k=0; k<=j; k++)
                dp[i][j] += dp[i-1][k] % mod;
        }

    }

    long result = 0;
    for (int i=0; i<10; i++)
        result += dp[N][i] % mod;

    cout << result << "\n";

    return 0;
}
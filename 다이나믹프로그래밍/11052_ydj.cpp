#include <iostream>
using namespace std;

int main(){
    int N, P[1001], dp[1001];

    cin >> N;

    for (int i=1; i<=N; i++)
        cin >> P[i];

    P[0] = 0;
    dp[0] = 0;
    dp[1] = P[1];

    for (int i=2; i<=N; i++){
        dp[i] = P[i];
        for (int j=1; j<=i; j++){
            dp[i] = max(dp[i], dp[i-j]+P[j]);
        }
    }

    for (int i=1; i<=N; i++)
        cout << dp[i] << endl;

    //cout << dp[N] << "\n";

    return 0;
}
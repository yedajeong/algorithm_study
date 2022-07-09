#include <iostream>
using namespace std;

int main(){
    int N;
    int dp[10001];
    int num[10001];

    cin >> N;
    for (int i=1; i<=N; i++)
        cin >> num[i];

    dp[0] = 0; // 시작
    dp[1] = num[1];
    dp[2] = dp[1] + num[2];

    for (int i=3; i<=N; i++){
        dp[i] = max(dp[i-2], dp[i-3]+num[i-1]) + num[i];
    }

    cout << dp[N] << "\n";

    return 0;
}

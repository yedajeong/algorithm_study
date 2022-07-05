#include <iostream>
using namespace std;

int main(){
    int n;
    int quant[10001];

    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> quant[i];
    }

    int dp[n+1][2]; // n번째 포도주 선택했을 때 max, 선택 안했을 때 max

    dp[1][0] = 0;
    dp[1][1] = quant[1];

    dp[2][0] = dp[1][1];
    dp[2][1] = dp[1][1] + quant[2];

    for (int i=3; i<=n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = max(dp[i-2][0]+quant[i-1], dp[i-1][0]) + quant[i];
    }

    cout << max(dp[n][0], dp[n][1]) << "\n";

    return 0;
}
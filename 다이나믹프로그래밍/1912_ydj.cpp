#include <iostream>
using namespace std;

int main(){
    int N, result;
    int dp[100001]; // num[i]가 포함된 부분수열 중 최대길이 증가하는 부분수열
    int num[100001];

    cin >> N;
    for (int i=1; i<=N; i++)
        cin >> num[i];

    dp[1] = num[1];
    result = dp[1]; // 1

    for (int i=2; i<=N; i++){
        dp[i] = max(num[i], dp[i-1]+num[i]);
        result = max(result, dp[i]);
    }

    cout << result << "\n";

    return 0;
}
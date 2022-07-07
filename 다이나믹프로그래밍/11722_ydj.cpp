#include <iostream>
using namespace std;

int main(){
    int N, result;
    int dp[1001]; // num[i]가 포함된 부분수열 중 최대길이 감소하는 부분수열
    int num[1001];

    cin >> N;
    for (int i=1; i<=N; i++)
        cin >> num[i];

    dp[1] = 1;
    result = dp[1]; // 1

    for (int i=2; i<=N; i++){
        int sequence = 0;
        for (int j=1; j<i; j++){
            // num[i]까지 포함된 수열: num[i]가 제일 작음 & 이전 item으로 만들 수 있는 가장 긴 수열 뒤에 num[i]붙이기 
            if (num[j] > num[i] && sequence < dp[j])
                sequence = dp[j];
        }
        dp[i] = sequence+1;
        result = max(result, dp[i]);
    }

    cout << result << "\n";

    return 0;
}
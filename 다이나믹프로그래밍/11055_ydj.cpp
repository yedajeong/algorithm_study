#include <iostream>
using namespace std;

int main(){
    int N, result;
    int dp[1001]; // num[i]가 포함된 부분수열 중 최대합인 증가부분수열
    int num[1001];

    cin >> N;
    for (int i=1; i<=N; i++)
        cin >> num[i];

    dp[1] = num[1];
    result = dp[1]; // num[1]

    for (int i=2; i<=N; i++){
        int sum = 0;
        for (int j=1; j<i; j++){
            // num[i]까지 포함된 수열: num[i]가 제일 큼 & 이전 item으로 만들 수 있는 가장 긴 수열 뒤에 num[i]붙이기 
            // dp[j] (num[j]까지 구한 최대합 증가 부분 수열) 에 제일 큰 num[i]만 추가
            if (num[j] < num[i] && sum < dp[j])
                sum = dp[j];
        }
        dp[i] = sum+num[i];
        result = max(result, dp[i]);
    }

    cout << result << "\n";

    return 0;
}
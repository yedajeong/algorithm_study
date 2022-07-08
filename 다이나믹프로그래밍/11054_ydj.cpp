#include <iostream>
using namespace std;

int main(){
    int N, result=0;
    int dp[1001]; // num[i]가 포함된 부분수열 중 최대길이
    int ascend[1001];
    int descend[1001];
    int num[1001];

    cin >> N;
    for (int i=1; i<=N; i++)
        cin >> num[i];

    ascend[1] = 1;
    descend[N] = 1;

    // 가장 긴 증가하는 수열 (1~N순)
    for (int i=2; i<=N; i++){
        int max_len = 0;
        for (int j=1; j<i; j++){
            if (max_len < ascend[j] && num[j] < num[i])
                max_len = ascend[j];
        }
        ascend[i] = max_len + 1;
    }

    // 1~N 가장 긴 감소하는 수열 == N~1 가장 긴 증가하는 수열
    for (int i=N-1; i>=1; i--){
        int max_len = 0;
        for (int j=N; j>i; j--){
            if (max_len < descend[j] && num[j] < num[i])
                max_len = descend[j];
        }
        descend[i] = max_len + 1;
    }

    // ascend+descend
    for (int i=1; i<=N; i++){
        dp[i] = ascend[i] + descend[i] - 1; // num[i] 중복 -> -1
        result = max(result, dp[i]);
    }

    cout << result << "\n";

    return 0;
}
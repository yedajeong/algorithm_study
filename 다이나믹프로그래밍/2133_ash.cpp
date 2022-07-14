#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int dp[31] = { 0 };

	dp[2] = 3;
	
	if (N > 2) {
		for (int i = 3; i < N + 1; i++) {
			if (i % 2 == 0) { //짝수일때만
				dp[i] = 3 * dp[i - 2]; //앞이 3*2
				for (int j = 2; j < i - 2; j += 2) { //앞이 3*2k 뒤가 3*(n-k) (k>2)
					dp[i] += 2 * dp[j];
				}
				dp[i] += 2; // 3*n짜리 두개 추가
			}
		}
	}

	cout << dp[N] << endl;

	return 0;
}
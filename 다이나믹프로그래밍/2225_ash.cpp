#include <iostream>
using namespace std;

int main() {
	int dp[201][201] = { 0, };
	int N, K;
	cin >> N >> K;

	
	for (int i = 1; i < N+1; i++) {
		dp[i][1] = 1;
	}
	for (int i = 1; i < K; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i < N + 1; i++) { //1
		for (int k = 2; k < K + 1; k++) { //2
			for (int j=0; j<i+1; j++){ //0
				dp[i][k] = (dp[i][k] + dp[j][k - 1]) % 1000000000;
			}
		}
	}

	cout << dp[N][K] << endl;

	return 0;
}
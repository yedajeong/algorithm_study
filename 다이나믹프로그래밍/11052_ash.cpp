#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int num[10001] = { 0 };

	for (int i = 1; i < N + 1; i++) {
		cin >> num[i];
	}

	int dp[10001] = { 0 };
	dp[1] = num[1];

	for (int i = 2; i < N + 1; i++) {
		dp[i] = num[i];
		for (int j = i/2; j < i; j++) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[N] << endl;

	return 0;
}
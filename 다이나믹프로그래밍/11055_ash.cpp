#include <iostream>
using namespace std;

int main() {
	int dp[1001] = { 0 };
	int size;
	cin >> size;
	int num[1001] = { 0 };

	for (int i = 1; i < size + 1; i++) {
		cin >> num[i];
	}

	int sol = 0;
	for (int i = 1; i < size + 1; i++) {
		dp[i] = num[i];
		for (int j = 0; j < i; j++) {
			if (num[i] > num[j]) {
				dp[i] = max(dp[i], dp[j] + num[i]);
			}
		}
		sol = max(sol, dp[i]);
	}

	cout << sol << endl;

	return 0;
}

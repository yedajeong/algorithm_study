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
	for (int i = size; i > 0; i--) {
		dp[i] = 1;
		for (int j = size; j > i; j--) {
			if (num[i] > num[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		sol = max(sol, dp[i]);
	}

	cout << sol << endl;

	return 0;
}

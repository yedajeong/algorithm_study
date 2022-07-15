#include <iostream>
using namespace std;

int dp[31];

int main() {
	int input_num;

	cin >> input_num;
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;
	dp[4] = 11;
	if (input_num % 2 == 0) {
		for (int n = 3; 2 * n <= input_num; n++) {
			dp[2 * n] = dp[2 * n - 2] * 3;
			for (int j = 4; 2*n - j >= 0; j++) {
				dp[2 * n] = dp[2 * n] + 2 * dp[2 * n - j];
			}
		}
	}

	
	cout << dp[input_num] << '\n';
}
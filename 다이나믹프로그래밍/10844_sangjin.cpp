#include <iostream>
using namespace std;

int dp[10][101] = {};

int Stair_number(int a) {
	int final_num = 0;
	dp[0][1] = 0;
	for (int i = 1; i < 10; i++) {
		dp[i][1] = 1;
	}
	for (int j = 2; j < a + 1; j++) {
		for (int k = 0; k < 10; k++) {
			if (k == 0) {
				dp[k][j] = dp[k + 1][j - 1];
			}
			if (k == 9) {
				dp[k][j] = dp[k - 1][j - 1];
			}
			if (k != 0 && k != 9) {
				dp[k][j] = dp[k - 1][j - 1] + dp[k + 1][j - 1];
			}
			dp[k][j] %= 1000000000;
		}
	}

	for (int n = 0; n < 10; n++) {
		final_num = (final_num + dp[n][a]) % 1000000000;
	}
	return final_num;
}

int main() {
	int input_number;

	cin >> input_number;

	cout << Stair_number(input_number) << '\n';
}

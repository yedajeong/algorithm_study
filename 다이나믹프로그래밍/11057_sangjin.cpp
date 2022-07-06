#include <iostream>
using namespace std;

int dp[1001][10] = {};

int UpStair_number(int a) {

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int j = 2; j <= a; j++) {
		for (int k = 0; k < 10 ; k++) {
			for (int n = 9; n+1 > k; --n) {
				dp[j][k] += dp[j-1][n];
				dp[j][k] %= 10007;
			}
		}
	}
	
	int final_num = 0;
	for (int n = 0; n < 10; n++) {
		final_num = (final_num + dp[a][n]) % 10007;
	}
	return final_num;
}

int main() {
	int input_number;

	cin >> input_number;

	cout << UpStair_number(input_number) << '\n';
}

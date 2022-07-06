#include <iostream>
using namespace std;

long long dp[91][2] = {};

long long Pinary_number(int a) {
	dp[1][0] = 0;
	dp[1][1] = 1;


	for (int i = 2; i <= a; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	return dp[a][0] + dp[a][1];
}


int main() {
	int input_num;

	cin >> input_num;

	cout << Pinary_number(input_num) << '\n';
}

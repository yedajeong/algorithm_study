#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001][2];
int input_num[100001][2];

int main() {
	int Test_case, input_number;
	cin >> input_number;

	for (int n = 0; n < input_number; n++) {
		cin >> Test_case;

		for (int i = 0; i < Test_case; i++) {
			cin >> input_num[i][0];
		}
		for (int j = 0; j < Test_case; j++) {
			cin >> input_num[j][1];
		}
		dp[0][0] = input_num[0][0];
		dp[0][1] = input_num[0][1];
		dp[1][0] = input_num[1][0] + input_num[0][1];
		dp[1][1] = input_num[1][1] + input_num[0][0];

		for (int t = 2; t < Test_case; t++) {
			dp[t][0] = input_num[t][0] + max(dp[t - 2][1], dp[t - 1][1]);
			dp[t][1] = input_num[t][1] + max(dp[t - 2][0], dp[t - 1][0]);
		}

		cout << max(dp[Test_case - 1][0], dp[Test_case - 1][1]) << '\n';
	}

}
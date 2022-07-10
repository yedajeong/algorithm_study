#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001][3];
int input_num[10001];

int main() {
	int row_num;

	cin >> row_num;

	for (int i = 0; i < row_num; i++) {
		cin >> input_num[i];
	}

	dp[0][0] = 0;
	dp[0][1] = input_num[0];
	dp[0][2] = input_num[0];
	dp[1][0] = dp[0][2];
	dp[1][1] = input_num[1];
	dp[1][2] = input_num[0] + input_num[1];

	for(int j = 2; j < row_num; j++){
		dp[j][0] = dp[j-1][2];
		dp[j][1] = max(dp[j - 1][0] + input_num[j], dp[j - 1][2] + input_num[j] - input_num[j - 1]);
		dp[j][2] = max({ dp[j - 1][1] + input_num[j],max(dp[j - 3][0] ,dp[j - 3][1]) + input_num[j - 1] + input_num[j] });
	}

	cout << max({ dp[row_num - 1][0],dp[row_num - 1][1], dp[row_num - 1][2] }) << '\n';
}
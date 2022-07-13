#include <iostream>
#include <algorithm>
using namespace std;

int stair_score[301];
int dp[301];

int main() {
	int input_num;

	cin >> input_num;

	for (int i = 1; i <= input_num; i++)
		cin >> stair_score[i];

	dp[1] = stair_score[1];
	dp[2] = stair_score[1] + stair_score[2];

	for (auto i = 3; i <= input_num; i++) {
		dp[i] = max(dp[i - 3] + stair_score[i - 1] + stair_score[i], dp[i - 2] + stair_score[i]);
	}

	cout << dp[input_num] << '\n';
}
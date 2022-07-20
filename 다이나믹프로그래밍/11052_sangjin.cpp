#include <iostream>
#include <algorithm>
using namespace std;

int card_score[1001];
int dp[1001];   //

int main() {
	int input_num;

	cin >> input_num;

	for (int i = 1; i <= input_num; i++) {
		cin >> card_score[i];
	}
	for (int i = 1; i <= input_num; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] = max(dp[i],dp[j] + card_score[i-j]);
		}
	}

	cout << dp[input_num] << '\n';
}
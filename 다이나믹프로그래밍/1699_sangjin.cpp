#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[100001];

int main() {
	for (int i = 1; i <= 100000; i++) 
		dp[i] = i;

	for (int i = 1; i * i <= 100000; i++)
		dp[i * i] = 1;

	int input_num;
	
	cin >> input_num;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= input_num; i++) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + dp[j * j]);
		}
	}

	cout << dp[input_num] << '\n';
}


#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int dp[100001] = { 0 };
	int num[100001] = { 0 };
	
	for (int i = 1; i < N+1; i++) {
		cin >> num[i];
	}

	int sol = -1000;
	for (int i = 1; i < N + 1; i++) {
		dp[i] = num[i];
		dp[i] = max(dp[i], dp[i - 1] + num[i]);
		sol = max(sol, dp[i]);
	}

	cout << sol << endl;
	return 0;
}
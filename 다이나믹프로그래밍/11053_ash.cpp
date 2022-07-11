#include <iostream>
using namespace std;

int main() {
	int dp[1001] = { 0 }; //0 -> 두번째 큰수, 1-> 가장큰수, 2-> 길이
	int size;
	cin >> size;
	int num[1001] = { 0 };

	for (int i = 1; i < size + 1; i++) {
		cin >> num[i];
	}

	dp[1] = 1;

	if (size > 1) {
		for (int i = 2; i < size + 1; i++) {
			for (int j = 1; j < i; j++) {
				if (num[i] > num[j]) {
					if (dp[i] < dp[j]) {
						dp[i] = dp[j];
					}
				}
			}
			dp[i]++;
		}
	}

	int sol = 0;
	for (int i = 1; i < size + 1; i++) {
		sol = max(sol, dp[i]);
	}
	cout << sol << endl;

	return 0;
}

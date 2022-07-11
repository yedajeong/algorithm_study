#include <iostream>
using namespace std;

int main() {
	int dp[1001][2] = { 0, }; //0:증가하는 부분 1:감소하는 부분
	int size;
	cin >> size;
	int num[1001] = { 0 };

	for (int i = 1; i < size + 1; i++) {
		cin >> num[i];
	}

	for (int i = 1; i < size + 1; i++) {
		dp[i][0] = 1;
		for (int j = 0; j < i; j++) { //증가하는 부분
			if (num[i] > num[j]) {
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
			}
		}
	}

	for (int i = size; i > 0; i--) { //감소하는 부분
		dp[i][1] = 1;
		for (int j = size; j > i; j--) {
			if (num[i] > num[j]) {
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
			}
		}
	}
	
	int sol = 0;
	for (int i = 1; i < size + 1; i++) { //최대값 비교
		sol = max(sol, dp[i][0] + dp[i][1] - 1);
	}

	cout << sol << endl;

	return 0;
}

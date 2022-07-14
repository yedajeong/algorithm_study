#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	int dp[100001] = { 0 };
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	if (N > 3) {
		for (int i = 4; i < N + 1; i++) {
			int b = sqrt(i);
			
			//case1. Á¦°ö¼öÀÏ¶§
			if (i == (b*b)){
				dp[i] = 1;
			}
			//case2. Á¦°ö¼ö°¡ ¾Æ´Ò¶§ (b-1ÀÌ >1ÀÏ¶§±îÁö ´Ù ºÁ¾ßÇÔ...
			else {
				dp[i] = dp[b * b] + dp[i - b * b];
				for (int j = b - 1; j > 1; j--) {
					dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
				}
			}
		}
	}
	cout << dp[N] << endl;

	return 0;
}
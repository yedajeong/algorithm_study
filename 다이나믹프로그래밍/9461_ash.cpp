#include <stdio.h>

int main() {
	int T;
	long long dp[101] = { 0 }; //자료형 주의...
	scanf_s("%d", &T);

	for (int i = 0; i < T; i++) {
		int N;
		scanf_s("%d", &N);
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		dp[4] = 2;
		dp[5] = 2;
		for (int j = 6; j < N + 1; j++) {
			dp[j] = dp[j - 1] + dp[j - 5];
		}

		printf("%lld\n", dp[N]);
	}
	return 0;
}
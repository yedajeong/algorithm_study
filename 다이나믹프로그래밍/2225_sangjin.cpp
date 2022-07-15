#include <iostream>
#include <algorithm>
using namespace std;

int dp[201][201];

int main() {
	int input_num, count_num;
	cin >> input_num >> count_num;

	

	for (int i = 0; i < 201; i++) {
		dp[0][i] = 1;
		dp[i][1] = 1;
		dp[i][2] = i + 1;
	}

	for (int i = 1; i <= input_num; i++) { 
		for (int j = 3; j <= count_num; j++) { 
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
		}
	}

	cout << dp[input_num][count_num] << '\n';

}
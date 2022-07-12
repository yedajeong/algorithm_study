#include <iostream>
#include <algorithm>
using namespace std;

int input_num[1001];
int dp[1001][2];

int main() {
	int size_num;

	cin >> size_num;

	for (int i = 0; i < size_num; i++)
		cin >> input_num[i];

	// 기준점 앞의 수
	for (int i = 0; i < size_num; i++) { 
		dp[i][0] = 1; //자기자신의 길이를 더해야하므로
		for (int j = 0; j < i; j++) {
			if (input_num[i] > input_num[j])
				dp[i][0] = max(dp[j][0] + 1, dp[i][0]);
		}
	}

	//기준점 뒤의 수
	for (int i = size_num - 1; i >= 0; i--) { 
		for (int j = i; j < size_num; j++) {
			if (input_num[i] > input_num[j])
				dp[i][1] = max(dp[j][1] + 1, dp[i][1]);	
		}
	}
	
	int max_num = 0;
	for (int i = 0; i < size_num; i++ ) {
		max_num = max(dp[i][0] + dp[i][1], max_num);
	}

	cout << max_num << '\n';
}
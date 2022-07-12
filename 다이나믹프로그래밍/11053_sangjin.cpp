#include <iostream>
#include <algorithm>

using namespace std;

int input_row[1001];
int dp[1001];

int main() {
	int size_num;

	cin >> size_num;
	for (int i = 0; i < size_num; i++) {
		cin >> input_row[i];
	}

	int max_num = 0;
	for (int i = 0; i < size_num; i++) {
		dp[i] = 1; //자기자신의 길이를 더해야하므로
		for (int j = 0; j < i; j++) {
			if (input_row[i] > input_row[j])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
		max_num = max(max_num, dp[i]);
	}


	cout << max_num << '\n';

}





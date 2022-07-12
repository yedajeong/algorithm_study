#include <iostream>
#include <algorithm>
using namespace std;

int input_num[100001];
int dp[100001];


int main() {
	int size_num;

	cin >> size_num;

	for (int i = 0; i < size_num; i++) 
		cin >> input_num[i];

	dp[0] = input_num[0];
	for (int i = 1; i < size_num; i++) {
		dp[i] = max(dp[i - 1] + input_num[i],input_num[i]);
	}

	int max_num = -1001;
	for (int i = 0; i < size_num; i++) {
		max_num = max(dp[i], max_num);
	}

	cout << max_num << '\n';

}
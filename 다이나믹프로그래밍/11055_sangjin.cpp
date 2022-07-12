#include <iostream>
#include <algorithm>
using namespace std;

int input_num[1001];
int dp[1001];

int main() {
	int size_num;

	cin >> size_num;

	for (int i = 0; i < size_num; i++) 
		cin >> input_num[i];


	for (int i = 0; i < size_num; i++) {
		dp[i] = input_num[i]; //자기 자신을 더해야함.
		for (int j = 0; j < i; j++) {
			if (input_num[i] > input_num[j]) {
				dp[i] = max(dp[j] + input_num[i], dp[i]);
			}
		}
	}
	int max_num = 0;

	for (int i = 0; i < size_num; i++) {
		max_num = max(dp[i], max_num);
	}
	cout << max_num << '\n';
}
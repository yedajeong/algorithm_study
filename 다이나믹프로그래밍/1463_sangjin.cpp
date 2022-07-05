#include <iostream>
using namespace std;

int dp[1000001] = {};

int Count_num(int a) {
	int b, c;

	if (a == 1)
		return 0;

	if (dp[a] != 0)
		return dp[a];

	dp[a] = Count_num(a - 1) + 1;

	if (a % 3 == 0) {
		c = Count_num(a / 3) + 1;
		if (dp[a] > c)
			dp[a] = c;
	}
	if (a % 2 == 0) {
		b = Count_num(a / 2) + 1;
		if (dp[a] > b)
			dp[a] = b;
	}
	return dp[a];
}


int main() {
	int input_num;

	cin >> input_num;

	cout << Count_num(input_num) << '\n';
}
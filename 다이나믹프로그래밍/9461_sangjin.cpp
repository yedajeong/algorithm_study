#include <iostream>
using namespace std;

long long dp[101];

long long fibonachi(int a) {
	if (a == 1)
		return dp[a] = 1;
	if (a == 2)
		return dp[a] = 1;
	if (a == 3)
		return dp[a] = 1;
	if (a == 4)
		return dp[a] = 2;
	if (a == 5)
		return dp[a] = 2;
	if (a == 6)
		return dp[a] = 3;
	if (a == 7)
		return dp[a] = 4;
	if (a == 8)
		return dp[a] = 5;

	if (dp[a] != 0)
		return dp[a];

	if(a >= 9)
		return dp[a] = fibonachi(a - 5) + fibonachi(a - 1);

}

int main() {
	int input_test, input_num;
	cin >> input_test;

	for (int i = 0; i < input_test; i++) {
		cin >> input_num;
		cout <<fibonachi(input_num) << '\n';
	}
}
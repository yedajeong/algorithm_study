#include <iostream>
using namespace std;

int dp[1001] = {};

int MakeTile(int a) {
	if (a == 1)
		return 1;
	if (a == 2)
		return 2;
	if (dp[a] != 0)
		return dp[a];
	return dp[a] = (MakeTile(a - 1) + MakeTile(a - 2)) % 10007;
}


int main() {
	int input_num;
	
	cin >> input_num;

	cout << MakeTile(input_num) << '\n';
}
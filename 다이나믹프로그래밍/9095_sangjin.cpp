#include <iostream>
using namespace std;

int dp[11] = {};

int Number_of_cases(int a) {
	if (a == 1)
		return 1;
	if (a == 2)
		return 2;
	if (a == 3)
		return 4;
	if (dp[a] != 0)
		return dp[a];

	return dp[a] = (Number_of_cases(a - 1) + Number_of_cases(a - 2) + Number_of_cases(a - 3));
}
int main() {
	int input_case, input_number;
	int test_case[1001] = {};

	cin >> input_case;


	for (int i = 0; i < input_case; i++) {
		cin >> input_number;
		test_case[i] = input_number;
	}
	for (int i = 0; i < input_case; i++) {
		cout << Number_of_cases(test_case[i]) << '\n';
	}
}
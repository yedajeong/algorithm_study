#include <iostream>
#include <string>
using namespace std;

int num_case[5001];
long long dp[5001];


int main() {
	string input_num;

	cin >> input_num;

	int length = input_num.size();

	for (int i = 0; i < length; i++) {
		string a = input_num.substr(i, 1);
		num_case[i + 1] = stoi(a);
	}
	dp[0] = 1;
	dp[1] = 1;

	if (num_case[1] == 0) {
		cout << "0" << '\n';
		return 0;
	}

	for (int i = 2; i <= length; i++) {
		if (num_case[i - 1] == 0) {
			if (num_case[i] == 0) {
				cout << "0" << '\n';
				return 0;
			}
		}

		if (num_case[i - 1] == 1) {
			if (num_case[i] == 0) {
				dp[i] = dp[i - 2];
			}
			if (num_case[i] >= 1) {
				dp[i] = dp[i - 1] + dp[i - 2];
			}

		}
		else if (num_case[i - 1] == 2) {
			if (num_case[i] == 0) {
				dp[i] = dp[i - 2];
			}
			if (num_case[i] >= 1 && num_case[i] <= 6) {
				dp[i] = dp[i - 1] + dp[i - 2];
			}
			if (num_case[i] >= 7) {
				dp[i] = dp[i - 1];
			}
		}
		else if (num_case[i - 1] >= 3) {
			if (num_case[i] == 0) {
				cout << "0" << '\n';
				return 0;
			}
			else {
				dp[i] = dp[i - 1];
			}
		}
		else {
			dp[i] = dp[i - 1];
		}
		dp[i] %= 1000000;
	}
	cout << dp[length] << '\n';

}
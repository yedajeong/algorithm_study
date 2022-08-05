#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string input_num;

	cin >> input_num;

	int input_size = input_num.size();
	
	int n = input_num[0] - '0';

	if (n == 0) {
		cout << "0";
	}

	for (int i = 0; i < input_size; i++) {
		int innum = input_num[i] - '0';
		string result = "";
		if (i == 0) {
			while (innum != 0) {
				result += to_string(innum % 2);
				innum = innum / 2;
			}
			reverse(result.begin(), result.end());
		}
		else {
			while (innum != 0) {
				result += to_string(innum % 2);
				innum = innum / 2;
			}
			reverse(result.begin(), result.end());

			while (result.size() != 3)
				result = "0" + result;
		}

		cout << result;
	}
}

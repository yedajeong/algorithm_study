#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int input_num;
	vector<int> vec;
	cin >> input_num;

	if (input_num == 0) {
		cout << "0" <<'\n';
		return 0;
	}

	while (input_num != 0) {
		int gcd = input_num % (-2);
		if (gcd < 0) {
			input_num = (input_num / (-2)) + 1;
			gcd = 1;
		}
		else {
			input_num = (input_num / (-2));
		}
		vec.push_back(gcd);
	}
	reverse(vec.begin(), vec.end());

	for (auto x : vec) {
		cout << x;
	}
}

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int Prime_num[1000001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int input_num;


	for (int i = 2; i <= 1000000; i++) {
		Prime_num[i] = i;
	}

	for (int i = 2; i < sqrt(1000000); i++) {
		if (Prime_num[i] == 0) {
			continue;
		}
		for (int j = i * i; j <= 1000000; j += i) {
			Prime_num[j] = 0;
		}
	}

	while (true) {
		vector<int> vec;
		int count = 0;

		cin >> input_num;

		if (input_num == 0) {
			break;
		}

		for (int i = 3; i <= input_num; i++) {
			if (Prime_num[i] != 0) {
				int n = input_num - Prime_num[i];
				if (Prime_num[n] != 0) {
					cout << input_num << " = " << Prime_num[i] << " + " << n << '\n';
					count++;
					break;
				}
			}
		}

		if (count == 0) {
			cout << "Goldbach's conjecture is wrong." << '\n';
		}
	}
	return 0;
}

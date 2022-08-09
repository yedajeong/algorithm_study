#include <iostream>
using namespace std;

int main() {
	int input_num;
	int print_case = 0;
	cin >> input_num;

	for (int i = 0; i < input_num; i++) {
		int a;
		cin >> a;

		if (a != 1) {
			int count = 0;

			for (int k = 2; k < a; k++) {
				if (a % k == 0) {
					count++;
				}
			}

			if (count == 0) {
				print_case++;
			}
		}
	}
	cout << print_case << '\n';
}

#include <iostream>
using namespace std;

int main() {
	int input_num;
	cin >> input_num;

	if (input_num == 0) {
		cout << "0" << '\n';
		return 0;
	}

	int n = 0;

	for (int i = input_num; i > 0; i--) {
		int k = i;
		while (k % 5 == 0) {
			k /= 5;
			n++;
		}
	}
	
	cout << n << '\n';

	return 0;
}

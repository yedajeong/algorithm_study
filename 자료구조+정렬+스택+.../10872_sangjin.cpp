#include <iostream>
using namespace std;

int main() {
	int input_num;
	cin >> input_num;
	
	if (input_num == 0) {
		cout << "1" << '\n';
		return 0;
	}

	int n = 1;

	for (int i = input_num; i > 0; i--) {
		n = n * i;
	}

	cout << n << '\n';

	return 0;
}

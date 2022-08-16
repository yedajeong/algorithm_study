#include <iostream>
using namespace std;

int main() {
	int input_num;
	cin >> input_num;

	if (input_num == 1)
		return 0;

	for (int i = 2; i <= input_num; i++) {
		while (input_num % i == 0) {
			cout << i << endl;
			input_num /= i;
		}
	}
}

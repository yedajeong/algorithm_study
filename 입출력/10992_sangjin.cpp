#include <iostream>
using namespace std;

int main() {
	int input_num;

	cin >> input_num;

	for (int i = 0; i < input_num - 1; i++) {
		for (int j = 0; j < input_num - i - 1; j++) 
			cout << " ";
		if (i == 0) {
			cout << "*";
		}
		else {
			cout << "*";
			for (int k = 0; k < (2*i) - 1 ; k++) 
				cout << " ";
			cout << "*";
		}
		cout << '\n';
	}

	for (int n = 0; n < 2 * (input_num) - 1; n++) {
		cout << "*";
	}
}
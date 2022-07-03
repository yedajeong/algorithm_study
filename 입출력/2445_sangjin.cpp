#include <iostream>
using namespace std;

int main() {
	int input_num;

	cin >> input_num;

	for (int i = 0; i < input_num; i++) {
		for (int t = 0; t < i + 1; t++)
			cout << "*";
		for (int j = 0; j < 2 * (input_num - i) - 2; j++)
			cout << " ";
		for (int k = 0; k < i + 1; k++)
			cout << "*";
		cout << '\n';
	}

	for (int n = 0; n < input_num - 1; n++) {
		for (int t = 0; t < input_num - n - 1; t++)
			cout << "*";
		for (int j = 0; j < 2*(n+1); j++)
			cout << " ";
		for (int k = 0; k < input_num - n - 1; k++)
			cout << "*";
		cout << '\n';
	}
}
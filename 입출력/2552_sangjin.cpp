#include <iostream>
using namespace std;

int main() {
	int input_num;

	cin >> input_num;

	for (int i = 0; i < input_num; i++) {
		for (int j = 1; j < input_num - i; j++)
			cout << " ";
		for (int k = 0; k < i + 1; k++)
			cout << "*";
		cout << '\n';
	}

	for (int n = 0; n < input_num - 1; n++) {
		for (int j = 0; j < n + 1; j++)
			cout << " ";
		for (int k = 0; k < input_num - n - 1; k++)
			cout << "*";
		cout << '\n';
	}
}
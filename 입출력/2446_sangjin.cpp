#include <iostream>
using namespace std;

int main() {
	int input_num;

	cin >> input_num;

	for (int i = 0; i < input_num; i++) {
		for (int j = 1; j < i + 1; j++)
			cout << " ";
		for (int k = 0; k < 2*(input_num - i) - 1 ; k++)
			cout << "*";
		cout << '\n';
	}

	for (int n = 0; n < input_num - 1; n++) {
		for (int j = 1; j < input_num - n - 1; j++)
			cout << " ";
		for (int k = 0; k < 2 *(n+1) + 1; k++)
			cout << "*";
		cout << '\n';
	}
}
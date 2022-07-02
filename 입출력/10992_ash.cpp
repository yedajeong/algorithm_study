#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		for (int j = n - 1; j > i; j--) {
			cout << " ";
		}
		cout << "*";
		for (int j = 0; j < i*2-1; j++) {
			cout << " ";
		}
		if (i != 0) {
			cout << "*";
		}
		cout << endl;
	}

	for (int i = 0; i < 2 * n - 1; i++) { //마지막 줄
		cout << "*";
	}
	return 0;
}
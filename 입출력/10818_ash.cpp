#include <iostream>
using namespace std;

/*
int main() {
	int n = 1;
	cin >> n;
	int* num = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> num[i];

	}

	int max = -1000000;
	int min = 1000000;

	for (int i = 0; i < n; i++) {
		if (num[i] > max) {
			max = num[i];
		}
		if (num[i] < min) {
			min = num[i];
		}
	}

	cout << min << " " << max << endl;

	delete[] num;
	return 0;
}
*/

//¼öÁ¤
int main() {
	int n;
	cin >> n;
	int num;
	int max = -1000000;
	int min = 1000000;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num > max) {
			max = num;
		}
		if (num < min) {
			min = num;
		}

	}
	cout << min << " " << max << endl;
	return 0;
}
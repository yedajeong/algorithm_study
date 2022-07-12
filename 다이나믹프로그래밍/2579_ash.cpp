#include <iostream>
using namespace std;

int main() {
	int n[10001][2] = { 0, }; //0 -> n-1, 1-> n-2
	int size;
	cin >> size;
	int num[10001] = { 0 };

	for (int i = 1; i < size + 1; i++) {
		cin >> num[i];
	}

	n[1][0] = num[1];
	n[2][0] = num[1] + num[2];
	n[2][1] = num[2];

	if (size > 2) {
		for (int i = 3; i < size + 1; i++) {
			n[i][0] = n[i - 1][1] + num[i];
			n[i][1] = max(n[i - 2][0], n[i - 2][1]) + num[i];
		}
	}

	int maximum = max( n[size][0], n[size][1]);
	cout << maximum << endl;

	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n[10001][3] = { 0, }; //0 -> n-1, 1-> n-2, 2->n-3
	int size;
	cin >> size;
	int num[10001] = { 0 };
	
	for (int i = 1; i < size+1; i++) {
		cin >> num[i];
	}

	n[1][0] = num[1];
	n[2][0] = num[1] + num[2];
	n[3][0] = num[2] + num[3];
	n[3][1] = num[1] + num[3];

	if (size > 3) {
		for (int i = 4; i < size + 1; i++) {
			n[i][0] = max(n[i - 1][1], n[i - 1][2])+ num[i];
			n[i][1] = max(n[i - 2][0], n[i-2][1])+num[i];
			n[i][2] = n[i - 3][0] + num[i];
		}
	}
	
	int maximum = max({ n[size][0], n[size][1], n[size - 1][0] });
	cout << maximum << endl;

	return 0;
}
	
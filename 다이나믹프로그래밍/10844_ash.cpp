#include <iostream>
using namespace std;

int main() {
	int n[101][10];
	int N;
	cin >> N;
	n[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		n[1][i] = 1;
	} //茄磊府荐

	if (N > 1) {
		for (int i = 2; i < N + 1; i++) {

			n[i][0] = n[i - 1][1]; //场磊府 0
			
			for (int j = 1; j < 9; j++) { //场磊府 1~8
				n[i][j] = (n[i - 1][j - 1] + n[i - 1][j + 1]) % 1000000000;
			}

			n[i][9] = n[i - 1][8]; //场磊府 9

		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++) {
		result = (result + n[N][i]) % 1000000000;
	}

	cout << result << endl;
	return 0;
}
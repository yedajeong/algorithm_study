#include <iostream>
using namespace std;

int main() {
	long long n[91][2] = { 0, }; //int로 하면 범위 벗어남
	int N;
	cin >> N;
	
	n[1][0] = 0;
	n[1][1] = 1;

	if (N > 1) {
		for (int i = 2; i < N + 1; i++) {
			n[i][0] = n[i - 1][0] + n[i - 1][1];
			n[i][1] = n[i - 1][0];
		}
	}

	long long result = n[N][0] + n[N][1];

	cout << result << endl;
	return 0;
}
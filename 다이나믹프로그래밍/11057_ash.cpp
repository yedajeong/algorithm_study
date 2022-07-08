#include <iostream>
using namespace std;

int main() {
	int n[1001][10] = { 0, };
	int N;
	cin >> N;
	for (int i = 0; i < 10; i++) {
		n[1][i] = 1;
	} //한자리수

	if (N > 1) {
		for (int i = 2; i < N + 1; i++) {
			for (int j = 0; j < 10; j++) { //끝자리 1~8
				for (int k = 0; k < j+1; k++) {
					n[i][j] = (n[i][j]+ n[i-1][k]) % 10007;
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++) {
		result = (result + n[N][i]) % 10007;
	}

	cout << result << endl;
	return 0;
}
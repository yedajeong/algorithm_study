#include <iostream>
using namespace std;

int coin[11];

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		coin[i] = x;
	}

	int cnt = 0;

	for (int j = N - 1; j >= 0; j--) {
		if (K == 0) 
			break;
		
		if (K / coin[j] != 0) {
			cnt += K / coin[j];
			K = K % coin[j];
		}
	}

	cout << cnt << '\n';
}

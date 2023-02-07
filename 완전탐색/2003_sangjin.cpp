#include <iostream>
using namespace std;

int num[10001] = { 0 };

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int cnt = 0;
	for (int start = 0; start < N; start++) {
		int result = 0;
		for (int j = start; j < N; j++) {
			
			result += num[j];

			if (result == M) {
				cnt++;
				break;
			}
			else if (result > M) 
				break;

			if (j == N - 1 && result < M) {
				cout << cnt << endl;
				return 0;
			}
		}
	}
	cout << cnt << endl;
}

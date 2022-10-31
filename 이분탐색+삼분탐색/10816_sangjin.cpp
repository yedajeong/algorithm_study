#include <iostream>
#include <cmath>
using namespace std;

int plus_num[10000001] = { 0, };
int minus_num[10000001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		if (t < 0) {
			minus_num[abs(t)]++;
		}
		else if (t >= 0) {
			plus_num[abs(t)]++;
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		int k;
		cin >> k;
		if (k < 0) {
			cout << minus_num[abs(k)] << " ";
		}
		else if(k >= 0) {
			cout << plus_num[abs(k)] << " ";
		}
	}
}

#include <iostream>
#include <algorithm>
using namespace std;

int subin[100001] = { 0 };

int main() {
	int N, K;

	cin >> N >> K;

	int cnt = 100001;

	for (int i = 0; i < 100001; i++) {
		if (i <= N) {
			subin[i] = N - i;
		}
		else {
			int mu = i / 2;
			if (i % 2 == 1) {
				int mu = i / 2;
				subin[i] = min(subin[i - 1] + 1, min(subin[mu] + 2, subin[mu + 1] + 2));
			}
			else {
				int mu = i / 2;
				subin[i] = min(subin[i - 1] + 1, subin[mu] + 1);
			}
		}
	}

	for (int i = 0; i < 100001; i++) {
		cnt = min(cnt, subin[i] + abs(K - i));
	}

	cout << cnt << endl;
}

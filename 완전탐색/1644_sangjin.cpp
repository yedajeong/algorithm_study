#include <iostream>
#include <cmath>
using namespace std;

bool arr[4000001] = { false };  
int sosu[1000000] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	int idx = 0;

	for (int i = 2; i <= (int)sqrt(N); i++) {
		if (arr[i]) {
			continue;
		}

		for (int j = i + i; j <= 4000000; j += i) {
			arr[j] = true;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (!arr[i]) {
			sosu[idx++] = i;
		}
	}

	int start = 0;
	int end = 0;
	int sum = 0;
	int cnt = 0;

	while (start < idx) {
		if (end == idx) {
			if (sum < N) {
				break;
			}
			else {
				if (sum == N) {
					cnt++;
					break;
				}
				else {
					sum -= sosu[start];
					start++;
				}
			}
		}
		else {
			if (sum < N) {
				sum += sosu[end];
				end++;
			}
			else if (sum == N) {
				cnt++;
				sum -= sosu[start];
				start++;
			}
			else {
				sum -= sosu[start];
				start++;
			}
		}
	}

	cout << cnt << endl;
}

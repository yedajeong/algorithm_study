#include <iostream>
#include <algorithm>
using namespace std;

long long int hap[100001] = { 0 };

int main() {
	long long int N, S;
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> hap[i];
	}
	long long int answer = 100001, sum = 0, start = 0, end = 0;

	while (start < N) {
		if (sum >= S) {
			answer = min(answer, end - start);
			sum -= hap[start];
			start++;
		}
		else {
			if (end != N) {
				sum += hap[end];
				end++;
			}
			else
				break;
		}
	}

	if (answer == 100001) {
		cout << "0" << '\n';
		return 0;
	}
	else {
		cout << answer << '\n';
	}
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> lan;

long long binary_search(long long start,long long end, long long value) {
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long lines = 0;

		for (auto x : lan) {
			lines += x / mid;
		}

		if (lines >= value) {
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	return end;
}


int main() {
	long long  K, N, max_num = 0;
	cin >> K >> N;
	
	for (int i = 0; i < K; i++) {
		long long a;
		cin >> a;
		max_num = max(a, max_num);
		lan.push_back(a);
	}

	cout << binary_search(1, max_num, N) << '\n';
}

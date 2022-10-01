#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> tree;

long long binary_search(long long start, long long end, long long value) {
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long length = 0;
		for (auto x : tree) {
			if (mid == 0) {
				return mid;
			}
			else {
				if (x / mid >= 1) {
					length += (x - mid);
				}
			}
		}

		if (length >= value) {
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	return end;
}

int main() {
	long long N, M;
	cin >> N >> M;

	long long max_tree = 0;
	for (int i = 0; i < N; i++) {
		long long a;
		cin >> a;
		max_tree = max(max_tree, a);
		tree.push_back(a);
	}

	long long max_height = binary_search(0, max_tree, M);

	cout << max_height << '\n';
}

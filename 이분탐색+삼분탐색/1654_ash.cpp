// 랜선 자르기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int k, n;
	cin >> k >> n;

	vector<long long> vec;
	long long max_num = 0;
	for (int i = 0; i < k; i++) {
		long long input;
		cin >> input;
		max_num = max(max_num, input);
		vec.push_back(input);
	}

	long long last = max_num;
	int vec_size = vec.size();

	int count = 0;
	long long first = 1;
	long long mid = 0;
	
	while (first <= last) {
		count = 0;
		mid = (first + last) / 2;

		for (int i = 0; i < vec_size; i++) {
			count += vec[i] / mid;
		}

		if (count < n) {
			last = mid - 1;
		}
		else {
			first = mid + 1;
		}
	}

	cout << last << '\n';

	return 0;
}

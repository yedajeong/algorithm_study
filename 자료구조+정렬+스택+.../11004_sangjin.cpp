#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int input_num, input_size;
	long long a;
	vector<long long> v;
 	cin >> input_num >> input_size;

	for (int i = 0; i < input_num; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	cout << v[input_size - 1] << '\n';
}

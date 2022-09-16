#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int input_num, num_re;

	cin >> input_num >> num_re;

	v.push_back(input_num);

	int count = 0;
	while (true) {
		int result = 0;
		int a = v[count];

		while (a > 0) {
			int k = a % 10;
			int t = a / 10;
			result += pow(k,num_re);
			a = t;
		}

		if (find(v.begin(), v.end(), result) != v.end()) {
			int index = find(v.begin(), v.end(), result) - v.begin();
			cout << index << '\n';
			break;
		}
		else {
			v.push_back(result);
			count++;
		}

	}
	return 0;
}

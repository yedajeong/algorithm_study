#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int gc = a % b;
		a = b;
		b = gc;
	}
	return a;
}

int main() {
	int test_case, case_num;

	vector<long long> gcd_vec;

	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		long long gcd_num = 0;
		vector<int> v = {};
		cin >> case_num;
		
		for (int j = 0; j < case_num; j++) {
			int input_num;
			cin >> input_num;
			v.push_back(input_num);
			for (int n = 0; n < v.size() - 1; n++) {
				gcd_num += gcd(input_num, v[n]);
			}
		}
		gcd_vec.push_back(gcd_num);
	}

	for (auto x : gcd_vec) {
		cout << x << '\n';
	}
}

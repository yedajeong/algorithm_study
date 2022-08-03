#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	long long input_num ,ip_case;
	vector<int> v;

	cin >> input_num >> ip_case;
	
	while (input_num != 0) {
		int gcd = input_num % ip_case;
		input_num = input_num / ip_case;
		v.push_back(gcd);
	}

	for (int i = v.size()-1; i >= 0; i--) {
		if (v[i] >= 10 && v[i] <= 35) {
			v[i] += 55;
			cout << (char)v[i];
		}
		else
			cout << v[i];
	}
	cout << '\n';
}

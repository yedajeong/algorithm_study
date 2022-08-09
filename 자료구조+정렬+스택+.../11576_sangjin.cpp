#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int a_num, b_num, input_case;
	int final_num = 0;
	vector <int> vec, print_v;

	cin >> a_num >> b_num;

	cin >> input_case;

	for (int i = 0; i < input_case; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}

	reverse(vec.begin(), vec.end());

	
	for (int i = 0; i < vec.size(); i++) {
		int b = vec[i] * pow(a_num, i);
		final_num += b;
	}

	while (final_num != 0) {
		int gcd = final_num % b_num;
		final_num = final_num / b_num;
		print_v.push_back(gcd);
	}
	
	reverse(print_v.begin(), print_v.end());

	for (auto x : print_v) {
		cout << x << " ";
	}
}

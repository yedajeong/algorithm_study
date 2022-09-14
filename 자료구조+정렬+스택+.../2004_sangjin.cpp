#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a_num, b_num;

	cin >> a_num >> b_num;

	long long count_o = 0; //5
	long long count_e = 0; //2 

	for (long long i = 5; i <= a_num; i *= 5) {
		long long k = a_num / i;
		count_o += k;
	}
	for (long long i = 2; i <= a_num; i *= 2) {
		long long k = a_num / i;
		count_e += k;
	}

	for (long long i = 5; i <= a_num - b_num; i *= 5) {
		long long k = (a_num - b_num) / i;
		count_o -= k;
	}
	for (long long i = 2; i <= a_num - b_num; i *= 2) {
		long long k = (a_num - b_num) / i;
		count_e -= k;
	}

	for (long long i = 5; i <= b_num; i *= 5) {
		long long k = (b_num) / i;
		count_o -= k;
	}
	for (long long i = 2; i <= b_num; i *= 2) {
		long long k = (b_num) / i;
		count_e -= k;
	}

	cout << min(count_o, count_e) << '\n';
}

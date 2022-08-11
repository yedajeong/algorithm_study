#include <iostream>
using namespace std;

int main() {
	//nCr == n!/r!(n-r)!
	//1676번과 다르게 2의 갯수도 세야한다.
	long long m, n;
	
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;

	long long count5 = 0;
	long long count2 = 0;

	for (long long i = 5; i <= n; i *= 5) { 
		count5 += n / i;
	}
	for (long long i = 2; i <= n; i *= 2) {
		count2 += n / i;
	}

	for (long long i = 5; i <= m; i *= 5) {
		count5 -= m / i;
	}
	for (long long i = 2; i <= m; i *= 2) {
		count2 -= m / i;
	}

	for (long long i = 5; i <= n-m; i *= 5) {
		count5 -= (n-m) / i;
	}
	for (long long i = 2; i <= n-m; i *= 2) {
		count2 -= (n-m) / i;
	}

	cout << min(count5,count2) << '\n';

	return 0;
}

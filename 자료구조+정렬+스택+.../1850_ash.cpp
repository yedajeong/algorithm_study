#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int gcd(unsigned long long n, unsigned long long m) { //유클리드 호제법
	if (n >= m) {
		while (m != 0) {
			unsigned long long r = n % m;
			n = m;
			m = r;
		}
		return n;
	}
	else {
		while (n != 0) {
			unsigned long long r = m % n;
			m = n;
			n = r;
		}
		return m;
	}

}
int main() {
	unsigned long long n, m; //a;
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	int g = gcd(n, m);

	/* 이게 왜 안되지...?
	a = 1;

	for (int i = 0; i < g - 1; i++) {
		a = a * 10 + 1;
	}
	
	cout << a << '\n';
	*/

	for (int i = 0; i < g; i++) {
		cout << 1;
	}

	return 0;
}

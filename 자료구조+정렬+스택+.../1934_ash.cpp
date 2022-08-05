#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int gcd(int n, int m) { //유클리드 호제법
	if (n >= m) {
		while (m != 0) {
			int r = n % m;
			n = m;
			m = r;
		}
		return n;
	}
	else {
		while (n != 0) {
			int r = m % n;
			m = n;
			n = r;
		}
		return m;
	}

}
int main() {
	int n, m, a, b,k;
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> n >> m;

		int g = gcd(n, m);
		a = n / g;
		b = m / g;
		int l = g * a * b;

		cout << l << '\n';
	}


	return 0;
}

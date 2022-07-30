#include <iostream>
using namespace std;

int main() {
	long a, c; // 자료형 주의
	int b, d;
	cin >> a >> b >> c >> d;
	
	int multb, multd;
	
	multb = b;
	multd = d;

	while (multb > 0) {
		a *= 10;
		multb /= 10;
	}

	while (multd > 0) {
		c *= 10;
		multd /= 10;
	}

	cout << a + b + c + d << '\n';

	return 0;
}

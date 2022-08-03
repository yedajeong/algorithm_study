#include <iostream>
#include <string>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long  b) {
	while (b != 0) {
		unsigned long long gc = a % b;
		a = b;
		b = gc;
	}
	return a;
}

int main() {
	unsigned long long A, B, big, small;

	cin >> A >> B;

	if (A > B) {
		big = gcd(A, B);
	}
	else if (B >= A) {
		big = gcd(B, A);
	}
	for (int i = 0; i < big; i++) {
		cout << "1";
	}

}

#include <iostream>
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
	int A, B;
	int big, small;

	cin >> A >> B;

	if (A > B) {
		big = gcd(A, B);
	}
	else if (B >= A) {
		big = gcd(B, A);
	}
	small = A * B / big;

	cout << big << '\n';
	cout << small << '\n';
}

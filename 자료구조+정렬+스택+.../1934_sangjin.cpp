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
	int A, B, input_num;
	int big, small;
	vector<int> v;

	cin >> input_num;
	for (int i = 0; i < input_num; i++) {
		cin >> A >> B;

		if (A > B) {
			big = gcd(A, B);
		}
		else if (B >= A) {
			big = gcd(B, A);
		}
		small = A * B / big;

		v.push_back(small);
	}

	for (auto x : v) {
		cout << x << '\n';
	}

}

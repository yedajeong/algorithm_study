#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	for (int i = 2; i <= sqrt(n); i++) {
		while (n != 0) {
			if (n % i == 0) {
				cout << i << '\n';
				n /= i;
			}
			else break;
		}
	}
	
	if (n != 1) {
		cout << n << '\n';
	}

	return 0;
}

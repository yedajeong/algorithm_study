#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	bool arr[1000001] = { false }; //1로는 초기화가 안되는듯?
	
	for (int i = 2; i <= 1000000; i++) {
		arr[i] = true;
	}

	for (int i = 2; i <= sqrt(1000000); i++) {
		if (arr[i] == true) {
			for (int j = i * i; j < 1000000; j += i) {
				if (arr[j] == true) arr[j] = false;
			}
		}
	}//소수이면 true, 아니면 false

	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			exit(0);
		}

		for (int j = 2; j <= n / 2; j++) {
			if (arr[j] == true && arr[n - j] == true) {
				cout << n << " = " << j << " + " << n - j << "\n";
				break;
			}
			else if (j == n / 2) {
				cout << "Goldbach's conjecture is wrong." << '\n';
			}
		}
	}
	return 0;
}

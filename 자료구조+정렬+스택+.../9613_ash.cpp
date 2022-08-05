#include <iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int t,n;
	int arr[100] = { 0 };
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		
		long long sum = 0;

		for (int j = 0; j < n-1; j++) {
			for (int k = j+1; k < n; k++) {
				sum += gcd(arr[j], arr[k]);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}

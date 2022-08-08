#include <iostream>
using namespace std;

int main() {
	int n, num;
	
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;
	int count = 0;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 2) {
			count++;
		}
		else {
			for (int j = 2; j < num; j++) {
				if (num % j == 0) {
					break;
				}
				else if (num % j != 0 && j == num - 1) {
					count++;
				}
			}
		}
	}
	cout << count << '\n';

	return 0;
}

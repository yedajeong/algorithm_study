#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	string input;
	cin >> input;

	//첫번째 수 
	int n = input[0] - 48;
	int r = n % 4;
	if (n / 4 != 0) {
		cout << n / 4;
		cout << r / 2;
	}
	else {
		if (r / 2 != 0) {
			cout << r / 2;
		}
	}
	cout << r % 2;

	for (int i = 1; i < input.size(); i++) {
		cout << (input[i] - 48) / 4;
		int r = (input[i] - 48) % 4;
		cout << r / 2;
		cout << r % 2;
	}
	cout << '\n';

	return 0;
}

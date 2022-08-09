#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	stack<int> s;
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	if (n == 0) {
		cout << "0" << '\n';
	}

	while (n != 0) {
		int r = n % (-2);
		if (r < 0) {
			s.push(1);
			n = n / (-2) + 1;
		}
		else {
			s.push(n % (-2));
			n /= (-2);
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << '\n';

	return 0;
}

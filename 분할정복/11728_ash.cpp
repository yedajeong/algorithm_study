#include <iostream>
using namespace std;

int a[1000001] = { 0 };
int b[1000001] = { 0 };
int c[2000002] = { 0 };

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		a[i] = input;
	}

	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		b[i] = input;
	}

	int a_idx = 0;
	int b_idx = 0;
	int c_idx = 0;

	while (a_idx < n && b_idx < m) { //merge
		if (a[a_idx] >= b[b_idx]) {
			c[c_idx] = b[b_idx];
			b_idx++;
		}
		else {
			c[c_idx] = a[a_idx];
			a_idx++;
		}
		c_idx++;
	}

	while (a_idx < n) { //a가남음
		c[c_idx] = a[a_idx];
		c_idx++;
		a_idx++;
	}

	while(b_idx < m){//b가 남음
		c[c_idx] = b[b_idx];
		c_idx++;
		b_idx++;
	}

	for (int i = 0; i < n + m; i++) {
		cout << c[i] << " ";
	}
	

	return 0;
}

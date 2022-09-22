#include <iostream>
#include <cmath>
using namespace std;

int next(int a, int p) {
	int next = 0;
	while (a != 0) {
		int r = a % 10;
		next += pow(r, p);
		a /= 10;
	}
	return next;
}

int visit[1000000] = { 0 };

int main() {
	int A, P;
	cin >> A >> P;

	int n = A;
	int idx = 1;

	while (visit[n] == 0) {
		visit[n] = idx;
		n = next(n, P);
		idx++;
	}

	cout << visit[n]-1 << '\n';
	
	return 0;
}

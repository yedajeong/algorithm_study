#include <iostream>
#include <cmath>
using namespace std;


void hanoi_top(int n, int start,int bypass,int end) {
	if (n == 1) {
		cout << start << " " << end << '\n';
		return;
	}
	else {
		hanoi_top(n - 1, start, end, bypass);
		cout << start << " " << end << '\n';
		hanoi_top(n - 1, bypass, start, end);
	}
}

int main() {
	int N;
	cin >> N;
	cout << (int)pow(2,N) - 1 << endl;
	hanoi_top(N, 1, 2, 3);
	return 0;
}

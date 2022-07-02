#include <iostream>
using namespace std;

int main() {
	int n, T;
	cin >> T;
	int sol[11] = { 0 * 11 };
	
	sol[0] = 0;
	sol[1] = 1;
	sol[2] = 2;
	sol[3] = 4;

	for (int i = 4; i < 11; i++ ) {
			sol[i] = sol[i-1]+sol[i-2]+sol[i-3];
	}

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << sol[n] <<endl;
	}

	return 0;
}
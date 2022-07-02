#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* sol = new int[n+1]; //¼ıÀÚ¶û ÀÎµ¦½º¶û ¸ÂÃß±â
	sol[1] = 0;
	for (int i = 2; i < n + 1; i++) {
		sol[i] = 1000000;
		if (i % 2 == 0) {
			if (sol[i / 2] + 1 < sol[i])
				sol[i] = sol[i / 2] + 1;
		}
		if (i % 3 == 0) {
			if (sol[i / 3] + 1 < sol[i])
				sol[i] = sol[i / 3] + 1;
		}
		
		if (sol[i - 1] + 1 < sol[i]) {
			sol[i] = sol[i - 1] + 1;
		}	
	}

	cout << sol[n];
}
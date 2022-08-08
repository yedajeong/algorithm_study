#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int m, n;
	bool *isprime;
	
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> m >> n;
	isprime = new bool[n + 1];
	
	isprime[0] = false;
	isprime[1] = false;

	for (int i = 2; i <= n; i++) {
		isprime[i] = true;
	}

	//에라토스테네스의 체
	for (int i = 2; i <= sqrt(n); i++) { // j = i*i 이므로  i<=sqrt(n)이다.
		if (isprime[i] == true) {
			for (int j = i * i; j <= n; j += i) { //앞에서 지워지기 때문에 i*i부터 확인
				if(isprime[j] == true) isprime[j] = false;
			}
		}
	}
	
	for (int i = m; i <= n; i++) {
		if (isprime[i] == true) cout << i << '\n';
	}

	delete[] isprime;

	return 0;
}

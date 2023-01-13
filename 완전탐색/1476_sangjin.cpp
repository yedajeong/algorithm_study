#include <iostream>
using namespace std;

int main() {
	int E, S, N;
	cin >> E >> S >> N;

	int result = 0; 

	for (int i = 1; i <= 7980; i++) {
		if (i % 15 == E % 15) {
			if (i % 28 == S % 28)
				if (i % 19 == N % 19) {
					result = i;
					break;
				}
		}

	}
	cout << result << '\n';
}

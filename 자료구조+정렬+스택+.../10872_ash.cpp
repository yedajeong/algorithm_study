#include <iostream>
using namespace std;

int main() {
	int N;
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;

	int result = 1;

	for (int i = 1; i <= N; i++) {
		result *= i;
	}
	
	cout << result << '\n';

	return 0;
}

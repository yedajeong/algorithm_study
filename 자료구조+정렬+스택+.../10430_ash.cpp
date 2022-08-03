#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> A >> B >> C;
	cout << (A + B) % C << '\n';
	cout << ((A % C) + (B % C)) % C << '\n';
	cout << (A * B) % C << '\n';
	cout << ((A % C) * (B % C)) % C << '\n';

	return 0;
}

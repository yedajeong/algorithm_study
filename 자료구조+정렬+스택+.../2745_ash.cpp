#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	int b, result=0;
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> b;

	for (int i = n.size() - 1; i >= 0; i--) {
		int count = 1;
		for (int j = i; j < n.size() - 1; j++) {
			count *= b;
		}
		
		if (n[i] <= 57) { //숫자일때
			result += count * (n[i]-48);
		}
		else { //알파벳
			result += count * (n[i] - 55);
		}
	}

	cout << result << "\n";

	return 0;
}

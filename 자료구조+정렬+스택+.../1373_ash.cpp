#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	
	string input;

	cin >> input;

	int t = input.size();
	int r = t % 3;

	if (r == 1) {
		cout << (input[0]-48);
	}
	else if(r == 2) {
		cout << (input[0] - 48) * 2 + (input[1] - 48);
	}

	for (int i = r; i < t-2; i+=3) {
		cout << (input[i]-48) * 4 + (input[i + 1]-48) * 2 + (input[i + 2]-48);
	}
	
	cout << '\n';

	return 0;
}

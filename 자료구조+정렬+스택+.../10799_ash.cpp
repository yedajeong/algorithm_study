#include <iostream>
#include <string>
using namespace std;

int main() {
	int stick = 0;
	int cut = 0;
	string input;
	
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(') {
			stick++;
		}
		else {
			stick--;
			if (input[i - 1] == '(') {
				cut += stick;
			}
			else {
				cut++;
			}
		}
	}

	cout << cut << '\n';

	return 0;
}

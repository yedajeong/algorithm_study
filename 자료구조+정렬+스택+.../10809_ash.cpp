#include <iostream>
#include <string>
using namespace std;


int main() {
	int arr[26];
	string input;
	
	for (int i = 0; i < 26; i++) {
		arr[i] = -1;
	}

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	

	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		if (arr[input[i] - 97] == -1) {
			arr[input[i] - 97] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}

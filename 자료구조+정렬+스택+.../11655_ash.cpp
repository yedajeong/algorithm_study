#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	getline(cin, input);
/*
	for (int i = 0; i < input.length(); i++) {
		if (input[i] > 64 && input[i] < 91) { //대문자일 때
			if (input[i] + 13 < 91) {
				input[i] = char(input[i] + 13);
			}
			else {
				input[i] = char(input[i] + 13 - 26);
			}
		}
		else if (input[i] > 96 && input[i] < 123) { //소문자일때
			if (input[i] + 13 < 123) {
				input[i] = char(input[i] + 13);
			}
			else {
				input[i] = char(input[i] + 13 - 26);
			}
		}
	}
*/
	for (int i = 0; i < input.length(); i++) {
		if (input[i] > 64 && input[i] < 78) { //대문자일 때
			input[i] = char(input[i] + 13);
		}
		else if (input[i] > 77 && input[i] < 91) {
			input[i] == char(input[i] - 13);
		}
		else if (input[i] > 96 && input[i] < 110) { //소문자일때
			input[i] = char(input[i] + 13);
		}
		else if (input[i] > 109 && input[i] < 123) {
			input[i] == char(input[i] - 13);
		}
	}

	cout << input << '\n';

	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
	string word;
	
	int count_alpha[27] = { 0, };
	
	for (int i = 0; i < 26; i++) {
		count_alpha[i] = -1;
	}
	
	cin >> word;

	int length = word.size();


	for (int i = 0; i < length; i++) {
		if (count_alpha[word[i] - 97] == -1) {
			count_alpha[word[i] - 97] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << count_alpha[i] << " ";
	}
}

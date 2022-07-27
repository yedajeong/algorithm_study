#include <iostream>
#include <string>
using namespace std;

int main() {
	string sentence;
	while (getline(cin, sentence)) {
		int AlPha = 0;
		int alpha = 0;
		int num = 0;
		int space = 0;
		for (int i = 0; i < sentence.size(); i++) {
			if (sentence[i] >= 65 && sentence[i] <= 91) {
				AlPha++;
			}
			if (sentence[i] >= 97 && sentence[i] <= 122) {
				alpha++;
			}
			if (sentence[i] >= 48 && sentence[i] <= 57) {
				num++;
			}
			if (sentence[i] == 32) {
				space++;
			}
		}
		cout << alpha << " " << AlPha << " " << num << " " << space << '\n';
	}
}

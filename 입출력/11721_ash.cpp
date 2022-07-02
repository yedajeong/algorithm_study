#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int iter = str.length() / 10 + 1;
	for (int i = 0; i < iter; i++) {
		cout << str.substr(i * 10, 10) << endl;
	}

	return 0;
}
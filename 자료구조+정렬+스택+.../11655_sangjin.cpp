#include <iostream>
#include <string>
using namespace std;

int main() {
	string password;

	getline(cin, password);

	int length = password.size();

	for (int i = 0; i < length; i++) {  //n이 기준
		if (password[i] >= 65 && password[i] <= 77) {
			password[i] += 13;
		}
		else if (password[i] >= 78 && password[i] <= 90) {
			password[i] -= 13;
		}
		else if (password[i] >= 97 && password[i] <= 109) {
			password[i] += 13;
		}
		else if (password[i] >= 110 && password[i] <= 122) {
			password[i] -= 13;
		}
	}

	for (int i = 0; i < length; i++) {
		cout << password[i];
	}
}

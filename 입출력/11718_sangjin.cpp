#include <iostream>
#include <string>
using namespace std;

int main() {
	string print_a;
	while (true) {
		getline(cin, print_a);
		if(print_a == "")
			break;
		cout << print_a << endl;

	}
}
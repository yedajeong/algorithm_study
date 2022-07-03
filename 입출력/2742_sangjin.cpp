#include <iostream>
using namespace std;

int main() {
	int print_num;

	cin >> print_num;

	for (int i = 0; i < print_num; i++) {
		cout << print_num - i << endl;
	}
	return 0;
}
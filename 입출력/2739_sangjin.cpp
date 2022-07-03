#include <iostream>
using namespace std;

int main() {
	int print_num;

	cin >> print_num;

	for (int i = 0; i < 9; i++) {
		cout << print_num << " * " << i + 1 << " = "
			<< print_num * (i + 1) << endl;
	}
	return 0;
}
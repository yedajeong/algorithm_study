#include <iostream>
using namespace std;

int main() {
	int input_num;
	int total_num = 0;

	cin >> input_num;

	for (int i = 0; i < input_num; i++) {
		total_num += i + 1;
	}

	cout << total_num << '\n';

	return 0;
}
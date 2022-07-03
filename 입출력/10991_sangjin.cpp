#include <iostream>
using namespace std;

int main() {
	int input_num;

	cin >> input_num;

	for (int i = 0; i < input_num; i++) {
		for (int j = 0; j < input_num - i - 1; j++) 
			cout << " ";
		for (int k = 0; k < i+1; k++) 
			cout << "* ";
			
		cout << '\n';
	}
}
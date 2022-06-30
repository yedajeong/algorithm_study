#include <iostream>
#include <string>
using namespace std;

int main() {
	int size_num, last_num;
	string input_string;

	cin >> input_string;

	size_num = (input_string.size() / 10);

	for (int i = 0; i < size_num ; i++) {
		string print_string = input_string.substr((i)*10 ,10);
		cout << print_string << endl;
	}
	cout << input_string.substr((size_num) * 10);

	
}
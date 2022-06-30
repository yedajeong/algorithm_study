#include <iostream>
#include <string>
using namespace std;

int main() {
	int input_num;
	int total_num = 0;
	string input_string;

	cin >> input_num;
	cin >> input_string;

	for (int i = 0; i < input_num; i++) {
		string num = input_string.substr(i, 1);
		total_num += stoi(num);
	}
	cout << total_num << endl;

}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int command_num;
	string command;
	vector<int> v;
	cin >> command_num;

	for (int i = 0; i < command_num; i++) {
		cin >> command;
		int size = v.size();
		if (command == "push") {
			int n;
			cin >> n;
			v.push_back(n);
		}
		if (command == "pop") {
			if (size == 0) {
				cout << "-1" << '\n';
			}
			else {
				cout << v[size-1] << '\n';
				v.pop_back();
			}
		}
		if (command == "size") {
			cout << size << '\n';
		}
		if (command == "empty") {
			if (size == 0) {
				cout << "1" << '\n';
			}
			else
				cout << "0" << '\n';
		}
		if (command == "top") {
			if (size == 0)
				cout << "-1" << '\n';
			else
				cout << v[size-1] << '\n';
		}
	}
}

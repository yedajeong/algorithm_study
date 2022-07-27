#include <iostream>
#include <string>
using namespace std;

int main() {
	int input_case;
	string structure;
	cin >> input_case;


	for (int i = 0; i < input_case; i++) {
		cin >> structure;
		int size = structure.size();
		int right_stu = 0;
		int left_stu = 0;
		for (int j = 0; j < size; j++) {
			string a = structure.substr(j, 1);
			if (a == "(") {
				left_stu++;
			}
			else if (a == ")") {
				right_stu++;
			}

			if (left_stu < right_stu)
				right_stu = right_stu + 51;
		}

 		if (left_stu == right_stu)
			cout << "YES" << '\n';
		else if (left_stu != right_stu)
			cout << "NO" << '\n';
	}
}

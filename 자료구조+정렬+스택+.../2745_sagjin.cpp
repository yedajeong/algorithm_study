#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	string input_num;
	int ip_case;
	vector<string> v;
	int print_num = 0;

	cin >> input_num >> ip_case;

	for (int i = input_num.size() - 1; i >= 0; i--) {
		int a = input_num[i];
		if (a >= 65 && a <= 90) {
			a -= 55;
		}
		else if (a >= 48 && a <= 57) {
			a -= 48;
		}
	
		a *= pow(ip_case, input_num.size() - 1 - i);

		print_num += a; 
	}

	cout << print_num << '\n';	

	return 0;
}

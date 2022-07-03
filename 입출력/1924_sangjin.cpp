#include <iostream>
using namespace std;

int main() {
	int month_num, day_num, total_num;

	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	cin >> month_num >> day_num;

	for (int i = 0; i < month_num - 1; i++) {
		day_num += month[i];
	}

	total_num = day_num % 7;

	if (total_num == 0)
		cout << "SUN" << '\n';
	else if (total_num == 1)
		cout << "MON" << '\n';
	else if (total_num == 2)
		cout << "TUE" << '\n';
	else if (total_num == 3)
		cout << "WED" << '\n';
	else if (total_num == 4)
		cout << "THU" << '\n';
	else if (total_num == 5)
		cout << "FRI" << '\n';
	else if (total_num == 6)
		cout << "SAT" << '\n';

}
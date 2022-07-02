#include <iostream>
using namespace std;

/*
int main() {
	int x, y;
	cin >> x >> y; 
	int sum = 0;
	int day = 0;
	
	for (int i = 0; i < (x-1); i++) {
		if ((i + 1) == 1 || (i + 1) == 3 || (i + 1) == 5 || (i + 1) == 7 || (i + 1) == 8 || (i + 1) == 10 || (i + 1) == 12) {
			sum += 31;
		}
		else if ((i + 1) == 4 || (i + 1) == 6 || (i + 1) == 9 || (i + 1) == 11) {
			sum += 30;
		}
		else {
			sum += 28;
		}
	}

	sum += (y-1);
	day = sum % 7;
	
	if (day == 0) {
		cout << "MON" << endl;
	}
	else if (day == 1) {
		cout << "TUE" << endl;
	}
	else if (day == 2) {
		cout << "WED" << endl;
	}
	else if (day == 3) {
		cout << "THU" << endl;
	}
	else if (day == 4) {
		cout << "FRI" << endl;
	}
	else if (day == 5) {
		cout << "SAT" << endl;
	}
	else {
		cout << "SUN" << endl;
	}

	return 0;
}
*/

//수정 (배열 사용)
int main() {
	int x, y;
	cin >> x >> y;
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 0;
	for (int i = 0; i < x - 1; i++) {
		sum += month[i];
	}

	sum += (y - 1);
	char day[7][4] = { "MON","TUE","WED","THU","FRI","SAT","SUN" }; //char은 각 문자열 끝에 '\0'이 들어가는 공간이 필요하기 때문에 3글자면 [4]필요
	
	cout << day[sum % 7] << endl;

	return 0;
}

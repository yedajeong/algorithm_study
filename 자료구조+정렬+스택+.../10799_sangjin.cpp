#include <iostream>
#include <string>
#include <vector>
using namespace std;

string v[1000001];

int main() {
	string laser;

	cin >> laser;

	int length = laser.size();
	int left_stu = 1; // "(" 시작점
	int total_stu = 0;
	for (int i = 0; i < length; i++) {
		string a = laser.substr(i, 1);
		v[i] = a;
	}

	for (int j = 1; j < length; j++) {
		if (v[j - 1] == "(" && v[j] == ")") {
			left_stu--;
			total_stu = total_stu + left_stu;
		}
		if (v[j - 1] == "(" && v[j] == "(") {
			left_stu++;
		}
		if (v[j - 1] == ")" && v[j] == ")") {
			left_stu--;
			total_stu++;
		}
		if (v[j - 1] == ")" && v[j] == "(") {
			left_stu++;
		}
	}
	
	cout << total_stu << '\n';
}

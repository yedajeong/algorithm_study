#include <iostream>
//#include <vector>
#include <cmath>
//#include <algorithm>
#include <stack>
using namespace std;

int main() {
	//입력
	int A, B, m;
	cin >> A >> B;
	cin >> m;
	int input[25] = { 0 };
	for (int i = 0; i < m; i++) {
		cin >> input[i];
	}

	//A진법 -> 10진법
	int ten = 0;
	for (int i = 0; i < m; i++) {
		ten += input[m - 1 - i] * pow(A, i);
	}
	//cout << ten << '\n'; //확인용

	//10진법 -> B진법 
	/*
	vector<int> result;
	while (ten / B != 0) {
		int r = ten % B;
		result.push_back(r);
		ten = ten / B;
	}
	result.push_back(ten);
	reverse(result.begin(), result.end());
	*/

	stack<int> result; //스택사용
	while (ten != 0) {
		result.push(ten % B);
		ten /= B;
	}

	//출력
	/*
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << '\n';
	*/

	while (!result.empty()) {
		cout << result.top() << " ";
		result.pop();
	}
	cout << '\n';

	return 0;
}

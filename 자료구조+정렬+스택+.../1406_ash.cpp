#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string N;
	char command;
	int M;
	stack<char> left,right;

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N.length(); i++) {
		left.push(N[i]);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> command;
		if (command == 'L') { //커서를 왼쪽으로
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (command == 'D') { //커서를 오른쪽으로
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (command == 'B') { //커서 왼쪽의 문자 삭제
			if (!left.empty()) {
				left.pop();
			}
		}
		else if (command == 'P') { //커서 왼쪽에 문자 추가
			char input;
			cin >> input;
			left.push(input);
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}

	cout << '\n';
	return 0; 
}

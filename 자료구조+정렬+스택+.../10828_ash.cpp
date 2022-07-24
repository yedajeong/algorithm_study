#include <iostream>
#include <string>
using namespace std;

//stack 구현 (구조체로)
struct stack {
	int arr[10000];
	int last;

	void init() {
		last = -1; //초기화
	}
	void push(int x) {
		last++;
		arr[last] = x;
	}
	int size() {
		return last + 1;
	}
	bool empty() {
		return (last < 0);
	}
	int top() {
		if (empty()) {
			return -1;
		}
		else {
			return arr[last];
		}
	}
	int pop() {
		int result;
		if (empty()) {
			result = -1;
		}
		else {
			result = arr[last];
			last--;
		}
		return result;
	}
};

int main() {
	int N,num;
	string command;
	stack s;
	s.init();

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push") {
			cin >> num;
			s.push(num);
		}
		else if (command == "top") {
			cout << s.top() <<'\n';
		}
		else if (command == "size") {
			cout << s.size() << '\n';
		}
		else if (command == "pop") {
			cout << s.pop() << '\n';
		}
		else if (command == "empty") {
			cout << s.empty() << '\n';
		}
	}
	return 0;
}


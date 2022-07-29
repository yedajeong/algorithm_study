#include <iostream>
#include <string>
using namespace std;

//queue 구현 (구조체로)
struct que {
	int arr[10000];
	int b;
	int f;

	void init() {
		f = 0;
		b = -1; //초기화
	}
	void push(int x) {
		b++;
		arr[b] = x;
	}
	int size() {
		return (b-f+1);
	}
	bool empty() {
		return (f > b);
	}
	int pop() {
		int result;
		if (empty()) {
			result = -1;
		}
		else {
			result = arr[f];
			f++;
		}
		return result;
	}
	int front() {
		if (empty()) {
			return -1;
		}
		else {
			return (arr[f]);
		}
	}
	int back() {
		if (empty()) {
			return -1;
		}
		else {
			return arr[b];
		}
	}
};

int main() {
	int N, num;
	string command;
	que q;
	q.init();

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push") {
			cin >> num;
			q.push(num);
		}
		else if (command == "front") {
			cout << q.front() << '\n';
		}
		else if (command == "size") {
			cout << q.size() << '\n';
		}
		else if (command == "pop") {
			cout << q.pop() << '\n';
		}
		else if (command == "empty") {
			cout << q.empty() << '\n';
		}
		else if (command == "back") {
			cout << q.back() << '\n';
		}
	}
	return 0;
}


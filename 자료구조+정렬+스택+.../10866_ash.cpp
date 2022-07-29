#include <iostream>
using namespace std;

struct deque{
	int arr[10000];
	int fr;
	int ba;
	int s;

	void init() {
		fr = 10001;
		ba = 10000;
		s = 0;
	}
	void push_front(int x) {
		fr--;
		arr[fr%10000] = x;
		s++;
	}
	void push_back(int x) {
		ba++;
		arr[ba%10000] = x;
		s++;
	}
	bool empty() {
		return(s == 0);
	}
	int size() {
		return s;
	}
	int pop_front() {
		if (empty()) {
			return -1;
		}
		else {
			int result = arr[fr % 10000];
			fr++;
			s--;
			return result;
		}
	}
	int pop_back() {
		if (empty()) {
			return -1;
		}
		else {
			int result = arr[ba % 10000];
			ba--;
			s--;
			return result;
		}
	}
	int front() {
		if (empty()) {
			return -1;
		}
		else {
			return arr[fr % 10000];
		}
	}
	int back() {
		if (empty()) {
			return -1;
		}
		else {
			return arr[ba % 10000];
		}
	}
};

int main() {
	int N, num;
	string command;
	deque dq;
	dq.init();

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (command == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (command == "front") {
			cout << dq.front() << '\n';
		}
		else if (command == "size") {
			cout << dq.size() << '\n';
		}
		else if (command == "pop_back") {
			cout << dq.pop_back() << '\n';
		}
		else if (command == "pop_front") {
			cout << dq.pop_front() << '\n';
		}
		else if (command == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (command == "back") {
			cout << dq.back() << '\n';
		}
	}
	return 0;
}

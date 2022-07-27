#include<iostream>
using namespace std;

struct queue {
	int size, print_size, sqc; //i는 그냥 배열로 계속 밀고 가려고
	int a[10001];

	void Init() {
		sqc = 0;
		size = 0;
		print_size = 0;
	}

	void push_front(int x) {
		for (int n = sqc; n >= 0; n--) {
			a[n + 1] = a[n];
		}
		a[print_size] = x;
		sqc++;
		size++;
	}
	void push_back(int x) {
		a[sqc] = x;
		sqc++;
		size++;
	}
	int pop_front() {
		if (size == 0)
			return -1;
		else if (size != 0) {
			int t = a[print_size];
			print_size++;
			size--;
			return t;
		}
	}
	int pop_back() {
		if (size == 0)
			return -1;
		else if (size != 0) {
			int t = a[sqc - 1];
			sqc--;
			size--;
			return t;
		}
	}

	int sizeo() {
		return size;
	}

	int front() {
		if (size == 0)
			return -1;
		return a[print_size];
	}

	int back() {
		if (size == 0)
			return -1;
		return a[sqc - 1];
	}

	int empty() {
		if (size == 0)
			return 1;
		else
			return 0;
	}
};


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	queue v;
	v.Init();
	int command_num;
	cin >> command_num;

	string command;

	for (int i = 0; i < command_num; i++) {
		cin >> command;
		if (command == "push_front") {
			int n;
			cin >> n;
			v.push_front(n);
		}
		if (command == "push_back") {
			int n;
			cin >> n;
			v.push_back(n);
		}
		if (command == "pop_front") {
			cout << v.pop_front() << '\n';
		}
		if (command == "pop_back") {
			cout << v.pop_back() << '\n';
		}
		if (command == "size") {
			cout << v.sizeo() << '\n';
		}
		if (command == "empty") {
			cout << v.empty() << '\n';
		}
		if (command == "front") {
			cout << v.front() << '\n';
		}
		if (command == "back") {
			cout << v.back() << '\n';
		}
	}
}

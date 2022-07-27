#include<iostream>
using namespace std;

struct queue {
	int size, print_size, i; //i는 그냥 배열로 계속 밀고 가려고
	int a[10001];

	void Init() {
		i = 0;
		size = 0;
		print_size = 0;
	}

	void push(int x) {
		a[i] = x;
		i++;
		size++;
	}

	int pop() {
		if (size == 0)
			return -1;
		else if (size != 0) {
			int t = a[print_size];
			print_size++;
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
		return a[i - 1];
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
		if (command == "push") {
			int n;
			cin >> n;
			v.push(n);
		}
		if (command == "pop") {
			cout << v.pop() << '\n';
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

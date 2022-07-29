#include <iostream>
#include <string>
#include <stack>;
using namespace std; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input_num;
	string input_sentence, command;
	stack<char> s_left;
	stack<char> s_right;

	cin >> input_sentence >> input_num;

	int c = input_sentence.size();

	for (int i = 0; i < c; i++) {
		s_left.push(input_sentence[i]);
	}

	for (int i = 0; i < input_num; i++) {
		cin >> command;

		if (command == "L") {
			if (s_left.size()!=0) {
				s_right.push(s_left.top());
				s_left.pop();
			}
		}
		else if (command == "D") {
			if (s_right.size()!=0) {
				s_left.push(s_right.top());
				s_right.pop();

			}
		}
		else if (command == "P") {
			char n;
			cin >> n;
			s_left.push(n);
		}
		else if (command == "B") {
			if (s_left.size()!=0) {
				s_left.pop();
			}
		}
	}
	while (!s_left.empty())
	{
		s_right.push(s_left.top());
		s_left.pop();
	}

	while (!s_right.empty())
	{
		cout << s_right.top();
		s_right.pop();
	}
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class member {
public:
	int age;
	string name;
	int num;

	member(int _age, string _name, int _num) {
		age = _age;
		name = _name;
		num = _num;
	}
};

bool compare(member& a, member& b) {
	if (a.age < b.age) {
		return true;
	}
	else if (a.age == b.age) {
		if (a.num < b.num) {
			return true;
		}
		else
			return false;
	}
	else return false;
}

int main() {
	int N, age;
	string name;
	cin >> N;

	vector<member> v;

	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		v.push_back(member(age, name, i));
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << v[i].age << " " << v[i].name << '\n';
	}

	return 0;
}

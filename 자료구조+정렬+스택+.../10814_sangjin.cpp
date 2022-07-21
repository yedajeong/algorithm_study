#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Member {
public:
	int sequence,age;
	string name;

	Member(int _age, string _name, int _sequence) {
		age = _age;
		name = _name;
		sequence = _sequence;
	}

};

bool compare(Member& a, Member& b) {
	if (a.age < b.age) {
		return true;
	}
	else if (a.age == b.age) {
		if (a.sequence < b.sequence) {
			return true;
		}
		else return false;
	}
	else return false;
}

int main() {
	int input_num;
	int member_age;
	string member_name;
	vector<Member> v;
	cin >> input_num;
	
	for (int i = 0; i < input_num; i++) {
		cin >> member_age >> member_name;
		v.push_back(Member(member_age, member_name,i));
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < input_num; i++) {
		cout << v[i].age << ' ' << v[i].name << '\n';
	}
}

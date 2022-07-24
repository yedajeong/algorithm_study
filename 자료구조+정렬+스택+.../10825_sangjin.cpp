#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Member {
public:
	int math_score,korean_score, english_score;
	string name;

	Member( string _name, int  _korean_score, int _english_score, int _math_score) {
		name = _name;
		math_score = _math_score;
		korean_score = _korean_score;
		english_score = _english_score;
	
	}
};

bool compare(Member& a, Member& b) {
	if (a.korean_score > b.korean_score) {
		return true;
	}
	else if (a.korean_score == b.korean_score) {
		if (a.english_score < b.english_score) {
			return true;
		}
		else if (a.english_score == b.english_score) {
			if (a.math_score > b.math_score) {
				return true;
			}
			else if (a.math_score == b.math_score) {
				if (a.name < b.name) {
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}


int main() {
	int input_num;
	int member_korean, member_english, member_math;
	string member_name;
	vector<Member> v;
	cin >> input_num;

	for (int i = 0; i < input_num; i++) {
		cin >> member_name >> member_korean >> member_english >> member_math;
		v.push_back(Member(member_name, member_korean, member_english, member_math));
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < input_num; i++) {
		cout << v[i].name << '\n';
	}
}

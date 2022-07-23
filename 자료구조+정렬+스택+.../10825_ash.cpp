#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class member {
public:
	string name;
	int kor;
	int eng;
	int math;

	member(string _name, int _kor, int _eng, int _math) {
		name = _name;
		kor = _kor;
		eng = _eng;
		math = _math;
	}
};

bool compare(member& a, member& b) {
	if (a.kor > b.kor) {
		return true;
	}
	else if (a.kor == b.kor) {
		if (a.eng < b.eng) {
			return true;
		}
		else if (a.eng == b.eng) {
			if (a.math > b.math) {
				return true;
			}
			else if (a.math == b.math) {
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
	int N, kor, eng, math;
	string name;
	cin >> N;

	vector<member> v;

	for (int i = 0; i < N; i++) {
		cin >> name >> kor >> eng >> math;
		v.push_back(member(name, kor, eng, math));
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << v[i].name << '\n';
	}

	return 0;
}

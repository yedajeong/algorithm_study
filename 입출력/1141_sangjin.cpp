#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> vec;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		vec.push_back(s);
	}
	sort(vec.begin(), vec.end());

	int print_count = vec.size();
	for (int i = 0; i < vec.size(); i++) {
		int cnt = 0;
		for (int j = i; j < vec.size(); j++) {
			int x_size = vec[i].size();
			if (vec[i] == vec[j].substr(0, x_size))
				cnt++;
		}
		if (cnt > 1) {
			print_count--;
		}
	}

	cout << print_count << '\n';
}

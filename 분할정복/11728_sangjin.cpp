#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v1;
vector<int> v2;

bool compare(int a, int b) {
	return a > b;
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v1.push_back(a);
	}

	for (int j = 0; j < M; j++) {
		int b;
		cin >> b;
		v2.push_back(b);
	}
	sort(v1.begin(), v1.end(), compare);
	sort(v2.begin(), v2.end(), compare);

	while (!v1.empty() && !v2.empty()) {
		if (v1.back() > v2.back()) {
			cout << v2.back() << " ";
			v2.pop_back();
		}
		else {
			cout << v1.back() << " ";
			v1.pop_back();
		}
	}

	if (v1.empty() == true) {
		while (!v2.empty()) {
			cout << v2.back() << " ";
			v2.pop_back();
		}
	}
	else {
		while (!v1.empty()) {
			cout << v1.back() << " ";
			v1.pop_back();
		}
	}

}

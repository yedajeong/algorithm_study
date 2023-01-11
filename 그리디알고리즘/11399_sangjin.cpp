#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int& a, int& b) {
	return a > b;
}

int main() {
	vector<int> money;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		money.push_back(a);
	}
	
	sort(money.begin(), money.end(), compare);

	int result = 0;

	for (int i = 0; i < N; i++) {
		result += money[i] * (i + 1);
	}
	
	cout << result << '\n';
}

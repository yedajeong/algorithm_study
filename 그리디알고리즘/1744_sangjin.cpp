#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> minus_line;
vector<int> plus_line;
vector<int> zero;

int main() {

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a == 0) {
			zero.push_back(a);
		}
		else if (a > 0) {
			plus_line.push_back(a);
		}
		else if (a < 0) {
			minus_line.push_back(a);
		}
	}

	sort(minus_line.begin(), minus_line.end());
	sort(plus_line.begin(), plus_line.end());

	int result = 0;
	
	int not_one = 0;
	for (int i = 0; i < plus_line.size(); i++) {
		if (plus_line[not_one] != 1) {
			break;
		}
		else {
			not_one++;
		}
	}
	// -5 -2 -1 -2 이런식으로 sort됨

	if ((minus_line.size()) % 2 == 1) {
		if (zero.size() != 0) {
			for (int i = 0; i < minus_line.size(); i+=2) {
				result += minus_line[i] * minus_line[i + 1];
			}
		}
		else {
			for (int i = 0; i < minus_line.size() - 1; i += 2) {
				result += minus_line[i] * minus_line[i + 1];
			}
			result += minus_line[minus_line.size() - 1];
		}
	}
	else {
		for (int i = 0; i < minus_line.size(); i += 2) {
			result += minus_line[i] * minus_line[i + 1];
		}
	}

	if ((plus_line.size()- not_one) % 2 == 1) {
		for (int i = plus_line.size() - 1; i > not_one; i -= 2) {
			result += plus_line[i] * plus_line[i - 1];
		}
		for (int j = 0; j <= not_one; j++) {
			result += plus_line[j];
		}
	}
	else {
		for (int i = plus_line.size() - 1; i > not_one; i -= 2) {
			result += plus_line[i] * plus_line[i - 1];
		}
		for (int j = 0; j < not_one; j++) {
			result += plus_line[j];
		}
	}

	std::cout << result << '\n';
}

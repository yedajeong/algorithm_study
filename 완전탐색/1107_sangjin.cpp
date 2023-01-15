#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main() {
	int N, M;
	vector<int> button;

	cin >> N >> M;


	for (int i = 0; i <= 9; i++) {
		button.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		button.erase(remove(button.begin(), button.end(), a), button.end());
	}

	int min_count = abs(N - 100);
	string num;

	for (int i = 0; i < 1000001; i++) {
		bool not_return = false;
		num = to_string(i); // int를 비교하기 편하게 string으로 변환

		for (int j = 0; j < num.size(); j++) {
			int a = num[j] - 48;
			if (find(button.begin(), button.end(), a) == button.end()) { // vector내에 0이 존재하지 않음
				not_return = true;
				break;
			}
		}
		
		if (not_return == false) {
			int count = i - N;
			count = abs(count) + num.size();
			min_count = min(min_count, count);
		}
	}
	cout << min_count;
}

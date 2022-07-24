#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10001];

int main() {
	std::ios::sync_with_stdio(false);
	int input_num, input_score;

	cin >> input_num;

	for (int i = 0; i < input_num; i++) {
		cin >> input_score;
		arr[input_score] += 1;
	}

	for (int i = 0; i < 10001; i++) {
		for (int k = 0; k < arr[i]; k++) {
			cout << i << '\n';
		}
	}
}

#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		
		int left_num = 0;
		int right_num = 0;
		int j = 0;

		while (j < input.length() && left_num>=right_num) {
			if (input[j] == '(') {
				left_num++;
			}
			else {
				right_num++;
			}
			j++;
		}

		if (left_num != right_num) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << "\n";
		}
	}

	return 0;
}

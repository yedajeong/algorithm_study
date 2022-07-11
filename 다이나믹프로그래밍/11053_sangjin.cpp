#include <iostream>
#include <algorithm>

using namespace std;

int input_row[1001];
int dp[1001];

int main() {
	int size_num;

	cin >> size_num;
	for (int i = 1; i <= size_num; i++) {
		cin >> input_row[i];
	}

	int max_num = 0;
	for (int i = 1; i <= size_num; i++) {
		for (int j = 0; j < i; j++) {
			if (input_row[i] > input_row[j])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
		max_num = max(max_num, dp[i]);
	}


	cout << max_num << '\n';

}
















/*
int row_size[1001];
int input_row[1001];
int standard_size[1001] = { 0, };
int max_size[1001];

int main() {
	int size_num;
	int count = 0;
	int numb = 1;

	cin >> size_num;

	for (int i = 0; i < size_num; i++) {
		cin >> input_row[i];
	}

	row_size[0] = input_row[0];
	for (int j = 1; j < size_num; j++) { 
		if (row_size[count] < input_row[j]) {
			row_size[count + 1] = input_row[j];
			count++;
		}
		else
			continue;
	}

	max_size[0] = count + 1;

	for (int a = 1; a < size_num; a++) {
		if (input_row[a-1] > input_row[a]) {
			standard_size[numb] = a;
			numb++;
		}
	}

	for (int n = 1; n < numb; n++) {
		int max_num = 0;
		int standard_num = standard_size[n];
		int min_standard = input_row[standard_num];
		int max_standard = input_row[standard_num];
		for (int k = standard_num; k >= 0; k--) {
			if (min_standard > input_row[k]) {
				max_num += 1;
				min_standard = input_row[k];
			}
			else if (min_standard < input_row[k] && input_row[k] < input_row[standard_num] ) {
				min_standard = input_row[k];
			}

		}
		for (int t = standard_num; t < size_num; t++) {
			if (max_standard < input_row[t]) {
				max_num += 1;
				max_standard = input_row[t];
			}
			else
				continue;
		}
		max_size[n] = max_num + 1;
	}

	int max_number = 0;

	for (int u = 0; u < numb; u++) {
		if (max_size[u] > max_number)
			max_number = max_size[u];
	}
	cout << max_number << '\n';
}
*/
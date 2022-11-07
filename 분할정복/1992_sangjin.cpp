#include <iostream>
#include <string>
using namespace std;

int video[65][65];

void divide_n(int n, int row, int col) {
	int num = video[row][col];
	for (int i = row; i < row + n; i++) {
		for (int j = col; j < col + n; j++) {
			if (video[i][j] != num) {
				cout << "(";
				divide_n(n / 2, row, col);
				divide_n(n / 2, row, col + n / 2);
				divide_n(n / 2, row + n / 2, col);
				divide_n(n / 2, row + n / 2, col + n / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << num;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			string k = s.substr(j, 1);
			video[i][j] = stoi(k);
		}
	}
	divide_n(N, 0, 0);
}

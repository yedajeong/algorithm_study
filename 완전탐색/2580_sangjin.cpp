#include <iostream>
#include <string>
#include <vector>
using namespace std;

int arr[9][9];

bool promising(int x, int y, int a) {
	for (int i = 0; i < 9; i++) {
		if (arr[x][i] == a)
			return false;
		if (arr[i][y] == a)
			return false;
	}
	int tt_x = (x / 3) * 3;
	int tt_y = (y / 3) * 3;
	for (int i = tt_x; i < tt_x + 3; i++) {
		for (int j = tt_y; j < tt_y + 3; j++)
			if (arr[i][j] == a) 
				return false;
	}
	return true;
}

void sudoku(int x, int y) {
	if (x == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << arr[i][j] << " ";
			cout << "\n";
		}
		return;
	}

	if (y == 9) 
		sudoku(x + 1, 0);

	if (arr[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (promising(x, y, i)) {
				arr[x][y] = i;
				sudoku(x, y + 1);
				arr[x][y] = 0; // 백트래킹 부분
				//만약 처음 넣은 숫자가 아니면 for 문을 돌면서 
				//뒤에 숫자가 다시 들어가서 dfs를 하게 됌.
			}
		}
	}
	else sudoku(x, y + 1);
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];
	}
	sudoku(0, 0);
	return 0;
}

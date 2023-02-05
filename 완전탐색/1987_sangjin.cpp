#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
int board[21][21];
bool visited[27] = { false }; //알파벳 방문
int dx[4] = { 1, -1 ,0 ,0 };
int dy[4] = { 0,0,1,-1 };
int result = 0;

void dfs(int row, int col, int cnt) {
	int start = board[row][col];
	visited[start] = true;
	for (int i = 0; i < 4; i++) {
		int new_row = row + dx[i];
		int new_col = col + dy[i];
		if (new_row < R && new_row >= 0 && new_col < C && new_col >= 0) {
			int y = board[new_row][new_col];
			if (visited[y] == false) {
				visited[y] = true;
				dfs(new_row, new_col, cnt + 1);
				visited[y] = false;
			}
		}
	}
	result = max(cnt, result);
}


int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char a;
			cin >> a;
			board[i][j] = a - 'A';
		}
	}

	dfs(0, 0, 1);

	cout << result << endl;
}

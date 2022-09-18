#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int row, col, island_count;
vector<int> result;
vector<int> graph[51];
int dx[8] = { 1, 1, 1, -1, -1,-1, 0, 0 };
int dy[8] = { 0, 1,-1, 0, 1, -1, -1, 1 };

void init(int v) {
	for (int i = 0; i < v; i++) {
		graph[i].clear();
	}
}

void  bfs(int x, int y) {
	queue<pair<int,int>> que;
	que.push(make_pair(x, y));
	graph[x][y] = 0;
	while (!que.empty()) {
		int island_x = que.front().first;
		int island_y = que.front().second;
		for (int i = 0; i < 8; i++) {
			int nx = island_x + dx[i];
			int ny = island_y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < row && ny < col) {
				if (graph[nx][ny] == 1) {
					que.push(make_pair(nx, ny));
					graph[nx][ny] = 0;
				}
			}

		}
		que.pop();
	}
	island_count++;
}


int main() {
	int input_num;

	while (true) {
		cin >> col >> row;   // 5 4
		if (row == 0 && col == 0)
			break;

		for (int i = 0; i < row; i++) { // 4
			for (int j = 0; j < col; j++) { // 5
				cin >> input_num;
				graph[i].push_back(input_num);
			}
		}

		island_count = 0;
		
		for (int i = 0; i < row; i++) { // 0 1 2 3
			for (int j = 0; j < col; j++) {// 0 1 2 3 4
				if (graph[i][j] == 1) {
					bfs(i, j);
				}
			}
		}
		result.push_back(island_count);
		init(row);
	}

	for (auto x : result) {
		cout << x << '\n';
	}
	return 0;
}

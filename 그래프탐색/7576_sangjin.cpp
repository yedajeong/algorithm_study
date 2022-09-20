#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> que;
int M, N, result_count, result;
int dx[4] = { 0, 0, 1, -1};
int dy[4] = { 1,-1, 0, 0};
vector<int> graph[1001];

void dfs() {

	while (!que.empty()) {
		int count = que.size();
		result += (result_count / count);
		result_count = 0;
		for (int t = 0; t < count; t++) {
			int row = que.front().first;
			int col = que.front().second;
			for (int i = 0; i < 4; i++) {
				int dx_row = row + dx[i];
				int dy_col = col + dy[i];
				if (dx_row >= 0 && dy_col >= 0 && dx_row < N && dy_col < M) {
					if (graph[dx_row][dy_col] == 0) {
						graph[dx_row][dy_col] = 1;
						que.push(make_pair(dx_row, dy_col));
						result_count++;
					}
				}
			}
			que.pop();
		}
	}
}

int main() {
	int tomato_s;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato_s;
			graph[i].push_back(tomato_s);
		}
	}

	result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 1)
				que.push(make_pair(i, j));
		}
	}
	
	dfs();

	bool zero_print = false;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0)
				zero_print = true;
		}
	}

	if (zero_print == true)
		cout << "-1" << '\n';
	else
		cout << result << '\n';


	return 0;
}

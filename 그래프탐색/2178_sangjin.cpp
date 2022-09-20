#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, result, result_count;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0 ,0};
vector<int> graph[101];
queue<pair<int, int>> que;
vector<int> result_graph;

void dfs() {
	graph[que.front().first][que.front().second] = 2;

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
					if (graph[dx_row][dy_col] == 1) {
						graph[dx_row][dy_col] = 2;
						que.push(make_pair(dx_row, dy_col));
						result_count++;
					}
					if (dx_row == 0 && dy_col == 0)
						result_graph.push_back(result);
				}
			}
			que.pop();
		}
	}
}

int main() {
	string miro;
	cout.tie();
	cin.tie();
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> miro;
		for (int j = 0; j < M; j++) {
			string a = miro.substr(j, 1);
			graph[i].push_back(stoi(a));
		}
	}
	que.push(make_pair(N - 1, M - 1)); // 3   5
	dfs();

	sort(result_graph.begin(), result_graph.end());

	cout << result_graph[0] + 2 << '\n';
}

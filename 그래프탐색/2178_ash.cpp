#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;


int graph[101][101] = { -1, }; //0으로 초기화하면 구분이 안됨.
int visit[101][101] = { 0, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int i, int j) {
	visit[i][j] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		int f_i = q.front().first;
		int f_j = q.front().second;

		for (int i = 0; i < 4; i++) {
			int next_i = f_i + dx[i];
			int next_j = f_j + dy[i];

			if (graph[next_i][next_j] == 1 && visit[next_i][next_j] == 0) {
				visit[next_i][next_j] = visit[f_i][f_j] + 1;
				q.push(make_pair(next_i, next_j));
			}
		}
		q.pop();
	}
}


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			string a = input.substr(j, 1);
			int input_num = stoi(a);
			graph[i][j + 1] = input_num;
		}
	}

	bfs(1, 1);
	
	int min_num = visit[n][m];

	cout << min_num << '\n';

	return 0;
}

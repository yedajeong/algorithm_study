#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[101][101] = { false };
int cnt[101][101] = { 0 };
int miro[101][101];
int N, M;
int result = 201;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
/*
void dfs(int row, int col, int count) {
	if (row == M - 1 && col == N - 1) {
		result = min(result, count);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int new_x = row + dx[i];
		int new_y = col + dy[i];
 		if (new_x >= 0 && new_x < M && new_y >= 0 && new_y < N) {
			if (visited[new_x][new_y] == false) {
				if (miro[new_x][new_y] == 0) {
					visited[new_x][new_y] = true;
					dfs(new_x, new_y, count);
					visited[new_x][new_y] = false;
				}
				else {
					visited[new_x][new_y] = true;
					dfs(new_x, new_y, count + 1);
					visited[new_x][new_y] = false;
				}
			}
		}
	}
}
*/

void djikstra(int r, int c) {

	cnt[r][c] = 0;        //first == count  second.first ==r second.second ==c
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0,{r,c} });

	while (!pq.empty()) {
		int count = pq.top().first;
		int current_r = pq.top().second.first;
		int current_c = pq.top().second.second;
		pq.pop();
		if (cnt[current_r][current_c] < count)
			continue;

		for (int i = 0; i < 4; i++) {
			int next_count;
			int next_r = current_r + dir[i][0];
			int next_c = current_c + dir[i][1];

			if (next_r >= 0 && next_r < M && next_c >= 0 && next_c < N) {
				if (miro[next_r][next_c] == 0) {

					next_count = cnt[current_r][current_c];
				}
				else {
					next_count = cnt[current_r][current_c] + 1;
				}
				if (cnt[next_r][next_c] > next_count) {
					pq.push({ next_count,{next_r,next_c} });
					cnt[next_r][next_c] = next_count;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < N; j++) {
			cnt[i][j] = 987654321;
			miro[i][j] = a[j] - '0';
		}
	}

	djikstra(0, 0);
	cout << cnt[M - 1][N - 1];

}

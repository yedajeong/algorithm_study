#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int box[1001][1001] = { 0, };
int visit[1001][1001] = { 0, };

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	queue<pair<int, int>> q;

	int m, n;
	cin >> m >> n;

	for (int i = 1; i <= n; i++) { //세로칸수
		for (int j = 1; j <= m; j++) { //가로칸수
			int tomato;
			cin >> tomato; //1(익음), 0(안익음), -1(없음)
			box[i][j] = tomato;

			if (tomato == 1) { //익은 토마토 queue에 저장
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) { //bfs
		int f_i = q.front().first;
		int f_j = q.front().second;

		if (box[f_i - 1][f_j] == 0 && f_i - 1 >= 1) { //안익은 토마토 search
			box[f_i - 1][f_j] = 1;
			q.push(make_pair(f_i - 1, f_j));
			visit[f_i - 1][f_j] = visit[f_i][f_j] + 1; //날짜 count
		}
		if (box[f_i + 1][f_j] == 0 && f_i + 1 <= n) {
			box[f_i + 1][f_j] = 1;
			q.push(make_pair(f_i + 1, f_j));
			visit[f_i + 1][f_j] = visit[f_i][f_j] + 1;
		}
		if (box[f_i][f_j - 1] == 0 && f_j - 1 >= 1) {
			box[f_i][f_j - 1] = 1;
			q.push(make_pair(f_i, f_j-1));
			visit[f_i][f_j-1] = visit[f_i][f_j] + 1;
		}
		if (box[f_i][f_j + 1] == 0 && f_j + 1 <= m) {
			box[f_i][f_j + 1] = 1;
			q.push(make_pair(f_i, f_j+1));
			visit[f_i][f_j+1] = visit[f_i][f_j] + 1;
		}

		q.pop();
	}
	

	bool pos = true;
	int maxday = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (box[i][j] == 0) {
				pos = false;
				break;
			}
			else {
				if (visit[i][j] > maxday) {
					maxday = visit[i][j];
				}
			}
		}
	}

	if (pos) {
		cout << maxday << '\n';
	}
	else {
		cout << -1 << '\n';
	}

	return 0;
}

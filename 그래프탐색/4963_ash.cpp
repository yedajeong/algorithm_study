#include <iostream>
using namespace std;

int graph[51][51] = { 0, };
int visit[51][51] = { 0, };

void dfs(int i, int j, int c) {
	visit[i][j] = c;

	for (int k = i - 1; k <= i + 1; k++) {
		for (int m = j - 1; m <= j + 1; m++) {
			if (visit[k][m] == 0 && graph[k][m] == 1) {
				dfs(k, m, c);
			}
		}
	}

}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	while (true) {
		int w, h;
		cin >> w >> h;
		if (w == 0 && h == 0) break; //0,0입력시 종료
		
		for (int i = 0; i < 51; i++) { //초기화
			for (int j = 0; j < 51; j++) {
				visit[i][j] = 0;
				graph[i][j] = 0;
			}
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				int input;
				cin >> input;
				graph[i][j] = input;
			}
		}

		int count = 0;

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (visit[i][j] == 0 && graph[i][j] == 1) {
					count++;
					dfs(i, j, count);
				}
			}
		}

		cout << count << '\n';
	}

	return 0;
}

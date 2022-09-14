#include <iostream>
using namespace std;

int graph[1001][1001] = { 0, };
bool visit[1001] = { 0 };

void dfs(int v, int n) {
	visit[v] = true;
	for (int i = 1; i <= n; i++) {
		if (graph[v][i] == 1 && visit[i] == false) {
			dfs(i, n);
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	int count = 0;

	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			dfs(i, n);
			count++;
		}
	}

	cout << count << '\n';

	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int visit[1001] = { 0 };
vector<int> graph[1001];

void dfs(int n) {
	visit[n] = 1;
	
	for (int i = 0; i < graph[n].size(); i++) {
		int next = graph[n][i];
		
		if (visit[next] == 0) {
			dfs(next);
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n, count;
		count = 0;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			int k;
			cin >> k;
			graph[j].push_back(k);
		}

		for (int j = 1; j <= n; j++) {
			if (visit[j] == 0) {
				dfs(j);
				count++;
			}
		}

		cout << count << '\n';

		for (int j = 0; j < 1001; j++) { //초기화
			graph[j].clear();
			visit[j] = 0;
		}
	}
}

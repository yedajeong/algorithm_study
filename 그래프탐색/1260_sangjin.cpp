#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;

bool visited[1001] = { false };
vector<int> graph[1001];


void dfs(int x)
{
	visited[x] = true;
	cout << x << " ";
	for (int i = 0; i < graph[x].size(); i++) // 인접한 노드 사이즈만큼 탐색
	{
		int y = graph[x][i];
		if (!visited[y])
			dfs(y); 
	}
}

void bfs(int x) {
	queue<int> Q;
	visited[x] = true;
	cout << x << " ";
	Q.push(x);

	while (!Q.empty()) {
		int t = Q.front();
		for (int i = 0; i < graph[t].size(); i++) {
			int y = graph[t][i];
			if (!visited[y]) {
				cout << y << " ";
				Q.push(y);
				visited[y] = true;
			}
		}
		Q.pop();
	}
}

int main() {
	int N, M, v;

	cin >> N >> M >> v;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i < N + 1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	dfs(v);

	for (int i = 1; i < N + 1; i++) {
		visited[i] = false;
	}
	cout << '\n';

	bfs(v);


	return 0;
}

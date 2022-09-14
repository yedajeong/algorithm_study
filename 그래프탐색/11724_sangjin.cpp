#include <iostream>
#include <vector>
using namespace std;

bool visited[1001] = { false };
vector<int> graph[1001];

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if(visited[y] == false){
			dfs(y);
		}
	}
}

int main() {
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int count = 0;

	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			dfs(i);
			count++;
		}
	}

	cout << count << '\n';
}

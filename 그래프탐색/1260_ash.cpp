#include <iostream>
#include <queue>
using namespace std;

void dfs(int v, int n); //스택이나 재귀함수로 구현할 수 있다.
void bfs(int v, int n); //큐로 구현

bool dvisited[1001] = {false}; //함수에서도 사용해야 하니까 main 밖에 선언
bool bvisited[1001] = { false };
int graph[1001][1001] = { 0, };

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int N, M, V;

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	dfs(V, N);
	cout << "\n";
	bfs(V, N);

	return 0;
}

void dfs(int v, int n) { //재귀로 구현
	dvisited[v] = true;
	cout << v << ' ';
	
	for (int i = 1; i <= n; i++) { //작은 수부터 방문
		if (graph[v][i] == 1 && dvisited[i] == false) {
			dfs(i, n);
		}
	}
}

void bfs(int v, int n) {
	queue<int> q;
	q.push(v);
	cout << v << " ";
	bvisited[v] = true;

	while (!q.empty()) {
		int front = q.front();
		for (int i = 1; i <= n; i++) {
			if (graph[front][i]==1 && bvisited[i] == false) {
				q.push(i);
				bvisited[i] = true;
				cout << i << " ";
			}
		}
		q.pop();
	}
}

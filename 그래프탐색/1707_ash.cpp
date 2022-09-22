#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[20001];
int visit[20001] = { 0 };

/*
bool dfs(int n, int c) {
	visit[n] = c; 

	for (int i = 0; i < graph[n].size(); i++) {
		int next = graph[n][i];
		if (visit[next] == c ) { //같은색인데 인접함
			return false;
		}
		else if (visit[next] == 0 ) { //방문한적 없음
			return dfs(next, c * -1); //리턴값때문에 한 노드에 그래프가 두개 있을때 못돌아감.... --> stack으로 구현 or bfs로 수정
		}
	}

	return true;
}*/

bool bfs(int n, int c) {
	queue<int> q;
	visit[n] = c;
	q.push(n);

	while (!q.empty()) {
		int front = q.front();

		for (int i = 0; i < graph[front].size(); i++) {
			int next = graph[front][i];
			
			if (visit[next] == 0) {
				q.push(next);
				visit[next] = -1 * visit[front];
			}
			
			else if (visit[next] == visit[front]) {
				return false;
			}
		}
		q.pop();
	}

	return true;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int v, e;
		bool isBip = true;
		cin >> v >> e;
		for (int j = 0; j < e; j++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int j = 1; j <= v; j++) { //비연결 그래프 고려
			if (visit[j] == 0 && isBip == true) {
				isBip = bfs(j, 1);
			}
		}
		
		if (isBip) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}

		//배열 초기화
		for (int  j= 0; j < 20001; j++) {
			visit[j] = 0;
			graph[j].clear();
		}
	}

	return 0;
}

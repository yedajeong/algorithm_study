#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[1001] = { false, };
vector<int> graph[1001];

void init(int v) {
	for (int i = 1; i <= v; i++) {
		visited[i] = false;
		graph[i].clear();
	}
}

void bfs(int x) {
	queue<int> que;
	que.push(x);
	visited[x] = true;

	int y = graph[x][0];
	que.push(y);
	visited[y] = true;
	
	int n = y;
	while (que.front() != que.back()) {
		y = graph[n][0];
		que.push(y);
		visited[y] = true;
		n = y;
	}
}

int main() {
	int case_num, N, a_num;

	cin >> case_num;
	
	for (int i = 0; i < case_num; i++) {
		cin >> N;
		for (int k = 1; k <= N; k++) {
			cin >> a_num;
			graph[k].push_back(a_num);
		}
		int count = 0;
		for (int k = 1; k <= N; k++) {
			if (visited[k] == false) {
				bfs(k);
				count++;
			}
		}
		cout << count << '\n';
		init(N);
	}
	return 0;
}

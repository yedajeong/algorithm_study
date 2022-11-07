#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[100001];
int visited[100001];
int max_num;
int N, M;
int print_max[100001];

void init() {
	for (int i = 0; i < 100001; i++) {
		visited[i] = 0;
	}
	max_num = 0;
}

void dfs(int x) {
	if (visited[x] == 0) {
		visited[x] = 1;
		max_num++;
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			dfs(y);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}
	max_num = 0;
	int ma_x = 0;
	for (int i = 1; i <= N; i++) {
		dfs(i);
		ma_x = max(max_num, ma_x);
		print_max[i] = max_num;
		init();
	}

	for (int i = 1; i <= N; i++) {		
		if (ma_x == print_max[i])
			cout << i << " ";
		
	}
}

#include <iostream>;
#include <string>;
#include <vector>
#include <queue>
using namespace std;

int visited[20001]; // 2 는 빨간색 3은파란색
vector<int> graph[20001];

void init(int v) { 
	for (int i = 1; i <= v; i++) {
		visited[i] = 0;
		graph[i].clear();
	}
}

void dfs(int x) {
	if (visited[x] == 0) {
		visited[x] = 2;
	}

	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (visited[y] == 0) {
			if (visited[x] == 2) {
				visited[y] = 3;
			}
			else if (visited[x] == 3) {
				visited[y] = 2;
			}
			dfs(y);
		}
	}
}

int main() {
	int t_case, V, E, a_num, b_num;

	cin >> t_case;

	while(t_case--){
		bool yorn = true;

		cin >> V >> E;

		for (int k = 0; k < E; k++) {
			cin >> a_num >> b_num;
			graph[a_num].push_back(b_num);
			graph[b_num].push_back(a_num);
		}

		for (int i = 1; i <= V; i++)
		{
			if (visited[i] == 0)
			{
				dfs(i);
			}
		}

		for (int n = 1; n <= V; n++) {
			for (int t = 0; t < graph[n].size(); t++) {
				int case_num = graph[n][t];
				if (visited[n] == visited[case_num])
					yorn = false;
			}
		}

		if (yorn == false) {
			cout << "NO" << '\n';
		}
		else
			cout << "YES" << '\n';

		init(V);
	}
	return 0;
}

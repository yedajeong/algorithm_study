#include <iostream>
#include <vector>
using namespace std;


int tree_node[100001];
vector<int> graph[100001];
bool visited[100001];

void dfs(int x) {
	visited[x] = true;

	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (visited[y] == false) {
			tree_node[y] = x;
			dfs(y);
		}

	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i < N + 1; i++) {
		cout << tree_node[i] << '\n';
	}

}

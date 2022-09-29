#include <iostream>
#include <vector>
#include <set>
using namespace std;

int visited[1000001]; // 0은 아직 방문 안한거 1은 방문한거
vector<pair<int, int>> node[100001];
set<int> end_num;

void init(int count_num) {
	for (int i = 0; i <= count_num; i++) {
		visited[i] = 0;
	}
}

int ans = 0;
int end_point;
void dfs(int point, int length) {
	
	if (visited[point])
		return;

	visited[point] = 1;

	if (ans < length) {
		ans = length;
		end_point = point;
	}

	int n = node[point].size();
	for (int i = 0; i < n; i++) {
		dfs(node[point][i].first, length + node[point][i].second);
	}
}


int main() {
	int V;
	cin >> V; 

	for (int i = 0; i < V; i++) {
		int parent, child, w;
		pair<int, int> v;
		cin >> parent;
		while (true) {
			cin >> child;
			if (child == -1)
				break;
			cin >> w;
			node[parent].push_back(make_pair(child, w));
		}
	}

	/*
	for (int i = 1; i <= V; i++) {
		dfs(i, 0);
		end_num.insert(end_point);
		init(V);
	}

	for (auto x : end_num) {
		dfs(x, 0);
		init(V);
	}
	*/
	dfs(1, 0);
	init(V);
	dfs(end_point, 0);

	cout << ans << '\n';

}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int visited[10002] = { 0 };
vector<pair<int, int>> node[10002];

int ans = 0;
int end_point = 0;

void init() {
	for (int i = 0; i < 10002; i++) {
		visited[i] = 0;
	}
}
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
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int parent, child, w;
		cin >> parent >> child >> w;
		node[parent].push_back(make_pair(child, w));
		node[child].push_back(make_pair(parent, w));
	}

	dfs(1, 0);

	ans = 0;

	init();

	dfs(end_point, 0);
	cout << ans << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int graph[26][26] = { 0, };
int visit[26][26] = { 0, };

void dfs(int i, int j, int c){
	visit[i][j] = c;

	for (int q = i - 1; q <= i + 1; q++) {  //열이 같을때
		if (graph[q][j] == 1 && visit[q][j] == 0) {
				dfs(q, j, c);
		}
	}

	for (int w = j - 1; w <= j + 1; w++) { //행이 같을 때
		if (graph[i][w] == 1 && visit[i][w] == 0) {
			dfs(i, w, c);
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf_s("%1d", &graph[i][j]);
		}
	}*/ //이건 또 왜안돼 진짜...

	string house;

	for (int i = 1; i <= n; i++) {
		cin >> house;
		int h_size = house.size();
		for (int j = 0; j < h_size; j++) {
			string a = house.substr(j, 1);
			int input_num = stoi(a);
			graph[i][j+1] = input_num;
		}
	}

	int count = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == 1 && visit[i][j] == 0) {
				count++;
				dfs(i, j, count);
			}
		}
	}

	cout << count << '\n';

	int li[1000] = { 0 };

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j] != 0) {
				li[visit[i][j]]++;
			}
		}
	}

	sort(li, li+1000);

	for (int i = 1000-count; i < 1000; i++) {
		cout << li[i] << '\n';
	}

	return 0;
}

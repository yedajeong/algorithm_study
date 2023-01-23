#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

bool visited[10001] = { false };
string cmd[10001];

void init() {
	for (int i = 0; i < 10001; i++) {
		visited[i] = false;
		cmd[i] = "";
	}
}

void bfs(int start, int end) {
	queue<int> que;
	que.push(start);
	visited[start] = true;

	while (!que.empty() && !visited[end]) {
		int cur = que.front();
		int D = cur * 2 > 9999 ? (cur * 2) % 10000 : cur * 2;
		int S = (cur - 1) >= 0 ? cur - 1 : 9999;
		int L = (cur % 1000) * 10 + cur / 1000;
		int R = (cur % 10) * 1000 + cur / 10;

		if (!visited[D]) {
			que.push(D);
			visited[D] = true;
			cmd[D] = cmd[cur] + "D";
		}
		if (!visited[S]) {
			que.push(S);
			visited[S] = true;
			cmd[S] = cmd[cur] + "S";
		}
		if (!visited[L]) {
			que.push(L);
			visited[L] = true;
			cmd[L] = cmd[cur] + "L";
		}
		if (!visited[R]) {
			que.push(R);
			visited[R] = true;
			cmd[R] = cmd[cur] + "R";
		}

		que.pop();
	}
}


int main() {
	int T;
	cin >> T;


	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;
		bfs(a, b);
		cout << cmd[b] << endl;
		init();
	}
}

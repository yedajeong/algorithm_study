#include <iostream>
#include <string>
#include <queue>
using namespace std;

int F, S, G, U, D;
int visited[2000001] = { 1 };

void bfs() {
	queue<int> que;
	que.push(S);
	visited[S] = 1;
	while (!que.empty()) {
		int y = que.front();
		if (y == G) {
			cout << visited[y] - 1 << endl;
			return;
		}
		else {
			int up = y + U;
			int down = y - D;
			if (up <= F && visited[up] == 0) {
				que.push(up);
				visited[up] = visited[y] + 1;
			}
			if (down >= 0 && visited[down] == 0) {
				que.push(down);
				visited[down] = visited[y] + 1;
			}
		}
		que.pop();
	}
	cout << "use the stairs" << endl;
	return;
}

int main() {
	cin >> F >> S >> G >> U >> D;
	// F 총 층수 S 현재 위치  G 목적지 U 위로 몇층 가는지 D 는 아래로 몇층 가는지

	bfs();

	return 0;
}

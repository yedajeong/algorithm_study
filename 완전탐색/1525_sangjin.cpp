#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(string puz) {
	set<string> chk;
	queue<pair<string, int>> q;
	q.push(make_pair(puz, 0));
	chk.insert(puz);  // visited 배열에서 1234567089 이런 식의 string의 방문 여부를 확인하고 싶으면
	                  // visited의 배열의 크기가 너무 커지기 때문에 set을 이용해 방문 했는지 확인 할 수 있다.
	while (!q.empty()) {
		string find = q.front().first;
		int cnt = q.front().second;

		if (find == "123456780") {
			cout << cnt << endl;
			return;
		}

		int zero = find.find("0");
		int z_x = zero / 3;
		int z_y = zero % 3;

		for (int i = 0; i < 4; i++) {
			int nx = z_x + dx[i];
			int ny = z_y + dy[i];
			if (0 <= nx && nx <= 2 && 0 <= ny && ny <= 2) {
				string new_puzzle = find;
				int swap_point = nx * 3 + ny;
				new_puzzle[zero] = new_puzzle[swap_point];
				new_puzzle[swap_point] = '0';

				if (chk.find(new_puzzle) == chk.end()) {
					chk.insert(new_puzzle);
					q.push(make_pair(new_puzzle, cnt + 1));
				}
			}
		}
		q.pop();
	}
	cout << "-1" << endl;
	return;
}

int main() {
	string puzzle;
	for (int i = 0; i < 9; i++) {
		string a;
		cin >> a;
		puzzle += a;
	}
	bfs(puzzle);
}

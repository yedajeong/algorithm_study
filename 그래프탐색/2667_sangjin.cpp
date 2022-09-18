#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int count_num, table_row_col;
vector<int> graph[26];
vector<int> count_size;

void bfs(int x, int y) {
	queue<pair<int,int>> que;
	que.push(make_pair(x, y));
	count_num++;
	graph[x][y] = 0;
	while (!que.empty()) {
		int row = que.front().first;
		int col = que.front().second;
		if (row < table_row_col) {
			if (graph[row + 1][col] == 1) {
				que.push(make_pair(row + 1, col));
				graph[row + 1][col] = 0;
				count_num++;
			}
		}
		if (col < table_row_col) {
			if (graph[row][col + 1] == 1) {
				que.push(make_pair(row, col + 1));
				graph[row][col + 1] = 0;
				count_num++;
			}
		}
		if (row >= 2) {
			if (graph[row - 1][col] == 1) {
				que.push(make_pair(row - 1, col));
				graph[row - 1][col] = 0;
				count_num++;
			}
		}
		if (col >= 2) {
			if (graph[row][col - 1] == 1) {
				que.push(make_pair(row, col - 1));
				graph[row][col - 1] = 0;
				count_num++;
			}
		}
		que.pop();
	}
	count_size.push_back(count_num);
}


int main() {

	cin >> table_row_col;

	string house;

	for (int i = 1; i <= table_row_col; i++) {
		graph[0].push_back(0);
		graph[i].push_back(0);
	}

	for (int i = 1; i <= table_row_col; i++) {
		cin >> house;
		int h_size = house.size();
		for (int k = 0; k < h_size; k++) {
			string a = house.substr(k, 1);
			int input_num = stoi(a);
			graph[i].push_back(input_num);
		}
		graph[0].push_back(0);

	}

	for (int j = 1; j <= table_row_col; j++) {
		for (int t = 1; t <= table_row_col; t++) {
			if (graph[j][t] == 1) {
				count_num = 0;
				bfs(j, t);
			}
		}
	}

	cout << count_size.size() << '\n';
	sort(count_size.begin(), count_size.end());
	for (auto x : count_size) {
		cout << x << '\n';
	}

}

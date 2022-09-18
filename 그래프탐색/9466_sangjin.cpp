#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cnt;
bool visited[100001] = { false };
bool done[100001] = { false };
vector<int> graph[100001];

void init(int x) {
	for (int i = 1; i <= x; i++) {
		visited[i] = false;
		done[i] = false;
		graph[i].clear();
	}
}

void dfs(int x) {
	visited[x] = true;
	int y = graph[x][0];
	if (!visited[y])
		dfs(y);
	else if (!done[y]) {
		for (int i = y; i != x; i = graph[i][0]) {
			cnt++;
		}
		cnt++;
	}
	done[x] = true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int test_case, student_num, stu;

	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		cin >> student_num;
		
		for (int k = 1; k <= student_num; k++) {
			cin >> stu;
			graph[k].push_back(stu);
		}

		cnt = 0;
		for (int j = 1; j <= student_num; j++)
			if (!visited[j])
				dfs(j);

		cout << student_num - cnt << endl;

		init(student_num);
	}
}

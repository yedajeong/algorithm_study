#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100001];
int visit[100001] = { 0 };
bool isteam[100001] = { 0 };

void dfs(int first, int n, vector<int>& v) {
	visit[n] = 1;
	v.push_back(n);

	int next = graph[n][0];

	if (next == first) { //팀이 되었을 때
		isteam[first] = 1;
	}
	else if (next == n) { //재귀
		isteam[n] = 1;
	}
	else if (visit[next] == 0) { //다음 탐색
		dfs(first, next, v);
	}
	else if (visit[next] == 1) { //루틴 중간에 사이클이 생기는 경우 체크
		for (int i = 0; i < v.size(); i++) {
			if (next == v[i]) {
				isteam[n] = 1;
			}
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t; //테스트 케이스
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n; //학생 수
		for (int j = 1; j <= n; j++) {
			int k;
			cin >> k;
			graph[j].push_back(k);
		}

		for (int j = 1; j <= n; j++) { //팀 탐색
			if (visit[j] == 0) {
				vector<int> v;
				dfs(j, j, v);
			}
		}
		
		for (int j = 1; j <= n; j++) {
			if (isteam[j] == 1) {
				int next = graph[j][0];
				while (next != j && isteam[next]==0) { //팀 속하는 학생 마크
					isteam[next] = 1;
					next = graph[next][0];
				}
			}
		}

		int nonteam = 0;
		for (int j = 1; j <= n; j++) {
			if (isteam[j] == 0) {
				nonteam++;
			}
		}

		cout << nonteam << '\n';

		for (int j = 0; j < 100001; j++) { //초기화
			graph[j].clear();
			visit[j] = 0;
			isteam[j] = 0;
		}
	}
}

#include <iostream>
#include <vector>
using namespace std;

int true_knn[51];  //진실을 알면 1 모르면 0;
bool visited[51] = { false, };
vector<int> graph[51];
vector<int> vec[51];
vector<int> true_talker;

void dfs(int x)
{
	visited[x] = true;
	true_knn[x] = 1;
	for (int i = 0; i < graph[x].size(); i++) // 인접한 노드 사이즈만큼 탐색
	{
		int y = graph[x][i];
		if (!visited[y]) // 방문하지 않았으면 즉 visited가 False일 때 not을 해주면 True가 되므로 아래 dfs 실행
			dfs(y); // 재귀적으로 방문
	}
}


int main() {
	int N, M, true_known;
	cin >> N >> M >> true_known;
	for (int i = 0; i < true_known; i++) {
		int a;
		cin >> a;
		true_knn[a] = 1;
		true_talker.push_back(a);
	}

	for (int i = 0; i < M; i++) {
		vector<int> v;
		bool trueknow = false; // 진실을아는애가 있는지 있으면 true 없으면 false
		int party_num;
		cin >> party_num;
		for (int k = 0; k < party_num; k++) {
			int party_person;
			cin >> party_person;
			vec[i].push_back(party_person);
			v.push_back(party_person);
		}

		for (int t = 0; t < v.size(); t++) {
			for (int j = 0; j < v.size(); j++) {
				if (t != j) {
					graph[v[t]].push_back(v[j]);
					graph[v[j]].push_back(v[t]);
				}
			}
		}
	}

	for (auto x : true_talker) {
		dfs(x);
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		bool not_talk_lier = false;
		for (int k = 0; k < vec[i].size(); k++) {
			int y = vec[i][k];
			if (true_knn[y] == 1) {
				not_talk_lier = true;
			}
		}
		if (not_talk_lier == false) {
			cnt++;
		}
	}
	cout << cnt << '\n';

}

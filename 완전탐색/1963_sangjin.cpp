#include <iostream>
#include <queue>
using namespace std;

int idx = 0;
int sosu[1062] = { 0 };
int start[1062] = { 0 };
bool visited[1062] = { false };

void init() {
	for (int i = 0; i < 1062; i++) {
		start[i] = 0;
		visited[i] = false;
	}
}

void dfs(int start_idx, int end) {
	queue<int> que;
	que.push(start_idx);
	visited[start_idx] = true;
	int result = 0;
	int cnt = 0;
	while(!que.empty()){
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int index = que.front();
			start[index] = cnt;
			if (index == end || cnt > 1063) {
				return;
			}
			for (int j = 0; j < idx; j++) {
				if (visited[j] == false) {
					if (sosu[index] % 1000 == sosu[j] % 1000) {
						que.push(j);
						visited[j] = true;
					}
					else if (sosu[index] / 1000 == sosu[j] / 1000
						&& sosu[index] % 100 == sosu[j] % 100) {
						que.push(j);
						visited[j] = true;
					}
					else if (sosu[index] / 100 == sosu[j] / 100
						&& sosu[index] % 10 == sosu[j] % 10) {
						que.push(j);
						visited[j] = true;
					}
					else if (sosu[index] / 10 == sosu[j] / 10) {
						que.push(j);
						visited[j] = true;
					}
				}
			}
			que.pop();
		}
		cnt++;
	}
}

int main() {
	int T;
	cin >> T;

	int s = 0;
	int e = 0;
	for (s = 1000; s < 10000; s++) {
		for (e = 2; e < s; e++) {
			if (s % e == 0) 
				break;            
		}
		if (s == e) {
			sosu[idx] = s;
			idx++;
		}
	}
	
	for (int i = 0; i < T; i++) {
		int a, b;
		int sta, end_idx;
		cin >> a >> b;
		for (int j = 0; j < idx; j++) {
			if (sosu[j] == a) {
				sta = j;
			}
			if (sosu[j] == b) {
				end_idx = j;
			}
		}
		dfs(sta, end_idx);
		if (sta == end_idx) {
			cout << 0 << endl;
		}
		else {
			if (start[end_idx] == 0) {
				cout << "Impossible" << endl;
			}
			else {
				cout << start[end_idx] << endl;
			}
		}
		init();
	}
	
}

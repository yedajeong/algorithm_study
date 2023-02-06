#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
vector<int> vec;
bool visited[21] = { false };
int sum = 0;
int result = 0;

void dfs(int end_num, int cnt) {
	if (cnt == N) {
		if (sum == S) {
			result++;
			return;
		}
	}
	else {
		if (sum == S && cnt != 0) {
			result++;
		}

		for (int i = 0; i < vec.size(); i++) {
			if (visited[i] == false && i >= end_num) {
				visited[i] = true;
				sum += vec[i];
				dfs(i, cnt+1);
				visited[i] = false;
				sum -= vec[i];
			}
		}
	}
}

int main() {
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	dfs(0, 0);
	cout << result << endl;
}

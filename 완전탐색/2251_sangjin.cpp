#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int visited[201][201] = { 0 };
int A, B, C;
vector<int> vec;

void dfs(int a, int b, int c) {
	if (visited[a][b] == 1) {
		return;
	}

	if (a == 0) {
		vec.push_back(c);
	}

	visited[a][b] = 1;

	if (a + b > B) {
		dfs((a + b) - B, B, c);
	}
	else {
		dfs(0, a + b, c);
	}

	if (a + b > A) {
		dfs(A, (a + b) - A, c);
	}
	else
		dfs(a + b, 0, c);

	if (c + a > A) {
		dfs(A, b, (a + c) - A);
	}
	else
		dfs(c + a, b, 0);
	
	if (c + b > B) {
		dfs(a, B, (c + b) - B);
	}
	else
		dfs(a, c + b, 0);

	dfs(a, 0, b + c);
	dfs(0, b, a + c);

	
}

int main() {

	cin >> A >> B >> C;

	dfs(0, 0, C);

	sort(vec.begin(), vec.end());

	for (auto x : vec) {
		cout << x << " ";
	}
}

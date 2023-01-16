#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10];
int N;
vector<int> vec;
bool check[10] = { false };
int result = 0;

void init() {
	for (int i = 0; i < N; i++) {
		arr[i] = 0;
		check[i] = false;
	}
}

void dfs(int cnt) {
	if (cnt == N) {
		int max_num = 0;
		for (int i = 0; i <= N - 2; i++) {
			max_num += abs(arr[i + 1] - arr[i]);
		}
		result = max(result, max_num);
	}
	else {
		int next_num = 0;
		int max_diff = 0;
		for (int i = 0; i < N; i++) {
			if (check[i] == false){
				if (max_diff <= abs(arr[cnt - 1] - vec[i])) {
					next_num = i;
					max_diff = abs(arr[cnt - 1] - vec[i]);
				}
			}
		}
		arr[cnt] = vec[next_num];
		check[next_num] = true;
		dfs(cnt + 1);
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++) {
		arr[0] = vec[i];
		check[i] = true;
		dfs(1);
		init();
	}

	cout << result << endl;
}

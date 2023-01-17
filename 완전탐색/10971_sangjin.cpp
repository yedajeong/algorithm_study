#include <iostream>
#include <algorithm>
using namespace std;

int N, start_city;
int city[11][11];
int check[11] = { false, };
int min_result = 2e9;

void dfs(int city_num, int cnt, int result) {
	check[city_num] = true;
	if (cnt == N) {
		if (city[city_num][start_city] > 0) {
			min_result = min(result + city[city_num][start_city], min_result);
		}
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (check[i] == false && city[city_num][i] != 0) {
				check[i] = true;
				dfs(i, cnt + 1, result + city[city_num][i]);
				check[i] = false;
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			city[i][j] = a;
		}
	}

	for (int i = 0; i < N; i++) {
		start_city = i;
		check[i] = true;
		dfs(i, 1, 0);
		check[i] = false;
	}

	cout << min_result << endl;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0, C = 0;
	int idx = 0;

	cin >> N >> C;

	vector<int>house(N, 0);
	for (idx; idx < N; ++idx)
		cin >> house[idx];
	sort(house.begin(), house.end());

	int left = 0, right = house[N - 1];
	// 공유기 사이의 거리를 x라고하면 
	//x를 기준으로 공유기 설치
	//c개 이상 설치한 경우에는 => 여유가 있다.
	while (left <= right) {
		int iptime_cnt = 1;
		int pre_idx = 0;
		int mid = (left + right) / 2;
		for (idx = 1; idx < N; ++idx) {
			if (house[idx] - house[pre_idx] >= mid) {
				pre_idx = idx;
				iptime_cnt++;
			}
		}
		if (iptime_cnt >= C)
			left = mid + 1;
		else right = mid - 1;
	}
	cout << right;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> node;

int main() {
	cin.tie(0); // 이줄포함 3줄 포함하니깐 맞음...
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		node.push_back(a);
	}
	sort(node.begin(), node.end());
	
	cin >> M;
	for (int j = 0; j < M; j++) {
		int start = 0;
		int end = N - 1;
		bool find = false;
		int k;
		cin >> k;

		while (start <= end) {
			int mid = (start + end) / 2;
			if (k == node[mid]) {
				find = true;
				break;
			}
			else if( k < node[mid]){
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}

		}

		if (find == true) {
			cout << "1" << " ";
		}
		else
			cout << "0" << " ";
	}
}

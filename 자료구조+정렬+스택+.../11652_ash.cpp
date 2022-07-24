#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long arr[100000];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr+N);

	int cnt = 1;
	int max_cnt = 0;
	int idx = 0;
	
	for (int i = 1; i < N; i++) {
		if (arr[i] == arr[i - 1]) {
			cnt++;
			if (cnt > max_cnt) { //정렬된 array내에서 진행하기 때문에 더 작은수인지를 확인할 필요는 없다.
				max_cnt = cnt;
				idx = i; //index로 안하고 값 자체를 저장했더니 틀림;; 왜지..?
			}
		}
		else {
			cnt = 1;
		}
	}

	cout << arr[idx] << '\n';

	return 0;
}

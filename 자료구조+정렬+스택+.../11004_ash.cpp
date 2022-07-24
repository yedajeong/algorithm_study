#include <iostream>
#include <algorithm>
using namespace std;
int arr[5000000];

int main() {
	int N, K;
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	cout << arr[K - 1];

	return 0;
}

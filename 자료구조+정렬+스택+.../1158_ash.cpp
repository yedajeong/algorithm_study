#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	int arr[5001] = { 0 };
	queue<int> q;

	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		arr[i] = q.front();
		q.pop();
	}
	
	cout << '<';
	
	for (int i = 0; i < n-1; i++) {
		cout << arr[i] << ", ";
	}

	cout << arr[n - 1] << '>' << '\n';

	return 0;
}

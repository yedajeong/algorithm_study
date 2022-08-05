#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, B;
	vector<int> v;
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> B;
	while (N != 0) {
		int a = N / B;
		int r = N % B;
		N = a;
		v.push_back(r);
	}

	reverse(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		if (v[i] <= 9) {
			cout << v[i];
		}
		else {
			cout << char(v[i] + 55);
		}
	}
	cout <<'\n';
	return 0;
}

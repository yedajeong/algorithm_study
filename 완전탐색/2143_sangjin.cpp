#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long int A[1001] = { 0 };
long long int B[1001] = { 0 };
vector<long long int>sum_a;
vector<long long int>sum_b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long int T,n,m;
	cin >> T >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> B[j];
	}

	for (int i = 0; i < n; i++) {
		long long int a = 0;
		for (int j = i; j < n; j++) {
			a = a + A[j];
			sum_a.push_back(a);
		}
	}
	for (int i = 0; i < m; i++) {
		long long int b = 0;
		for (int j = i; j < m; j++) {
			b = b + B[j];
			sum_b.push_back(b);
		}
	}

	sort(sum_a.begin(), sum_a.end());
	sort(sum_b.begin(), sum_b.end());

	long long int cnt = 0;
	int start = 0;
	int end = sum_b.size() - 1;

	while (start < sum_a.size() && end >= 0) {
		long long int a_start = sum_a[start];
		long long int b_end = sum_b[end];
		long long int a_cnt = 0;
		long long int b_cnt = 0;

		if (a_start + b_end > T) {
			end--;
		}
		else if (a_start + b_end == T) {
			while (start < sum_a.size() && sum_a[start] == a_start) {
				start++;
				a_cnt++;
			}
			while (end >= 0  && sum_b[end] == b_end) {
				end--;
				b_cnt++;
			}
			cnt += a_cnt * b_cnt;
		}
		else {
			start++;
		}
	}


	cout << cnt << endl;
	/*
	long long result = 0;

	for (int i = 0; i < sum_b.size(); i++) {
		int low = lower_bound(sum_a.begin(), sum_a.end(), T - sum_b[i]) - sum_a.begin();
		int high = upper_bound(sum_a.begin(), sum_a.end(), T - sum_b[i]) - sum_a.begin();
		
		result += high - low;
	}

	cout << result << endl;
	*/


}

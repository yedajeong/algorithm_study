#include <iostream>
#include <vector>
using namespace std;

vector<int> copy_arr(1000001, 0);

void merge(vector<int> &v, int start, int mid, int end);
void mergesort(vector<int>& v, int start, int end);

int main() {
	std::ios_base::sync_with_stdio(false);
	int N;

	cin >> N;

	vector<int> v(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	mergesort(v, 0, N - 1);


	for (auto x : v)
		cout << x << '\n';

	return 0;
}

void merge(vector<int>& v, int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

 
	while (i <= mid && j <= right) {
		if (v[i] <= v[j]) {
			copy_arr[k] = v[i];
			k++;
			i++;
		}
			
		else {
			copy_arr[k] = v[j];
			k++;
			j++;
		}	
	}

	if (i > mid) {
		for (l = j; l <= right; l++) {
			copy_arr[k] = v[l];
			k++;
		}	
	}
	else {
		for (l = i; l <= mid; l++) {
			copy_arr[k] = v[l];
			k++;
		}
	}

	for (l = left; l <= right; l++)
		v[l] = copy_arr[l];
}

void mergesort(vector<int>& v, int start, int end) { //1,5
	int mid;

	if (start < end) {
		mid = (start + end) / 2;
		mergesort(v, start, mid); //1,3
		mergesort(v, mid + 1, end); //4,5
		merge(v, start, mid, end); //
	}
}

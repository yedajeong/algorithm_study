#include <stdio.h>

void merge(int arr[], int start, int mid, int end); 
void mergesort(int arr[], int start, int end);

int main() {
	//입력
	int N;
	int arr[1000001] = { 0 };
	
	scanf_s("%d" ,&N);
	
	for (int i = 1; i <= N; i++) {
		scanf_s("%d" , &arr[i]);
	}

	mergesort(arr, 1, N);

	for (int i = 1; i <= N; i++) {
		printf("%d\n"  , arr[i]);
	}

	return 0;
}

void merge(int arr[], int start , int mid, int end) {
	int sortarr[1000001] = { 0 };
	int i, j, k;
	i = start; j = mid+1; k = start;
	
	while (i <= mid && j <= end) {
		if (arr[i] > arr[j]) {
			sortarr[k] = arr[j];
			j++;
		}
		else {
			sortarr[k] = arr[i];
			i++;
		}
		k++;
	}

	if (i > mid) { 
		for (int idx = 0; idx <= end-j; idx++) {
			sortarr[k + idx] = arr[j + idx];
		}
	}
	else {
		for (int idx = 0; idx <= mid - i; idx++) {
			sortarr[k + idx] = arr[i + idx];
		}
	}

	for (int idx = start; idx <= end; idx++) {
		arr[idx] = sortarr[idx];
	}

}

void mergesort(int arr[], int start, int end) {
	int mid = (start+end) / 2; 

	if ( start < end ) {
		mergesort(arr, start, mid);
		mergesort(arr, mid+1, end); 
		merge(arr, start, mid, end); 
	}
}

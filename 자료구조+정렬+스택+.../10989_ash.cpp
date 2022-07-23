#include <stdio.h>

int main() {
	int N;
	int arr[10001] = { 0 };
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		scanf_s("%d", &num);
		arr[num]++;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}

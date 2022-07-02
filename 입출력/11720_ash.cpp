#include <stdio.h>

int main() {
	int N,num;
	int sum = 0;
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%1d", &num);
		sum += num;
	}

	printf("%d", sum);
	return 0;
}
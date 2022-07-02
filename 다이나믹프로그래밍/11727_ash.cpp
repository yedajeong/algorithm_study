#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* sol = new int[n + 1]; //숫자랑 인덱스랑 맞추기

	if (n ==1) {
		sol[1] = 1;
	}
	else if (n == 2) {
		sol[1] = 1;
		sol[2] = 3;
	}
	else {
		sol[1] = 1;
		sol[2] = 3;
		for (int i = 3; i < n + 1; i++) {
			sol[i] = (sol[i - 1] + sol[i - 2]*2) % 10007; //int 값 범위 때문에 계산할때부터 10007로 나눠준다;;
		}
	}
	cout << sol[n];

	delete[] sol;
	return 0;
}
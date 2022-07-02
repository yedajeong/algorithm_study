#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) { //0,1,2,3,4
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int j = 2*N-1; j > 2*i; j--) { //9(9~1), 7(9876543), 5(98765), 3(987), 1(9)
			cout << "*";
		}
		cout << endl;
	}

	for (int i = 0; i < N - 1; i++) { //0,1,2,3
		for (int j = N; j > i+2; j--) { //3(5,4,3),2(5,4),1,0
			cout << " ";
		}
		for (int j = 0; j < 2 * i + 3; j++) { //3(0,1,2), 5(0,1,2,3,4), 7, 9
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}
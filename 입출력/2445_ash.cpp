#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 2 * N - 1; i++) { //0,1,2,3,4,5,6,7,8
		if (i < N) { //0,1,2,3,4
			for (int j = 0; j < i + 1; j++) { //1,2,3,4,5 
				cout << "*";
			}
			for (int j = N; j > i+1; j--) { // 4(5432),3(543),2(54),1(5),0(56(x))
				cout << " ";
			}
			for (int j = N; j > i+1; j--) {
				cout << " ";
			}
			for (int j = 0; j < i + 1; j++) {
				cout << "*";
			}
		}
		else { //5,6,7,8
			for (int j = N; j > i-N+1; j--) { //4(5432),3(543),2(54),1(5)
				cout << "*";
			}
			for (int j = 0; j < i-N + 1; j++) {//1,2,3,4
				cout << " ";
			}
			for (int j = 0; j < i-N + 1; j++) {
				cout << " ";
			}
			for (int j = N; j > i-N+1; j--) {
				cout << "*";
			}
		}
		cout << endl;
	}
}
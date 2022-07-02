#include <iostream>
using namespace std;

/*
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) { //0,1,2
		for (int j = N; j > i+1; j--) { 
			cout << " ";
		}
		for (int j = 0; j < i+1; j++) {
			cout << "*";
		}
		cout << endl;
	}

	for (int i = 0; i < N - 1; i++) { //0,1
		for (int j = 0; j < i+1; j++) { 
			cout << " ";
		}
		for (int j = N; j > i + 1; j--) {//2,1
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}*/

//¼öÁ¤
int main() {
	int N;
	cin >> N;//3
	for (int i = 0; i < N; i++) { //0,1,2
		for (int j = 0; j < N; j++) { //0,1,2
			if (j > N-i-2) { //i=0, j=2;   i=1, j=1,2; i=2, j=0,1,2
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < N - 1; i++) { //0,1
		for (int j = 0; j < N; j++) { //0,1,2
			if (j > i) { //i=0, j=1,2;   i=1, j=2;
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;

int main() {
	int n[200001] = { 0 }; //다들 2차원으로 하드라...
	int trynum;
	cin >> trynum;

	for (int i = 0; i < trynum; i++) { //전체 반복 횟수
		int size;
		cin >> size;
		int num[200001] = { 0 };
		for (int i = 1; i < 2 * size; i += 2) { 
			cin >> num[i]; //첫째줄
		}
		for (int i = 2; i < 2 * size + 1; i += 2) {
			cin >> num[i]; //둘째줄
		}

		n[1] = num[1];
		n[2] = num[2];
		n[3] = num[2] + num[3];
		n[4] = num[1] + num[4];

		if (size > 2) {
			for (int i = 3; i < size + 1; i++) {
				n[2 * i - 1] = max(n[2 * i - 2] + num[2 * i - 1], n[2 * (i - 2)] + num[2 * i - 1]); //윗줄로 도착
				n[2 * i] = max(n[2 * i - 3] + num[2 * i], n[2 * i - 5] + num[2 * i]);  //아래줄로 도착
			}
		}
		int maximum = max(n[2 * size], n[2 * size - 1]);
		cout << maximum << endl;
	}
	return 0;
}
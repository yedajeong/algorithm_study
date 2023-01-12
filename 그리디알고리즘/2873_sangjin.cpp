#include <iostream>
#include <vector>
using namespace std;

int graph[1001][1001];


int main() {
	int R, C;
	cin >> R >> C;

	pair <int, int> blank;
	int min = 1001;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int a;
			cin >> a;
			if (min > a && (i + j) % 2 == 1) {
				min = a;
				blank.first = i;
				blank.second = j;
			}
			graph[i][j] = a;
		}
	}

	if (R % 2 == 1) {
		for (int t = 0; t <= R - 1; t++) {
			for (int n = 0; n < C - 1; n++) {
				if (t % 2 == 0) {
					cout << "R";
				}
				else {
					cout << "L";
				}
			}
			if (t != R - 1) 
				cout << "D";
			
		}
	}
	else if (C % 2 == 1) {
		for (int t = 0; t <= C - 1; t++) {
			for (int n = 0; n < R - 1; n++) {
				if (t % 2 == 0) {
					cout << "D";
				}
				else {
					cout << "U";
				}
			}
			if (t != C - 1)
				cout << "R";
		}
	}
	else {
		int r, c;
		if (blank.first % 2 == 1)
			r = blank.first - 1; //blank가 있는 윗줄까지
		else
			r = blank.first; //blank가 있는 줄까지 

		//blank가 있는 줄 전까지  
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < C - 1; j++) {
				if (i % 2 == 0)
					cout << "R";
				else
					cout << "L";
			}
			cout << "D";
		}
		c = blank.second;

		for (int i = 0; i < c; i++) {
			if (i % 2 == 0)
				cout << "DR";
			else
				cout << "UR";
		}

		//blank 후
		for (int i = c; i < C - 1; i++) {
			if (i % 2 == 0)
				cout << "RD";
			else
				cout << "RU";
		}

		for (int i = r + 2; i < R; i++) {
			cout << "D";
			for (int j = 0; j < C - 1; j++) {
				if (i % 2 == 0)
					cout << "L";
				else
					cout << "R";
			}
		}
	}
	//R과 C가 모두 짝수일 때는 모든 칸을 지나치지 못한다(최소 한칸은 지나치지 못함) 
  //기쁨의 합이 최대로 하기 위해서는 지 제일 작은 기쁨인 한 칸을 제외하고 모든 칸을 지나쳐야한다.

}

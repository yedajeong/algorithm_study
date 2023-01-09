#include <iostream>
#include <string>
using namespace std;

#define NUM (1000000000)
#define ABS(a) ((a)>0? (a) : (-a))

void numX(int x);
void pop();
void inv();
void dup();
void swp();
void add();
void sub();
void mul();
void div();
void mod();

long long stack[1001]; //int 4byte: 2^31 = 약 21억
						//long long 8byte: 64비트
int cmd[100001];
int num[100001];

int sPt,cPt, nPt;
string command;
int flag;

void input();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string command;
	while (1) {
		input();
		if (flag == -1) return 0;
		
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			sPt = nPt = 0;
			int first;
			cin >> first;
			stack[sPt++] = first;

			for (int j = 0; j < cPt; j++) {
				flag = 0;
				if (cmd[j] == 0) {
					numX(num[nPt++]);
				}
				else if (sPt == 0) { //숫자부족
					flag = -2;
					break;
				}
				else if (cmd[j] == 1) {
					pop();
				}
				else if (cmd[j] == 2) {
					inv();
				}
				else if (cmd[j] == 3) {
					dup();
				}
				else if (cmd[j] == 4) {
					swp();
				}
				else if (cmd[j] == 5) {
					add();
				}
				else if (cmd[j] == 6) {
					sub();
				}
				else if (cmd[j] == 7) {
					mul();
				}
				else if (cmd[j] == 8) {
					div();
				}
				else if (cmd[j] == 9) {
					mod();
				}
				if (flag == -2) break; //기타 에러
			}
			if (flag == -2 || sPt != 1) {
				cout << "ERROR\n";
			}
			else cout <<stack[0] <<'\n';
		}
		cout << '\n';
	}
	return 0;
}

void input() {
	flag = 0;
	cPt = nPt = 0;
	while (1) {
		cin >> command;
		if (command == "END") {
			break;
		}
		if (command == "QUIT") {
			flag = -1;
			return;
		}
		else if (command == "NUM") {
			int x;
			cin >> x;
			cmd[cPt++] = 0;
			num[nPt++] = x;
		}
		else if (command == "POP") {
			cmd[cPt++] = 1;
		}
		else if (command == "INV") {
			cmd[cPt++] = 2;
		}
		else if (command == "DUP") {
			cmd[cPt++] = 3;
		}
		else if (command == "SWP") {
			cmd[cPt++] = 4;
		}
		else if (command == "ADD") {
			cmd[cPt++] = 5;
		}
		else if (command == "SUB") {
			cmd[cPt++] = 6;
		}
		else if (command == "MUL") {
			cmd[cPt++] = 7;
		}
		else if (command == "DIV") {
			cmd[cPt++] = 8;
		}
		else if (command == "MOD") {
			cmd[cPt++] = 9;
		}
	}
}

void numX(int x) {
	stack[sPt++] = x;
}

void pop() {
	sPt--;
}

void inv() {
	stack[sPt - 1] = -stack[sPt - 1];
}

void dup() {
	stack[sPt] = stack[sPt - 1];
	sPt++;
}

void swp() {
	long long tmp = stack[sPt - 2];
	stack[sPt - 2] = stack[sPt - 1];
	stack[sPt - 1] = tmp;
}

void add() {
	long long tmp = stack[sPt - 1] + stack[sPt - 2];
	if (ABS(tmp) > NUM) {
		flag = -2;
		return;
	}
	stack[sPt - 2] = tmp;
	sPt--;
}

void sub() {
	long long tmp = stack[sPt - 2] - stack[sPt - 1];
	if (ABS(tmp) > NUM) {
		flag = -2;
		return;
	}
	stack[sPt - 2] = tmp;
	sPt--;
}

void mul() {
	long long tmp = stack[sPt - 2]  * stack[sPt - 1];
	if (ABS(tmp) > NUM) {
		flag = -2;
		return;
	}
	stack[sPt - 2] = tmp;
	sPt--;
}

void div() {
	if (stack[sPt - 1] == 0) {
		flag = -2;
		return;
	}

	long long tmp1, tmp2;
	tmp1 = stack[sPt - 2];
	tmp2 = stack[sPt - 1];

	if (tmp1 * tmp2 < 0) {
		tmp1 = -(ABS(tmp1) / ABS(tmp2));
	}
	else {
		tmp1 = (ABS(tmp1) / ABS(tmp2));
	}
	stack[sPt - 2] = tmp1;
	sPt--;
}

void mod() {
	if (stack[sPt - 1] == 0) {
		flag = -2;
		return;
	}

	long long tmp = (ABS(stack[sPt-2]) % ABS(stack[sPt-1]));
	if (stack[sPt - 2] < 0) {
		stack[sPt - 2] = -tmp;
	}
	else {
		stack[sPt - 2] = tmp;
	}
	sPt--;
}

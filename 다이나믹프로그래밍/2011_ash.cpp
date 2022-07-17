#include <iostream>
#include <string>
using namespace std;

int main() {
	int dp[5001][2] = { 0, }; //0: 맨 앞이 두자리 수  2: 맨 앞이 한자리 수
	int num[5001] = { 0 };
	string input;

	cin >> input;

	int len = input.length();

	for (int i = len; i > 0; i--) { //암호 입력받고 저장 (거꾸로)
		num[i] = input[len-i]-'0'; //문자의 경우 '0'=48을 빼주면 숫자로 바꿀 수 있다...
	}
	
	if (num[len] == 0 ) { //암호가 잘못된 경우 case1--> 0으로 시작
		cout << 0 << endl;
	} //case 2 --> 0앞의 수가 30, 40
	else {
		dp[1][0] = 1;
		dp[1][1] = 0;

		for (int i = 2; i < len + 1; i++) {
			dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000;
			if (num[i] > 2 || (num[i] == 2 && num[i - 1] > 6)) { //27이상일 때
				dp[i][1] = 0;
			}
			else if(num[i]==0 && ( num[i+1]!=1 && num[i+1]!=2)){
				cout << 0 << endl;
				return 0;
			}
			else {
				dp[i][1] = dp[i - 1][0];
			}
		}

		cout << (dp[len][0] + dp[len][1]) % 1000000 << endl;
	}

	return 0;
}
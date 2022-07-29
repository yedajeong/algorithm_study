#include <iostream>
#include <string>
using namespace std;


int main() {
	string input;


	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	

	while (getline(cin, input)) {//한줄을 받음 & EOF입력시 종료
		int arr[4] = { 0 };

		for (int i = 0; i < input.length(); i++) {
			if (input[i] == ' ') { //공백
				arr[3]++;
			}
			else if (input[i] < 58 && input[i]>47) { //숫자
				arr[2]++;
			}
			else if (input[i] > 64 && input[i] < 91) {
				arr[1]++;
			}
			else if (input[i] > 96 && input[i] < 123) {
				arr[0]++;
			}
		}

		for (int i = 0; i < 4; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}

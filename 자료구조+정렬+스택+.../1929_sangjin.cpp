#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int Prime_num[1000001] = { 0, };

int main() {
	int input_start, input_end;

	cin >> input_start >> input_end;

	for (int i = 2; i <= input_end; i++) {
		Prime_num[i] = i;
	}

	for (int i = 2; i <= sqrt(input_end); i++) { //2 3 4 
		if (Prime_num[i] == 0) {
			continue;
		}

		for (int j = i * i; j <= input_end; j += i) {  
			Prime_num[j] = 0;   
		}
	}

	for (int i = input_start; i <= input_end; i++)
	{
		if (Prime_num[i] != 0) {
			cout << Prime_num[i] << '\n';
		}
	}
	return 0;
}

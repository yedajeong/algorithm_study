#include <iostream>
using namespace std;

int main() {
	int input_num, arr_num;
	int max_num = -1000000, min_num = 1000000;
	cin >> input_num;

	int num_array[1000001];

	for (int i = 0; i < input_num; i++) {
		cin >> arr_num;
		num_array[i] = arr_num;
	}

	for (int i = 0; i < input_num; i++) {
		if (num_array[i] > max_num) {
			max_num = num_array[i];
		}
		if (num_array[i] < min_num) {
			min_num = num_array[i];
		}
	}

	cout << min_num << " " << max_num << '\n';

	return 0;
}
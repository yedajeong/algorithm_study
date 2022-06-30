#include <iostream>
using std::cout;
using std::cin;
using std::endl;

bool MathArea(int a) {
	if (0 < a < 10)
		return true;
	else
		return false;

}

int main() {
	int a, b;
	int num_count;

	cin >> num_count;

	for (int i = 0; i < num_count; i++) {
		cin >> a >> b;
		if (MathArea(a) && MathArea(b))
			cout << a + b << endl;
		else
			cout << "잘못된 범위의 숫자입니다." << endl;
	}
}
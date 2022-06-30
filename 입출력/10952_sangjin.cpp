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
	int a, b, num;
	while (true)
	{
		cin >> a >> b;
		num = a + b;
		if (a == 0 && b == 0)
			break;

		if (MathArea(a) && MathArea(b))
			cout << num << endl;
		else
			cout << "잘못된 범위의 숫자입니다." << endl;
	}
	return 0;
}
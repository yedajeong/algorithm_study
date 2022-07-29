#include <iostream>
#include <string>
using namespace std;

int main() {
	string A, B, C, D;

	cin >> A >> B >> C >> D;

	string plus_front = A + B;
	string plus_back = C + D;

	cout << stoll(plus_front) + stoll(plus_back) << '\n';
}

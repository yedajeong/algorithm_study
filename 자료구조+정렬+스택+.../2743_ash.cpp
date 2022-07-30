#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> input;
	cout << input.length() << '\n';
	return 0;
}

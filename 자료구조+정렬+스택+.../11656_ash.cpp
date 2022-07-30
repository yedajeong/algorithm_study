#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string input;
	vector<string> v;
	cin >> input;
	
	for (int i = 0; i < input.length(); i++) {
		v.push_back(input.substr(i,input.length()-i));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < input.length(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}

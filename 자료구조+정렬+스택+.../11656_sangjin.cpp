#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string word;
	vector<string> vec;

	cin >> word;

	int length = word.size();

	for (int i = 0; i < length; i++) {
		string a = word.substr(i);
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < length; i++) {
		cout << vec[i] << '\n';
	}
}

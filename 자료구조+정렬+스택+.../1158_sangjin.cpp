#include <iostream>
#include <vector>
using namespace std;

int main() {
	int pp_num, od_num;
	vector<int> v;
	vector<int> print_v;

	cin >> pp_num >> od_num;
	for (int i = 0; i < pp_num; i++) {
		v.push_back(i + 1);
	}

	int size = od_num - 1;

	for (int i = 0; i < pp_num-1; i++) {
		print_v.push_back(v[size]);
		v.erase(v.begin() + size);
		size = (size + od_num - 1) % v.size();	
	}


	cout << "<";
	for (auto x : print_v) {
		cout << x << ", ";
	}
	cout << v[0] << ">" << '\n';
}

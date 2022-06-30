#include <iostream>
#include <string>
using namespace std;

int main() {
	int num;
	string input_num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> input_num;
		if (input_num.find(",") == string::npos)
			cout << "잘못된 형식의 입력값" << endl;
		else
		{
			int k = input_num.find(",");
			string a = input_num.substr(0, k);
			string b = input_num.substr(k + 1);
			int a_num = stoi(a);
			int b_num = stoi(b);
			cout << a_num + b_num << endl;
		}

	}
	return 0;
}
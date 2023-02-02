#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int L, C;
char password[16];
bool visited[16] = { false };

void dfs(string a, int cnt) {
	if (cnt == L) {
		//count는 모음의 총 합
		int count = std::count(a.begin(), a.end(), 'a') + std::count(a.begin(), a.end(), 'e')+ std::count(a.begin(), a.end(), 'i')
			+ std::count(a.begin(), a.end(), 'o')+ std::count(a.begin(), a.end(), 'u');
		
		if (cnt - count >= 2 && count != 0) {
			cout << a << endl;
		}
		
		return;
	}
	else{
		for (int i = 0; i < C; i++) {
			if (visited[i] != true) {
				if (cnt != 0) {
					if (a.back() < password[i]) {
						visited[i] = true;
						dfs(a + password[i], cnt + 1);
						visited[i] = false;
					}
				}
				else {
					visited[i] = true;
					dfs(a + password[i], cnt + 1);
					visited[i] = false;
				}
			}
		}
	}
}

int main() {
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> password[i];
	}

	sort(password, password + C);

	dfs("", 0);
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>


using namespace std;

int n, k; //n: 단어 갯수 k: 배울 글자
vector<string> words; //단어 배열
bool alphabet[26]; //알파벳 배우는 여부 체크
int result; //답
int countWords();
void dfs(int id, int cnt);

int main() {

	//freopen("input.txt", "r", stdin);
	cin >> n >> k;
	result = 0;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		words.push_back(s);
	}

	//a,n,t,i,c 는 꼭 배워야함.
	alphabet['a' - 'a'] = true;
	alphabet['n' - 'a'] = true;
	alphabet['t' - 'a'] = true;
	alphabet['i' - 'a'] = true;
	alphabet['c' - 'a'] = true;

	dfs(1,k-5); //b부터 시작

	printf("%d",result);

	return 0;
}

void dfs(int id, int cnt) {
	if (cnt == 0) { //k개만큼 선택함
		int num = countWords();
		if (result < num) {
			result = num;
		}
		return;
	}

	if (id >= 26) return; //z까지 선택 안함
	
	//1)알파벳 사용
	if (alphabet[id] == false) {
		alphabet[id] = true;
		dfs(id+1, cnt-1);
		alphabet[id] = false; //backtracking
	}
 
 //안사용
	dfs(id + 1, cnt);
}

int countWords() {
	string word;
	int num = 0;
	bool canRead;

	for (int i = 0; i < words.size(); i++) {
		canRead = true;
		word = words[i];
		for (int j = 0; j < word.size(); j++) {
			if (alphabet[word[j] - 'a'] == false) {
				canRead = false;
				break;
			}
		}

		if (canRead == true) num++;
	}

	return num;
}

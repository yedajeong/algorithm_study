#include <iostream>
#include <vector>;
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
}


int main() {
	vector<pair<int, int>> conf;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		conf.push_back(make_pair(start, end));
	}
	
	sort(conf.begin(), conf.end(), cmp);
	//그냥 sort는 정수를 자료형으로 갖는 pair의 first를 1차, second를 2차로 오름차순 정렬한다.

	int end_time = conf[0].second;
	int count = 1;
	for (int i = 1; i < N; i++) {
		if (end_time <= conf[i].first)
		{
			count++;
			end_time = conf[i].second;
		}
	}

	cout << count;
}

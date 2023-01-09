#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

	int N, start, end;
	cin >> N;
	vector<pair<int, int>> schedule;

	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		schedule.push_back(make_pair(end, start));
	}

	sort(schedule.begin(), schedule.end());

	int time = schedule[0].first;
	int count = 1;
	for (int i = 1; i < N; i++)
	{
		if (time <= schedule[i].second)
		{
			count++;
			time = schedule[i].first;
		}
	}

	cout << count;
}

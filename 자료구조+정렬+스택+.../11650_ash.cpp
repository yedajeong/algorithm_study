#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

bool compare(Point& a, Point& b) {
	if (a.x < b.x) {
		return true;
	}
	else if (a.x == b.x) {
		if (a.y < b.y) {
			return true;
		}
		else return false;
	}
	else return false;
}

int main() {
	int N, x, y;
	cin >> N;
	vector<Point> v;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(Point(x, y));
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << v[i].x << ' ' << v[i].y << '\n'; //endl은 시간초과...
	}

	return 0;
}

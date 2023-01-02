#include <iostream>
#include <cmath>
using namespace std;


double Start(double start, double end) {
	return start + (end - start) / 3;
}

double End(double start, double end) {
	return end - (end - start) / 3;
}

int main() {
	double ax, ay, bx, by, cx, cy, dx, dy;

	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

	double mid1 = 0, mid2 = 0;

	int i = 100;
	while (i--) {
		mid1 = sqrt(pow(ax - cx, 2) + pow(ay - cy, 2));
		mid2 = sqrt(pow(bx - dx, 2) + pow(by - dy, 2));

		if (mid1 >= mid2) {
			ax = Start(ax, bx);
			ay = Start(ay, by);
			cx = Start(cx, dx);
			cy = Start(cy, dy);
		}
		else if (mid1 < mid2) {
			bx = End(ax, bx);
			by = End(ay, by);
			dx = End(cx, dx);
			dy = End(cy, dy);
		}
		else {
			break;
		}
	}
	cout << fixed;
	cout.precision(10);
	cout << min(mid1, mid2);
}

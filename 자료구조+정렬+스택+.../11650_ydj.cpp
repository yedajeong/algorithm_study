#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point{
public:
    int x, y;
    Point(int _x, int _y):x(_x), y(_y){}
};

bool compare(Point a, Point b){
    if (a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}

int main(){
    int N, x, y;

    cin >> N;

    vector<Point> v;
    for (int i=0; i<N; i++){
        cin >> x >> y;
        v.push_back(Point(x, y));
    }
    
    sort(v.begin(), v.end(), compare); // 사용자 정의 함수로 sorting

    for (int i=0; i<N; i++)
        cout << v[i].x << " " << v[i].y << '\n';

    //cout << v.size() << endl;
    return 0;
}

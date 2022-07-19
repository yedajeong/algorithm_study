#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    // 시간초과 방지
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, K, item;

    cin >> N >> K;

    vector<int> v;

    for (int i=0; i<N; i++){
        cin >> item;
        v.push_back(item);
    }
    
    sort(v.begin(), v.end());

    cout << v[K-1] << endl;

    return 0;
}

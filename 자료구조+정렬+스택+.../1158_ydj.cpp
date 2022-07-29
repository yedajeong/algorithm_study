#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K;
    
    cin >> N >> K;

    vector<int> v;

    cout << "<";

    for (int i=1; i<=N; i++)
        v.push_back(i);

    int idx = -1;
    for (int i=0; i<N; i++){
        idx = (idx+K)%(N-i);
        cout << v[idx];
        v.erase(v.begin()+idx);
        idx--;

        if (i<N-1)
            cout << ", ";
    }

    cout << ">\n";

    return 0;
}

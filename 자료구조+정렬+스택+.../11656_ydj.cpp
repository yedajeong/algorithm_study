#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string S;

    cin >> S;

    vector<string> v(S.size());
    
    for (int i=0; i<S.size(); i++)
        v[i] = S.substr(i);

    sort(v.begin(), v.end());

    for (int i=0; i<S.size(); i++)
        cout << v[i] << "\n";

    return 0;
}

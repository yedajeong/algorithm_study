#include <iostream>
#include <map>
using namespace std;

int main(){
    int N;

    cin >> N;

    map<long long, int> myMap;
    long long item;

    for (int i=0; i<N; i++){
        cin >> item;
        myMap[item] += 1;
    }


    map<long long, int>::iterator p = myMap.begin();
    map<long long, int>::iterator result = p;
    for (p=p; p!=myMap.end(); p++){
        if (result->second < p->second)
            result = p;
    }

    cout << result->first << "\n";

    return 0;
}

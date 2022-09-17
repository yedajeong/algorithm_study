#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int next(int n, int P){
    int result = 0;

    while(n > 0){
        result += pow(n%10, P);
        n /= 10;
    }

    return result;
}

int main(){
    int A, P;

    cin >> A >> P;

    vector<int> D;
    D.push_back(A);
    int idx = 0;

    while(true){
        int item = next(D[idx], P);

        if(find(D.begin(), D.end(), item) != D.end()){ // 벡터 내에 item이 이미 존재함
            cout << find(D.begin(), D.end(), item) - D.begin() << "\n";
            break;
        }

        D.push_back(item);
        idx++;
    }

    return 0;
}

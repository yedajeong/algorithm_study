#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int A, B, m, input[25];

    cin >> A >> B;
    cin >> m;

    for(int i=0; i<m; i++)
        cin >> input[i];

    // A->10
    int dec = 0;
    for (int i=0; i<m; i++)
        dec += input[i] * pow(A, m-i-1);

    // 10->B
    vector<int> result;
    while(dec/B != 0){ //몫이 0일 때까지
        result.push_back(dec % B);
        dec /= B;
    }

    result.push_back(dec % B);
    
    while(!result.empty()){
        cout << result.back() << " ";
        result.pop_back();
    }

    cout << "\n";

    return 0;
}

#include <iostream>
using namespace std;

int main(){
    int T, A, B;

    cin >> T;

    for (int i=0; i<T; i++){
        cin >> A >> B;
        cout << "Case #"+to_string(i+1)+": "+to_string(A)+" + "+to_string(B)+" = " << A+B << endl;
    }

    return 0;
}
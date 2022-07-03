#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    // 첫 줄
    for (int i=0; i<N-1; i++)
        cout << " ";
    cout << "*\n";

    // 중간 줄
    for (int line=1; line<N-1; line++){
        for (int i=line; i<N-1; i++)
            cout << " ";
        cout << "*";

        for (int i=0; i<2*line-1; i++)
            cout << " ";
        cout << "*\n";
    }

    // 마지막 줄
    if (N>1){
        for (int i=0; i<2*N-1; i++)
            cout << "*";
        cout << "\n";
    }

    return 0;
}
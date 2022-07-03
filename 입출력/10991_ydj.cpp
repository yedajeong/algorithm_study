#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    for (int line=1; line<=N; line++){
        for (int i=line; i<N; i++)
            cout << " ";
        for (int i=0; i<line; i++)
            cout << "* ";
        cout << "\n";
    }

    return 0;
}
#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    for (int line=0; line<N; line++){
        for (int i=0; i<line; i++)
            cout << " ";
        for (int i=0; i<2*(N-line)-1; i++)
            cout << "*";
        cout << "\n";
    }

    for (int line=1; line<N; line++){
        for (int i=0; i<N-line-1; i++)
            cout << " ";
        for (int i=0; i<2*line+1; i++)
            cout << "*";
        cout << "\n";
    }

    return 0;
}
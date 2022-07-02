#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    for (int line=1; line<=N; line++){

        for (int i=0; i<line; i++)
            cout << "*";
        for (int i=0; i<2*(N-line); i++)
            cout << " ";
        for (int i=0; i<line; i++)
            cout << "*";

        cout << "\n";
    }

    for (int line=1; line<N; line++){

        for (int i=N-line; i>0; i--)
            cout << "*";
        for (int j=0; j<2*line; j++)
            cout << " ";
        for (int i=N-line; i>0; i--)
            cout << "*";
        
        cout << "\n";
    }

    return 0;
}
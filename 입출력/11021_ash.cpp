#include <iostream>
using namespace std;

int main() {
    int num, A, B;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> A >> B;
        cout << "Case #"<<i+1<<": "<< A + B << endl;
    }
    return 0;
}
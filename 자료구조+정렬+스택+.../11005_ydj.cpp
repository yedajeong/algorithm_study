#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, B;
    string result = "";
    char num[36];

    cin >> N >> B;

    for (int i=0; i<10; i++)
        num[i] = char(48+i); //0-9
    
    for (int i=10; i<36; i++)
        num[i] = char(55+i); //A-Z

    while(N/B != 0){ //몫이 0일 때까지
        result += num[N%B];
        N /= B;
    }

    result += num[N%B];
    
    for (int i=result.size()-1; i>=0; i--)
        cout << result[i];

    cout << "\n";

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a, b;
    
    cin >> a >> b;

    // 최대공약수 구하기
    vector<int> divisor; //a, b의 공약수

    for (int i=2; i<=min(a, b); i++){
        if (a%i == 0 && b%i == 0){
            a /= i;
            b /= i;
            divisor.push_back(i);
            i--; //나눴던 걸로 다시 나눠보기
            //cout << a << "\t" << b << "\n";
        }
    }

    int result = 1;
    for (int i=0; i<divisor.size(); i++){
        //cout << divisor[i] << endl;
        result *= divisor[i];
    }

    cout << result << "\n";


    // 최소공배수 구하기 (최대공약수*남은 약수 두 개)
    //cout << a << endl << b << endl;
    cout << result * a * b << "\n";

    return 0;
}

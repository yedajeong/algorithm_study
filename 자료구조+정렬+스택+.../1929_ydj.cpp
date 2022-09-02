#include <iostream>
using namespace std;

int main(){
    int M, N;

    cin >> M >> N;

    //에라토스테네스의 체
    int num[N+1];

    for(int i=2; i<=N; i++)
        num[i] = i;

    num[1] = 0; //1은 예외처리
    for(int i=2; i<=N; i++){
        if(num[i] == 0)
            continue;
        for(int j=i+i; j<=N; j+=i)
            num[j] = 0; //지움
    }

    for(int i=M; i<=N; i++)
        if(num[i] != 0)
            cout << num[i] << "\n";

    return 0;
}

#include <iostream>
using namespace std;

long gcd(long big, long small){
    if (big % small != 0)
        return gcd(small, big%small);

    else
        return small;
}

int main(){
    int T, N;
    long result; // 가능한 GCD 합의 최대값이 int 범위 초과

    cin >> T;

    for (int t=0; t<T; t++){
        cin >> N;
        long input[N];

        for (int n=0; n<N; n++)
            cin >> input[n];

        result = 0;
        for (int i=0; i<N; i++){
            for (int j=i+1; j<N; j++)
                result += gcd(max(input[i], input[j]), min(input[i], input[j]));
        }

        cout << result << "\n";
    }

    return 0;
}

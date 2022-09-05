#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    
    int n, left, right;

    //에라토스테네스의 체
    int num[1000001];

    num[1] = 0;
    for(int i=2; i<=1000000; i++)
        num[i] = i;

    for(int i=2; i*i<=1000000; i++){
        if(num[i] == 0)
            continue;
        for(int j=i*i; j<=1000000; j+=i){
            num[j] = 0;
        }
    }

    while(true){
        cin >> n;
        if(n==0)
            break;

        left = 3;
        right = n-3;

        while(left <= right){
            if(num[left] && num[right]){ //소수이면서
                if(num[left]+num[right] == n) //합이 n이면
                    break;
            }
            left+=2; //홀수 소수의 합이므로
            right-=2;
        }

        if(left>right)
            cout << "Goldbach's conjecture is wrong.\n";
        else
            cout << n << " = " << left << " + " << right << "\n";
    }

    return 0;
}

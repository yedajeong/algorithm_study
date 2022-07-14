#include <iostream>
#include <string>
using namespace std;

int main(){
    int mod = 1000000;
    string input;
    long dp[5001][2] = {{0}}; // [][0]: 이전 암호에 붙음 [][1]: 이전 암호에 안붙음
    char code[5001];


    cin >> input;

    int cnt = input.length();

    for (int i=1; i<=cnt; i++)
        code[i] = input[i-1];

    // 잘못된 입력(1)
    if (code[1]=='0'){
        cout << 0 << endl;
        return 0;
    }

    code[0] = 0;
    dp[1][0] = 1; // 문자 하나로 만들 수 있는 암호는 한 개
    
    char zero = '0';
    char six = '6';

    for (int i=2; i<=cnt; i++){
        if (code[i]=='0'){
            dp[i][0] = 0;
            if (code[i-1]=='1' || code[i-1]=='2')
                dp[i][1] = dp[i-1][0];
            else { // 잘못된 입력(2)
                cout << 0 << endl;
                return 0;
            }
        }
            
        else{
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;

            if (code[i-1]=='1')
                dp[i][1] = dp[i-1][0] % mod;

            else if (code[i-1]=='2' && code[i]>=zero && code[i]<=six)
                dp[i][1] = dp[i-1][0] % mod; 
        }
            
    }

    cout << (dp[cnt][0] + dp[cnt][1]) % mod << endl;

    // for (int i=1; i<=cnt; i++){
    //     cout << code[i] << ": " << dp[i][0] << " " << dp[i][1] << endl;
    // }
       

    return 0;

}
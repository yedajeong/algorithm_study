#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string input, result = "";

    cin >> input;

    int idx;
    for(idx=input.size()-1; idx-3>=0; idx-=3){
        int tmp = 0;
        for(int j=0; j<3; j++){
            tmp += (input[idx-j]-'0') * pow(2, j);
        }
        result += to_string(tmp);
    }

    //3개씩 묶고 남은 자리
    if(idx > -1){
        int j=0;
        int tmp = 0;
        while(idx > -1){
            tmp += (input[idx]-'0') * pow(2, j);
            idx--;
            j++;
        }
        result += to_string(tmp);
    }

    for(int i=result.size()-1; i>=0; i--)
        cout << result[i];
    cout << "\n";

    return 0;
}

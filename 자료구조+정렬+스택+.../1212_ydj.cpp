#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string input, result = "";

    cin >> input;

    for(int i=input.size()-1; i>=0; i--){
        int tmp = input[i]-'0';
        string tmpStr = "";
        
        while(tmp / 2 != 0){
            tmpStr += to_string(tmp%2);
            tmp /= 2;
        }

        tmpStr += to_string(tmp%2);

        while(tmpStr.size() < 3)
            tmpStr += "0";

        result += tmpStr;
    }

    //반례
    if(result == "000"){
        cout << "0\n";
        return 0;
    }

    //앞에 0 떼주기
    while(true){
        int i = result.size()-1;
        if(result[i] == '0')
            result = result.substr(0, i);
        else
            break;
    }

    //뒤집어서 출력
    for (int i=result.size()-1; i>=0; i--)
        cout << result[i];
    cout << "\n";


    return 0;
}

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    long long input;
    string result = "";

    cin >> input;

    if (input == 0){
        cout << "0\n";
        return 0;
    }

    while(input/(-2) != 0){
        if(input%(-2) == -1){
            result += "1"; //나머지 1로 만들어주기
            input = input/(-2) + 1;
        }
        else{
            result += to_string(input%(-2));
            input /= -2;
        }
    }

    if (input%(-2)==-1){
        result += "1";
        input = input/(-2) + 1;
    }
    result += to_string(input%(-2));

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

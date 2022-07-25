#include <iostream>
using namespace std;

int main(){
    string input;

    // 대문자: 65-90
    // 소문자: 97-122
    getline(cin, input);
    for (int i=0; i<input.size(); i++){
        if (input[i] <= 90 && input[i]+13 > 90)
            input[i] = (input[i]+13) - 90 + 64;
        else if (input[i] <= 122 && input[i]+13 > 122)
            input[i] = (input[i]+13) - 122 + 96;
        else if (input[i] == 32 || (input[i] >= 48 && input[i] <= 57))
            continue;
        else
            input[i] += 13;
    }

    cout << input << "\n";

    return 0;
}

#include <iostream>
using namespace std;

int main(){
    string input;

    while(true){
        getline(cin, input);

        if (cin.eof()) break;

        int small =0, big = 0, num = 0, ws = 0;
        
        for (int i=0; i<input.size(); i++){
            if (input[i] >= 97 && input[i] <= 122)
                small++;
            else if (input[i] >= 65 && input[i] <= 90)
                big++;
            else if (input[i] >= 48 && input[i] <= 57)
                num++;
            else if (input[i] == 32)
                ws++;
        }
        cout << small << " " << big << " " << num << " " << ws << " \n";
    }

    return 0;
}

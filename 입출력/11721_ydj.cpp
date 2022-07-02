#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;

    cin >> input;

    try{
        while(true){
            if (input.length()>=10){
                cout << input.substr(0, 10) << endl;
                input = input.substr(10);
            }
            else{
                throw(input);
            }
        }
    }
    catch(string s){
        cout << s << endl;
    }

    return 0;
}
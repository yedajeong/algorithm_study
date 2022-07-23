#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Stack{
private:
    char s[100100]; // 런타임 에러나서 배열 크기 여유있게?
    int _top;
    int stick;
    int piece;

public:
    Stack(): _top(-1), stick(0), piece(0) {}

    void push(char input){
        stick++;
        piece++;

        _top++;
        s[_top] = '(';
    }

    void pop(){

        if (s[_top] == '('){ // 레이저
            stick--;
            piece--;
            piece += stick;
        }
        else
            stick--;

        _top++;
        s[_top] = ')';
    }

    int getPiece(){
        return piece;
    }

};


int main(){
    string input;
    Stack stack;

    cin >> input;

    for (int j=0; j<input.size(); j++){
        if (input[j] == '(')
            stack.push('(');

        else if (input[j] == ')')
            stack.pop();
    }

    cout << stack.getPiece() << "\n";
        
    return 0;
}

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Stack{
private:
    char s[50];
    int _size;
    int _top;

public:
    Stack(): _size(0), _top(-1) {}

    void push(){
        _top++;
        _size++;
    }

    void pop(){
        _top--;
        _size--;
    }

    bool empty(){
        if (_size <= 0)
            return 1;
        else
            return 0;
    }
};


int main(){
    int N;

    cin >> N;

    string input, isVPS;

    for (int i=0; i<N; i++){
        Stack stack;
        isVPS = "YES";

        cin >> input;
        char inputArr[input.size()];
        strcpy(inputArr, input.c_str());

        for (int j=0; j<input.size(); j++){
             if (inputArr[j] == '(')
            stack.push();

            else if (inputArr[j] == ')'){
                if (stack.empty()){
                    isVPS = "NO";
                    break;
                }
                else
                    stack.pop();
            }
        }

        if (!stack.empty())
            isVPS = "NO";

        cout << isVPS << "\n";
        
    }

    return 0;
}

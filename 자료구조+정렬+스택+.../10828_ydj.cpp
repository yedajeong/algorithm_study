#include <iostream>
using namespace std;

class Stack{
private:
    int s[10000];
    int _size;
    int _top;

public:
    Stack(): _size(0), _top(-1) {}

    void push(int x){
        _top++;
        s[_top] = x;
        _size++;
    }

    void pop(){
        if (empty())
            cout << -1 << "\n";
        else{
            cout << s[_top] << "\n";
            _top--;
            _size--;
        }
    }

    int size(){
        return _size;
    }

    bool empty(){
        if (_size <= 0)
            return 1;
        else
            return 0;
    }

    void top(){
        if (!empty())
            cout << s[_top] << "\n";
        else
            cout << -1 << "\n";
    }
};


int main(){
    int N, item;
    Stack stack;

    cin >> N;

    string command;

    for (int i=0; i<N; i++){
        cin >> command;

        if (command == "push"){
            cin >> item;
            stack.push(item);
        }
        else if (command == "pop")
            stack.pop();
        else if (command == "size")
            cout << stack.size() << "\n";
        else if (command == "empty")
            cout << stack.empty() << "\n";
        else if (command == "top")
            stack.top();
    }

    return 0;
}

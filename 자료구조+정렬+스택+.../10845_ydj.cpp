#include <iostream>
using namespace std;

class Queue{
private:
    int s[10000];
    int _size;
    int _front;
    int _back;

public:
    Queue(): _size(0), _front(0), _back(-1) {}

    void push(int x){
        _back++;
        s[_back] = x;
        _size++;
    }

    void pop(){
        if (empty())
            cout << -1 << "\n";
        else{
            cout << s[_front] << "\n";
            _front++;
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

    void front(){
        if (!empty())
            cout << s[_front] << "\n";
        else
            cout << -1 << "\n";
    }

    void back(){
        if (!empty())
            cout << s[_back] << "\n";
        else
            cout << -1 << "\n";
    }
};


int main(){
    int N, item;
    Queue queue;

    cin >> N;

    string command;

    for (int i=0; i<N; i++){
        cin >> command;

        if (command == "push"){
            cin >> item;
            queue.push(item);
        }
        else if (command == "pop")
            queue.pop();
        else if (command == "size")
            cout << queue.size() << "\n";
        else if (command == "empty")
            cout << queue.empty() << "\n";
        else if (command == "front")
            queue.front();
        else if (command == "back")
            queue.back();
    }

    return 0;
}

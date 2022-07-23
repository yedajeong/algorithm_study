#include <iostream>
using namespace std;

#define MAX_DEQUE_SIZE 10000
class Deque{
private:
    int dq[MAX_DEQUE_SIZE];
    int _size;
    int _front;
    int _back;

public:
    Deque(): _size(0), _front(0), _back(0) {}

    void push_front(int x){
        _front = (_front-1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE; //circular
        dq[_front] = x;
        _size++;
    }

    void push_back(int x){
        dq[_back] = x;
        _back = (_back+1) % MAX_DEQUE_SIZE; //circular
        _size++;
    }

    void pop_front(){
        if (empty())
            cout << -1 << "\n";
        else{
            cout << dq[_front] << "\n";
            _front = (_front+1) % MAX_DEQUE_SIZE;
            _size--;
        }
    }

    void pop_back(){
        if (empty())
            cout << -1 << "\n";
        else{
            _back = (_back-1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
            cout << dq[_back] << "\n";
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
            cout << dq[_front] << "\n";
        else
            cout << -1 << "\n";
    }

    void back(){
        if (!empty())
            cout << dq[(_back-1+MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE] << "\n";
        else
            cout << -1 << "\n";
    }
};


int main(){
    int N, item;
    Deque deque;

    cin >> N;

    string command;

    for (int i=0; i<N; i++){
        cin >> command;

        if (command == "push_front"){
            cin >> item;
            deque.push_front(item);
        }
        else if (command == "push_back"){
            cin >> item;
            deque.push_back(item);
        }
        else if (command == "pop_front")
            deque.pop_front();
        else if (command == "pop_back")
            deque.pop_back();
        else if (command == "size")
            cout << deque.size() << "\n";
        else if (command == "empty")
            cout << deque.empty() << "\n";
        else if (command == "front")
            deque.front();
        else if (command == "back")
            deque.back();
    }

    return 0;
}

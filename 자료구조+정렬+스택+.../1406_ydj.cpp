#include <iostream>
#include <string>
using namespace std;

struct Node{
    char word;
    Node* front;
    Node* rear;
};

class LL{
private:
    Node* currentNode; //커서

public:
    LL(){
        currentNode = new Node;
        currentNode->front = nullptr;
        currentNode->rear = nullptr;
        currentNode->word = 'T'; //temp node
    }

    void left(){
        if (currentNode->front != nullptr){ //맨 앞(temp node)이 아니면
            currentNode = currentNode->front;
        }
    }

    void right(){
        if (currentNode->rear != nullptr) //맨 뒤가 아니면
            currentNode = currentNode->rear;
    }

    void del(){
        if (currentNode->front != nullptr){
            
            currentNode = currentNode->front;

            if ((currentNode->rear)->rear != nullptr){
                currentNode->rear = (currentNode->rear)->rear;
                delete (currentNode->rear)->front;
                (currentNode->rear)->front = currentNode;
            }

            else{
                delete currentNode->rear;
                currentNode->rear = nullptr;
            }            
        }
    }

    void insert(char c){
        Node* insertNode = new Node;
        insertNode->word = c;
        insertNode->front = currentNode;
        insertNode->rear = currentNode->rear;

        currentNode->rear = insertNode;

        if (insertNode->rear != nullptr)
            (insertNode->rear)->front = insertNode;

        currentNode = insertNode;
    }

    void print(){
        if (currentNode->front != nullptr){ 
            while((currentNode->front)->front != nullptr)
                currentNode = currentNode->front; //제일 앞 노드로 이동
        }
        else //temp node인 경우
            currentNode = currentNode->rear;
    
        while(currentNode->rear != nullptr){
            cout << currentNode->word;
            currentNode = currentNode->rear;
        }
        
        if (currentNode->front != nullptr) //temp node는 출력 x
            cout << currentNode->word << "\n";
    }

    ~LL(){
        while(currentNode->front != nullptr)
            currentNode = currentNode->front;

        while(currentNode->rear != nullptr){
            currentNode = currentNode->rear;
            // delete currentNode->front; BOJ에서는 런타임에러(DoubleFree)
            currentNode->front = nullptr;
        }

        if(currentNode->rear==nullptr)
            // delete currentNode; BOJ에서는 런타임에러(DoubleFree)
            currentNode = nullptr;
    }
};

int main(){
    string input, command;
    int M;
    LL ll;

    cin >> input;
    cin >> M;

    for (int i=0; i<input.size(); i++)
        ll.insert(input[i]);

    for (int i=0; i<M; i++){
        cin >> command;

        if (command == "L")
            ll.left();
        else if (command == "D")
            ll.right();
        else if (command == "B")
            ll.del();
        else if (command == "P"){
            char item;
            cin >> item;
            ll.insert(item);
        }
    }

    ll.print();

    return 0;
}

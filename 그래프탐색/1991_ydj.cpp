#include <iostream>
#include <queue>
using namespace std;

int N;

struct Node{
    char data;
    Node* left;
    Node* right;
};

Node* CreateNode(char data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

Node* SearchNode(Node* node, char find){
    if(node != nullptr){
        if(node->data == find)
            return node;
        else{
            Node* tmp = SearchNode(node->left, find);
            if(tmp != nullptr)
                return tmp;
            else
                return SearchNode(node->right, find);
        }
    }
    else
        return nullptr;  // node == nullptr
}

void preorder(Node* tree){
    if(tree == nullptr){
        return;
    }
    else{
        cout << tree->data;
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(Node* tree){
    if(tree == nullptr){
        return;
    }
    else{
        inorder(tree->left);
        cout << tree->data;
        inorder(tree->right);
    }
}

void postorder(Node* tree){
    if(tree == nullptr){
        return;
    }
    else{
        postorder(tree->left);
        postorder(tree->right);
        cout << tree->data;
    }
}

int main(){
    cin >> N;

    Node* tree = CreateNode('A');
    Node* sub_tree;

    char a, b, c;
    for(int i=0; i<N; i++){
        cin >> a >> b >> c;
        sub_tree = SearchNode(tree, a);
        if(b != '.')
            sub_tree->left = CreateNode(b);
        if(c != '.')
            sub_tree->right = CreateNode(c);
    }

    preorder(tree);
    cout << "\n";
    inorder(tree);
    cout << "\n";
    postorder(tree);
    cout << "\n";

    return 0;
}

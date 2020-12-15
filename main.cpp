#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
}*root = 0;

void LevelOrder() {
    Node* ptr=0;
    if(!(root)) return;
    queue<Node*> Q;
    Q.push(root);
    cout << "Level Order: ";
    while(!Q.empty()) {
        ptr = Q.front();
        Q.pop();

        cout << ptr->data << " ";
        if(ptr->left) {
            Q.push(ptr->left);
        }
        if(ptr->right) {
            Q.push(ptr->right);
        }
    }
    cout << endl;
}

Node* Insert(Node* root, int data) {
    if(root==0) {
        root = new Node;
        root->data = data; root->left = root->right = 0;
        return root;
    }
    if(root->data > data) {
        root->left = Insert(root->left, data);
    } else if(root->data < data) {
        root->right = Insert(root->right, data);
    }
    //not going to insert if the value is equal as not going to iterate
    return root;
}

void CreateBST() {
    root = Insert(root, 10);
    Insert(root, 20);
    Insert(root, 30);
    Insert(root, 39);
    Insert(root, 20);
    Insert(root, 40);
}

int main() {
    CreateBST();
    LevelOrder();
    return 0;
}
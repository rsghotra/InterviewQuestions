#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct Node {
    Node* left;
    int data;
    Node* right;
}*root = NULL;

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

void InOrder() {
    if(root == 0) {
        return;
    }
    Node* t = root;
    stack<Node*> stk;
    cout << "InOrder: ";
    while(t != 0 || !stk.empty()) {
        if(t != 0) {
            stk.push(t);
            t = t->left;
        } else {
            t = stk.top();
            stk.pop();
            cout << t->data << " ";
            t = t->right;
        }
    }
    cout << endl;
}

void PreOrder() {
    if(root == 0) return;
    Node* t = root;
    stack<Node*> stk;
    cout << "PreOrder: " ;
    while( t != 0 || !stk.empty()) {
        
        if(t != 0) {
            cout << t->data << " ";
            stk.push(t);
            t = t->left;
        }else {
            t = stk.top();
            stk.pop();
            t = t->right;
        }
    }
    cout << endl;
}

void PostOrder(Node* root) {

}

void CreateBT() {
    int x;
    queue<Node*> Q;
    root = new Node;
    cout << "Enter root node: ";
    cin >> root->data;
    root->left = 0; root->right = 0;
    Q.push(root);
    Node* ptr = 0;
    Node* temp = 0;
    while(!Q.empty()) {
        ptr = Q.front();
        Q.pop();
        cout << "Enter left child of " << ptr->data << ": ";
        cin >> x;
        if(x != -1) {
            temp = new Node;
            temp->data = x;
            temp->left = 0; temp->right = 0;
            ptr->left = temp;
            Q.push(temp);
        }
        cout << "Enter right child of " << ptr->data << ": ";
        cin >> x;
        if(x != -1) {
            temp = new Node;
            temp->data = x;
            temp->left = 0; temp->right = 0;
            ptr->right = temp;
            Q.push(temp);
        }
    }
}

int SplitIndex(Node* root, int data) {

}

void GenerateBT(int inorder[], int preorder[], int inStart, int inEnd) {

}

int Height(Node* root) {
    
}

int Sum(Node* root) {

}

int Count(Node* root) {

}

int Diameter(Node* root) {

}

int FindUniqueBTs(int num_of_nodes) {

}

int main() {
    CreateBT();
    LevelOrder();
    PreOrder();
    InOrder();
    return 0;
}
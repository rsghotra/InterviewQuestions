#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;
//https://algorithms.tutorialhorizon.com/determine-whether-given-binary-tree-is-binary-search-treebst-or-not/
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(){}
    Node(int data) {
        this->data = data;
        this->left = this->right = 0;
    }
}*root = NULL;

void LevelOrder() {
    if(!root) return;
    queue<Node*> Q;
    Node* t = 0;
    Q.push(root);
    cout << "Level Order: "; 
    while(!Q.empty()) {
        t = Q.front();
        Q.pop();

        cout << t->data << " ";
        if(t->left) Q.push(t->left);
        if(t->right) Q.push(t->right);
    }
    cout << endl;
}

Node* ConvertBST(vector<int>& vect, int start, int end) {
    if(start > end) {
        return nullptr;
    }

    int middle = (start+end)/2;
    Node* root = new Node(vect.at(middle));

    root->left = ConvertBST(vect, start, middle-1);
    root->right = ConvertBST(vect, middle+1, end);
    return root;
}

void PreOrder() {
    Node* t = root;
    stack<Node*>stk;
    cout << "PreOrder: ";
    while(t != 0 || !stk.empty()) {
        if(t != 0) {
            cout << t->data << " ";
            stk.push(t);
            t = t->left;
        } else {
            t = stk.top();
            stk.pop();
            t = t->right;
        }
    }
    cout << endl;
}

void InOrder() {
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

void PostOrder() {
    stack<long int> stk;
    long int temp;
    Node* t = root;
    cout << "PostOrder: ";
    while(t != 0 || !stk.empty()) {
        if(t != 0) {
            stk.push(reinterpret_cast<uintptr_t>(t));
            t = t->left;
        } else {
            temp = stk.top();
            stk.pop();
            if(temp > 0) {
                t = reinterpret_cast<Node*>(temp);
                t = t->right;
                stk.push(-temp);
            } else {
                t = reinterpret_cast<Node*>((-1)*(temp));
                cout << t->data << " ";
                t = 0;
            }
        }
    }
    cout << endl;
}

int main() {
    vector<int> vect{5,10,15,40,20,25,30,35};
    root = ConvertBST(vect, 0, vect.size()-1);
    LevelOrder();
    PreOrder();
    InOrder();
    PostOrder();
    return 0;
}
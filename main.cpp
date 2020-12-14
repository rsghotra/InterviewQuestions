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
    if(root == 0) return;
    queue<Node*> Q;
    Node* ptr = 0;
    Q.push(root);
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

}

void InOrder() {

}

void PreOrder(Node* root) {

}

void PostOrder(Node* root) {

}

void CreateBT() {
    int x;
    queue<Node*> Q;
    root = new Node;
    cout << "Enter root node: ";
    cin >> root->data;
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
            ptr->left = temp;
            Q.push(temp);
        }
        cout << "Enter right child of " << ptr->data << ": ";
        cin >> x;
        if(x != -1) {
            temp = new Node;
            temp->data = x;
            ptr->right = temp;
            Q.push(temp);
        }
    }
}

void CreateBSTByInsert(Node* root, int data) {

}

Node* Delete(Node* root, int val) {

}

Node* InOrderSucc(Node* root) {

}

Node* InOderPred(Node* root) {

}

int SplitIndex(Node* root, int data) {

}

void GenerateBT(int inorder[], int preorder[], int inStart, int inEnd) {

}

int Height(Node* root) {
    if(root == 0) return 0;
    if(root && root->left == 0 && root->right == 0) return 0;
    int leftTreeHght = Height(root->left);
    int rightTreeHght = Height(root->right);
    if(leftTreeHght > rightTreeHght) return 1 + leftTreeHght;
    if(rightTreeHght >= leftTreeHght) return 1 + rightTreeHght;
}

int Sum(Node* root) {

}

int Count(Node* root) {

}

int Diameter(Node* root) {

}

void TopView(Node* root) {

}

void BottomView(Node* root) {

}

Node* SearchBST(Node* root, int val) {

}

Node* GenerateBST(vector<int> preorder) {

}

int BalanceFactor(Node* root) {

}

Node* LLRotation(Node* root) {

}

Node* RRRotation(Node* root) {

}

Node* LRRotation(Node* root) {

}

Node* RLRotation(Node* root) {

}

int FindUniqueBTs(int num_of_nodes) {

}

Node* ConvertNArryTreeToBT(Node* root) {

}

int main() {
    CreateBT();
    LevelOrder();
    return 0;
}
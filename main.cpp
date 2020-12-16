#include<iostream>
#include<string>
#include<queue>
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
    cout << "Level Order: " << endl; 
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


int main() {
    vector<int> vect{5,10,15,40,20, 25, 30,35};
    root = ConvertBST(vect, 0, vect.size()-1);
    cout << "\nisBST: " << isBST(root, INT_MIN, INT_MAX) << endl;
    LevelOrder();
}
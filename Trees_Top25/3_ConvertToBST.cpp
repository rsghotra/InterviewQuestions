#include<iostream>
#include<string>
#include<queue>
using namespace std;
//https://algorithms.tutorialhorizon.com/sorted-array-to-binary-search-tree-of-minimal-height/
struct Node {
    int data;
    Node* left;
    Node* right;
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

int Height(Node* root) {
    if(root == 0) {
        return 0;
    }
    if(root && root->left==0 && root->right == 0) {
        return 0;
    }
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    if(leftHeight > rightHeight) {
        return 1 + leftHeight;
    } else {
        return 1 + rightHeight;
    }
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
    vector<int> vect{1,2,3,4,5,6,7};
    root = ConvertBST(vect, 0, vect.size()-1);
    LevelOrder();
    cout << "Height of the tree: " << Height(root) << endl;
    return 0;
}
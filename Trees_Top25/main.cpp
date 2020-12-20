#include<iostream>
#include<string>
#include<queue>
#include<vector>
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
    if(root == 0) {
        return;
    }
    queue<long int> Q;
    long int temp;
    Node* t = root;
    int i = 1;
    Q.push(reinterpret_cast<uintptr_t>(t));
    while(!Q.empty()) {
        while(Q.front() > 0) {
            temp = Q.front();
            Q.pop();
            //means child will put -ve addresses into the queue
            t = reinterpret_cast<Node*>(temp);
            cout << t->data << " ";
            if(t->left) {
                temp = reinterpret_cast<uintptr_t>(t->left);
                Q.push(-temp);
            }
            if(t->right) {
                temp = reinterpret_cast<uintptr_t>(t->right);
                Q.push(-temp);
            }
        }
        cout << endl;
        while(Q.front() < 0) {
            temp = Q.front();
            Q.pop();
            //means child will push positive address into the queue
            temp = -1 * temp;
            t = reinterpret_cast<Node*>(temp);
            cout << t->data << " ";
            if(t->left) {
                temp = reinterpret_cast<uintptr_t>(t->left);
                Q.push(temp);
            }
            if(t->right) {
                temp = reinterpret_cast<uintptr_t>(t->right);
                Q.push(temp);
            }
        }
        cout << endl;
    }
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

int isBalanced(Node* root) {
    if(root == 0) {
        return 0;
    }
    if(root && root->left==0 && root->right == 0) {
        return 0;
    }
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    if(abs(leftHeight - rightHeight) > 1) {
        return false;
    } else {
        return true;
    }
}

void CheckBalance() {
    int result = isBalanced(root);
    if(result == 1) {
        cout << "Tree is  balanced" << endl;
    }
    else {
        cout << "Tree is not balanced" << endl;
    }
}

int main() {
    vector<int> vect{5,-2,3,1,2};

    // root = ConvertBST(vect, 0, vect.size()-1);
    // LevelOrder();
    // cout << "Height of the tree: " << Height(root) << endl;
    // CheckBalance();
    return 0;
}
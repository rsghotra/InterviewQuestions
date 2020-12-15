#include<iostream>
#include<string>
#include<queue>
using namespace std;

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

void Search(int data) {
    if(!root) {
        cout << "BST is empty." << endl;
        return;
    }
    Node* t = root;
    while(t) {
        if(t->data == data) {
            cout << "Node found: " << t << endl;
            return;
        }
        else if(t->data > data) {
            t = t->left;
        } else {
            t = t->right;
        }
    }
}

Node* Insert(Node* root, int data) {
    if(root == 0) {
        root = new Node(data);
        return root;
    }
    if(root->data > data) {
        root->left = Insert(root->left, data);
    } else if(root->data < data) {
        root->right = Insert(root->right, data);
    }
    return root;
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

Node* InorderPred(Node* ptr) {
    while(ptr && ptr->right)
        ptr = ptr->right;
    return ptr;
}

Node* InorderSucc(Node* ptr) {
    while(ptr && ptr->left) {
        ptr = ptr->left;
    }
    return ptr;
}

Node* Delete(Node* ptr, int data) {
    static Node* root = ptr;
    if(ptr == 0) {
        return nullptr;
    }

    if(ptr && ptr->data == data && ptr->left == 0 && ptr->right == 0) {
        if(ptr == root) {
            root = 0;
        }
        int val = ptr->data;
        delete ptr;
        ptr = 0;
        return nullptr;
    }

    if(ptr->data > data) {
        ptr->left = Delete(ptr->left, data);
    } else if(ptr->data < data) {
        ptr->right = Delete(ptr->right, data);
    } else {
        //element is found
        if(Height(ptr->left) > Height(ptr->right)) {
            Node* temp = InorderPred(ptr->left);
            ptr->data = temp->data;
            ptr->left = Delete(ptr->left, temp->data);
        } else {
            Node* temp = InorderSucc(ptr->right);
            ptr->data = temp->data;
            ptr->right = Delete(ptr->right, temp->data);
        }
    }
}

void CreateBST() {
    root = Insert(root, 10);
    Insert(root,20);
    Insert(root,30);
    Insert(root,39);
    Insert(root,20);
    Insert(root,40);
}

int main() {
    CreateBST();
    LevelOrder();
    Delete(root, 40);
    Delete(root, 10);
    LevelOrder();
    return 0;
}
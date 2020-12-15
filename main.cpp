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

Node* InOrderPred(Node* ptr) {
    while(ptr && ptr->right) {
        ptr = ptr->right;
    }
    return ptr;
}

Node* InOrderSuc(Node* ptr) {
    while(ptr && ptr->left) {
        ptr = ptr->left;
    }
    return ptr;
}

int Height(Node* root) {
    if(root == 0) {
        return 0;
    }
    if(root->left == 0 && root->right == 0) {
        return 0; //option if you want to keep the height as 1 for zeroth node
    }
    int left = Height(root->left);
    int right = Height(root->right);
    if(left > right) {
        return left + 1;
    } else {
        return right + 1;
    }
}


Node* Delete(Node* ptr, int data) {
    Node* temp = 0;
    if(ptr == 0) {
        return nullptr;
    }
    if(ptr->data == data && ptr->left == 0 && ptr->right == 0) {
        //deletion of the lead node;
        if(ptr == root) {
            root = 0;
        }
        delete ptr;
        ptr = 0;
        return nullptr;
    } 
    if(ptr->data > data) {
        ptr->left = Delete(ptr->left, data);
    } else if(ptr->data < data) {
        ptr->right = Delete(ptr->right, data);
    } else {
        //value found
        if(Height(ptr->left) > Height(ptr->right)) {
            temp = InOrderPred(ptr->left);
            ptr->data = temp->data;
            ptr->left = Delete(ptr->left, ptr->data); //new data now
        } else {
            temp = InOrderSuc(ptr->right);
            ptr->data = temp->data;
            ptr->right = Delete(ptr->right, ptr->data);
        }
    }
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
    Delete(root, 10);
    LevelOrder();
    return 0;
}
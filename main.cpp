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

void PostOrder() {
    if(root == 0) {
        return;
    }
    //MUST TAKE LONG INT AND UINTPTR_T and reinterpret case
    stack<long int> stk;
    Node* t = root;

    cout << "PostOrder: ";
    while(t != 0 || !stk.empty()) {
        if( t!= 0) {
            stk.push(reinterpret_cast<uintptr_t>(t));
            t = t->left;
        } else {
            long int temp = stk.top();
            stk.pop();
            if(temp < 0) {
                t = reinterpret_cast<Node*>((-1)*(temp));
                cout << t->data << " ";
                t = 0; //PITFALL
            } else {
                t = reinterpret_cast<Node*>(temp);
                t = t->right;
                stk.push(-temp);
            }
        }
    }
    cout << endl;
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
    return 0;
}

void GenerateBT(int inorder[], int preorder[], int inStart, int inEnd) {

}

int Height(Node* root) {
    if(root == 0) {
        return 0;
    }
    if(root->left == 0 && root->right == 0) {
        return 0;
    }
    int left = Height(root->left);
    int right = Height(root->right);
    if(left > right) {
        return left + 1;
    } else {
        return right + 1;
    }
}

void _Height() {
    cout << "Height of the tree is: " << Height(root) << endl;
}

int Sum(Node* root) {
    if(root == 0) {
        return 0;
    }
    return root->data + Sum(root->left) + Sum(root->right);
}

void _Sum() {
    cout << "Sum of all nodes in the tree is: "  << Sum(root) << endl;
}

int Count(Node* root) {
    if(root == 0) {
        return 0;
    }
    return 1 + Count(root->left) + Count(root->right);
}

void _Count() {
    cout << "Number of Nodes: " << Count(root) << endl;
}

int Diameter(Node* root) {
    return 0;
}

void _Diameter() {
    cout << "Diameter of the tree is: " << Diameter(root) << endl;
}

int Combination(int n, int r) {
    if(n == r || r == 0) {
        return 1;
    }
    return Combination(n-1, r) + Combination(n-1, r-1);
}

int fact(int n) {
    if(n == 0) {
        return 1;
    }
    return n * fact(n-1);
}

void FindUniqueBTs(int n) {
    /*
        - Catalan Number = 2nCn/n+1
    */
    int numer = Combination(2*n, n);
    int deno = n+1;
    cout << "Number of Unique BT from " << n << " nodes " << (numer/deno) << endl;
}

int main() {
    CreateBT();
    LevelOrder();
    PreOrder();
    InOrder();
    PostOrder();
    _Height();
    _Count();
    _Sum();
    FindUniqueBTs(5);
    _Diameter();
    return 0;
}
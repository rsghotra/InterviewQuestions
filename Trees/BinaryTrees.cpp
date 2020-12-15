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

/*https://algorithms.tutorialhorizon.com/diameter-of-a-binary-tree/
What is Diameter Of a Tree: Diameter of tree is defined as A longest path or route between any two nodes in a tree.
The path may or may not for through the root.
Diameter of a tree w.r.t root can be defined as

Maximum(Diameter of left subtree, Diameter of right subtree, Longest path between two nodes which passes through the root.)

Now the diameter of left and right subtree’s can be solved recursively. 
And Longest path between two nodes which passes through the root can be calculated 
as 1 + height of left subtree + height of right subtree.
*/

int Diameter(Node* root) {
    if(root == 0) {
        return 0;
    }
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);

    int leftDia = Diameter(root->left);
    int rightDia = Diameter(root->right);
    int rootDia = leftHeight + rightHeight + 1;
    return max(rootDia, max(leftDia, rightDia));
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

int SearchSplit(vector<int> vect, int start, int end, int data) {
    for(int i = start; i <= end; i++) {
        if(vect.at(i) == data) {
            return i;
        }
    }
    return -1;
}

Node* GenerateBT(vector<int> inorder, vector<int> preorder, int inorderStart, int inorderEnd) {
    static int preIndex = 0;
    if(inorderStart > inorderEnd) {
        return nullptr;
    }
    Node* root = new Node;
    root->data = preorder[preIndex];
    preIndex++;
    if(inorderStart == inorderEnd) {
        root->left = root->right = 0;
        return root;
    }

    int splitIndex = SearchSplit(inorder, inorderStart, inorderEnd, root->data);
    root->left = GenerateBT(inorder, preorder, inorderStart, splitIndex-1);
    root->right = GenerateBT(inorder, preorder, splitIndex+1, inorderEnd);
    return root;
}

void _GenerateBT() {
    vector<int> inorder{7,6,9,3,4,5,8,2,1};
    vector<int> preorder{4,7,9,6,3,2,5,8,1};
    cout << "Generated BT: ";
    root = GenerateBT(inorder, preorder, 0, inorder.size() -1);
    InOrder();
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
    _GenerateBT();
    return 0;
}
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void Display(Node* root) {
    if(root == 0) return;
    cout << root->data << " ";
    Display(root->next);
}

void Display_Reverse(Node* ptr) {
    if(ptr == 0) return;
    Display_Reverse(ptr->next);
    cout << ptr->data << " ";
}

Node* Reverse(Node* ptr) {
    Node* root = ptr;
    Node* p = ptr;
    Node* q = 0;
    Node* r = 0;
    while(p) {
        q = p;
        r = q;
        p = p->next;
        q->next = r;
    }
    root = q;
    return q;
}

bool isLoop(Node* root) {
    Node* ptr = root;
    Node* qtr = root;
    if(root == 0) return false;
    if(root->next==0) return false;
    while(ptr) {
        ptr = ptr->next;
        if(ptr) {
            ptr->next;
        }
        qtr = qtr->next;
        if(ptr == qtr) {
            cout << "Loop Detected" << endl;
            return;
        }
    }
    cout << "No Loop" << endl;
}

Node* MThNode(Node* root, int m) {
    static int count = 0;
    if(m < 0) return 0;
    if(root == 0) {
        return 0;
    }
    MThNode(root->next, m);
    count++;
    if(count == m) {
        return root;
    }
}

Node* FindMiddle(Node* root) {
    if(root == 0) return 0;
    Node* ptr = root;
    Node* qtr = root;
    while(ptr) {
        ptr = ptr->next;
        if(ptr) {
            ptr->next;
        }
        qtr = qtr->next;
    }
    return qtr;
}

Node* mLastNode(Node* head,Node* ptr, int m) {
    static int count = 0;
    if(m<0) return nullptr;
    if(!head) nullptr;
    if(!ptr) return nullptr;
    mLastNode(head, ptr->next, m);
    count++;
    if(count == m) {
        return ptr;
    }
}

Node* Merge(Node* root1, Node* root2) {
    if(root1 == 0 && root2 == 0) return nullptr;
    if(root1 == 0) return root2;
    if(root2 == 0) return root1;
    Node* root = new Node;
    Node* first = root1;
    Node* second = root2;
    if(root1->data <= root2->data) {
        root = root1;
        first = root1->next;
    } else {
        root = root2;
        second = root2->next;
    }
    Node* ptr = root;
    while(first && second) {
        if(first->data <= second->data) {
            ptr->next = first;
            ptr = first;
            first = first->next;
        } else {
            ptr->next = second;
            ptr = second;
            second = second->next;
        }
    }
    if(!first) {
        ptr->next = second;
    } else if(!second) {
        ptr->next = first;
    }
    return root;
}

Node* delete_at(Node* ptr, int pos) {
    int x;
    if(ptr == 0) {
        cout << "Linked List supplied was empty." << endl;
        return nullptr;
    }
    if(pos == 1) {
        //Deleting head is a special case
        Node* p = ptr;
        ptr = ptr->next;
        delete p;
    } else {
        Node* p = ptr;
        Node* q = 0;
        for(int i=0;i<pos-1 && p;i++) {
            q = p;
            p = p->next;
        }
        if(!p) {
            cout << "Invalid Index is given." << endl;
            return ptr;
        } else {
            q->next = p->next;
            delete p;
        }
    }
    return ptr;
}

Node* create_ll_by_array(int A[], int n) {
    Node* head = new Node;
    head->data = A[0];
    head->next = 0;

    //==
    Node* last = head;
    Node* t;
    int i;
    for(i=1;i < n; i++) {
        t = new Node;
        t->data = A[i];t->next=0;
        last->next = t;
        last = t;
    }
    return head;
}
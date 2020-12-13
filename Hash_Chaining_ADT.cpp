#include<iostream>
#include<array>
#define SIZE 13
using namespace std;
/*
    - Chaining: Infinite Sized Hash Table; Deletion Friendly
*/

class Node {
    public:
        int data;
        Node* next;
};

class HashTable {
    private:
    public:
        Node** HT;
        HashTable();
        ~HashTable();
        int Hash(int key);
        void Insert(int);
        int Search(int);
        Node* Delete(int);
        void Print();
};

HashTable::HashTable() {
    //created hash table and initialized with null
    this->HT = new Node*[SIZE]();
}

HashTable::~HashTable() {
    for(int i=0; i < SIZE; i++) {
        Node* ptr = this->HT[i];
        while(HT[i]) {
            this->HT[i] = (this->HT[i])->next;
            delete ptr;
            ptr = HT[i];
        }
    }
    delete [] HT;
}

int HashTable::Hash(int key) {
    return key%SIZE;
}

int HashTable::Search(int key) {
    int index = Hash(key);
    if(this->HT[index]) {
        Node* ptr = this->HT[index];
        while(ptr) {
            if(ptr->data == key) {
                return ptr->data;
            }
            ptr = ptr->next;
        }
    }
    return -1;
}

Node* HashTable::Delete(int key) {
    int index = Hash(key);
    Node* temp = 0;
    if(this->HT[index]) {
        Node* ptr = this->HT[index];
        Node* qtr = 0;

        //handling head
        if(ptr->data == key) {
            temp = ptr;
            this->HT[index] = ptr->next;
        } else {
            while(ptr) {
                if(ptr->data == key) {
                    temp = ptr;
                    break;
                } else {
                    qtr = ptr;
                    ptr = ptr->next;
                }
            }
        }
    }
    return temp;
}

void HashTable::Insert(int key) {
    int index = Hash(key);
    Node* temp = new Node;
    temp->data = key; temp->next = 0;
    if(this->HT[index] == 0) {
        this->HT[index] = temp;
    } else {
        Node* ptr = this->HT[index];
        Node* qtr = 0;
        if(ptr->data >= temp->data) {
            temp->next = ptr;
            this->HT[index] = temp;
        } else {
            while(ptr && ptr->data < temp->data) {
                qtr = ptr;
                ptr=ptr->next;
            }
            temp->next = qtr->next;
            qtr->next=temp;
        }
    }
}

void HashTable::Print() {
    Node* p = 0;
    if(HT != 0) {
        for(int i = 0 ; i < SIZE; i++) {
            p = HT[i];
            if(p == 0) cout << "XXXXX" << " ";
            while(p != 0) {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
}

int main() {
    int A[9] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    HashTable HT;

    for(int i = 0; i < 9; i++) {
        HT.Insert(A[i]);
    }

    HT.Print();

    cout << "Successful Search" << endl;
	int key = 6;
	int value = HT.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
	cout << "Unsuccessful Search" << endl;
	key = 39;
	value = HT.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
    return 0;
}
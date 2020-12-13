#include<iostream>
#define SIZE 10
using namespace std;

class HashTable {
    int* HT;
    public:
        HashTable();
        ~HashTable();
        int  Hash(int);
        int  LinearProbe(int);
        void Insert(int);
        int  Search(int);
        void Print();
};

HashTable::HashTable() {
    //must initialize the hash table with something - zero in this case
    this->HT = new int[SIZE]();
}
HashTable::~HashTable() {
    delete [] HT;
    HT = 0;
}

void HashTable::Print() {
    for(int i=0; i < SIZE; i++) {
        cout << this->HT[i] << " ";
    }
    cout << endl;
}

int HashTable::Hash(int key) {
    return key%SIZE;
}

//need to stop loop when Hash is full else it will go in loop condition
int HashTable::LinearProbe(int key) {
    int index = Hash(key);
    int i = 0;
    do {
        if(this->HT[(index+i)%SIZE] == 0) {
            return this->HT[(index+i)%SIZE];
        }
        i++;
    } while((index+i)%SIZE != index);
    return -1;
}

void HashTable::Insert(int key) {
    int index = Hash(key);
    if(this->HT[index] == 0) {
        this->HT[index] = key;
    } else {
        index = this->LinearProbe(key);
        if(index != -1) {
            this->HT[index] = key;
        } else {
            cout << "Sorry - Hash Table is Full." << endl;
        }
    }
}

//extra search operation
int HashTable::Search(int key) {
    int index = Hash(key);

    if(this->HT[index] == key) return index;
    int i = 0;
    do {
        if(this->HT[(index+i)%SIZE] == key) {
            return this->HT[(index+i)%SIZE];
        }
        i++;
    } while((index+i)%SIZE != index);
    return -1;
}

int main() {
    HashTable HT;
    HT.Insert(12);
    HT.Insert(25);
    HT.Insert(35);
    HT.Insert(37);
    HT.Insert(39);
    HT.Insert(41);
    HT.Print();
    cout << "Key found at " << HT.Search(35) << endl;
    cout << "Key found at " << HT.Search(30) << endl;
    cout << "Key found at " << HT.Search(12) << endl;
}

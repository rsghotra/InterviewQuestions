#include<iostream>
#define SIZE 10
using namespace std;

class HashTable {
    private:
        int* HT;
    public:
        HashTable();
        ~HashTable();
        void Print();
        int Hash(int);
        int QuadraticProbing(int);
        int Search(int);
        void Insert(int);
};

HashTable::HashTable() {
    //must initialize with zero
    this->HT = new int[SIZE]();
}

HashTable::~HashTable() {
    delete [] this->HT;
    HT = 0;
}

int HashTable::Hash(int key) {
    return key%SIZE;
}

int HashTable::QuadraticProbing(int key) {
    int index = Hash(key);

    if(this->HT[index] == 0) {
        return this->HT[index];
    } else {
        int i = 0;
        do {
            if(this->HT[(index+ i*i)%SIZE] == 0) {
                return (index + i*i)%SIZE;
            }
            i++;
        } while((index+i*i)%SIZE != index); //careful - checking for index not for value here.
    }
    return -1;
}

void HashTable::Insert(int key) {
    int index = Hash(key);

    if(this->HT[index] == 0) {
        this->HT[index] = key;
    } else {
        index = this->QuadraticProbing(key);
        if(index != -1) {
            this->HT[index] = key;
        } else {
            cout << "Hash Table is Full." << endl;
        }
    }
}

int HashTable::Search(int key) {
    int index = Hash(key);

    if(this->HT[index] == key) {
        return index;
    }
    int i = 0;
    do {
        //the moment we see - 0 in our probe - the element is not present
        if(this->HT[(index+i*i)%SIZE] == 0) {
            return -1;
        }
        if(this->HT[(index+i*i)%SIZE] == key) {
            return (index+i*i)%SIZE;
        }
        i++;
    }while((index+i*i)%SIZE != index);
    return -1;
}

void HashTable::Print() {
    for(int i{0}; i < SIZE;i++) {
        cout << this->HT[i] << " ";
    }
    cout << endl;
}

int main() {
    HashTable HT;
    HT.Insert(12);
    HT.Insert(25);
    HT.Insert(35);
    HT.Insert(55);
    HT.Insert(39);
    HT.Insert(41);
    HT.Print();
    cout << "Key found at: " << HT.Search(35) << endl;
    cout << "Key found at: " << HT.Search(30) << endl;
    cout << "Key found at: " << HT.Search(55) << endl;
    return 0;
}
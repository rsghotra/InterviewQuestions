#include<iostream>
using namespace std;

class Queue {
    private:
        int size;
        int front;
        int rear;
        int* Q;
    public:
        Queue(int);
        ~Queue();
        void Print();
        void Enqueue(int);
        int Dequeue();
        bool isFull();
        bool isEmpty();
};

Queue::Queue(int sz) {
    this->size = sz;
    //front pointing value will never be used
    this->Q = new int[this->size]();
    this->front = -1;
    this->rear = -1;
}

Queue::~Queue() {
    delete [] this->Q;
    this->Q = 0;
}

bool Queue::isEmpty() {
    if(this->front == this->rear) return true;
    else return false;
}

bool Queue::isFull() {
    //or this->rear = this->size-1
    if(this->rear == this->size-1) return true;
    else return false;
}

void Queue::Enqueue(int data) {
    if(!this->isFull()) {
        this->rear++;
        this->Q[this->rear] = data;
    }
}

int Queue::Dequeue() {
    if(!this->isEmpty()) return -1;
    this->front++;
    int val = this->Q[this->front];
    this->Q[this->front] = 0;
    return val;
}

void Queue::Print() {
    if(!this->isEmpty()) {
        //key is front is pointing to last deleted(processed element)
        for(int i = this->front+1; i <= this->rear; i++) {
            cout << this->Q[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[] = {1, 3, 5, 7, 9};
 
    Queue q(sizeof(A)/sizeof(A[0]));
 
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.Enqueue(A[i]);
    }
 
    // Display
    q.Print();
 
    // Overflow
    q.Enqueue(10);
 
    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        q.Dequeue();
    }
    q.Print();
    // Underflow
    q.Dequeue();
    
    return 0;
}
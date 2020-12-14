#include<iostream>
using namespace std;

class CQueue {
    private:
        int front;
        int rear;
        int size;
        int* Q;
    public:
        CQueue(int);
        ~CQueue();
        void Print();
        void Enqueue(int data);
        int Dequeue();
        bool isFull();
        bool isEmpty();
};

CQueue::CQueue(int sz) {
    this->size = sz;
    this->Q = new int[this->size+1];
    this->front = 0;
    this->rear = 0;
}

CQueue::~CQueue() {
    delete [] this->Q;
    this->Q=0;
}

bool CQueue::isEmpty() {
    if(this->front == this->rear) return true;
    return false;
}

bool CQueue::isFull() {
    if((this->rear+1)%this->size == this->front) return true;
    return false;
}

void CQueue::Enqueue(int data) {
    if((this->rear+1)%this->size == this->front) {
        cout << "Queue is Full." << endl;
        return;
    }
    this->rear = (this->rear+1)%this->size;
    this->Q[this->rear] = data;
}

int CQueue::Dequeue() {
    if(this->isEmpty()) {
        cout << "Queue is Empty." << endl;
        return -1;
    }
    this->front = (this->front + 1)%this->size;
    return this->Q[this->front];
}

void CQueue::Print() {
    if(this->isEmpty()) {
        cout << "Queue is Empty. Nothing to display." << endl;
    } else {
        int i = this->front+1;
        while(i != (this->rear+1)%this->size)
        {
            cout << this->Q[i] << " ";
            i = (i+1)%this->size;
        }
    }
    cout << endl;
}


int main() {
        int A[] = {1,3,5,7,9,10, 11, 12, 13};
        CQueue cq(10);
        for(int i=0;i<10;i++) {
            cq.Enqueue(A[i]);
        }
        cq.Print();
        cq.Enqueue(10);
        for(int i=0;i<5;i++) {
            cout << "Dequeued from Circular Queue: " << cq.Dequeue() << endl;
        }
        //underflow
        cq.Dequeue();
        cq.Dequeue();
        cq.Dequeue();
        cq.Print();

}
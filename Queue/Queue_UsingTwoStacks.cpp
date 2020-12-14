#include<iostream>
#include<stack>
using namespace std;

class Queue {
    private:
        stack<int> stk1;
        stack<int> stk2;
    public:
        void Enqueue(int data);
        int  Dequeue();
        void Print();
};

//always enqueue in stack1
void Queue::Enqueue(int data) {
    stk1.push(data);
}

int Queue::Dequeue() {
    if(!stk2.empty()) {
        cout << "Dequeueud: " << stk2.top() << endl;
        stk2.pop();
    } else {
        while(!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        if(!stk2.empty()) {
            cout << "Dequeueud: " << stk2.top() << endl;
            stk2.pop();
        }
    }

}

void Queue::Print() {
    if(!stk2.empty()) {
        while(!stk2.empty()) {
            cout << stk2.top() << " ";
            stk2.pop();
        }
    }
    if(!stk1.empty()) {
        while(!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
    }
    if(!stk2.empty()) {
        while(!stk2.empty()) {
            cout << stk2.top() << " ";
            stk2.pop();
        }
    }
}

int main() {
    Queue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Enqueue(60);
    q.Dequeue();
    q.Dequeue();
    q.Enqueue(70);
    q.Enqueue(80);
    q.Dequeue();
    q.Print();
    return 0;
}


#include<iostream>
#include<thread>
#include<chrono>
using namespace std;


void run(int count) {
    while(count --> 0) {
        cout << count << " CppNuts" << endl;
        cout << "thread finished" << endl;
    }
}

int main() {
    std::thread t1(run, 10);
    cout << "main()" << endl;

    t1.detach();
    cout << "main() after" << endl;
    return 0;
}